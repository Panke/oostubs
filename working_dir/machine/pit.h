/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                  P I T                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __pit_include__
#define __pit_include__
#include "machine/io_port.h"

/** 
 * Class PIT implements the 'Programmable Interval Timer' used to programm the
 * timer interrupt.
 */
class PIT { 
   
public:
  /**
   * Default constructor initialiseing the timer interval.
   */
  PIT (int us); 
  
  
  /**
   * Method 'interval()' returns the timer interval of the PIT.
   *
   * @return the timer interval of the PIT as int value.
   */
  int interval (); 
  
  void interval(int us);
  /**
   * Method 'interval()' implements the programming of the timer interrupt using
   * IO_Ports.
   * 
   * @param us timer interval (int)
   */
  /* ToDo: insert sourcecode */ 

private:
  int a_interval;
  IO_Port controlp;
  IO_Port rwport;
};

#endif
