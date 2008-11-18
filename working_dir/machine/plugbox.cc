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
	return *(map[slot]);
}
