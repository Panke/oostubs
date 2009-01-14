/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                          S C H E D U L E R                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/
#include "thread/scheduler.h"

void Scheduler::ready(Entrant* that)
{
	queue.enqueue(that);
}

void Scheduler::schedule()
{
	Entrant* ent = (Entrant*) queue.dequeue();
	if(ent)
		this->go(ent);
}

void Scheduler::exit()
{
	schedule();
}

void Scheduler::kill(Entrant* that)
{
	queue.remove(that);
}

void Scheduler::resume()
{
	queue.enqueue((Entrant*) active());
	dispatch((Entrant*)queue.dequeue());
}
