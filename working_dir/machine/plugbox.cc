/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              P L U G B O X                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "machine/plugbox.h"
#include "device/panic.h"

// Nochmal überdenken, keine Ahnung wo das Erstellt wird.
extern Panic panic;

Plugbox::Plugbox() : timer(32) , keyboard(33)
{
	// Für alle Unterbrechungen das Panic-Objekt eintragen.
	for(int i=0; i<64; i++)
	{
		map[i] = &panic;
	}
}

void assign(unsigned int slot, Gate& gate)
{
	if(0 <= slot && slot <64)
	{
		map[slot] = gate;
	}
}
Gate& report(unsigned int slot)
{
	return map[slot];
}
