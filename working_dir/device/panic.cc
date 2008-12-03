/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                 P A N I C                                 *
 *                                                                           *
 *---------------------------------------------------------------------------*/
#include "device/panic.h"
#include "device/cgastr.h"
#include "machine/cpu.h"

extern CPU cpu;
extern CGA_Stream kout;

//void Panic::trigger()
//{
//	kout << "Panic triggered!" << endl;
//}

void Panic::prologue()
{
	kout << "prologue() of panic" << endl;
	cpu.halt();
}
