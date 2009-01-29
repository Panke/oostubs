#include "device/cgastr.h"
#include "machine/keyctrl.h"
#include "machine/cpu.h"
#include "device/panic.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "device/keyboard.h"
#include "user/appl.h"
#include "guard/guard.h"
#include "syscall/guarded_scheduler.h"
#include "device/watch.h"
#include "device/dummy.h"

CPU cpu;
CGA_Stream kout;
Panic panic;
PIC pic;
Plugbox plugbox;
Keyboard keyboard;
Guarded_Scheduler scheduler;
Guard guard;
Watch watch(25000);
//Dummy dummy;
int main() 
{
	//cpu.disable_int();
	keyboard.plugin();
	//plugbox.assign(39,dummy);
	static long stack1[1024];
	static long stack2[1024];
	static long stack3[1024];
	Application app1('X',10, (void*)(stack1+sizeof(stack1)));
	Application app2('Y',11, (void*)(stack2+sizeof(stack2)));
	Application app3('Z',12, (void*)(stack3+sizeof(stack3)));

	scheduler.ready(&app1);	
	scheduler.ready(&app2);
	scheduler.ready(&app3);
	guard.enter();	
	watch.windup();
	scheduler.schedule();
	return 0;
}
