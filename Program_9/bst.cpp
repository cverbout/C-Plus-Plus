#include "bst.h"
using namespace std;

// Chase Verbout
// Program 4
// CS 163
// bst.cpp

// This file contains the functions for the bst class. This class requires
// the item class. The functions included: add_item adds an item to the bst in order,
// load loads an external txt file of items seperated by ":" with each item on a new
// line, a display function that displays an item given a name if it exists, a 
// display function that displays all items in sorted order, a retrieve
// function that will grab all of the items with the matching name given, a remove 
// that removes an item by a given name should it exist, and a display type fucntion that
// displays all of the items of a given type.
// The class contains private recursive functions in addition to a private root node
/*
   private:
   node * root;
 */

// Constructor
bst::bst(void)
{
	 root = nullptr;
}



// Destructor
bst::~bst(void)
{
	 if (root)
		  remove_all(root);
	 root = nullptr;
}	



// Postorder recursive travel to delete all nodes
void bst::remove_all(node *& root)
{
	 if (!root) // We are at a null - back out of this function call
		  return;
	 remove_all(root->left);
	 remove_all(root->right);
	 delete root;
	 root = nullptr;
	 return;
}



// Adds an item to the bst
// Precondition: an item object as input and the name of that object as a char arr
// Postcondition: The item is added to the bst based on its alphanumeric ordering
int bst::add_item(char* name, item & to_add)
{
	 if(!name) // Invalid name given we cannot add this item
		  return 0;

	 return r_add(root, name, to_add);	
}



// Recursively traverses the bst based on the comparison of names and adds a new node
int bst::r_add(node *& root, char* name, item& to_add)
{
	 if (!root) // We have reached a null child - add the node and get out
	 {
		  node * temp = new node;
		  temp->left = temp->right = nullptr;
		  temp->an_item.add(to_add);
		  root = temp;
		  return 1;
	 }
	 else if (root->an_item.compare_name(name) < 0) // The item is smaller than this one - go left
		  r_add(root->left, name, to_add);
	 else if (root->an_item.compare_name(name) >= 0) // The item is larger than or equal to this one - go right
		  r_add(root->right, name, to_add);	

	 return 1;
}



// Display all in alphanumeric order of item name
int bst::display_all(void)
{
	 return r_display_all(root);
}



// Recursively traverse inorder and display items along the way
int bst::r_display_all(node* root)
{
	 if (!root) // Reach the end - exit
		  return 0;
	 int count = 1 + r_display_all(root->left);
	 root->an_item.display();
	 cout << "------------------------------" << endl;
	 count += r_display_all(root->right);
	 return count; // return the number of items in the tree
}



// Load a file of items into the bst
// Pre-Condition: An empty char array for name, desc, type, platform, and an int for rate
//                The file must be in this format = name:description:type:platform:int
//				  And seperate each item by a newline
// Post-Condition: The file contents are converted into items and added to the bst
int bst::load(char* temp_name, char* temp_desc, char* temp_type, char* temp_plat, int rate_toadd)
{
	 ifstream file_in;
	 file_in.open("small.txt"); // Hardcoded for convenience of testing
	 if (!file_in)
		  return 0;
	 item an_item;
	 if (file_in)
	 {		// Prime the file
		  file_in.get(temp_name, 100, ':');
		  file_in.ignore(100, ':');
		  while(!file_in.eof())  // Collect data until the end of the file
		  {
			   file_in.get(temp_desc,100, ':');
			   file_in.ignore(100, ':');
			   file_in.get(temp_type, 100, ':');
			   file_in.ignore(100, ':');
			   file_in.get(temp_plat, 100, ':');
			   file_in.ignore(100, ':');
			   file_in >> rate_toadd;
			   file_in.ignore(100, '\n');
			   an_item.add(temp_name, temp_desc, temp_type, temp_plat, rate_toadd);
			   add_item(temp_name, an_item);
			   an_item.~item(); // delete current input in item so we can add new data
			   file_in.get(temp_name, 100, ':');
			   file_in.ignore(100, ':');
		  }
		  file_in.close();
	 }
	 return 1;
}



// display a specific item by matching name - if multiple displays all of that name
// Precondition: char array name_tofind is valid and bst is not null
// Postcondition: All items with the name in name_tofind will be displayed and the number of
// 				  matching nodes is returned
int bst::display(char* name_tofind)
{
	 return r_display(root, name_tofind);
}



