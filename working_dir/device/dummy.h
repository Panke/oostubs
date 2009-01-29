#ifndef __dummy_include__
#define __dummy_include__

/* INCLUDES */
#include "guard/gate.h"

/**
 * This class is a subclass of Gate and implements a standard interrupt routine
 * used as default for interrupts.
 */
class Dummy : public Gate  {
public:
  
  /**
   * Method trigger() prints an error message and halts the cpu.
   */
  	
  void trigger();	
  void prologue();
};

#endif
