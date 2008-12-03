/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                               L O C K E R                                 *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Locker_include__
#define __Locker_include__

/**
 * Class Locker imlements a locking variable used to secure critical sections of
 * the operating system. It is important to notice that the locking variable 
 * used, only shows if a critical section is occupied or free. Waiting for the
 * locking variable and securing the variable has to implemented otherwise.
 */
class Locker {
protected:
	bool lock;
  /* ToDo: insert sourcecode */ 
public:
  /**
   * Default constructor initialising the locking variable (free). 
   */
	Locker() : lock(false) {};
  /**
   * Method enter() is called if a critical section is entered and the locking 
   * variable has to be locked.
   */
	inline void enter() {lock = true;};

  /**
   * Method retne() is called if a critical section is left and the lockin 
   * variable can be released.
   */
	inline void retne() {lock = false;};

  /**
   * Method avail() tests if a critical section is occupied or free.
   *
   * @return the value of the locking variable indicating if the critical 
   *         section is occupied or free.
   */
	inline bool avail() {return !lock;};
};

#endif
