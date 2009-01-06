/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                          C O R O U T I N E                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/
 
#ifndef __Coroutine_include__
#define __Coroutine_include__

#include "machine/toc.h"
/**
 * Class Coroutine implements the conception of a context switch useing 
 * coroutines. Every coroutine uses its own stack and every coroutine contains 
 * the structure toc (thread of control) to save the non-volatile registers 
 * before a context switch.
 * The first coroutine is initially activated useing the method go(). Afterwards
 * every context switch is triggered using resume().
 */
class Coroutine {
private:
  /** structure toc saving the non-volatile registers (see file 'toc.h'). */
  /* ToDo: insert sourcecode */ 
public:
  /**
   * Default constructor initialising the stack of the coroutine useing the 
   * external method 'toc_settle()' as well as the structure toc containing the 
   * non-volatile registers of this coroutine.
   * 
   * @param tos pointer to the stack used by this coroutine
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Method 'go()' activates the first coroutine useing the external method 
   * toc_go(). Afterwards every context switch is triggered by resume().
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Method 'resume()' triggers every context switch after the first coroutine 
   * has been activated by go().
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Method 'action()' implements the real function of the coroutine. But since
   * every coroutine does something differenct this method has to be implemented
   * by a subclass of Coroutine (e.g. Application).
   */
  /* ToDo: insert sourcecode */ 
};

#endif
