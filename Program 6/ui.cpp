#include "cuisine.h"
using namespace std;

//Chase Verbout
//CS163
//Program 1
//ui.cpp
//
//The purpose of this file is to hold the functions that deal with user
//interaction. This includes the introduction, menu fucntionality, and
//quiting. It will be considered the testing grounds for our purposes.
//
//************DISCLAIMER*************
//Since we are not graded on our client program this may be messier than the actual assignment.
//By that I mean the function will be longer than the usual amount of alloted lines.

//This is the menu function that displays the menu interface to the user, prompts
//them, and returns the character they input
char menu()
{
	 //This is a variable to record the user's response
	 char response {'z'};

	 cout << "*************MENU*************" << endl
		  << "* a) Add new Cuisine         *" << endl 
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* b) Add new Foodcart        *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* c) Display Cuisine Names   *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* d) Display Cuisine Content *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* e) Display Open Foodcarts  *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* f) Display All             *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* g) Remove Foodcart         *" << endl
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



//This function manages what function the program should call based on the user's input.
//It also keeps track of whether the program should continue and will return a boolean
//that depends on the user's selection.
bool translate(char option, cuisine_list & clist)
{
	 //This is a boolean to keep track of whether the program should continue.
	 bool again {true};
	 float stars {0};
	 char cname[100];
	 char fcname[100];
	 int open {0};
	 int close {0};
	 char location[100];
	 int weekdays;
	 int weekends;

	 if ('A' == option)
	 {
		  cout << "Please enter the name of the Cuisine: ";
		  cin.get(cname, 100, '\n');
		  cin.ignore(100, '\n');
		  if (clist.add_cuisine(cname) == 0)
			   cout << endl << "This Cuisine already exists!";
	 }
	 else if ('B' == option)
	 {
		  foodcart a_foodcart;
		  cout << "Cuisine to add to: ";
		  cin.get(cname, 100, '\n');
		  cin.ignore(100, '\n');
		  cout << "Foodcart name: ";
		  cin.get(fcname, 100, '\n');
		  cin.ignore(100, '\n');
		  cout << "Please enter open time in military standard (whole number): ";
		  cin >> open;
		  cin.ignore(100, '\n');
		  cout << "Please enter close time in military standard (whole number): ";
		  cin >> close;
		  cin.ignore(100, '\n');
		  cout << "Open weekdays?";
		  if (yes_no())
			   weekdays = 1;
		  else
			   weekdays = 0;
		  cout << "Open weekends?";
		  if (yes_no())
			   weekends = 1;
		  else 
			   weekends = 0;
		  cout << "Please enter location: ";
		  cin.get(location, 100, '\n');
		  cin.ignore(100, '\n');
		  cout << "Please enter a star rating out of 5.0: ";
		  cin >> stars;
		  cin.ignore(100, '\n');

		  a_foodcart.add(fcname, open, close, weekdays, weekends, location, stars);
		  if(clist.add_foodcart(a_foodcart, cname) == 0)
			   cout << endl << "The Cuisine you tried to add to does not exist...Yet!";
	 }
	 else if ('C' == option)
	 {
		  if (clist.display_cuisine_names() == 0)
			   cout << endl << "There are no Cuisines currently in this list. Try adding one!";
	 }
	 else if ('D' == option)
	 {
		  cout << endl << "Please enter the name of the Cuisine: ";
		  cin.get(cname, 100, '\n');
		  cin.ignore(100, '\n');
		  if(clist.display_specific_cuisine(cname) == 0)
			   cout << endl << "This Cuisine was not in the list. Try checking the cuisine names or adding this one!";
	 }
	 else if ('E' == option)	
	 {
		  cout << "This wil only show foodcarts with the exact open time or an" << endl
			   << "earlier open time AND the exact close time or a later close time." << endl
			   << "It also only needs one yes match between weekends and weekdays." << endl
			   << endl << "Please use the nearest whole number inclusively between"
			   << " 0 and 24 for military time." << endl << endl;
		  cout << "Open: ";
		  cin >> open;
		  cin.ignore(100, '\n');
		  cout << "Close: ";
		  cin >> close;
		  cin.ignore(100, '\n');
		  cout << "Weekdays";
		  if (yes_no())
			   weekdays = 1;
		  else 
			   weekdays = 0;
		  cout << "Weekends";
		  if (yes_no())
			   weekends = 1;
		  else
			   weekends = 0;	
		  if(clist.display_open(open, close, weekdays, weekends) == 0)
			   cout << endl << "The list is currently empty. Try adding a Cuisine!";
	 }
	 else if ('F' == option)
	 {
		  if (clist.display_all() == 0)
			   cout << endl << "There are no Cuisines currently in this list. Try adding one!";
	 }
	 else if ('G' == option)
	 {
		  cout << "Foodcart name: ";
		  cin.get(fcname, 100, '\n');
		  cin.ignore(100, '\n');
		  if(clist.remove_foodcart(fcname) == 0)
			   cout << endl << "This foodcart is not in the list or there is no list yet!";
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

