#include "cuisine.h"
using namespace std;

//Chase Verbout
//163
//Program 1
//main.cpp
//
//This is where code will be tested for the CS Foodlandia program.

int main()
{
	 //response variable that keeps track of user's menu selection.
	 char response {'z'};

	 cout << "Welcome to Cartlandia!" << endl;
	 //constructs the user's syntax list for them to interact with.
	 cuisine_list user_clist;

	 cout << "Please select an option from the menu below." << endl << endl;
	 do
	 {
		  response = menu();
	 } while (translate(response, user_clist));	
	 goodbye();

	 return 0;
}
