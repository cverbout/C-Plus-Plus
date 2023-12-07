#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

// Chase Verbout
// CS 163
// Program 3
// item.h

// This file contains an overview of the item class that is utilized by the table
// class. The item class will have two add methods for individual input and whole
// item input. It will also contain a retrieve method to grab an item if the name
// input matches and a display method. The variables in the item class include:
// char arrays for the name,description, type of item, platform that the item is
// used with, and an int for the popularity rating of the item out of 10.

// CONSTANTS
const int TABLESIZE {29};

// CLASS INTERFACE
class item
{
	 public:
		  item(void);
		  ~item(void);
		  int add(char name_add[], char desc_add[], char type_add[], char platform_add[], int rate_add);
		  int add(item & item_addfrom);
		  int retrieve_item(char* name_tofind, item & found);
		  int type_match(char* type_tofind);
		  int match(char* name_tofind);
		  int display(void) const;

	 private:
		  char* name;
		  char* desc;	
		  char* type;
		  char* platform;
		  int rate;
};

struct node
{
	 node* next;
	 item an_item;
};
