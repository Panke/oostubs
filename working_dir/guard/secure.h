/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                               S E C U R E                                 *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Secure_include__
#define __Secure_include__

/**
 * Class Secure is used as a simple interface to set and release the 
 * lockvariable we used for securing critical sections of the operating system. 
 * The constructor locks and the destructor releases the variable, so simply 
 * declaring the object is enough to secure the scope of the object.
 */
class Secure {
public:
  /**
   * Default constructor seting the lock through method guard.enter().
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Default destructor unsetting the lock through method guard.leave().
   */
  /* ToDo: insert sourcecode */ 
};

#endif
