#include "table.h"
using namespace std;

// Chase Verbout
// Program 3
// CS 163
// table.cpp

// This file contains the functions for the table class. This class requires
// the item class. The functions included: add_item adds an item to the table,
// load loads an external txt file of items seperated by ":" with each item on a new
// line, a display function the displays an item given a name if it exists, a retrieve
// function that will grab all of the items with the matching name given, a remove 
// that removes an item by a given name should it exist, and a display type fucntion that
// displays all of the items of a given type.
// The class contains private recursive functions for display, remove, and display_type
// as well as a private hash function for table distribution.
// The private variables are an array of node* and an int for the size of the hashtable
/*
   private:
   node** hashtable;
   int hashtable_size;
 */

// Constructor
// Precondition: an integer size for the number of chains in the table
// Postcondition: A table with a size length array of node* initialized to nullptr
table::table(int size)
{
	 hashtable_size = size;
	 hashtable = new node*[hashtable_size];
	 for (int i = 0; i < hashtable_size; ++i)
		  hashtable[i] = nullptr;
}



// Destructor
table::~table(void)
{
	 if (hashtable)
	 {
		  for (int i = 0; i < hashtable_size; ++i)
		  {
			   // Get the head for the current hashtable LLL
			   node * temp = hashtable[i];
			   // While our hashtable pointer is not null delete nodes
			   while (temp)
			   {
					node * curr = temp;
					temp = temp->next;
					delete curr;
			   }
		  }
		  // Delete the array that is the hashtable
		  delete [] hashtable;
	 }
	 hashtable = nullptr;
	 hashtable_size = 0;
}	



// Converts a key(name) into an integer for equal distribution in the table
// Precondition: a non null char string
// Postcondition: returns an integer that is within the size of the hashtable array
int table::hash(char * name)
{
	 if (!name)
		  return 0;

	 int hash_val = 0;	
	 for (int i = 0; i < strlen(name); ++i)
		  hash_val += name[i] * 127;

	 return hash_val % hashtable_size;
}



// This is a second version of the hash function
// To use this one change this function name to hash and the function hash
// to hash2. 
int table::hash2(char * name)
{
	 if (!name)
		  return 0;

	 int hash_val = 0;
	 for (int i = 0; i < strlen(name); ++ i)
		  hash_val += (name[i] / 5) * name[i] * 127;

	 return hash_val % hashtable_size;	
}



// Adds an item to the hashtable
// Precondition: an item object as input
// Postcondition: The item is added to the table in a chain based on its hashing
int table::add_item(char* name, item & to_add)
{
	 if (!name)
		  return 0;
	 int index = hash(name);
	 node * temp = new node;
	 // If our item has an add issue don't add it - safety measure
	 if (!temp->an_item.add(to_add))
	 {
		  delete temp;
		  return 0;
	 }
	 // New node points to head
	 temp->next = hashtable[index];
	 // Table pointer points to new node
	 hashtable[index] = temp; 
	 return 1;
}



// Display all - For Testing Purposes
int table::display_all(void) const
{
	 if (!hashtable)
		  return 0;
	 for (int i = 0; i < hashtable_size; ++i)
	 {
		  int counter = 0;
		  cout << "Chain #" << i + 1 << ":" << endl;
		  node * temp = hashtable[i];
		  while(temp)
		  {
			   cout << "------------------------------" << endl;
			   temp->an_item.display();
			   ++counter;
			   temp = temp->next;
		  }
		  cout << "------------------------------" << endl;
		  cout << "Chain #" << i + 1 << " Count: " << counter << endl << endl;
	 }	
	 return 1;
}



