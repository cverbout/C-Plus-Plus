#include <iostream>
#include <cctype>
#include <cstring>

// Chase Verbout
// CS 163
// Program 2
// product.h

// This file contains the product class that will be used in the stack and queue classes.
// It will contain a char array name, char array description, and a float price. For functions
// It will have an add product function that takes in the individual variables, an add fucntion
// that takes in an existing product, and a display function that outputs the name, descritpion
// and price in an orderly fashion.

// This file also contains the stack node struct that contains a product pointer for the creation of
// a dynamic array and a next pointer to the next node as well as the queue node that contains a single
// product and a next node. These will be used by the stack and queue classes.

//Constants
const int MAX {5};


//Class interfaces
class product 
{
	 public:
		  product(void);
		  ~product(void);
		  int add(char*, char*, float);
		  int add(const product&);
		  int display(void) const;
	 private:
		  char * name;
		  char * description;
		  float price;
};

struct s_node
{
	 product* prods;
	 s_node* next;
};

struct q_node
{
	 product prod;
	 q_node* next;
};

