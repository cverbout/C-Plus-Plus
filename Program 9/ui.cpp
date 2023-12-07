#include "bst.h"
using namespace std;

// Chase Verbout
// CS163
// Program 4
// ui.cpp
//
// The file holds the functions that deal with user
// interaction. This includes the introduction, menu fucntionality, and
// quiting.
//
// ************DISCLAIMER*************
// Since we are not graded on our client program this may be messier than the actual assignment.
// By that I mean the function will be longer than the usual amount of alloted lines.

// This is the menu function that displays the menu interface to the user, prompts
// them, and returns the character they input
char menu(void)
{
	 // This is a variable to record the user's response
	 char response {'z'};

	 cout << "*************MENU*************" << endl
		  << "* a) Add an item             *" << endl 
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* b) Load external file      *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* c) Display item            *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* d) Retrieve item           *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* e) Remove item             *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* f) Display by type         *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* g) Display All (Testing)   *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* h) Quit                    *" << endl
		  << "******************************" << endl;


	 cout << endl << "Select a letter: ";

	 cin >> response;
	 cin.ignore(100, '\n');
	 response = toupper(response);
	 cout << endl;
	 return response;
}



// This function manages what function the program should call based on the user's input.
// It also keeps track of whether the program should continue and will return a boolean
// that depends on the user's selection.
bool translate(char option, bst& user_bst)
{
	 // This is a boolean to keep track of whether the program should continue.
	 bool again {true};
	 // Item inputs
	 char name[100];
	 char desc[100];
	 char type[100];
	 char platform[100];
	 int rate{0};
	 char itemName[100];

	 if ('A' == option)
	 {
		  item an_item;
		  cout << "Please enter the Item name: ";
		  cin.get(name, 100, '\n');
		  cin.ignore(100, '\n');
		  cout << "Please enter the Item description: ";
		  cin.get(desc, 100, '\n');
		  cin.ignore(100, '\n');
		  cout << "Please enter the Item type: ";
		  cin.get(type, 100, '\n');
		  cin.ignore(100, '\n');
		  cout << "Please enter the Item platform: ";
		  cin.get(platform, 100, '\n');
		  cin.ignore(100, '\n');
		  cout << "Please enter the Item rating: ";
		  cin >> rate;
		  cin.ignore(100, '\n');
		  if (an_item.add(name, desc, type, platform, rate) == 0)
			   cout << endl << "name, description, type or platform input was incorrect";
		  if (user_bst.add_item(name, an_item) == 0)
			   cout << endl << "Error";
	 }
	 else if ('B' == option)
	 {
		  if (!user_bst.load(name, desc, type, platform, rate))
			   cout << endl << "No file to add from";
		  else
			   cout << "~File Loaded~";
	 }
	 else if ('C' == option)
	 {
		  cout << "Please enter the Item name: ";
		  cin.get(itemName, 100, '\n');
		  cin.ignore(100, '\n');
		  cout << "Items of the name " << itemName << " found: " << endl;
		  cout << "------------------------------" << endl;
		  int amount = user_bst.display(itemName);
		  if (amount == 0)
			   cout << "There are no items by that name!";
		  else 
			   cout << "There were " << amount << " items with that name.";
	 }
	 else if ('D' == option)
	 {
		  item * retrieved = new item[5];
		  cout << "Please enter the Item name: ";
		  cin.get(itemName, 100, '\n');
		  cin.ignore(100, '\n');
		  if (user_bst.retrieve(itemName, retrieved) == 0)
			   cout << endl << "There is no item by that name";
		  else
		  {
			   cout << "Would you like to see the first 5 retrieved items (testing purposes):";
			   if (yes_no())
			   {
					cout << "------------------------------" << endl;
					for (int i = 0; i < 5; ++i)
					{
						 if(retrieved[i].display())
							  cout << "------------------------------" << endl;
					}
			   }
		  }
		  delete [] retrieved;
	 }
	 else if ('E' == option)	
	 {
		  cout << "Please enter the Item name: ";
		  cin.get(itemName, 100, '\n');
		  cin.ignore(100, '\n');
		  if (user_bst.remove(itemName) == 0)
			   cout << "There are no items by that name!";
		  else 
			   cout << "First item found by the name " << itemName << " was removed.";
	 }
	 else if ('F' == option)
	 {
		  cout << "Please enter the Item type: ";
		  cin.get(type, 100, '\n');
		  cin.ignore(100, '\n');
		  cout << "Items of type " << type << " found: " << endl;
		  cout << "------------------------------" << endl;
		  int amt = user_bst.display_type(type);
		  if (amt == 0)
			   cout << "There are no items by that type!";
		  else
			   cout << "There are " << amt << " items of that type!";
	 }
	 else if ('G' == option)
	 {
		  int amt = user_bst.display_all();
		  if(amt == 0)
			   cout << endl << "No bst yet";
		  else
			   cout << "There are " << amt << " total items.";
	 }
	 else if ('H' == option)
	 {
		  again = false;
		  cout << "You have selected quit";
	 }
	 else
		  cout << "Invalid letter - Try Again!";

	 cout << endl << endl;

	 return again;
}



// This is a utility function that will ask a yes or no question and return a t/f response.
bool yes_no(void)
{
	 // Keeps track of yes or no resposne
	 char response {'n'};

	 cout << "(y/n): ";
	 cin >> response;
	 cin.ignore(100, '\n');
	 response = toupper(response);

	 if (response == 'Y')
		  return true;
	 else
		  return false;
}



// This function displays the goodbye message once the user has decided to quit.
void goodbye(void)
{
	 cout << endl;
	 cout << "Thank you for using our application. Have a great day!";
	 cout << endl;
}

