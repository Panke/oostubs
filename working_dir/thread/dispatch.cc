/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                          D I S P A T C H E R                              *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "thread/dispatch.h"

Dispatcher::Dispatcher()
{
	c_active = 0;
}

void Dispatcher::go(Coroutine* first)
{
	c_active = first;
	first->go();
}

void Dispatcher::dispatch(Coroutine* next)
{
	Coroutine* runing = c_active;
	c_active = next;
	runing->resume(*next);
}

Coroutine* Dispatcher::active()
{
	return c_active;
}
