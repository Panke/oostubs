/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                  P I T                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/
#include "machine/pit.h"

PIT::PIT(int us) : controlp(0x43) , rwport(0x40)
{
	interval(us);
}
void PIT::interval(int us)
{
	// 7 6 5 4 3 2 1 0
	// 0 0 1 1 0 1 0 0  = 52 = 0x34
	char cw = 52;
	controlp.outb(0x34);
	a_interval = us;
	//Niederwertige Bits
	rwport.outb(us & 0xff);
	//Höherwertige Bits
	rwport.outb(  (us >>  8) );
}

int PIT::interval()
{
	return a_interval;
}


