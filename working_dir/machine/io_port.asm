;*---------------------------------------------------------------------------*
;* Operating Systems I                                                       *
;*---------------------------------------------------------------------------*
;*                                                                           *
;*                              I O _ P O R T                                *
;*                                                                           *
;*---------------------------------------------------------------------------*

; EXPORTED METHODS

[GLOBAL _outb]
[GLOBAL _outw]
[GLOBAL _inb]
[GLOBAL _inw]

; IMPLEMENTATION 

[SECTION .text]

; OUTB: C-Prototyp: void outb (int port, int value);

_outb:
	push	ebp
	mov	ebp,esp
	mov	edx,[8+ebp]
	mov	eax,[12+ebp]
	out	dx,al
	pop	ebp
	ret

; OUTW: C-Prototyp: void outw (int port, int value);

_outw:
	push	ebp
	mov	ebp,esp
	mov	edx,[8+ebp]
	mov	eax,[12+ebp]
	out	dx,ax
	pop	ebp
	ret

; INB: C-Prototyp: int inb (int port);

_inb:
	push	ebp
	mov	ebp,esp
	mov	edx,[8+ebp]
	xor	eax,eax
	in	al,dx
	pop	ebp
	ret

; INW: C-Prototyp: int inw (int port);

_inw:
	push	ebp
	mov	ebp,esp
	mov	edx,[8+ebp]
	xor	eax,eax
	in	ax,dx
	pop	ebp
	ret
