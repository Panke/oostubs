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

/* GLOBAL VARIABLES */
extern CGA_Stream kout;

Application::Application(char x, void* tos) : Coroutine(tos), zeichen(x), next(*this)
{}


void Application::action () {
  /* ToDo: insert sourcecode */ 
	int i = 0;
	while(true)
	{
		{
		Secure secure;
		kout.setpos(0,2);
		kout << zeichen;	
		i++;
		i %= 24;
		}
		if(i==24) {
			{ Secure secure; kout << endl; }
			this->resume(this->next);
		}
	};   
}

void Application::set_next(Coroutine& _next)
{
	this->next = _next;
}



