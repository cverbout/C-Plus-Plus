#include "foodcart.h"
//
//Chase Verbout
//163
//Program 1
//cuisine.h
//
//This file contains the cuisine class and cuidine node that will allow the program to
//work with cuisines as a linear linked list. The CS foodlandia class will contain a head
//cuisine node and provide the user with functions to add a new cuisine, display all cuisine names.
//display foodcarts of a specific cuisine, display open foodcarts, and display all foodcarts, and remove
//foodcarts. The class will also use several private recursive functions to assist public functions.
//The cuisine node will contain the name of the cuisine, a cuisine node pointer to the next 
//cuisine, and a foodcart node pointer head to the first foodcart in the cuisine and tail the last.
//
//It also holds the prototypes for the user interface testing menu.

struct c_node
{
	 char * name = nullptr;
	 fc_node * fc_head = nullptr; 
	 fc_node * fc_tail = nullptr;
	 c_node * next = nullptr;
};

class cuisine_list
{
	 public:
		  cuisine_list();
		  ~cuisine_list();
		  int add_cuisine(char * c_name);
		  int add_foodcart(const foodcart & new_fc, char * c_name);
		  int display_cuisine_names();
		  int display_specific_cuisine(char * c_type);
		  int display_open(int open, int close, int, int);
		  int display_all();
		  int remove_foodcart(char * fc_name);

	 private:
		  int r_remove_foodcart(c_node * & temp_head, char * fc_toRemove);
		  int r_display_open(c_node * temp_head, int want_open, int want_close, int want_weekdays, int want_weekends);
		  int r_display_spec_cuisine(c_node * temp_head, char * c_type);
		  int rec_add_cuisine(c_node * temp_head, c_node * temp, c_node * & prev, char * name_tomatch); 
		  c_node * head;
		  c_node * tail;
};

//Prototypes
bool translate(char, cuisine_list &);
char menu();
void goodbye();
bool yes_no();



