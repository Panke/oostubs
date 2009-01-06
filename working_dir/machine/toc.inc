;*---------------------------------------------------------------------------*
;* Operating Systems I                                                       *
;*---------------------------------------------------------------------------*
;*                                                                           *
;*                                 T O C                                     *
;*                                                                           *
;*---------------------------------------------------------------------------*

; TOC: non-volatile registers of the Intel 80386 cpu
;      IMPORTANT: The order of the registers has to correspond to the definition 
;                 of the structure toc.

; The values of the offsets are equivalent to the distances of the elements to 
; the startadress of the structure toc. 
; ebx_offset = 0, esi_offset = 4, edi_offset = 8, ...

[ABSOLUTE 0]
ebx_offset:	resd 1
esi_offset:	resd 1
edi_offset:	resd 1
ebp_offset:	resd 1
esp_offset:	resd 1
