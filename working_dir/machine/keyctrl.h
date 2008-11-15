/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                       K E Y B O A R D _ C O N T R O L L E R               *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Keyboard_Controller_include__
#define __Keyboard_Controller_include__

#include "machine/io_port.h"
#include "machine/key.h"

/**
 * Abstraction of the keyboad controller of a computer.
 */
class Keyboard_Controller {
private:
  unsigned char code;
  unsigned char prefix;
  Key gather;
  char leds;

  /** user defined port for seting status(R) or control(W) register */
  const IO_Port ctrl_port;
  /** user defined port for output(R) or input(W) of a buffer*/
  const IO_Port data_port;

  /** defined bits in the status register */
  enum { outb = 0x01, inpb = 0x02, auxb = 0x20 };

  /** keyboard commands. */
  struct kbd_cmd {
  	enum { set_led = 0xed, set_speed = 0xf3 };
  };
  
  enum { cpu_reset = 0xfe };

  /** name of the keyboard LEDs */
  struct led {
    enum { caps_lock = 4, num_lock = 2, scroll_lock = 1 };
  };

  /** keyboard responses */
  struct kbd_reply {
	  enum { ack = 0xfa };
  }; 

  /** constants used to decode the keyboard codes */
  enum { break_bit = 0x80, prefix1 = 0xe0, prefix2   = 0xe1 };

  static unsigned char normal_tab[];
  static unsigned char shift_tab[];
  static unsigned char alt_tab[];
  static unsigned char asc_num_tab[];
  static unsigned char scan_num_tab[];
         
  /**
   * Interpretes the make and break code of the keyboard an returns an valid
   * ASCII code, scancode and information about modifier keys like SHIFT and 
   * CTRL. 
   *
   * @return TRUE if character is komplete otherwise FALSE.
   */
  bool key_decoded ();

  /** 
   * Determins the ASCII code of a key according to the scancode and 
   * modifier bits.
   */
  void get_ascii_code ();
public:

   /**
    * Default constructor initially turns all LEDs of and sets speed and delay
    * of the keyboard maximal.
    */
   Keyboard_Controller ();

  /**
   * Is used to get the information of the pressed key after is has been 
   * pressed. If a scancode and ASCII code could not be determined an invalid 
   * key is returned.
   *
   * @return an invalid key if data transfer has not ended otherwise a valid 
   *         key with every information is returned. Can be checked withd 
   *         Key::valid().
   */
  Key key_hit ();

  /**
   * Reboots the computer using a keyboard controller command.
   */
  void reboot ();

  /**
   * Sets the speed and delay of repeats of the keyboard. 
   *
   * @param speed defines speed of a repeat (0 fast - 31 slow)
   * @param delay defines delay of a repeat (0 minimal - 7 maximal)
   */
  void set_repeat_rate (int speed, int delay);

  /**
   * Switches the specified LED of the keyboard on or off.
   * 
   * @param led specifies the LED turned on or off
   * @param on if TRUE LED is turned on otherwise off
   */
  void set_led (char led, bool on);
};

#endif
