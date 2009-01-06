/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                          D I S P A T C H E R                              *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __dispatch_include__
#define __dispatch_include__

/**
 * Class Dispatcher administrates the switching of the thread of control. Useing
 * method go() it starts the first coroutine of the system. Afterwards every
 * switch of context is done by the method dispatch(). 
 */
class Dispatcher {
private:
  /** pointer to the currently active coroutine */
  /* ToDo: insert sourcecode */ 
public:
  /** Default constructor of the class Displatcher. */
  /* ToDo: insert sourcecode */ 

  /**
   * The Method 'go()' starts the execution of the first coroutine of the 
   * operating system.
   * 
   * @param first reference of the coroutine that will be executed first.
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Method 'dispatch()' switches the thread of control to the specified 
   * coroutine. This method can be called by a coroutine or a scheduler.
   *
   * @param next reference of the coroutine that will be executed next.
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Method 'active()' returns the currently active coroutine.
   *
   * @return pointer for the currently active coroutine.
   */
  /* ToDo: insert sourcecode */ 
};

#endif
