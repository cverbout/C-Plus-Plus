#include "graph.h"
using namespace std;

// Chase Verbout
// CS163
// Program 5
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
		  << "* a) Build Graph             *" << endl 
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* b) Insert Conncection      *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* c) Display Concepts        *" << endl
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



// This function manages what function the program should call based on the user's input.
// It also keeps track of whether the program should continue and will return a boolean
// that depends on the user's selection.
bool translate(char option, graph& user_graph)
{
	 // This is a boolean to keep track of whether the program should continue.
	 bool again {true};
	 // Item inputs
	 char name[100];
	 char name2[100];

	 if ('A' == option)
	 {
		  int left = 99;
		  do
		  {
			   cout << "Please enter a Concept name: ";
			   cin.get(name, 100, '\n');
			   cin.ignore(100, '\n');

			   left = user_graph.build(name);
			   cout << "Space left: " << left << endl;
			   if (left != 0)
					cout << "Continue? ";
		  } while (left > 0 && yes_no());	
		  if (left == 0)
			   cout << "No more space - list is full!";
	 }
	 else if ('B' == option)
	 {
		  cout << "Please enter a Concept name: ";
		  cin.get(name, 100, '\n');
		  cin.ignore(100, '\n');

		  cout << "Please enter a Concept to connect it to: ";
		  cin.get(name2, 100, '\n');
		  cin.ignore(100, '\n');

		  if(!user_graph.insert(name, name2))
			   cout << endl << "Concept does not exist, first concept already points to the second, or same concept entered.";
	 }
	 else if ('C' == option)
	 {
		  if(!user_graph.display())
			   cout << "Please build the list first!";
	 }
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

