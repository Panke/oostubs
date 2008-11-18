/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              P L U G B O X                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Plugbox_include__
#define __Plugbox_include__

#include "guard/gate.h"

/**
 * Class Plugbox is used as an abstraction of the IDT (interrupt descriptor 
 * table). It enables the system to define an appropriate handling routine for
 * every hard and software interrupt.
 */
class Plugbox {
   
  /** map is an fixed array of pointers to gate objects */
private:
	// Interruptvektortabelle in das für alle Unterbrechungen ein Gate-Objekt eingetragen werden kann.
	//
	// Hier fehlt noch wie das Array initialisiert wird und ob das Array so richtig ist vom Type Gate als Pointer.
	// TODO Help 
	Gate* map[64];

public:
	// Konstanten
	static const unsigned int timer = 32;
	static const unsigned int keyboard = 33;

  /**
   * Default constructor of the plugbox initialising the map with default gates.
   */
  Plugbox ();

  /**
   * Method assign() assigns a handling routine for an interrupt using a gate
   * object.
   *
   * @param slot number of interrupt the gate object will be assigned to
   * @param gate reference of the gate object containing the handling routine 
   *             for the interrupt
   */
	void assign(unsigned int slot, Gate& gate);

  /**
   * Method report() returns the gate object assigned to a given interrupt
   * number. 
   *
   * @param slot number of occured interrupt 
   * @return reference of the gate object that contains the handling routine for
   *         the given interrupt. If no gate object has been assigned to that 
   *         interrupt number a panic object will be returned.
   */
	Gate& report(unsigned int slot); 

 
};

#endif
