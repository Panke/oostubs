/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                             C G A _ S C R E E N                           *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __screen_include__
#define __screen_include__

/**
 * CGA_Screen enables the basic control of the screen of a computer by accessing
 * the screen memory and I/O ports directly.
 */
class CGA_Screen {
 
public:

  /**
   * Method setpos() sets a new position for the screen cursor.
   *
   * @param x column number of new position 
   * @param y row number of new position
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Method getpos() gets the current position of the screen cursor.
   *
   * @param x reference for column number of current position
   * @param y reference for row number of curent position
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Method show() displays a character at a given position using the 
   * specified attributs.
   *
   * @param x column number of display position
   * @param y row number of display position
   * @param character character to be displayed
   * @param attrib display attributs
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Method print() displays a string of characters starting at the current 
   * position of the cursor.
   * 
   * @param string string of characters to be displayed
   * @param n number auf characters in string
   * @param attrib display attributs
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Method scrollup() scrolls the screen one row up. 
   * The new row at the bottom of the screen has to be empty (filled with spaces).
   */
  /* ToDo: insert sourcecode */ 
};

#endif
