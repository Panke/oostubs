/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            O _ S T R E A M                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __o_stream_include__
#define __o_stream_include__

#include "object/strbuf.h"
#include <cstdlib>

/**
 * O_Stream extends the Stringbuffer and contains the definitions of the 
 * << operator of the most important predefined datatypes. It is used to 
 * implement the known usability of the C++ io_stream library. 
 * At the moment the display of characters, strings and digits is supported.
 * Besides the operator definition contained in O_Stream several auxiliary 
 * manipulators are defined. These manipulators are used to choose the basis 
 * for display of digits and to print the buffer after an endl.
 */
class O_Stream : Stringbuffer  {
public:
	enum Base {DEC=1, OCT, HEX};
  /** Default constructor initialising with dezimal system */
	O_Stream(Base b=DEC);
	O_Stream(Base b, size_t size);
  /** 
   * Operator << overloading the default operator. Is used to convert
   * the given datatype into a string that can be printed on an output device.
   * This operator has to be implemented for every standard data type (char, 
   * unsigned char, short, unsigned short, int, unsigned int, long, 
   * unsigned long, void*, char*).
   *
   * @param value value of datatype (has the type of datatype) 
   * @return reference to the current O_Stream object.
   */
  O_Stream& operator << (char c);

  O_Stream& operator << (unsigned char c);
  O_Stream& operator << (int n);
  O_Stream& operator << (unsigned int n);
  O_Stream& operator << (short n);
  O_Stream& operator << (unsigned short n);
  O_Stream& operator << (long n);
  O_Stream& operator << (unsigned long n);
  O_Stream& operator << (void* pointer);
  
  O_Stream& operator << (const char* const text);
  
  /**
   * Operator << overloading the default operator is used to call defined 
   * manipulators.
   *
   * @param 
   * @return reference to the current O_Stream object.
   */
  O_Stream& operator << (O_Stream& (*f) (O_Stream&));
protected:
  Base base;
};

/*---------------------------------------------------------------------------*
 *                                                                           *
 *                          M A N I P U L A T O R E N                        *
 *                                                                           *
 *---------------------------------------------------------------------------*/
/**
 * The following methods receive and return a referenz to the current O_Stream
 * object. Class O_Stream defines an operator that can be used to call this so
 * called manipulators. It is eveen possible to embedd the output of the method
 * into the input of the stream.
 * Main goal of the manipulators is to influence the display of the following 
 * output (eg. by choosing a basis for the display of digits).
 */ 
/** ENDL: prints buffer after adding a newline at the end of the buffer */
 	O_Stream& endl(O_Stream& os);
/** BIN: choose binary basis for display */
 	O_Stream& bin(O_Stream& os);
/** OCT: choose oktale basis for display */
 	O_Stream& oct(O_Stream& os);
/** DEC: choose dezimal basis for display */
 	O_Stream& dec(O_Stream& os);
/** HEX: choose hexadezimal basis for display */
 	O_Stream& hex(O_Stream& os);
#endif
