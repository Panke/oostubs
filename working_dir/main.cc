#include "device/cgastr.h"
#include "machine/keyctrl.h"
#include "machine/cpu.h"
#include "device/panic.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "device/keyboard.h"
#include "user/appl.h"
#include "guard/guard.h"
#include "thread/scheduler.h"

CPU cpu;
CGA_Stream kout;
Panic panic;
PIC pic;
Plugbox plugbox;
Keyboard keyboard;
Scheduler scheduler;
//Application application;
Guard guard;

int main() 
{
	//cpu.disable_int();
	keyboard.plugin();
	char stack1[400];
	char stack2[400];
	char stack3[400];
	Application app1('X',10, (void*)(stack1+400));
	Application app2('Y',11, (void*)(stack2+400));
	Application app3('Z',12, (void*)(stack3+400));

	scheduler.ready(&app1);	
	scheduler.ready(&app2);
	scheduler.ready(&app3);

	scheduler.schedule();
	return 0;
}
