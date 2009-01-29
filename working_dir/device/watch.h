/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              W A T C H                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __watch_include__
#define __watch_include__

/* INCLUDES */
#include "guard/gate.h"
#include "machine/pit.h"

/**
 * This class is a subclass of Gate and implements the interrupt routine used 
 * for the clock.
 */
class Watch : public Gate, public PIT {
public:
  /**
   * Default constructor of the interrupt handler of the clock. The constructor
   * initialises the PIT to cause an interrupt every us microsecound if enabled.
   * @param us interval between interrupts caused by the time-interrupt in 
   *           microsecounds
   */
  Watch (int us) : PIT (us) {}

  /**
   * Method windup() is used to enable the clock interrup. After calling 
   * windup() the clock interrupt is triggered in the defined interval. This 
   * time interval is defined useing the mechanisms of the PIT class.
   */
	void windup();
  /**
   * Implements the prologue of the clock interrupt.
   */
	void prologue();

  /**
   * Implements the epilogue of the clock interrupt.
   */
	void epilogue();
};

#endif
