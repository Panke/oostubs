; $Id: bootsect.asm,v 1.1.1.1 2002/09/20 20:40:30 gal Exp $

;******************************************************************************
;* Betriebssysteme                                                            *
;*----------------------------------------------------------------------------*
;*                                                                            *
;*                            B O O T S E C T                                 *
;*                                                                            *
;*----------------------------------------------------------------------------*
;* Code fuer den Disketten-Bootblock des System-Images. Das BIOS laedt den    *
;* ersten Block einer Diskette (den Bootblock) beim Starten des Rechner in    *
;* den Hauptspeicher und fuehrt ihn aus. Der Programmcode des Bootblocks      *
;* laedt nun das restliche System und fuehrt es aus.                          *
;******************************************************************************

;
; Konstanten
;
	BIOSSEG		equ 0x07c0	; Hierher wird der Bootsector
					; vom BIOS geladen
	BOOTSEG		equ 0x0060	; Hierher verschiebt sich der
					; Boot-Code
	SETUPSEG	equ 0x9000	; Hierher laedt der Boot-Code den
					; Setup-Code (max. 64K inkl. Stack)
	SYSTEMSEG	equ 0x1000	; System-Code (max. 512K)
	SECTORSZ	equ 512		; Groesse eines Sektors in Bytes

[SECTION .text]

;
; Boot-Code
;
bootsector:
	jmp	skip_data

;------------------------------------------------------------------------------
;
; Datenbereich, der von 'build' beim Erzeugen der Boot-Diskette
; gefuellt wird.
;
pad:
	db 0	; Byte zum auffuellen, damit 'total_tracks' an einer
		; geraden Adresse liegt
total_tracks:
	dw 0	; Anzahl der Tracks der Diskette
total_heads:
	dw 0	; Anzahl der Seiten der Diskette
total_sectors:
	dw 0	; Anzahl der Sektoren pro Track
setup_sectors:
	dw 0	; Anzahl der Sektoren, die der Setup-Code einnimmt
system_sectors:
	dw 0	; Anzahl der Sektoren, die das System einnimmt
bootdevice:
	db 0	; BIOS Geraetecode: 00: Disk A, 01: Disk B, ..., 0x80 HD0, ...
curr_track:
	db 0	; Track, bei dem die Diskette/Partition beginnt
curr_head:
	db 0	; Head,  bei dem die Diskette/Partition beginnt
curr_sector:
	db 0	; Sector,  bei dem die Diskette/Partition beginnt

;-----------------------------------------------------------------------

;
; Kopieren des Bootsectors
;
skip_data:
	mov	ax,BIOSSEG
	mov	ds,ax
	xor	si,si
	mov	ax,BOOTSEG
	mov	es,ax
	xor	di,di
	mov	cx,SECTORSZ/2
	rep movsw
;
; Ausfuehrung durch die Kopie fortsetzen
;
	jmp	BOOTSEG:start
;
; Segmentregister initialisieren und Platz fuer den Stack schaffen
;
start:	
	mov	ax,cs		; Daten-, Stack- und Codesegment sollen
	mov	ds,ax		; hierher zeigen.
	mov	ss,ax
	mov	sp,4*SECTORSZ	; Drei Sektoren als Stack freilassen
;
; Ausgabe einer Meldung mit Hilfe eines BIOS-Aufrufs
;
	mov	ah,0x03		; Feststellen der Cursor-Position
	xor	bh,bh
	int	0x10
	
	mov	cx,13		
	mov	bx,0x0007	; page 0, attribute 7 (normal)
	mov	ax,ds
	mov	es,ax
	mov	bp,bootmessage
	mov	ax,0x1301	; Ausgabe des Textes, Cursor bewegen
	int	0x10
;
; Nachladen des Setup-Codes und des Systems selbst.
;
	xor	ah,ah		; Reset des Disketten-/Plattencontrollers
	mov	dl,[bootdevice]
	int	0x13
;
; Weiterstellen der Disketten-/Plattenposition um 1 (Bootblock)
;
	call	step_disk
;
; Laden des Setup-Codes
;
	mov	word [curr_segment],SETUPSEG
	mov	word [curr_offset],0
	mov	ax,[setup_sectors]
	call	load
