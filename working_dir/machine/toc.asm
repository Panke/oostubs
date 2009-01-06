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
; ToDo: insert sourcecode 

; TOC_SWITCH : switch of context, the current registers are saved and the 
;              registers of the new 'thread of control' are imported
;
; C Prototyp: void toc_switch (struct toc* regs_now,
;                              struct toc* reg_then);

_toc_switch:
; ToDo: insert sourcecode 