// Recursively find items to display based on name_tofind
int bst::r_display(node* root, char* name_tofind)
{
	 int count = 0; // Keep track of items displayed
	 if (!root) // Reach the bottom of path - exit
		  return 0;
	 if (root->an_item.match(name_tofind))
	 {
		  count += root->an_item.display();
		  cout << "------------------------------" << endl;
	 }	
	 if (root->an_item.compare_name(name_tofind) < 0)
		  count += r_display(root->left, name_tofind);
	 else if (root->an_item.compare_name(name_tofind) >= 0)
		  count += r_display(root->right, name_tofind);

	 return count; // return the number of displayed items
}



// Retrieve all items of a name
// Precondition: name_tofind is a valid char array and found_items is an empty
//               item array of size 5(arbitrary number for this implementation)
// Postcondition: found_items is an array containing any items that match the name
//				  given by name_tofind
int bst::retrieve(char* name_tofind, item*& found_items)
{
	 int arr = 0; 
	 return r_retrieve(root, name_tofind, found_items, arr);	
}



// Recursively retrieve items of the same name as name_tofind
int bst::r_retrieve(node* root, char* name_tofind, item*& found_items, int arr)
{
	 int count = 0;
	 if (!root || arr >= 5) // If we reach the bottom(null) or the array is full - leave
		  return 0;
	 if (root->an_item.match(name_tofind))
		  count = 1 + found_items[arr++].add(root->an_item);
	 if (root->an_item.compare_name(name_tofind) < 0)
		  count += r_retrieve(root->left, name_tofind, found_items, arr);
	 else if (root->an_item.compare_name(name_tofind) >= 0)
		  count += r_retrieve(root->right, name_tofind, found_items, arr);

	 return count; // return number of items found
}



// Remove a specific item by name
// Precondition: name_tofind is a valid char array and bst is not null
// Postcondition: If an item has the same name as name_tofind the first instance of
// 			      that item found is removed.
int bst::remove(char* name_tofind)
{
	 if (!name_tofind) // invalid name given - fail
		  return 0;

	 return r_remove(root, root, name_tofind);
}



// Recursively removes an item if it has the same name as name_tofind
int bst::r_remove(node*& curr, node*& prev, char* name_tofind)
{
	 int removed = 0;
	 if (!curr) // We do not find the item to remove after traversing the path 
		  return 0;
	 else if (curr->an_item.match(name_tofind)) // We find the matching item
	 {
		  if (!curr->left && !curr->right) // The item's node is a leaf
		  {
			   delete curr;
			   curr = nullptr;
		  }
		  else if (curr->left && !curr->right) // The item's node has only a left child
		  {	
			   node * temp = curr->left;
			   delete curr;
			   curr = temp;

		  }
		  else if (!curr->left && curr->right) // The item's node has only a right child
		  {
			   node * temp = curr->right;
			   delete curr;
			   curr = temp;
		  }
		  else // The item's node has both a left and right child - find IOS
		  {
			   node * temp = curr->right; 
			   curr->an_item.~item(); // delete dynamic memory stored by item to remove
			   if (!temp->left) // The right child does not have a left child so we are done
			   {
					curr->right = temp->right;
					curr->an_item.add(temp->an_item);
					delete temp;
			   }		
			   else // The right child has a left child so traverse to the last left child node
			   {
					node * parent = temp; // previous pointer to the parent node of the IOS after traversal
					while (temp->left) // Traverse until the left child is null
					{
						 parent = temp;
						 temp = temp->left;
					}
					curr->an_item.add(temp->an_item); // Fill out deleted item's node with this IOS item info
					parent->left = temp->right; // Connect parent to whatever was to the right of IOS
					delete temp; // Delete the IOS node
			   }
		  }
		  return 1;
	 }
	 else if (curr->an_item.compare_name(name_tofind) < 0) // Item is smaller go left
		  removed = r_remove(curr->left, curr, name_tofind);
	 else if (curr->an_item.compare_name(name_tofind) > 0) // Item is larger go right
		  removed += r_remove(curr->right, curr, name_tofind);

	 return removed;
}



// Display all items of a specific type
// Precondition: type_tofind is a valid char array and bst is not null
// Postcondition: All items with a matching type type_tofind are displayed
int bst::display_type(char* type_tofind)
{
	 return r_display_type(root, type_tofind);
}



// Recursively find items of a type to display
int bst::r_display_type(node * root, char* type_tofind)
{
	 if (!root) // End of the path this is a null - time to exit
		  return 0;
	 int count = r_display_type(root->left, type_tofind);
	 if (root->an_item.type_match(type_tofind))
	 {
		  count += root->an_item.display();
		  cout << "------------------------------" << endl;
	 }
	 count += r_display_type(root->right, type_tofind);
	 return count;				
}

