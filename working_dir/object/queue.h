/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              Q U E U E                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __queue_include__
#define __queue_include__

#include "object/chain.h"

/**
 * Class Queue implements a simple linked list of Chain objects. The following
 * methods are implemented:
 *  - enqueue queues a new list item at the end of the linked list
 *  - dequeue gets the first item of the list and removes it from the list
 *  - remove  removes a given item from the list
 *
 * Unlike other implementations of linked lists tail is not pointing to the last
 * item of the list but to the next pointer of the last item or as long as the
 * list is empty to the head of the list. This saves the verification for 
 * existing items if an item is queued. If however an item is removed this 
 * verification has to be done.
 */
class Queue {
protected:
  Chain* head;
  Chain** tail;
public:
  Queue () { head = 0; tail = &head; }
  void enqueue (Chain* item);
  Chain* dequeue ();
  void remove (Chain*);
};

#endif
