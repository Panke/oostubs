/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                 P A N I C                                 *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __panic_include__
#define __panic_include__

/* INCLUDES */
#include "guard/gate.h"

/**
 * This class is a subclass of Gate and implements a standard interrupt routine
 * used as default for interrupts.
 */
class Panic : public Gate  {
public:
  
  /**
   * Method trigger() prints an error message and halts the cpu.
   */
	
  void trigger();	

};

#endif
