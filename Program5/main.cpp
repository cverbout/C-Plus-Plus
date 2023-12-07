#include "header.h"

//Chase Verbout
//CS162
//
//This is the file that contains the main function for this program. It ensures
//that the program is organzied in a neat and effecient manner.
//
//
int main()
{
	//response variable that keeps track of user's menu selection.
	char response {'z'};

	cout << "Welcome to Syntax Supervisor!" << endl;
	//constructs the user's syntax list for them to interact with.
	syntax_list user_list;

	cout << "Please select an option from the menu below." << endl << endl;
	do
	{
	response = menu();
	} while (translate(response, user_list));	
	goodbye();
	
	return 0;
}
