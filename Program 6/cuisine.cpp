#include "cuisine.h"
using namespace std;
//
//Chase Verbout
//163
//Program 1
//cuisine.cpp
//
//This file contains the cuisine class functions which includes the constructor,
//destructor, add a new cuisine, add a new foodtcart to a cuisine, display all,
//display cuisine names, display specific cuisine, display open foodtrucks, and
//remove a foodtruck. There are several recursive helper functions in this file as
//well.
/*
   struct fc_node
   {
   foodcart a_foodcart;
   fc_node * next;
   }

   struct c_node
   {
   char * name;
   fc_node * fc_head; 
   fc_node * fc_tail;
   c_node * next;
   };

   class cuisine_list
   {
   c_node * head;
   c_node * tail;
   };
 */

// This constructs a new cuisine list
cuisine_list::cuisine_list()
{
	 head = nullptr;
	 tail = nullptr;
}



//This de-allocates the memory used by the cuisine list
cuisine_list::~cuisine_list()
{
	 c_node * c_temp = nullptr;
	 //Go through each cuisine node and delete
	 while(head)
	 {
		  c_temp = head->next;
		  fc_node * fc_temp = head->fc_head; 
		  //Go through each foodcart node in the current cuisine node and delete
		  while (head->fc_head)
		  {
			   fc_temp = head->fc_head->next;
			   delete head->fc_head;
			   head->fc_head = fc_temp;
		  }
		  delete [] head->name;
		  head->fc_tail = nullptr;
		  delete head;
		  head = c_temp; 
	 }
	 tail = nullptr;
}



//This function will add a new cuisine to the LLL
//Precondition: name_toadd is a character array that is not already in the list
//Postcondition: The cuisine list will have a new cuisine with the given name
int cuisine_list::add_cuisine(char * name_toadd)
{
	 //Create new temp node to add and fill it out
	 c_node * temp = new c_node();
	 temp->fc_head = temp->fc_tail = nullptr;
	 temp->name = new char[strlen(name_toadd) + 1];
	 strcpy(temp->name, name_toadd);
	 // If no head exists make this the head
	 if (!head)
	 {
		  head = tail = temp;
		  head->next = nullptr;
		  return 1;
	 }
	 // Node comes before head and is the new head
	 if (strcmp(name_toadd, head->name) < 0)
	 {
		  temp->next = head;
		  head = temp;
		  return 1;
	 }
	 return rec_add_cuisine(head, temp, head, name_toadd);
}



// This function uses recursive practices to add nodes in the correct order
int cuisine_list::rec_add_cuisine(c_node * temp_head, c_node * addNode, c_node * & prev, char * c_name)
{
	 // This Cuisine already exists - exit
	 if (strcmp(temp_head->name, c_name) == 0)
		  return 0;
	 // This Cuisines name comes after the new one so add in the middle
	 if (strcmp(c_name, temp_head->name) < 0)
	 {
		  temp_head = prev->next;
		  prev->next = addNode;
		  prev->next->next = temp_head;
		  return 1;
	 }
	 // We've reached the end of the Cuisine list without finding a Cuisine name that was larger
	 if (!temp_head->next)
	 {
		  tail->next = addNode;
		  tail = tail->next;
		  return 1;
	 }
	 // We haven't found the spot yet so call the function again
	 return rec_add_cuisine(temp_head->next, addNode, temp_head, c_name);
}



// Add a foodcart to an existing Cuisine in the list. 
// Precondition: new_fc is a foodcart object created by the user through the client
// and c_name is a char array of the name of an already existing cuisine in the list
// Postcondition: A foodcart item is added the the tail of the existing LLL in the given Cuisine
int cuisine_list::add_foodcart(const foodcart & new_fc, char * c_name)
{
	 c_node * current = head;
	 // While the cuisine list is not null
	 while(current)
	 {
		  // If we find the matching cuisine name
		  if (strcmp(c_name, current->name) == 0)
		  {
			   fc_node * temp_fc = new fc_node;
			   temp_fc->a_foodcart.add(new_fc);
			   temp_fc->next = nullptr;
			   // if there are no foodcarts in this cuisine yet add it at the head and tail
			   if(!current->fc_head)
					current->fc_head = current->fc_tail = temp_fc;
			   // else add the foodcart at the tail
			   else 
			   {
					current->fc_tail->next = temp_fc;
					current->fc_tail = current->fc_tail->next;
			   }
			   return 1;
		  }
		  current = current->next;
	 }
	 return 0;
}



// This function will display all of the cuisine names currently in the list
int cuisine_list::display_cuisine_names()
{
	 if (!head)
		  return 0;
	 c_node * current = head;
	 cout << "-------------------------------------------" << endl;
	 while(current)
	 {
		  cout << "Cuisine Name: " << current->name << endl;
		  current = current->next;
		  cout << "-------------------------------------------" << endl;
	 }
	 return 1;
}



