#include "queue.h"
using namespace std;

// Chase Verbout
// CS 163
// Program 2
// product.cpp
//
// This file contains the functions that the product class can use. That includes
// two add functions (variables vs product struct)and a display function.
// This class is neccessary to the stack and queue classes and nodes.

/*************************************
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
 **************************************/

// Constructor
product::product(void)
{
	 name = description = nullptr;
	 price = 0.0;
}



// Destructor
product::~product(void)
{
	 if (name)
		  delete [] name;
	 if (description)
		  delete [] description;

	 name = description = nullptr;
	 price = 0.0;
}



// This function adds data to a product
// Precondition: name_toadd and description_toadd are char strings and price_toadd is a float
// Postcondition: The variables are appropiately applied to the product's data
int product::add(char * name_toadd, char * description_toadd, float price_toadd)
{
	 if (!name_toadd || !description_toadd)
		  return 0;
	 name = new char[strlen(name_toadd) + 1];
	 strcpy(name, name_toadd);
	 description = new char[strlen(description_toadd) + 1];
	 strcpy(description, description_toadd);
	 price = price_toadd;
	 return 1;
}



// This function adds data to a product by passing in a whole product
// Precondition: prod_toadd is a properly filled out product
// Postcondition: This product has the same data that prod_toadd has
int product::add(const product& prod_toadd)
{
	 return add(prod_toadd.name, prod_toadd.description, prod_toadd.price);
}



// This function displays the product's data
// Precondition: name and description are not null
// Postcondition: Displays the product data in an organized fashion
int product::display(void) const
{
	 if (!name || !description)
		  return 0;

	 cout << "-----------------------------" << endl;
	 cout << "Name: " << name << endl;
	 cout << "Description: " << description << endl;
	 cout << "Price: $" << price << endl;
	 return 1;
}

