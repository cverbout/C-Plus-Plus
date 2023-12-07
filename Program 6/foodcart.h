#include <iostream>
#include <cctype>
#include <cstring>

//Chase Verbout
//163
//Program 1
//foodcart.h
//
//This file contains the information for the foodcart class and foodcart node struct.
//The foodcart class will contain information about an indvidual foodcart such as
//name, hours, week availability, location, and star rating. This class will allow the user to add a new cart,
//remove a cart, display a foodcart, check if the foodcart is open, and check if a name is the same
//as this foodcart. The foodcart node will enable foodcart objects
//to be used in a linear linked list containing a foodcart object and a next node.
//
//Constants
//Prototypes
//Class interfaces

class foodcart
{
	 public:
		  foodcart();
		  ~foodcart();
		  int add(char * name, int open, int close, int weekdays, int weekends, char * location, float stars);
		  int add(const foodcart & new_fc);
		  int display();
		  bool is_Open(int open, int close, int weekdays, int weekends);
		  bool sameName(char * name);

	 private:
		  char * name;
		  int open;
		  int close;
		  char * location;
		  float stars;
		  int weekdays;
		  int weekends;
};

struct fc_node
{
	 foodcart a_foodcart;
	 fc_node * next;
};



