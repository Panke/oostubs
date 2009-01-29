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
	if(!active()){
		Entrant* ent = (Entrant*) queue.dequeue();
		if(ent){
			this->go(ent);
		}
	}
}

void Scheduler::exit()
{
	Entrant* ent = (Entrant*) queue.dequeue();
	if(ent)
		dispatch(ent);
}

void Scheduler::kill(Entrant* that)
{
	queue.remove(that);
}

void Scheduler::resume()
{
	Entrant* ent = (Entrant*) queue.dequeue();
	if(ent){
		queue.enqueue((Entrant*) active());
		dispatch(ent);
	}
}
