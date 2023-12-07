#include "stack.h"

// Chase Verbout
// CS 163
// Program 2
// queue.h

// The purpose of this file is to contain an overview of the queue class. It will permit a 
// user to enqueue and item to the back of the list, dequeue an item from the front of the list,
// peek at the front item of the list, and display all of the items in the list. It contains one
// private data items: a node pointer rear.

// This file also contains the prototypes for the interface since by this point our program knows
// what queues and stacks are.

// Class interfaces
class queue
{
	 public:
		  queue(void);
		  ~queue(void);
		  int enqueue(const product&);
		  int dequeue(void);
		  int display(void) const;
		  int peek(product&);
	 private:
		  q_node * rear;
};

//Prototypes
bool translate(char, stack&, queue&);
char menu();
void goodbye();
bool yes_no();
