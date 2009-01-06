/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                          C O R O U T I N E                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "thread/coroutine.h"

// External methods implemented using assembler (see file 'toc.asm'). Those 
// methods have to be declarated extern "C" to be conform with the c++ standard
extern "C" {
	 void toc_go (struct toc* regs);
	 void toc_switch (struct toc* regs_now, struct toc* reg_then);	 
	 void toc_settle(struct toc*, void* , void (*func)(void*) , void* );
}

extern void kickoff(void*);

Coroutine::Coroutine(void* tos)
{
	toc_settle(&(this->regs), tos, kickoff, this);
}
Coroutine::~Coroutine(){}
void Coroutine::go()
{
	toc_go( &(this->regs) );
}

void Coroutine::resume(Coroutine& next)
{
	toc_switch( &(this->regs) , &(next.regs) );
}