// Load a file of items into the table
// Pre-Condition: An empty char array for name, desc, type, platform, and an int for rate
//                The file must be in this format = name:description:type:platform:int
//				  And seperate each item by a newline
// Post-Condition: The file contents are converted into items and added to the hashtable
int table::load(char* temp_name, char* temp_desc, char* temp_type, char* temp_plat, int rate_toadd)
{
	 ifstream file_in;
	 file_in.open("items.txt"); // Hardcoded for convenience of testing
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
// Precondition: char array name_tofind is valid and hashtable is not null
// Postcondition: All items with the name in name_tofind will be displayed
int table::display(char* name_tofind)
{
	 if (!hashtable)
		  return 0;
	 int index = hash(name_tofind);
	 node * head = hashtable[index];
	 return r_display(head, name_tofind);
}



// Recursively find items to display based on name_tofind
int table::r_display(node* curr, char* name_tofind)
{
	 if (!curr)
		  return 1;
	 if (curr->an_item.match(name_tofind))
	 {
		  curr->an_item.display();
		  cout << "------------------------------" << endl;
	 }
	 return r_display(curr->next, name_tofind);
}



// Retrieve all items of a name
// Precondition: name_tofind is a valid char array and found_items is an empty
//               item array of size 5(arbitrary number for this implementation)
// Postcondition: found_items is an array containing any items that match the name
//				  given by name_tofind
int table::retrieve(char* name_tofind, item*& found_items)
{
	 if (!hashtable || !name_tofind)
		  return 0;
	 int index = hash(name_tofind);
	 int arr = 0;
	 node * head = hashtable[index];		
	 return r_retrieve(head, name_tofind, found_items, arr);
}



// Recursively retrieve items of the same name as name_tofind
int table::r_retrieve(node* curr, char* name_tofind, item*& found_items, int arr)
{
	 if (!curr)
	 {
		  // No matches were found since arr index did not change
		  if (arr == 0)
			   return 0;
		  return 1;
	 }
	 // If matching item, add it to the array
	 if (curr->an_item.match(name_tofind))
	 {
		  found_items[arr++].add(curr->an_item);
		  // If our retreival array is full return
		  if (arr >= 5)
			   return 1;
	 }
	 return r_retrieve(curr->next, name_tofind, found_items, arr);
}



// Remove a specific item by name
// Precondition: name_tofind is a valid char array and hashtable is not null
// Postcondition: If an item has the same name as name_tofind the first instance of
// 			      that item found is removed.
int table::remove(char* name_tofind)
{
	 if (!hashtable)
		  return 0;
	 int index = hash(name_tofind);	
	 node * head = hashtable[index];
	 // if the first node is a match remove head and return
	 if (head && head->an_item.match(name_tofind) == 1)
	 {
		  hashtable[index] = head->next;
		  delete head;
		  return 1;
	 }
	 return r_remove(head, head, name_tofind);
}



// Recursively removes an item if it has the same name as name_tofind
int table::r_remove(node*& curr, node*& prev, char* name_tofind)
{
	 if (!curr)
		  return 0;
	 // if match remove node
	 if (curr->an_item.match(name_tofind))
	 {
		  node * temp = curr;
		  prev->next = curr->next;
		  delete temp;
		  return 1;
	 }
	 // move to next node
	 return r_remove(curr->next, curr, name_tofind);
}



// Display all items of a specific type
// Precondition: type_tofind is a valid char array and hashtable is not null
// Postcondition: All items with a matching type type_tofind are displayed
int table::display_type(char* type_tofind) const
{
	 if (!hashtable || !type_tofind)
		  return 0;
	 int index = 0;
	 node * head = hashtable[index];
	 return r_display_type(head, index, type_tofind);
}



// Recursively find items of a type to display
int table::r_display_type(node * curr, int index, char* type_tofind) const
{
	 // If curr is null
	 if (!curr)
	 {
		  // If the next index is larger than our htable size is leave
		  if (index + 1 >= hashtable_size)
			   return 1;
		  // If not, move to the next hashtable array
		  node * head = hashtable[++index];
		  return r_display_type(head, index, type_tofind);
	 }
	 // If match display item
	 if (curr->an_item.type_match(type_tofind) == 1)
	 {
		  curr->an_item.display();
		  cout << "------------------------------" << endl;
	 }	
	 // Move to the next node in the current index
	 return r_display_type(curr->next, index, type_tofind);
}

