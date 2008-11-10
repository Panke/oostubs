//#include "device/cgastr.h"
#include "machine/cgascr.h"

int main() 
{
	//CGA_Stream kout;
	//kout << 'S'<<'T'<<'A'<<'R'<<'T'<<endl;
	//kout << "Lorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit ametLorem IpsumLorem ipsum dolor sit amet12" << endl;

	CGA_Screen sc;
	char c = 'a';
	for(int y=0;y<25;y++)
	{
		for(int x=0; x<80; x++)
			sc.show(x,y,c,15);
		c += 1;
	}
	sc.scrollup();
  return 0;
}
