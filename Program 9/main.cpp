#include "bst.h"
using namespace std;

// Chase Vebout
// Program 4
// CS 163
// main.cpp

// The purpose of this file is to test out the table ADT
// This uses an interface from the ui.cpp file and will continue to prompt
// the user until they choose to stop.


int main()
{

	 //response variable that keeps track of user's menu selection.
	 char response {'z'};

	 cout << "Welcome to Bestbuy!" << endl;
	 //constructs the user's bst table for them to interact with.
	 bst user_bst;

	 cout << "Please select an option from the menu below." << endl << endl;
	 do
	 {
		  response = menu();
	 } while (translate(response, user_bst));	
	 goodbye();

	 return 0;
}

