#include "table.h"
using namespace std;

// Chase Vebout
// Program 3
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
	 //constructs the user's table for them to interact with.
	 table user_table(TABLESIZE);

	 cout << "Please select an option from the menu below." << endl << endl;
	 do
	 {
		  response = menu();
	 } while (translate(response, user_table));	
	 goodbye();

	 return 0;
}
