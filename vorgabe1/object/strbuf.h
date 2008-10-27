/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                       S T R I N G B U F F E R                             *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __strbuf_include__
#define __strbuf_include__

/**
 * Stringbuffer implements a buffer gathering characters that have to be 
 * outputed on the screen or a differenct output device. If the buffer is full
 * or the user wishes to print the content of the buffer on the output device
 * method flush() is called. To enable Stringbuffer to work with different 
 * output devices method flush() has to be implemented by the subclasses of 
 * Stringbuffer.
 * Since every subclass needs access to the variables and methods of the
 * Stringbuffer every variable and method of Stringbuffer is declared 
 * 'protected'.
 */
class Stringbuffer {
protected:
  /** buffer containing the characters of the Stringbuffer */
  /* ToDo: insert sourcecode */ 
  /** buffer pointer saving the position of the next insertion */
  /* ToDo: insert sourcecode */ 

  /** Default constructor of Stringbuffer setting the buffer empty. */
  /* ToDo: insert sourcecode */ 

  /** Default desctructor of Stringbuffer. Nothing has to be done here. */
  /* ToDo: insert sourcecode */ 

  /** 
   * Method put() inserts a character into the buffer. If the buffer is full 
   * after the insertion the buffer has to be emptied by calling the method 
   * flush().
   *
   * @param c character to be inserted into the buffer
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Method flush() prints the curent content of the buffer. It is called 
   * automaticaly as soon as the buffer is full or manualy if an output is 
   * forced. After printing the buffer content the buffer pointer is reseted.
   * To enalbe the Stringbuffer to work with different output mechanisms the
   * method has to be implemented in a subclass of Stringbuffer.
   */
  /* ToDo: insert sourcecode */ 
};

#endif
