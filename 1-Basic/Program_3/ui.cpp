#include "header.h"

//Chase Verbout
//CS162
//
//The purpose of this file is to hold the functions that deal with user
//interaction. This includes the introduction, menu fucntionality, and
//quiting
//

void welcome()
{
	cout << "Welcome to Service Animal Select!" << endl
		 << "Please select an option from the menu below." << endl << endl;
}

char menu()
{
	//This is a variable to record the user's response
	char response {'z'};

	cout << "*************MENU*************" << endl
		 << "* a) Add a new service animal*" << endl
		 << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		 << "* b) Display all aniamls     *" << endl 
		 << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		 << "* c) Load from a file        *" << endl
		 << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		 << "* d) Quit                    *" << endl
		 << "******************************" << endl;

	cout << endl << "Select a letter: ";

	cin >> response;
	cin.ignore(100, '\n');
	response = toupper(response);
	cout << endl;

	return response;
}

bool translate(char option, animal zoo[], int& count)
{
	bool again {true};
	if ('A' == option)
		add_animal(zoo, count);
	else if ('B' == option)
		display_everything(zoo, count);
	else if ('C' == option)
		cout << "Option c has not been implemented yet - Stay tuned!";
	else if ('D' == option)
	{
		again = false;
		cout << "You have selected quit";
	}
	else
		cout << "Invalid letter - Try Again!";

	cout << endl << endl;

	return again;
}

void goodbye()
{
	cout << endl;
	cout << "Thank you for using our application. Have a great day!";
	cout << endl;
}

