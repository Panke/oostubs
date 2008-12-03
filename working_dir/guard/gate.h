/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                  G A T E                                  *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Gate_include__
#define __Gate_include__

#include "object/chain.h"

/**
 * Class Gate is the superclass of a set of classes that are able to handle 
 * interrupts. Every subclass of Gate has to implement method trigger() that 
 * implements the appropriated behavior of the handler.
 */

class Gate : public Chain  {
  
public:
  //Gate ()   {};
 virtual ~Gate(){ };
  /**
   * Method trigger() is called just after an interrupt occured. It is executed 
   * asynchronous to other activities of the operation system. To enalbe 
   * different behavior according to the occured interrupt this method has to 
   * be implemented in subclasses of Gate.
   */
  
  /* ToDo: insert sourcecode */ 
	virtual void prologue() = 0;
	virtual void epilogue() {};
	virtual void queued(bool b) {inQ = b;};
	virtual bool queued() {return inQ;};
private:
	bool inQ;
};

#endif
