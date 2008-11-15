;*---------------------------------------------------------------------------*
;* Operating Systems I                                                       *
;*---------------------------------------------------------------------------*
;*                                                                           *
;*                                   C P U                                   *
;*                                                                           *
;*---------------------------------------------------------------------------*

; EXPORTED METHODS

[GLOBAL _int_enable]
[GLOBAL _int_disable]
[GLOBAL _cpu_halt]

; IMPLEMENTATION OF THE METHODS

[SECTION .text]

; INT_ENABLE: enable interrupts
;
;       C-Prototyp: void int_enable ();

_int_enable:
	sti
	ret

; INT_DISABLE: disable interrupts
;
;       C-Prototyp: void int_disable ();

_int_disable:
	cli
	ret

; CPU_HALT : halts the cpu
;
; C Prototyp: void cpu_halt (void)

_cpu_halt:
	hlt
  ret
