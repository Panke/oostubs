/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                 T O C                                     *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "machine/toc.h"

/**
 * Method 'toc_settle()' is used to initialise the structure toc 
 * (thread of control) and the stack of the thread.
 *
 * @param regs pointer to the structur toc of the thread
 * @param tos pointer to the stack of the thread
 * @param kickoff pointer to method kickoff()
 * @param object pointer to the thread that will be initialiesed
 */
void toc_settle (struct toc* regs, void* tos, void (*kickoff)(void*), void* object) {
  /* ToDo: insert sourcecode */ 
}
