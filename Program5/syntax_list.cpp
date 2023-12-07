#include "header.h"

//Chase Verbout
//CS162
//
//This file contains the syntax_list class and all of its pertaining functions. This includes
//a constructor, destructor, add syntax, display syntax, display difficulty, edit syntax, display LLL, and sort LLL function.
//
//Class data members include
/*
   The array that will hold the user's syntax inputs.
   array syntax[]
   An int to keep track of the size of list the user wants.
   int size
   An int to keep track of the count of syntax already in the list.
   int count
   A node pointer to keep track of the LLL
   node * head
 */
//
//
//This is a constructor for the syntax list object. It initializes the array size based on what
//the user inputs and sets the count at 0.
syntax_list::syntax_list()
{
	 cout << "How many syntax items would you like in your list: ";
	 cin >> size;
	 cin.ignore(100, '\n');

	 //Creating a new syntax array of size size as chosen by the user
	 array = new syntax[size];
	 //count varaible initialized to a 0 at start
	 count = 0;
	 //head pointer is set to null since there are no items yet.
	 head = NULL;
}



//This is the syntax list destructor that will de-allocate the used memory when we are 
//done with a syntax list.
syntax_list::~syntax_list()
{
	 // de-allocate array
	 if (array)
		  delete [] array;
	 array = NULL;
	 size = 0;
	 count = 0;
     // de-allocate LLL
	 if (head)
	 {
		  node * current = head;
		  while (head)
		  {
			   current = current->next;
			   delete head;
		   	   head = current;
		  }
	 }
}



//This function will prompt the user to add the components of a syntax structure. It will keep
//track of the number of entries so far and if the list is full it will notift the user. It will
//also keep track of entries in sorted order by name using a linear linked list.
void syntax_list::add_syntax()
{
	 if (count < size)
	 {
		  cout << "Syntax Name: ";
		  cin.get(array[count].name, SMALL, '\n');
		  cin.ignore(100, '\n');

		  cout << "Syntax Example: ";
		  cin.get(array[count].example, MEDIUM, '\n');
		  cin.ignore(100,'\n');

		  cout << "Syntax Description: ";
		  cin.get(array[count].description, LARGE, '\n');
		  cin.ignore(100, '\n');

		  cout << "Syntax Difficulty: ";
		  cin >> array[count].difficulty;
		  cin.ignore(100, '\n');

		  cout << "Syntax Frequency: ";
		  cin >> array[count].frequency;
		  cin.ignore(100, '\n');

		  if (!head)  //If head is null create the first node at head
		  {
			   head = new node();
			   head->data = array[count];
			   head->next = NULL;
		  }
		  else  //Else add the node in sorted order
			   sort_syntax();

		  ++count;
	 }
	 else
		  cout << "This syntax list is full!";
}



//This function will go through each of the syntax entries added so far and display all of their
//contents for the user. If there are no syntax entries it will tell the user.
void syntax_list::display_all()
{
	 if(count > 0)
	 {
		  for (int i {0}; i < count; ++i)
		  {
			   cout << "-----------------------------------------------------" << endl;
			   cout << "Sytax Name: " << array[i].name << endl;
			   cout << "Syntax Example: " << array[i].example << endl;
			   cout << "Syntax Description: " << array[i].description << endl;
			   cout << "Syntax Difficulty: " << array[i].difficulty << endl;
			   cout << "Syntax Frequency: " << array[i].frequency << endl;
		  }
		  cout << "-----------------------------------------------------";
	 }
	 else
		  cout << "This list is empty. Try adding some syntax!";
}



