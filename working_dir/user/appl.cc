/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                         A P P L I C A T I O N                             *
 *                                                                           *
 *---------------------------------------------------------------------------*/

/* INCLUDES         */
#include "user/appl.h"
#include "device/cgastr.h"
#include "guard/secure.h"
#include "thread/scheduler.h"

/* GLOBAL VARIABLES */
extern CGA_Stream kout;
extern Scheduler scheduler;

Application::Application(char x,int z, void* tos) : Entrant(tos), zeichen(x), zeile(z)
{}


void Application::action () {
  /* ToDo: insert sourcecode */ 
	int i = 0;
	int x,y;
	while(true)
	{
		{
		Secure secure;
		kout.getpos(x,y);
		if(y != zeile)
			kout.setpos(0,zeile);
		kout << zeichen ;	 
		i++;
		i %= 25;
		kout.flush();
		}
		if(i==24) {
			scheduler.resume();
		}
	};   
}




