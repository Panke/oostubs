/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                         C G A _ S T R E A M                               *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __cgastr_include__
#define __cgastr_include__

#include "object/o_stream.h"
#include "machine/cgascr.h"

/**
 * CGA_Stream enables the output of different data as string using the CGA 
 * screen. It is derived from the class CGA_Screen which makes additional 
 * formats and effects available.
 * CGA_Stream extends the functionality of the classes CGA_Screen and O_Stream.
 */
class CGA_Stream : public O_Stream, public CGA_Screen  {
public:
 
  /**
   * The Method flush() prints the curent content of the Stringbuffer. 
   * It is called automaticaly as soon as the buffer is full or manualy 
   * if an output is forced.
   */
	void flush();
	//Konstruktor zum Bildschirm löschen und Zieger auf 0,0 setzen
	CGA_Stream();
};

#endif
