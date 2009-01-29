/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                             T H R E A D                                   *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __thread_include__
#define __thread_include__
#include "thread/entrant.h"
/**
 * Class Thread implements the userinterface of a thread using an  Entrant.  
 */
class Thread : public Entrant    {
public:
  /**
   * Default consturctor for class Thread.
   *
   * @param tos pointer to the stack used by this thread
   */
  Thread(void* tos) : Entrant(tos){ } 
};

#endif