//This function will search for a matching difficulty level and display the entry to the user
void syntax_list::display_difficulty(int user_diff)
{
	 //This boolean will represent whether or not there was a match.
	 bool present {false};

	 for (int i{0}; i < count; ++i)
	 {
		  if (user_diff == array[i].difficulty)
		  {
			   present = true;
			   cout << "-----------------------------------------------------" << endl;
			   cout << "Sytax Name: " << array[i].name << endl;
			   cout << "Syntax Example: " << array[i].example << endl;
			   cout << "Syntax Description: " << array[i].description << endl;
			   cout << "Syntax Difficulty: " << array[i].difficulty << endl;
			   cout << "Syntax Frequency: " << array[i].frequency << endl; 
		  }
	 }
	 cout << "-----------------------------------------------------";
	 if (!present)
		  cout << "There were no syntax items in the list with this difficulty!";
}



//This function will allow the user to edit a syntax entry that is in their list already.
//It will prompt them for each member of the syntax item so that they only change the ones
//that they want to.
void syntax_list::edit_syntax(char user_name[])
{
	 //This boolean will represent whether or not there was a match.
	 bool present {false};

	 for (int i{0}; i < count; ++i)
	 {
		  if (strcmp(user_name, array[i].name) == 0)
		  {
			   present = true;

			   cout << "Edit syntax name";
			   if (yes_no())
			   {
					cout << "Syntax Name: ";
					cin.get(array[i].name, SMALL, '\n');
					cin.ignore(100, '\n');
			   }

			   cout << "Edit example";
			   if (yes_no())
			   {
					cout << "Syntax Example: ";
					cin.get(array[i].example, MEDIUM, '\n');
					cin.ignore(100,'\n');
			   }

			   cout << "Edit description";
			   if (yes_no())
			   {
					cout << "Syntax Description: ";
					cin.get(array[i].description, LARGE, '\n');
					cin.ignore(100, '\n');
			   }

			   cout << "Edit difficulty";
			   if (yes_no())
			   {
					cout << "Syntax Difficulty: ";
					cin >> array[i].difficulty;
					cin.ignore(100, '\n');
			   }

			   cout << "Edit frequency";
			   if (yes_no())
			   {
					cout << "Syntax Frequency: ";
					cin >> array[i].frequency;
					cin.ignore(100, '\n');
			   }
		  }
	 }
	 if (!present)
		  cout << "There were no syntax items with this name!";
}



//This function will display syntax entries that were organized by name in the LLL
void syntax_list::display_LLL()
{
	 node * current = head;
	 while (current)
	 {
		  cout << "-----------------------------------------------------" << endl;
		  cout << "Sytax Name: " << current->data.name << endl;
		  cout << "Syntax Example: " << current->data.example << endl;
		  cout << "Syntax Description: " << current->data.description << endl;
		  cout << "Syntax Difficulty: " << current->data.difficulty << endl;
		  cout << "Syntax Frequency: " << current->data.frequency << endl;	
		  current = current->next;
	 }
	 cout << "-----------------------------------------------------";
}



//This function assists the add syntax function by taking in the entry and making
//sure that it is sorted in the LLL in alphabetic order. Addresses three cases:
//The syntax needs to replace the one at head, the syntax needs to go in between 
//two existing syntax entries, and the syntax needs to be added at the very end.
void syntax_list::sort_syntax()
{
	 node * current = head;
	 node * prev = NULL;

	 if (strcmp(head->data.name, array[count].name) > 0) //If the syntax entry needs to go before the one in head
	 {
		  head = new node();
		  head->data = array[count];
		  head->next = current;
	 }
	 else  //else it will need to go between two or at the very end
	 {
		  //cycle through the LLL while current is not null and the entry being added 
		  //is greater than the one that current is at.
		  while (current && strcmp(current->data.name, array[count].name) <= 0)
		  {
			   prev = current;
			   current = current->next;
		  }
		  if (current) //if current is not null we know we left the loop because the entry was less
			   //than the one at current and we will add it before by using the prev pointer.
		  {
			   prev->next = new node();
			   prev = prev->next;
			   prev->data = array[count];
			   prev->next = current;
		  } else //we know we left because current is null and so we can add the entry to the end
			   //using the prev pointer.
		  {
			   current = new node();
			   current->data = array[count];
			   current->next = NULL;
			   prev->next = current;
		  }
	 }
}

