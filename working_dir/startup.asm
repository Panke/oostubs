;*---------------------------------------------------------------------------*
;* Operating Systems I                                                       *
;*---------------------------------------------------------------------------*
;*                                                                           *
;*                        S T A R T U P . A S M                              *
;*                                                                           *
;*---------------------------------------------------------------------------*

;* 'startup' is the entry point for the system. The switch into 'protected mode'
;* has allready been done. Now everything is prepared to execute our own source.

;
;   System
;

[GLOBAL startup]
[GLOBAL _startup]
[GLOBAL _idt]
[GLOBAL ___builtin_delete]
[GLOBAL ___pure_virtual]
[GLOBAL ___cxa_pure_virtual]
[GLOBAL __ZdlPv]
[GLOBAL ___cxa_atexit]
[GLOBAL __alloca]
[GLOBAL ___w32_sharedptr_initialize]
[GLOBAL ___w32_sharedptr_initialize]
[GLOBAL ___dso_handle]

[EXTERN _main]
[EXTERN _guardian]
[EXTERN _init]
[EXTERN _fini]

[SECTION .text]

startup:
_startup:

; GCC-kompilierter Code erwartet das so.

	cld

; Globales Datensegment

	mov	ax,0x10
	mov	ds,ax
	mov	es,ax
	mov	fs,ax
	mov	gs,ax

; Stack festlegen

	mov	ss,ax
	mov	esp,init_stack+4096

; Unterbrechungsbehandlung sicherstellen

	call	setup_idt
	call	reprogram_pics

; Aufruf des C-Codes

	call	_init		; Konstruktoren globaler Objekte ausfuehren
	call	_main		; C/C++ Level System
	call	_fini		; Destruktoren
	hlt

; Default Interrupt Behandlung

; Spezifischer Kopf der Unterbrechungsbehandlungsroutinen

%macro wrapper 1
wrapper_%1:
	push	eax
	mov	al,%1
	jmp	wrapper_body
%endmacro

; ... wird automatisch erzeugt.
%assign i 0
%rep 256
wrapper i
%assign i i+1
%endrep

; Gemeinsamer Rumpf
wrapper_body:
	cld			; das erwartet der gcc so.
	push	ecx		; Sichern der fluechtigen Register
	push	edx
	and	eax,0xff	; Der generierte Wrapper liefert nur 8 Bits
	push	eax		; Nummer der Unterbrechung uebergeben
	call	_guardian
	add	esp,4		; Parameter vom Stack entfernen
	pop	edx		; fluechtige Register wieder herstellen
	pop	ecx
	pop	eax
	iret			; fertig!

;
; setup_idt
;
; Relokation der Eintraege in der IDT und Setzen des IDTR

setup_idt:
	mov	eax,wrapper_0	; ax: niederwertige 16 Bit
	mov	ebx,eax
	shr	ebx,16		; bx: hoeherwertige 16 Bit
	mov	ecx,256		; Zaehler
.loop:	add	[_idt+8*ecx+0],ax
	adc	[_idt+8*ecx+6],bx
	dec	ecx
	jge	.loop

	lidt	[idt_descr]
	ret

;
; reprogram_pics
;
; Neuprogrammierung der PICs (Programmierbare Interrupt-Controller), damit
; alle 15 Hardware-Interrupts nacheinander in der idt liegen.

reprogram_pics:
	mov	al,0x11   ; ICW1: 8086 Modus mit ICW4
	out	0x20,al
	call	delay
	out	0xa0,al
	call	delay
	mov	al,0x20   ; ICW2 Master: IRQ # Offset (32)
	out	0x21,al
	call	delay
	mov	al,0x28   ; ICW2 Slave: IRQ # Offset (40)
	out	0xa1,al
	call	delay
	mov	al,0x04   ; ICW3 Master: Slaves an IRQs
	out	0x21,al
	call	delay
	mov	al,0x02   ; ICW3 Slave: Verbunden mit IRQ2 des Masters
	out	0xa1,al
	call	delay
	mov	al,0x03   ; ICW4: 8086 Modus und automatischer EIO
	out	0x21,al
	call	delay
	out	0xa1,al
	call	delay

	mov	al,0xff		; Hardware-Interrupts durch PICs
	out	0xa1,al		; ausmaskieren. Nur der Interrupt 2,
	call	delay		; der der Kaskadierung der beiden
	mov	al,0xfb		; PICs dient, ist erlaubt.
	out	0x21,al

	ret

; delay
;
; Kurze Verzoegerung fuer in/out Befehle.

delay:
	jmp	.L2
.L2:	ret

; Die Funktion wird beim abarbeiten der globalen Konstruktoren aufgerufen
; (unter Linux). Das Label muss definiert sein (fuer den Linker). Die
; Funktion selbst kann aber leer sein, da bei StuBs keine Freigabe des 
; Speichers erfolgen muss.

___pure_virtual:
___cxa_pure_virtual:
___builtin_delete:
__ZdlPv:
___cxa_atexit:
__alloca:
___w32_sharedptr_initialize:
___dso_handle:

        ret

[SECTION .data]
	
;  'interrupt descriptor table' mit 256 Eintraegen.

_idt:

%macro idt_entry 1
	dw	(wrapper_%1 - wrapper_0) & 0xffff
	dw	0x0008
	dw	0x8e00
	dw	((wrapper_%1 - wrapper_0) & 0xffff0000) >> 16
%endmacro

; ... wird automatisch erzeugt.

%assign i 0
%rep 256
idt_entry i
%assign i i+1
%endrep

idt_descr:
	dw	256*8-1		; idt enthaelt 256 Eintraege
	dd	_idt

;   Stack und interrupt descriptor table im BSS Bereich

[SECTION .bss]

init_stack:
	resb	4096

