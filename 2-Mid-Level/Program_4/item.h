#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

// Chase Verbout
// CS 163
// Program 4
// item.h

// This file contains an overview of the item class that is utilized by the BST
// class. The item class will have two add functions for individual input and whole
// item input as well as a display function, a type and name match function, and a
// name compare function. The variables in the item class include:
// char arrays for the name,description, type of item, platform that the item is
// used with, and an int for the popularity rating of the item out of 10.
// This file also contains the protoypes for User interace interaction

// UI Function Prototypes
bool yes_no(void);
bool translate(char response, class bst& user_bst);
void goodbye(void);
char menu(void);

// CLASS INTERFACE
class item
{
	 public:
		  item(void);
		  ~item(void);
		  int add(char name_add[], char desc_add[], char type_add[], char platform_add[], int rate_add);
		  int add(item & item_addfrom);
		  int type_match(char* type_tofind);
		  int match(char* name_tofind);
		  int compare_name(char* name_tocomp);
		  int display(void) const;

	 private:
		  char* name;
		  char* desc;	
		  char* type;
		  char* platform;
		  int rate;
};

