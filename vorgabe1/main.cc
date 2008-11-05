#include "machine/cgascr.h"

int main() 
{
	CGA_Screen screen;
	for(int y=0; y<25; ++y)
	for(int x=0; x<80; ++x)
		screen.show(x,y,' ',15);

	screen.setpos(1,0);
	screen.print("TEST", 4, 15);	
	
	screen.setpos(0,2);
	screen.print("HALLO", 5, 15);

	screen.setpos(4,12);
	screen.print("MITTE", 5, 15);
	//screen.setpos(0,0);
  return 0;
}
