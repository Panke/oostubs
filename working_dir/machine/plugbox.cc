/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              P L U G B O X                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "machine/plugbox.h"
#include "device/panic.h"
#include "device/cgastr.h"
#include "guard/secure.h"

// Nochmal überdenken, keine Ahnung wo das Erstellt wird.
extern Panic panic;
extern CGA_Stream kout;

Plugbox::Plugbox()
{
	// Für alle Unterbrechungen das Panic-Objekt eintragen.
	for(int i=0; i<64; i++)
	{
		map[i] = &panic;
	}
}

void Plugbox::assign(unsigned int slot, Gate& gate)
{
	if(0 <= slot && slot <64)
	{
		map[slot] = &gate;
	}
}
Gate& Plugbox::report(unsigned int slot)
{
	//{Secure secure;
	//	kout << slot << endl;
	//}
	return *(map[slot]);
}
