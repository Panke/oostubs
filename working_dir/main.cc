#include "device/cgastr.h"
#include "machine/keyctrl.h"
#include "machine/cpu.h"
#include "device/panic.h"
#include "machine/pic.h"

CPU cpu;
CGA_Stream kout;
Panic panic;
PIC pic;

void guardian()
{
	kout << "Guardian" << endl;
}


int main() 
{
	pic.allow(PIC::keyboard);
	kout << "Interrupt ist an" << endl;
	while(true)
	{

	}
	/*kout << "Start" <<endl;
	Keyboard_Controller keycont;	
	kout << "Init" <<endl;
	Key down;
	do
	{
		
		down =keycont.key_hit();
		if(down.valid())
		{
			char outc = (char)down.ascii();
			if(outc == '\n')
				kout << endl;
			else{
				kout << outc;
				kout.flush();
			}
		}
	}while(down.ascii() != 'q');
	kout <<endl;
	kout << "Ende" << endl;
	*/
  return 0;
}
