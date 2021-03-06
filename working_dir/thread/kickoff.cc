/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            K I C K O F F                                  *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "thread/coroutine.h" 
#include "device/cgastr.h"
#include "guard/guard.h"

extern CGA_Stream kout;
extern Guard guard;
/**
 * Method 'kickoff()' is used to start a coroutine initially. This method is not
 * called directly. It is called throught clever manipulaiton of the stack used
 * by the coroutine. It has to be ensured that this method is never left.
 */
void kickoff(void* object)
{
	guard.leave();
	((Coroutine*)object)->action();
}
