#include "product.h"

// Chase Verbout
// CS 163
// Program 2
// stack.h

// This file contains the general overview of the stack class. The stack class will
// allow a user to push(add) a product to the the top of the their cart, display all of the
// products in their cart, and pop(remove) the most recent product from their cart. The class
// contains a private head node that holds dynamic array of products and a count of the items
// and a private recursive function for display.

//Class interfaces
class stack
{
	 public:
		  stack(void);
		  ~stack(void);
		  int push(const product&);
		  int pop(void);
		  int display(void) const;

	 private:
		  int r_display(s_node* head) const;

		  s_node * head;
		  int top;
};
