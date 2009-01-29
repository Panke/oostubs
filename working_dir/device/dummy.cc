#include "device/dummy.h"
#include "device/cgastr.h"
#include "machine/cpu.h"

extern CPU cpu;
extern CGA_Stream kout;

//void Panic::trigger()
//{
//	kout << "Panic triggered!" << endl;
//}

void Dummy::prologue()
{
}
