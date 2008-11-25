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

extern CGA_Stream kout;
extern Plugbox plugbox;

void Keyboard::plugin()
{
	plugbox.assign(Plugbox::keyboard,*this);
}

void Keyboard::trigger()
{
	Key keyhit = key_hit();
	if(keyhit.alt() && keyhit.ctrl() && keyhit.scancode() == 0x53)
	{
		reboot();	
	}
	if(keyhit.valid())
	{
		kout.show(60,10,keyhit.ascii(),15);
	}
}
