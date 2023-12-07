#include "queue.h"
using namespace std;

// Chase Verbout
// CS 163
// Program 2
// queue.cpp

// The purpose of this file is to manage the queue class functions.
// The queue class functions contain methods to enqueue a product,
// dequeue a product, display all of the products, and peek at the
// front queue product.

/****************************
  class queue
  q_node * rear;
 ******************************
 struct q_node
 product prod;
 q_node* next;
 ******************************/	

// Constructor
queue::queue(void)
{
	 rear = nullptr;
}



// Destructor
queue::~queue(void)
{
	 if (rear)
	 {
		  q_node * curr = rear->next;
		  while (curr != rear)
		  {
			   q_node * temp = curr;
			   curr = curr->next;
			   delete temp;
		  }
		  delete rear;
		  rear = nullptr;
	 }
}



// Add an input product to the back of the queue
// Precondition: prod_toadd is a product
// Postcondition: prod_toadd is placed at the rear of the queue
int queue::enqueue(const product& prod_toadd)
{
	 q_node * temp = new q_node;
	 temp->prod.add(prod_toadd); 
	 // There is no queue to add to yet - set rear
	 if (!rear)
	 {
		  rear = temp;
		  rear->next = rear;
		  return 1;
	 }
	 // Else make the new node the new rear
	 temp->next = rear->next;
	 rear->next = temp;
	 rear = temp;
	 return 1;
}



// Remove the front product from the queue
// Precondition: There is a product in the queue
// Postcondition: The product at the front of the queue is removed
int queue::dequeue(void)
{
	 // No products in queue - exit
	 if (!rear)
		  return 0;

	 q_node * temp = rear->next;	
	 // rear and front are the same so there is only 1 node
	 if (temp == rear)
	 {
		  rear = nullptr;
		  delete temp;
		  return 1;
	 }
	 // There is more than 1 node so move pointers accordingly
	 rear->next = temp->next;
	 delete temp;
	 return 1;
}



// Display all of the products in the queue
// Precondition: There is a product in the queue
// Postcondition: The product's in the queue are displayed in the order
// 				  of FIFO
int queue::display(void) const
{
	 // There is no queue - exit
	 if (!rear)
		  return 0;
	 q_node * curr = rear->next;
	 // traverse and display until curr is at the rear node
	 while (curr != rear)
	 {
		  curr->prod.display();
		  curr = curr->next;
	 }
	 // We know this is the last node so display and exit
	 rear->prod.display();
	 cout << "-----------------------------" << endl;
	 return 1;
}



// Look at the front queue item without removing it
// Precondition: There is at least 1 product in the queue and toPeek
// 				 is a product.
// Postcondition: The front product is copied to toPeek, the front becomes
//                the new rear by moving rear forward one node
int queue::peek(product& toPeek)
{
	 // There is no queue - exit
	 if (!rear)
		  return 0;
	 // Copy the info of the front product to peek product
	 toPeek.add(rear->next->prod);	
	 // move rear forward 1
	 // Works even with one node because it moves to itself.
	 // Opted for not requiring uneccessary check of "if 1 node"
	 rear = rear->next;
	 return 1;
}

