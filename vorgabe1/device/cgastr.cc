/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                         C G A _ S T R E A M                               *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "device/cgastr.h"

CGA_Stream::CGA_Stream()
{
	for(int y=0; y<25; ++y)
	for(int x=0; x<80; ++x)
		show(x,y,' ',15);

	setpos(0,0);
}


void CGA_Stream::flush()
{
	char* start=buffer;
	char* zeiger=buffer;
	int x,y;
	char out;
	while(start != end)
	{

		out = *start; 
		

		if(out == '\n')
		{
			int dif = ((int) start) - ((int) zeiger);
			print(zeiger,start - zeiger,15);
			getpos(x,y);
			x = 0;
			y++;
			if(y>24)
			{
				y = 24;
				scrollup();
			}
			setpos(x,y);
			zeiger = start;
		}

		start++;	
	}
	if(out != '\n')
		print(zeiger,(end-zeiger),15);
	end = buffer;
}
