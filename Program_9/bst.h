#include "item.h"

// Chase Verbout
// CS 163
// Program 4
// bst.h

// This file contains the bst class. This class requires the use of the item class.
// The table class contains public functions to: add an item, load a file of items,
// display an item by matching name, retrieve items by matching name, remove an
// item by matching name, and display all items or all items of a certain type.
// The bst class contains private recursive helper functions and a private root node.

// This file also contains the node struct that holds a left child node, a right child
// node and an item

// STRUCT
struct node
{
	 node* left;
	 node* right;
	 item an_item;
};

// CLASS INTERFACE
class bst
{
	 public: 
		  bst(void);
		  ~bst(void);
		  int add_item(char* name, item & to_add);
		  int load(char* temp_name, char* temp_desc, char* temp_type, char* temp_play, int rate_toadd);
		  int display_all(void);
		  int display(char* name_tofind);
		  int retrieve(char* name_tofind, item *& found_items);
		  int remove(char* name_tofind);
		  int display_type(char* type_tofind);

	 private:
		  int r_add(node*& root, char* name, item& to_add);
		  int r_display_all(node* curr);
		  int r_display(node* curr, char* name_tofind);
		  int r_remove(node*& curr, node*& prev, char* name_tofind);
		  int r_display_type(node * curr, char* type_tofind);
		  int r_retrieve(node* curr, char* name_tofind, item*& found_items, int arr);
		  void remove_all(node *& root);

		  node * root;
};

