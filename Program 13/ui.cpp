#include "BST.h"
using namespace std;

// Chase Verbout
// CS202
// Program 3
// ui.cpp
//
// The file holds the functions that deal with user
// interaction. This includes the introduction, menu functionality, and
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
		  << "* a) Add an STL Concept      *" << endl 
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* b) Add a Modern Concept    *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* c) Add a Python Concept    *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* d) Add a Python Method     *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* e) Display Concept         *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* f) Display All Concepts    *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* g) Remove Concept          *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  <<  "* h) Quit                    *" << endl
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
bool translate(char option, BST &user_BST)
{
	 BAD_OUTPUT bad_output;
	 BAD_INPUT bad_input;
	 ALREADY_EXISTS already_exists;
	 // This is a boolean to keep track of whether the program should continue.
	 bool again {true};
	 char website[TEMP];
	 char input2[TEMP];
	 char input3[TEMP];
	 char input4[TEMP];
	 int rate {0};
	 try 
	 {

		  // Item inputs
		  if ('A' == option)
		  {
			   cout << "Website: ";
			   cin.get(website, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Rate(0-10): ";
			   cin >> rate;
			   cin.ignore(TEMP, '\n');
			   cout << "Keyword: ";
			   cin.get(input2, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Method: ";
			   cin.get(input3, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Description: ";
			   cin.get(input4, TEMP, '\n');
			   cin.ignore(TEMP, '\n');

			   Concept *cptr = new STL;

			   cptr->add(website, input2, input3, input4, rate);
			   user_BST.insert(cptr);
		  }
		  else if ('B' == option)
		  {
			   cout << "Website: ";
			   cin.get(website, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Rate(0-10): ";
			   cin >> rate;
			   cin.ignore(TEMP, '\n');
			   cout << "Description: ";
			   cin.get(input2, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Pros: ";
			   cin.get(input3, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Cons: ";
			   cin.get(input4, TEMP, '\n');
			   cin.ignore(TEMP, '\n');

			   Concept *cptr = new Modern;

			   cptr->add(website, input2, input3, input4, rate);
			   user_BST.insert(cptr);
		  }
		  else if ('C' == option)
		  {	  
			   cout << "Website: ";
			   cin.get(website, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Rate(0-10): ";
			   cin >> rate;
			   cin.ignore(TEMP, '\n');
			   cout << "Library: ";
			   cin.get(input2, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Description: ";
			   cin.get(input3, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Method: ";
			   cin.get(input4, TEMP, '\n');
			   cin.ignore(TEMP, '\n');

			   Concept *cptr = new Python;

			   cptr->add(website, input2, input3, input4, rate);
			   user_BST.insert(cptr);

		  }
		  else if ('D' == option)
		  {
			   cout << "What is the website name: ";
			   cin.get(website, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Which Python library: ";
			   cin.get(input2, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Method: ";
			   cin.get(input3, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   user_BST.addMethod(website, input2, input3);

		  }
		  else if ('E' == option)	
		  {
			   cout << "Enter a website to find: ";
			   cin.get(website, TEMP, '\n');
			   cin.ignore(TEMP, '\n');

		  }
		  else if ('F' == option)
		  {
			   user_BST.display_all();
		  }
		  else if ('G' == option)
		  {
			   cout << "Enter the website name: ";
			   cin.get(website, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "If Modern re-enter website. Otherwise enter Keyword or Library: ";
			   cin.get(input2, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   user_BST.remove(website, input2);
		  }
		  else if ('H' == option)
		  {
			   again = false;
			   cout << "You have selected quit";
		  }
		  else
			   cout << "Invalid letter - Try Again!";

	 }
	 catch (BAD_OUTPUT bad_output)
	 {
		  cout << bad_output.message;
	 }
	 catch (BAD_INPUT bad_input)
	 {
		  cout << bad_input.message;
	 }
	 catch (ALREADY_EXISTS already_exists)
	 {
		  cout << already_exists.message;
	 }
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
	 cout << endl;

	 if (response == 'Y')
		  return true;
	 else
		  return false;
}



// This function displays the goodbye message once the user has decided to quit.
bool goodbye(void)
{
	 cout << endl;
	 cout << "Thank you for using our application. Have a great day!";
	 cout << endl;
	 return true;
}

