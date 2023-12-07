#include "item.h"

// Chase Verbout
// CS 163
// Program 3
// table.h

// This file contains the table class. This class requires the use of the item class.
// The table class contains public functions to: add an item, load a file of items,
// display an item by matching name, retrieve and item by matching name, remove an
// item by matching name, and display all items of a certain type. It also contains
// private functions to hash the name of the item before adding.
// The table class contains an array of node* and an int that keeps track of the size
// of the array.
// At the bottom this file contains the protoypes for User interace interaction

class table
{
	 public: 
		  table(int size);
		  ~table(void);
		  int add_item(char* name, item & to_add);
		  int load(char* temp_name, char* temp_desc, char* temp_type, char* temp_play, int rate_toadd);
		  int display_all(void) const;
		  int display(char* name_tofind);
		  int retrieve(char* name_tofind, item *& found_items);
		  int remove(char* name_tofind);
		  int display_type(char* type_tofind) const;

	 private:
		  int hash(char * name);
		  int hash2(char * name);
		  int r_display(node* curr, char* name_tofind);
		  int r_remove(node*& curr, node*& prev, char* name_tofind);
		  int r_display_type(node * curr, int index, char* type_tofind) const;
		  int r_retrieve(node* curr, char* name_tofind, item*& found_items, int arr);

		  node** hashtable;
		  int hashtable_size;
};


// UI Function Prototypes
bool yes_no(void);
bool translate(char response, table& user_table);
void goodbye(void);
char menu(void);
