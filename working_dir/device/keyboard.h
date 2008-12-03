/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            K E Y B O A R D                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "machine/keyctrl.h"
#include "guard/gate.h"
#include "machine/key.h"
 
/**
 * This class is a subclass of Gate and implements the interrupt routine used 
 * for the keyboard.
 */
class Keyboard : public Gate, Keyboard_Controller {
   
public:
   
  /**
   * Method plugin() enables all keyboard interrupts. After calling plugin()
   * interrupts activated by the keyboard are recognised.
   */
	void plugin ();

  /**
   * Method trigger() is called if a keyboard interrupt occurs.
   */
//	void trigger();
	void prologue();
	void epilogue();

private:
	Key current_key;
        
};

#endif
