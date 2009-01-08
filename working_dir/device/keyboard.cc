/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            K E Y B O A R D                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "device/keyboard.h"
#include "machine/plugbox.h"
#include "device/cgastr.h"
#include "machine/pic.h"
#include "guard/guard.h"

extern CGA_Stream kout;
extern Plugbox plugbox;
extern PIC pic;
extern Guard guard;

void Keyboard::plugin()
{
	plugbox.assign(Plugbox::keyboard, *this);
	pic.allow(PIC::keyboard);
}

void Keyboard::prologue()
{
	current_key = key_hit();
	if(current_key.valid())
	{
		if(current_key.alt() && current_key.ctrl() 
		   && current_key.scancode() == 0x53)
		{
			reboot();	
		}else{
			pic.ack();	
			guard.relay(this);
		}
	}
}

void Keyboard::epilogue() 
{
	kout.setpos(40,20);
	kout << (char)current_key.ascii() << endl;
}
