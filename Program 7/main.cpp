#include "queue.h"
using namespace std;

// Chase Verbout
// Cs 163
// Program 2
// main.cpp

// The purpose of this file is to test out the stack and queue ADTs
// This uses an interface from the ui.cpp file and will continue to prompt
// the user until they choose to stop.


int main()
{

	 //response variable that keeps track of user's menu selection.
	 char response {'z'};

	 cout << "Welcome to ShopStop!" << endl;
	 //constructs the user's stack and queue for them to interact with.
	 stack user_stack;
	 queue user_queue;

	 cout << "Please select an option from the menu below." << endl << endl;
	 do
	 {
		  response = menu();
	 } while (translate(response, user_stack, user_queue));	
	 goodbye();

	 return 0;
}
