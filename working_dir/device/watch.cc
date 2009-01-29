/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              W A T C H                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "device/watch.h" 
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "guard/guard.h"
#include "syscall/guarded_scheduler.h"
#include "device/cgastr.h"

extern CGA_Stream kout;
extern Guard guard;
extern PIC pic;
extern Plugbox plugbox;
extern Guarded_Scheduler scheduler;

void Watch::windup()
{
	plugbox.assign(Plugbox::timer, *this);
	pic.allow(PIC::timer);
}

void Watch::prologue()
{
	pic.ack();
	guard.relay(this);	
}

void Watch::epilogue()
{
 	scheduler.Scheduler::resume();
}	
