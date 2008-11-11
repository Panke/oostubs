#include "device/cgastr.h"
#include "machine/keyctrl.h"

int main() 
{
	CGA_Stream kout;
	kout << "Start" <<endl;
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
	kout <<endl << "Ende" << endl;




	kout << "Lorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit amet12" << endl;
	kout << bin << 585 << hex << "hex:" << 585 << "oct:" << oct << 64 << dec << "dec:" << &kout << endl;
	/*CGA_Screen sc;
	char c = 'a';
	for(int y=0;y<25;y++)
	{
		for(int x=0; x<80; x++)
			sc.show(x,y,c,15);
		c += 1;
	}
	sc.scrollup();*/
  return 0;
}
