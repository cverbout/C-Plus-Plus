#include "queue.h"
using namespace std;

// Chase Verbout
// CS163
// Program 2
// ui.cpp
//
// The purpose of this file is to hold the functions that deal with user
// interaction. This includes the introduction, menu fucntionality, and
// quiting. It will be considered the testing grounds for our purposes.
//
// ************DISCLAIMER*************
// Since we are not graded on our client program this may be messier than the actual assignment.
// By that I mean the function will be longer than the usual amount of alloted lines.

// This is the menu function that displays the menu interface to the user, prompts
// them, and returns the character they input
char menu()
{
	 // This is a variable to record the user's response
	 char response {'z'};

	 cout << "*************MENU*************" << endl
		  << "* a) Push product to Stack   *" << endl 
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* b) Display all Stack       *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* c) Pop product from Stack  *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* d) Enqueue Product         *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* e) Display all Queue       *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* f) Peek next Queue Product *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* g) Dequeue Product         *" << endl
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
bool translate(char option, stack& pStack, queue& pQueue)
{
	 // This is a boolean to keep track of whether the program should continue.
	 bool again {true};
	 float price {0.0};
	 char name[100];
	 char desc[100];

	 if ('A' == option)
	 {
		  product a_product;
		  cout << "Please enter the name of the product: ";
		  cin.get(name, 100, '\n');
		  cin.ignore(100, '\n');
		  cout << "Please enter the product description: ";
		  cin.get(desc, 100, '\n');
		  cin.ignore(100, '\n');
		  cout << "Please enter the price of the product: $";
		  cin >> price;
		  cin.ignore(100, '\n');
		  if (a_product.add(name, desc, price) == 0)
			   cout << endl << "name or description input was incorrect";
		  if (pStack.push(a_product) == 0)
			   cout << endl << "Error";
	 }
	 else if ('B' == option)
	 {
		  if(pStack.display() == 0)
			   cout << endl << "The Stack has no products...Yet!";
	 }
	 else if ('C' == option)
	 {
		  if (pStack.pop() == 0)
			   cout << endl << "No Stack yet";
	 }
	 else if ('D' == option)
	 {
		  product a_product;
		  cout << "Please enter the name of the product: ";
		  cin.get(name, 100, '\n');
		  cin.ignore(100, '\n');
		  cout << "Please enter the product description: ";
		  cin.get(desc, 100, '\n');
		  cin.ignore(100, '\n');
		  cout << "Please enter the price of the product: $";
		  cin >> price;
		  cin.ignore(100, '\n');
		  if (a_product.add(name, desc, price) == 0)
			   cout << endl << "name or description input was incorrect";
		  if(pQueue.enqueue(a_product) == 0)
			   cout << endl << "Error!";
	 }
	 else if ('E' == option)	
	 {
		  if (pQueue.display() == 0)
			   cout << endl << "Nothing in Queue";
	 }
	 else if ('F' == option)
	 {
		  product a_product;
		  if (pQueue.peek(a_product) == 0)
			   cout << endl << "No product in Queue";
		  else
		  {
			   a_product.display();
			   cout << endl << "Would you like to add this to your Stack?";
			   if (yes_no())
					pStack.push(a_product);
		  }
	 }
	 else if ('G' == option)
	 {
		  if (pQueue.dequeue() == 0)
			   cout << endl << "Nothing to remove";
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
bool yes_no()
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
void goodbye()
{
	 cout << endl;
	 cout << "Thank you for using our application. Have a great day!";
	 cout << endl;
}

