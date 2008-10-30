/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                             C G A _ S C R E E N                           *
 *                                                                           *
 *---------------------------------------------------------------------------*/
 
#include "machine/cgascr.h"
#include "machine/io_port.h"
char * const CGA_Screen::MEMORY = (char*)0xb8000;
void CGA_Screen::show(int x, int y, char c, unsigned char attrib)
{
	char* const start_ram = MEMORY;
	int offset = (y*80+x)*2;
	start_ram[offset] = c; // start_ram[offset] = c
	start_ram[offset + 1] = attrib;
}

void CGA_Screen::setpos(int x, int y)
{
	IO_Port index(INDEXREGISTER);
	IO_Port data(DATENREGISTER);

	int offset = (80*y+x)*2;
	index.outb(14); //Register 14: Offset des Cursors
	data.outb(offset);
}

void CGA_Screen::getpos(int& x, int& y)
{
	IO_Port index(INDEXREGISTER);
	IO_Port data(DATENREGISTER);
	
	index.outb(14);
	int offset = data.inb();
	x = (offset/2) % 80;
	y = (offset/2) / 80;
}

void CGA_Screen::print(char* text, int length, unsigned char attrib)
{
	int x, y;
	getpos(x, y);
	for(int i = 0; i < length; ++i)
	{
		if(x > 79) {
			x = x % 80;
			if(y == 24)
				scrollup();
			else
				++y;
		}
		show(x, y, text[i], attrib);
		++x;
	}
}

void CGA_Screen::scrollup()
{
	char* const start_ram = MEMORY;
	for(int i = 0; i < 80*24; i++) {	// nochmal drüber nachdenken TODO
		start_ram[i] = start_ram[i+80];
	}
	int offset = 80*24;
	for(int i = 0; i < 80; i++) {
		start_ram[offset+i] = ' ';
	}
}
	

