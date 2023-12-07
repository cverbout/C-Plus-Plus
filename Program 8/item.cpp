#include "table.h"
using namespace std;

// Chase Verbout
// CS 163
// Program 3
// item.cpp

// This file contains the functions for the item class. This includes:
// 2 add functions, 2 retrieve functions, and a display function. The 
// private variables are char arrays of a name, a descriptions, a type,
// a platform, and an int rating out of 10
/*
   class item
   char* name;
   char* desc;	
   char* type;
   char* platform;
   int rate;
 */

// Constructor
// Initializes new item object
item::item(void)
{
	 name = desc = type = platform = nullptr;
	 rate = 0;
}



// Destructor
// Delete item object
item::~item(void)
{
	 if (name)
		  delete [] name;
	 if (desc)
		  delete [] desc;
	 if (type)
		  delete [] type;
	 if (platform)
		  delete [] platform;

	 name = desc = type = platform = nullptr;
	 rate = 0;
}



// Adds the information to an item object
// Precondition: name, desc, type, and platform are not null
// Postcondition: The item object contains the data from the input
int item::add(char name_add[], char desc_add[], char type_add[], char platform_add[], int rate_add)
{
	 if (!(name_add && desc_add && type_add && platform_add))
		  return 0;
	 name = new char[strlen(name_add) + 1];
	 strcpy(name, name_add);
	 desc = new char[strlen(desc_add) + 1];
	 strcpy(desc, desc_add);
	 type = new char[strlen(type_add) + 1];
	 strcpy(type, type_add);
	 platform = new char[strlen(platform_add) + 1];
	 strcpy(platform, platform_add);

	 rate = rate_add;
	 return 1;
}



// Adds the information to an item object from an existing item
// Precondition: item_addfrom is an item 
// Postcondition: This item will have the same data as item_addfrom
int item::add(item & item_addfrom)
{
	 if (!item_addfrom.name)
		  return 0;

	 add(item_addfrom.name, item_addfrom.desc, item_addfrom.type, item_addfrom.platform, item_addfrom.rate);
	 return 1;
}



// Retreieves an item if the name matches and passes it to a reference item
// Precondition: name_tofind is not null and found is an item object
// Postcondition: If the name matches the item's name it will copy the data onto the item found
int item::retrieve_item(char* name_tofind, item & found)
{
	 if (!name_tofind)
		  return 0;

	 if (strcmp(name_tofind, name) == 0)
	 {
		  found.add(name, desc, type, platform, rate);
		  return 1;
	 }
	 return 0;
}



// Checks if the item has a matching name and returns 1 if so, 0 if not
// Precondition: name_tofind is a valid char array
// Postcondition: Returns 1 if the current item has that name
int item::match(char* name_tofind)
{
	 if (!name_tofind)
		  return 0;
	 if (strcmp(name, name_tofind) == 0)
		  return 1;

	 return 0;
}



// Displays the contents of an item
// Precondition: The item has valid data stored in it
// Postcondition: The item data is displayed in an orderly manner
int item::display(void) const
{
	 if (!(name && desc && type && platform))
		  return 0;

	 cout << "Item Name: " << name << endl;
	 cout << "Description: " << desc << endl;
	 cout << "Type: " << type << endl;
	 cout << "Platform: " << platform << endl;
	 cout << "Rating: " << rate << "/10" << endl;
	 return 1;
}



// Checks if this item has a matching type
// Precondition: type_tofind is a valid char arr
// Postcondition: If type_tofind matches return 1 if not return 0
int item::type_match(char* type_tofind)
{
	 if (!type_tofind)
		  return 0;
	 if (strcmp(type, type_tofind) == 0)
		  return 1;

	 return 0;
}
