/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              G U A R D I A N                              *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "device/cgastr.h"
#include "machine/pic.h"
#include "guard/gate.h"
#include "machine/plugbox.h"

/* METHODS  */
extern "C" void guardian (unsigned int slot);
extern CGA_Stream kout;
extern PIC pic;
extern Plugbox plugbox;

/**
 * Main method for interrupt handleing.
 *
 * @param slot number of occurred interrupt
 *
 * wobei slot schon die Adresse der Plugbox darstellt
 */
void guardian (unsigned int slot) {
	plugbox.report(slot).trigger();
	pic.ack();
}
