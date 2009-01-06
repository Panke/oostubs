#include "device/cgastr.h"
#include "machine/keyctrl.h"
#include "machine/cpu.h"
#include "device/panic.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "device/keyboard.h"
#include "user/appl.h"
#include "guard/guard.h"


CPU cpu;
CGA_Stream kout;
Panic panic;
PIC pic;
Plugbox plugbox;
Keyboard keyboard;
//Application application;
Guard guard;

int main() 
{
	cpu.disable_int();
	keyboard.plugin();
	char stack1[400];
	char stack2[400];
	Application app1('X', (void*)stack1);
	Application app2('U', (void*)stack2);

	app1.set_next(app2);
	app2.set_next(app1);

	app1.go();
	kout << "Fertig!" << endl;
	return 0;
}
