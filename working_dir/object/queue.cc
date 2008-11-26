/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              Q U E U E                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "object/queue.h"

void Queue::enqueue (Chain* item) { 
  item->next = 0;         // new item has no following item
  *tail = item;           // insert the element at the end of the list
  tail = &(item->next);   // and set new tail-pointer
}

Chain* Queue::dequeue () {
  Chain* item;

  item = head;            // head points to the first item of the list
  if (item) {             // head ist NULL if list is empty
    head = item->next;    // Das erste Element aus der Liste ausklinken.
    if (!head)            // if list is now empty tail has to point to head
      tail = &head;
    else                  // otherwise delete entry for following item
    	item->next = 0;
  }
  return item;
}

void Queue::remove (Chain* item) {
  Chain* cur;

  if (head) {
    cur = head;            // start search at the head of the linked list
    if (item == cur)       // if first element is what we are looking for
      dequeue ();          // dequeue is enough
    else {
      // go through linked list one item at a time until end of list is reachted
      // or next item is the item we look for
      while (cur->next && item != cur->next) {
        cur = cur->next;
      }

      if (cur->next) {
        cur->next = item->next;   // delete item from list
        item->next = 0;           // delete entry for following item

        if (!cur->next)           // if cur has no following item tail has to be
          tail = &(cur->next);    // updated.
      }
    }
  }
}
