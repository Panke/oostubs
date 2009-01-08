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
#include "machine/cpu.h"

/* METHODS  */
extern "C" void guardian (unsigned int slot);
extern CGA_Stream kout;
extern PIC pic;
extern Plugbox plugbox;
extern CPU cpu;

/**
 * Main method for interrupt handleing.
 *
 * @param slot number of occurred interrupt
 *
 * wobei slot schon die Adresse der Plugbox darstellt
 */
void guardian (unsigned int slot) {
	plugbox.report(slot).prologue();
	cpu.enable_int();
}
