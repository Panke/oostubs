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
 
/* GLOBAL VARIABLES */
extern CGA_Stream kout;
 
void Application::action () {
  /* ToDo: insert sourcecode */ 
	int i = 0;
	char c = 'a';
	while(true){
		kout.show(40,23,c+i%26, 15);	
		i++;
	};   
}
