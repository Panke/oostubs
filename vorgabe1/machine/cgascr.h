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
class CGA_Screen  {
 
public:

  /**
   * Method setpos() sets a new position for the screen cursor.
   *
   * @param x column number of new position 
   * @param y row number of new position
   */
	void setpos(int x, int y);
  /**
   * Method getpos() gets the current position of the screen cursor.
   *
   * @param x reference for column number of current position
   * @param y reference for row number of curent position
   */
	void getpos(int& x, int& y);
  /**
   * Method show() displays a character at a given position using the 
   * specified attributs.
   *
   * @param x column number of display position
   * @param y row number of display position
   * @param character character to be displayed
   * @param attrib display attributs
   */
	void show(int x, int y, char c, unsigned char attrib);
  /**
   * Method print() displays a string of characters starting at the current 
   * position of the cursor.
   * 
   * @param string string of characters to be displayed
   * @param n number auf characters in string
   * @param attrib display attributs
   */
	void print (char* text, int length, unsigned char attrib);
  /**
   * Method scrollup() scrolls the screen one row up. 
   * The new row at the bottom of the screen has to be empty (filled with spaces).
   */
	void scrollup();

protected:
	static const int INDEXREGISTER = 0x3d4;
	static const int DATENREGISTER = 0x3d5;
	static char* const MEMORY;
};

#endif