// This function will display a specific Cuisine's foodcarts
// Precondition: c_type is a char array containing an existing cuisine in the list
int cuisine_list::display_specific_cuisine(char * c_type)
{
	 if (!head)
		  return 0;
	 return r_display_spec_cuisine(head, c_type);	
}



//This function recursively displays the contents of a cuisine if 
//it finds a matching cuisine with the one the user entered
int cuisine_list::r_display_spec_cuisine(c_node * temp_head, char * name_tomatch)
{
	 if (!temp_head)
		  return 0;
	 else if (strcmp(temp_head->name, name_tomatch) == 0)
	 {
		  fc_node * current_fc = temp_head->fc_head;
		  while (current_fc)
		  {
			   current_fc->a_foodcart.display();
			   current_fc = current_fc->next;	
		  }
		  cout << "-------------------------------------------" << endl;
		  return 1;
	 }
	 return r_display_spec_cuisine(temp_head->next, name_tomatch);
}



// This function will display all of the open foodcarts given
// the user's wanted hours and weekends/weekday availability.
// Precondition: An integer for want_open and want_close that that are between 0 and 24
// as well as intergers for want_weekdays and want_weekends where 1 is yes and 0 no
int cuisine_list::display_open(int want_open, int want_close, int want_weekdays, int want_weekends)
{
	 if (!head)
		  return 0;
	 return r_display_open(head, want_open, want_close, want_weekdays, want_weekends);
}



// This function recursively checks if each foodcart is open and displays it if it is.
int cuisine_list::r_display_open(c_node * temp_head, int want_open, int want_close, int want_weekdays, int want_weekends)
{
	 if (!temp_head)
		  return 1;	
	 fc_node * current_fc = temp_head->fc_head;
	 while (current_fc)
	 {
		  // If the foodcart fits the open criteria
		  if (current_fc->a_foodcart.is_Open(want_open, want_close, want_weekdays, want_weekends))
			   current_fc->a_foodcart.display();
		  current_fc = current_fc->next;
	 }
	 return r_display_open(temp_head->next, want_open, want_close, want_weekdays, want_weekends);

}



// This function displays all of the current Cuisines and their respective foodtrucks
int cuisine_list::display_all()
{
	 if (!head)
		  return 0;
	 c_node * current_c = head;
	 while(current_c)
	 {
		  fc_node * current_fc = current_c->fc_head;
		  if (current_c == head)
			   cout << "-------------------------------------------" << endl;
		  cout << "Cuisine Name: " << current_c->name << endl;
		  while (current_fc)
		  {
			   current_fc->a_foodcart.display();
			   current_fc = current_fc->next;
		  }
		  cout << "-------------------------------------------" << endl;
		  current_c = current_c->next;
	 }
	 return 1;
}



// This function will remove a foodcart from the list after
// being given one by the user.
// Precondition: a char array fc_toRemove that is the name of an existing foodcart
// Postcondition: The foodcart with the given name will be removed
int cuisine_list::remove_foodcart(char * fc_toRemove)
{
	 if (!head)
		  return 0;
	 return r_remove_foodcart(head, fc_toRemove);
}



// This function recurively checks each cuisines foodcarts for the
// matching foodcart and removes it from the list.
int cuisine_list::r_remove_foodcart(c_node * & temp_head, char * fc_toRemove)
{
	 // Reached the end of the Cuisine list - exit
	 if (!temp_head)
		  return 0;
	 // This Cuisine has no FCs - go to next Cuisine
	 if (!temp_head->fc_head)
		  return r_remove_foodcart(temp_head->next, fc_toRemove);
	 // The head fc is the one being removed so set a new head and possibly tail
	 else if (temp_head->fc_head->a_foodcart.sameName(fc_toRemove))
	 {
		  fc_node * temp = temp_head->fc_head->next;
		  delete temp_head->fc_head;
		  temp_head->fc_head = temp;
		  // temp_head->fc_head = temp_head->fc_head->next;
		  if (!temp_head->fc_head)
			   temp_head->fc_tail = nullptr;
		  return 1;
	 }
	 else // It wasn't the head fc so check the rest
	 {
		  fc_node * current_fc = temp_head->fc_head;	
		  fc_node * prev = temp_head->fc_head;
		  while (current_fc->next)
		  {
			   // Found the fc in the middle so set previous pointer to skip it and delete the node
			   if (current_fc->a_foodcart.sameName(fc_toRemove))
			   {
					prev->next = current_fc->next;
					delete current_fc;
					return 1;
			   }
			   prev = current_fc;
			   current_fc = current_fc->next;
		  }
		  // It's the tail node so remove and set the new tail
		  if (current_fc->a_foodcart.sameName(fc_toRemove))
		  {
			   prev->next = current_fc->next;
			   delete current_fc;
			   temp_head->fc_tail = prev;
			   return 1;
		  }
	 }
	 return r_remove_foodcart(temp_head->next, fc_toRemove);
}


