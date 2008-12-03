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
Application application;
Guard guard;

int main() 
{
	keyboard.plugin();
	application.action();
	return 0;
}
