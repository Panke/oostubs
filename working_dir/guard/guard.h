/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                G U A R D                                  *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Guard_include__
#define __Guard_include__

#include "object/queue.h"
#include "guard/locker.h"
#include "guard/gate.h"
/**
 * Guard enables the operating system to synchroniste actions of interrupt 
 * handlers for critical sections that are secured using the lock of the 
 * Guard object.
 */
class Guard : public Locker {

  /* ToDo: insert sourcecode */ 
	Queue epiQ;
  /**
   * Method remove_epilogue() gets the next epilogue from the queue. This method
   * has to be called secured to ensure that the structure of the queue stays
   * consistent.
   *
   * @return a pointer to the Gate object implementing the next epilogue.
   */
	Gate* remove_epilogue();
public:
  /**
   * Method leave() leaves the critical section. Waiting epilogues can be
   * processed now.
   */
	void leave();
  /**
   * Method relay() synchronise the procession of an epilogue. If possible the
   * epilogue is processed right away but if the critical section used for the
   * epilogue is locke the epilogue has to be queued for later processing.
   *
   * @param item pointer to the Gate object implementing the epilogue.
   */
	void relay(Gate* item);
};

#endif
