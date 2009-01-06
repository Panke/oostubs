/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                          S C H E D U L E R                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __schedule_include__
#define __schedule_include__

#include "thread/dispatch.h"
 
/**
 * This class implements a simple scheduler (FIFO) for the operating system 
 * extending the Dispatcher.
 */
class Scheduler   {
private:
  /** queue of threads that are ready to be processed */
  /* ToDo: insert sourcecode */ 
public:
  Scheduler () {}

  /**
   * Method 'schedule()' starts the scheduling by starting the first thread 
   * contained in the queue of the scheduler.
   */
  /* ToDo: insert sourcecode */ 
  
  /**
   * Method 'ready()' inserts the specified thread into the queue of threads 
   * that are ready to be processed.
   *
   * @param that reference of the thread to be inserted into the queue of 
   *             threads.
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Method 'exit()' removes the currently active thread from the queue of 
   * thread and resumes with the next thread. If there are no more threads 
   * the scheduler starts an idle loop.
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Method 'kill()' removes the specified thread from the queue of processes.
   *
   * @param that reference of the thread to be killed.
   */
  /* ToDo: insert sourcecode */ 

  /**
   * Method 'resume()' uses the scheduling algorithm to get the next thread and
   * resumes with that thread.
   */
  /* ToDo: insert sourcecode */ 
};

#endif
