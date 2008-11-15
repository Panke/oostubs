/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                   C P U                                   *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __CPU_include__
#define __CPU_include__

// external methods implemented in cpu.asm
extern "C" void int_enable ();
extern "C" void int_disable ();
extern "C" void cpu_halt ();

/**
 * Class CPU implements an abstraction of the processor. It provides methods to
 * enable/disable interrupts globally and to halt the processor.
 */
class CPU {
public:
  /**
   * This method enables interrupts globally using the assembler command STI.
   */
  inline void enable_int () {
    int_enable ();
  }

  /**
   * This method disables interrupts globally using the assembler command CLI.
   */
  inline void disable_int () {
    int_disable ();
  }

  /**
   * This method is used to halt the cpu. It is using the assembler command HLT.
   */
  inline void halt () {
    cpu_halt ();
  }
};

#endif
