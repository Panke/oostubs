#include "device/cgastr.h"
#include "machine/keyctrl.h"
#include "machine/cpu.h"
#include "device/panic.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "device/keyboard.h"
#include "user/appl.h"


CPU cpu;
CGA_Stream kout;
Panic panic;
PIC pic;
Plugbox plugbox;
Keyboard keyboard;
Application application;

int main() 
{
	keyboard.plugin();
	pic.forbid(PIC::all);
	//pic.forbid(PIC::timer);
	pic.allow(PIC::keyboard);
	application.action();
  return 0;
}
