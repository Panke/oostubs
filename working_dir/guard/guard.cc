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
	cpu.enable_int();
	return static_cast<Gate*>(head);
}

void Guard::leave() 
{
	Gate* current = remove_epilogue();
	while(current) {
		current->epilogue();
		current = remove_epilogue();
	}
	retne();
}

	
void Guard::relay(Gate* item)
{
	if(avail()) 
	{
		item->epilogue();
	}
	else 
	{
		cpu.disable_int();
		epiQ.enqueue(item);
		cpu.enable_int();
	}
}
