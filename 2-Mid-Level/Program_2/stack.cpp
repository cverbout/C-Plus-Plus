#include "queue.h"
using namespace std;

// Chase Verbout
// CS 163
// Program 2
// stack.cpp

// The purpose of this file is to manage the functions for the stack class.
// This class contains functions for pushing a new product to the stack,
// poping a new function from the stack, and displaying all of the products
// in the stack.

/*****************************
  class stack
  s_node * head;
  int count;
 ******************************
 struct s_node
 product* prods;
 s_node* next;
 ******************************/	

// Constructor
stack::stack(void)
{
	 head = nullptr;
	 top = 0;
}



// Destructor
stack::~stack(void)
{
	 s_node * temp;
	 while (head)
	 {
		  temp = head;
		  head = head->next;
		  delete [] temp->prods;
		  delete temp;
	 }
	 head = nullptr;
	 top = 0;
}



// This function adds a product the the top of the stack
// Precondition: prod_toadd is a properly filled out product
// Postcondition: prod_toadd is added to the top of the stack
//                and top increases by 1. If a node's array reaches
//                the MAX # of products a new node is created with
//                a new array of size MAX where the product will go.
//                The new node will be placed at the head and its next node 
//				  will point to the newly full array's node.
int stack::push(const product& prod_toadd)
{
	 // There are no products in the stack yet - add at head
	 if (!head)
	 {
		  head = new s_node;
		  head->prods = new product[MAX];
		  head->prods[top].add(prod_toadd);
		  ++top;
		  head->next = nullptr;
		  return 1;
	 }
	 // The array in the node has reached the MAX number of products
	 // - Create new node, add node at head, and point to full node.
	 if (top == MAX)
	 {
		  s_node * temp = head;
		  head = new s_node;
		  top = 0; // reset top to 0 
		  head->next = temp;
		  head->prods = new product[MAX];
	 }
	 // Now that node is in the proper place and array is initialized 
	 // add the product and increment top
	 head->prods[top].add(prod_toadd);
	 ++top;
	 return 1;
}




// This function removes the top product from the stack
// Precondtion: There is at least 1 product in the stack
int stack::pop(void)
{
	 // Stack is empty - exit
	 if (!head)
		  return 0;
	 // There is 1 product in the current head's array
	 // - Delete that node and make the next node head
	 if (top == 1)
	 {
		  s_node * temp = head;
		  head = head->next;
		  delete [] temp->prods;
		  delete temp;
		  // Set top equal to MAX 
		  top = MAX;
		  // if the node deleted was the last node top is 0 to prepare for
		  // starting a new stack
		  if (!head)
			   top = 0;	

		  return 1;
	 } 
	 // if there is more than 1 product in the array decrement 1 from
	 // top so that we change that index upon the next add.
	 --top;
	 // release the dynamic arrays in that product(name and desc) so that when we add over
	 // it we can add new dynamic arrays for the product's name and description
	 // of the new appropriate length.
	 head->prods[top].~product();
	 return 1;
}



// This function displays all of the products in the stack
// Precondition: There is at least 1 product in the stack
// Postcondition: All products in the stack are displayed in LIFO order
int stack::display(void) const
{
	 if (!head)
		  return 0;
	 for (int i = 0; i < top; ++i)
		  head->prods[top - 1 - i].display();

	 return r_display(head->next);		
}



// Recursively displays products in the stack
int stack::r_display(s_node* head) const
{
	 if (!head)
	 {
		  cout << "-----------------------------" << endl;
		  return 1;
	 }
	 for (int i = MAX - 1; i >= 0; --i)
		  head->prods[i].display();
	 return r_display(head->next);
}

