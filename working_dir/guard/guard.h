/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                G U A R D                                  *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Guard_include__
#define __Guard_include__

/**
 * Guard enables the operating system to synchroniste actions of interrupt 
 * handlers for critical sections that are secured using the lock of the 
 * Guard object.
 */
class Guard : public Locker {
  /** queue of waiting epilogues */
  /* ToDo: insert sourcecode */ 

  /**
   * Method remove_epilogue() gets the next epilogue from the queue. This method
   * has to be called secured to ensure that the structure of the queue stays
   * consistent.
   *
   * @return a pointer to the Gate object implementing the next epilogue.
   */
  /* ToDo: insert sourcecode */ 
public:
  /**
   * Method leave() leaves the critical section. Waiting epilogues can be
   * processed now.
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Method relay() synchronise the procession of an epilogue. If possible the
   * epilogue is processed right away but if the critical section used for the
   * epilogue is locke the epilogue has to be queued for later processing.
   *
   * @param item pointer to the Gate object implementing the epilogue.
   */
  /* ToDo: insert sourcecode */ 
};

#endif
