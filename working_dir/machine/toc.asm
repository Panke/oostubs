;*---------------------------------------------------------------------------*
;* Operating Systems I                                                       *
;*---------------------------------------------------------------------------*
;*                                                                           *
;*                                 T O C                                     *
;*                                                                           *
;*---------------------------------------------------------------------------*

%include "machine/toc.inc"

; EXPORTED METHODS

[GLOBAL _toc_switch]
[GLOBAL _toc_go]

; IMPLEMENTATION

[SECTION .text]

; TOC_GO : initial start of the process used for all new processes
;
; C Prototyp: void toc_go (struct toc* regs);

_toc_go:
	mov ecx,[esp+4]
	mov ebx,[ecx]
	mov esi,[ecx+esi_offset]
	mov edi,[ecx+edi_offset]
	mov ebp,[ecx+ebp_offset]
	mov esp,[ecx+esp_offset]
	ret

; TOC_SWITCH : switch of context, the current registers are saved and the 
;              registers of the new 'thread of control' are imported
;
; C Prototyp: void toc_switch (struct toc* regs_now,
;                              struct toc* reg_then);

_toc_switch:
	mov ecx,[esp+4]
	mov [ecx],ebx
	mov [ecx+esi_offset],esi
	mov [ecx+edi_offset],edi
	mov [ecx+ebp_offset],ebp
	mov [ecx+esp_offset],esp
	mov ecx,[esp+8]
	push ecx
	call _toc_go
	ret


