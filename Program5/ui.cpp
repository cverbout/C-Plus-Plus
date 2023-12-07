#include "header.h"

//Chase Verbout
//CS162
//
//The purpose of this file is to hold the functions that deal with user
//interaction. This includes the introduction, menu fucntionality, and
//quiting
//

//This is the menu function that displays the menu interface to the user, prompts
//them, and returns the character they input
char menu()
{
	//This is a variable to record the user's response
	char response {'z'};

	cout << "*************MENU*************" << endl
		 << "* a) Add new syntax          *" << endl 
		 << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		 << "* b) Display all syntax      *" << endl
		 << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		 << "* c) Display in order(LLL)   *" << endl
		 << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		 << "* d) Search for difficulty   *" << endl
		 << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
         	 << "* e) Edit syntax array       *" << endl
		 << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		 << "* f) Quit                    *" << endl
		 << "******************************" << endl;

	cout << endl << "Select a letter: ";

	cin >> response;
	cin.ignore(100, '\n');
	response = toupper(response);
	cout << endl;

	return response;
}



//This function manages what function the program should call based on the user's input.
//It also keeps track of whether the program should continue and will return a boolean
//that depends on the user's selection.
bool translate(char option, syntax_list& slist)
{
	//This is a boolean to keep track of whether the program should continue.
	bool again {true};
	//This is the user's difficulty entry for fidning a match to display.
	int difficulty {0};
	//This is the user's syntax name that they would like to edit.
	char name[SMALL];

	if ('A' == option)
		slist.add_syntax();
	else if ('B' == option)
		slist.display_all();
	else if ('C' == option)
		slist.display_LLL();
	else if ('D' == option)
	{
		cout << "What difficulty would you like to find: ";
		cin	>> difficulty;
		cin.ignore(100, '\n');
		slist.display_difficulty(difficulty);
	}
	else if ('E' == option)
	{
		cout << "Name of syntax entry you would like to edit: ";
		cin.get(name, SMALL, '\n');
		cin.ignore(100, '\n');
		slist.edit_syntax(name);
	}
	else if ('F' == option)
	{
		again = false;
		cout << "You have selected quit";
	}
	else
		cout << "Invalid letter - Try Again!";

	cout << endl << endl;

	return again;
}



//This is a utility function that will ask a yes or no question and return a t/f response.
bool yes_no()
{
	//Keeps track of yes or no resposne
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



//This function displays the goodbye message once the user has decided to quit.
void goodbye()
{
	cout << endl;
	cout << "Thank you for using our application. Have a great day!";
	cout << endl;
}

