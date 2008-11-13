/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              I O _ P O R T                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __io_port_include__
#define __io_port_include__

/* EXTERN METHODS */
extern "C" void outb (int port, int value);
extern "C" void outw (int port, int value);
extern "C" int inb (int port);
extern "C" int inw (int port);

/**
 * Every computer uses a separate I/O memory that is only adressable by 
 * the methods <code>'in'</code> and <code>'out'</code>.
 * Each instance of IO_Port is an abstraction of an adress in that memory.
 * Using those abstractions adresses in memory can be accessed like ports. 
 */
class IO_Port {
  /** adress of the port in the I/O adress space */
  int address;
public:
  IO_Port (int a) : address (a) {};

  /**
   * Puts a value to the associated port.
   *
   * @param val byte value that will be put to the port
   */
  void outb (int val) const { 
    ::outb (address, val); 
  };

  /**
   * Puts a value to the associated port.
   *
   * @param val word value that will be put to the port
   */
  void outw (int val) const { 
    ::outw (address, val); 
  };

  /**
   * Gets a value from the associated port.
   *
   * @return the byte value from the associated port.
   */
  int inb () const { 
    return ::inb (address); 
  };

  /**
   * Gets a value from the associated port.
   *
   * @return the word value from the associated port.
   */
  int inw () const { 
    return ::inw (address); 
  };
};

#endif
