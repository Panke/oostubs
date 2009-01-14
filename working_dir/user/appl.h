/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                         A P P L I C A T I O N                             *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __application_include__
#define __application_include__
#include "thread/entrant.h"

/**
 * This class defines the only application used by oo-StuBS. Every application
 * class is derived from Application.
 */        
class Application : public Entrant    {
public:
	Application(char x, int z, void* tos);
  /**
   * This method runs the application defined by this class.
   */
  void action ();
  void set_next(Coroutine* next);
private:
  char zeichen;
  int zeile;
};

#endif
