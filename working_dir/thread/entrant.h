/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            E N T R A N T                                  *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __entrant_include__
#define __entrant_include__

#include "thread/coroutine.h"
#include "object/chain.h"


/**
 * Class Entrant implements a coroutine administered by a scheduler.
 */
class Entrant : public Coroutine , public Chain  {
public:
  /**
   * Default consturctor for class Entrant.
   *
   * @param tos pointer to the stack used by this coroutine
   */
	Entrant(void* tos) : Coroutine(tos)
	{}
};

#endif
