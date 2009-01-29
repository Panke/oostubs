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
#include "syscall/guarded_scheduler.h"

/* GLOBAL VARIABLES */
extern CGA_Stream kout;
extern Guarded_Scheduler scheduler;

Application::Application(char x,int z, void* tos) : Thread(tos), zeichen(x), zeile(z)
{}


void Application::action () {
  /* ToDo: insert sourcecode */ 
	int i = 0;
	int x,y;
	while(true)
	{
		{
		Secure secure;
		/*kout.getpos(x,y);
		if(y != zeile)
			kout.setpos(0,zeile);*/
		kout.show(60,3,(char)87+zeile,15);
		//kout << zeichen ;	 
		kout.show(i,zeile,zeichen,15);
		i++;
		i %= 25;
		}
	//	if(i==12)
	//		scheduler.resume();		
	};   
}




