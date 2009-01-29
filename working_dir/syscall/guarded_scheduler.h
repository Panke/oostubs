/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                   G U A R D E D _ S C H E D U L E R                       *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __guarded_scheduler_include__
#define __guarded_scheduler_include__
#include "thread/scheduler.h"
#include "syscall/thread.h"

/**
 * The Guarded_Scheduler implements the system interface of the Scheduler. 
 * The defined methods are guarded but otherwise directly maped to the methods 
 * of the superclass Scheduler. Another difference is that Threads are handled 
 * instead of Entrans.
 */
class Guarded_Scheduler  : public Scheduler {
public:
  /**
   * Method 'ready()' inserts the specified thread into the queue of threads 
   * that are ready to be processed.
   *
   * @param that reference of the thread to be inserted into the queue of 
   *             threads.
   */
	void ready(Thread* that);

  /**
   * Method 'exit()' removes the currently active thread from the queue of 
   * thread and resumes with the next thread. If there are no more threads 
   * the scheduler starts an idle loop.
   */
	void exit();

  /**
   * Method 'kill()' removes the specified thread from the queue of processes.
   *
   * @param that reference of the thread to be killed.
   */
	void kill(Thread* that);

  /**
   * Method 'resume()' uses the scheduling algorithm to get the next thread and
   * resumes with that thread.
   */
	void resume();
};

#endif
