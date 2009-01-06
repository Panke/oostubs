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
//extern void toc_settle(toc*, void*, void (*func)(void*), void*);
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
	toc regs;
public:
  /**
   * Default constructor initialising the stack of the coroutine useing the 
   * external method 'toc_settle()' as well as the structure toc containing the 
   * non-volatile registers of this coroutine.
   * 
   * @param tos pointer to the stack used by this coroutine
   */
	Coroutine(void* tos);
	virtual ~Coroutine();
  /**
   * Method 'go()' activates the first coroutine useing the external method 
   * toc_go(). Afterwards every context switch is triggered by resume().
   */
	void go();

  /**
   * Method 'resume()' triggers every context switch after the first coroutine 
   * has been activated by go().
   */
	void resume(Coroutine& next);

  /**
   * Method 'action()' implements the real function of the coroutine. But since
   * every coroutine does something differenct this method has to be implemented
   * by a subclass of Coroutine (e.g. Application).
   */
	virtual void action() = 0;
};

#endif