;
; Laden des Kernels
;
	mov	word [curr_segment],SYSTEMSEG
	mov	word [curr_offset],0
	mov	ax,[system_sectors]
	call	load
;
; Floppy wieder abschalten
;
	call	stop_floppy_motor
;
; Start des Setup-Codes
;
	jmp	SETUPSEG:0

;
; load
;
; Die 'ax' Sektoren von der Diskette in den Hauptspeicher. Die Position auf
; der Diskette muss vorher in curr_head/curr_track/curr_sector und die
; Position im Hauptspeicher in curr_segment/curr_offset stehen. Die Positionen
; werden entsprechend der geladenen Sektoren weitergestellt.
;
load:
	mov	[to_load],ax
l_next_part:
	mov	al,[curr_head]
	mov	[last_head],al
	mov	al,[curr_track]
	mov	[last_track],al
	mov	al,[curr_sector]
	mov	[last_sector],al
	mov	ax,[curr_segment]
	mov	[last_segment],ax
	mov	ax,[curr_offset]
	mov	[last_offset],ax

	mov	al,0
	
l_loop:	call	step

	cmp	byte [curr_sector],0x01
	je	l_now
	cmp	word [curr_offset],0x0000
	je	l_now
	cmp	al,[to_load]
	jne	l_loop

l_now:
	push	ax
	mov	dl,[bootdevice]
	mov	dh,[last_head]
	mov	ch,[last_track]
	mov	cl,[last_sector]
	mov	bx,[last_segment]
	mov	es,bx
	mov	bx,[last_offset]
	mov	ah,0x02		; Funktionscode fuer 'Lesen'
	int	0x13
	pop	ax

	push	ax
	call	print_dot
	pop	ax
	
	mov	ah,0
	sub	[to_load],ax
	jne	l_next_part
	ret

;
; step
;
; Stellt die aktuelle Position im Hauptspeicher und auf der Diskette
; um einen Sektor (512 Byte) weiter.
;
step:	add	al,1
	call	step_disk
	call	step_memory
	ret

step_disk:
	mov	bl,[curr_sector]
	add	bl,1
	mov	[curr_sector],bl
	cmp	bl,[total_sectors]
	jle	l_1
	mov	byte [curr_sector],1
	
	mov	bl,[curr_head]
	add	bl,1
	mov	[curr_head],bl
	cmp	bl,[total_heads]
	jne	l_1
	mov	byte [curr_head],0

	mov	bl,[curr_track]
	add	bl,1
	mov	[curr_track],bl

l_1:	ret

step_memory:
	mov	bx,[curr_offset]
	add	bx,SECTORSZ
	mov	[curr_offset],bx
	test	bx,0xffff
	jne	l_2
	mov	bx,[curr_segment]
	add	bx,0x1000		; 64 KByte weiterstellen
	mov	[curr_segment],bx

l_2	ret

;
; Ausgabe eines Stern ('*') mit Hilfe eines BIOS-Aufrufs
;
print_dot:
	mov	ah,0x03		; Feststellen der Cursor-Position
	xor	bh,bh
	int	0x10
	
	mov	cx,1		
	mov	bx,0x0007	; page 0, attribute 7 (normal)
	mov	ax,ds
	mov	es,ax
	mov	bp,dot
	mov	ax,0x1301	; Ausgabe des Textes, Cursor bewegen
	int	0x10

	ret

;
; stop_floppy_motor
;
; Stopt den Motor der Floppy, da das BIOS dazu in Kuerze nicht mehr in
; der Lage sein wird. Egal, ob von Floppy oder Platte gebootet wurde.
;
stop_floppy_motor:
	mov	dx,0x3f2
	xor	al,al
	out	dx,al
	ret
	
;
; Datenbereich
;

bootmessage:
	db 13,10
	db 'booting ... '

dot:
	db '*'
	
to_load:
	dw 0	
curr_segment:
	dw 0
curr_offset:
	dw 0

last_head:
	db 0
last_track:
	db 0
last_sector:
	db 0
last_segment:
	dw 0
last_offset:
	dw 0

unused:
	times bootsector+510-$ db 0

mark:
	dw 0xaa55
