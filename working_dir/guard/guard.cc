/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                G U A R D                                  *
 *                                                                           *
 *---------------------------------------------------------------------------*/


#include "guard/guard.h"
#include "machine/cpu.h"

extern CPU cpu;

Gate* Guard::remove_epilogue() 
{
	cpu.disable_int();
	Chain* head = epiQ.dequeue();
	Gate* g = static_cast<Gate*>(head);
	cpu.enable_int();
	return g;
}

void Guard::leave() 
{
	Gate* current = remove_epilogue();
	while(current) {
		current->queued(false);
		cpu.enable_int();
		current->epilogue();
		cpu.disable_int();
		current = remove_epilogue();
	}
	retne();
}

	
void Guard::relay(Gate* item)
{
	if(avail()) 
	{
		enter();
		cpu.enable_int();
		item->epilogue();
		leave();
	}
	else 
	{
		if(!item->queued()){
			cpu.disable_int();
			item->queued(true);
			epiQ.enqueue(item);
			cpu.enable_int();
		}
	}
}
