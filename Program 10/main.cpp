#include "graph.h"
using namespace std;

// Chase Vebout
// Program 5
// CS 163
// main.cpp

// The purpose of this file is to test out the graph ADT
// This uses an interface from the ui.cpp file and will continue to prompt
// the user until they choose to stop.


int main()
{

	 //response variable that keeps track of user's menu selection.
	 char response {'z'};
	 int size {0};

	 cout << "Welcome to Study Buddy!" << endl;

	 cout << "How many concepts would you like to have total: ";
	 cin >> size;
	 cin.ignore(100, '\n');

	 //constructs the user's bst table for them to interact with.
	 graph user_graph(size);

	 cout << "Please select an option from the menu below." << endl << endl;
	 do
	 {
		  response = menu();
	 } while (translate(response, user_graph));	
	 goodbye();

	 return 0;
}

