#include "list.h"
using namespace std;

// Chase Verbout
// CS202
// Program 2
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
		  << "* a) Add Zoo Reservation     *" << endl 
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* b) Display All Zoo Res     *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* c) Add LTag Reservation    *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* d) Find LTag Reservation   *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* e) Remove LTag Reservation *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* f) Display All LTag        *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* g) Add Dinner Reservation  *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* h) + People to Dinner Res  *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* i) - People to Dinner Res  *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* j) Change Dinner Order     *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* k) Display All Dinner      *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* l) Quit                    *" << endl
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
bool translate(char option, DLL<Zoo> &user_DLL, LTL &user_LTL, DinDeque &user_DD)
{
	 BAD_OUTPUT bad_output;
	 BAD_INPUT bad_input;
	 ALREADY_EXISTS already_exists;
	 // This is a boolean to keep track of whether the program should continue.
	 bool again {true};
	 char user_name[TEMP];
	 char misc[TEMP];
	 int hour = 0;
	 int minute = 0;
	 int size = 0;
	 bool member = false;
	 try 
	 {

		  // Item inputs
		  if ('A' == option)
		  {
			   Zoo temp_zoo;

			   cout << "Username: ";
			   cin.get(user_name, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Hour(0-24): ";
			   cin >> hour;
			   cin.ignore(TEMP, '\n');
			   cout << "Minutes(0-60): ";
			   cin >> minute;
			   cin.ignore(TEMP, '\n');
			   cout << "Exhibits Visiting: ";
			   cin.get(misc, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Are you a member";
			   member = yes_no();

			   temp_zoo.add_zoo(user_name, hour, minute, misc, member);
			   user_DLL.insert(temp_zoo);
		  }
		  else if ('B' == option)
		  {
			   user_DLL.display();					
		  }
		  else if ('C' == option)
		  {	  
			   LazerTag temp_lt;
			   cout << "Username: ";
			   cin.get(user_name, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Hour(0-24): ";
			   cin >> hour;
			   cin.ignore(TEMP, '\n');
			   cout << "Minutes(0-60): ";
			   cin >> minute;
			   cin.ignore(TEMP, '\n');
			   cout << "Enter a team name: ";
			   cin.get(misc, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Enter a team size: ";
			   cin >> size;	
			   cin.ignore(TEMP, '\n');

			   temp_lt.add_lazertag(user_name, hour, minute, misc, size);
			   user_LTL.insert(temp_lt);

		  }
		  else if ('D' == option)
		  {
			   cout << "Enter a team name to find: ";
			   cin.get(misc, TEMP, '\n');
			   cin.ignore(TEMP, '\n');

			   if(!user_LTL.find_team(misc))
					cout << endl << "Could not find match" << endl;
		  }
		  else if ('E' == option)	
		  {
			   cout << "Enter a team name to remove: ";
			   cin.get(misc, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   if (user_LTL.remove_team(misc))
					cout << endl << "Delete Successful" << endl;
			   else
					cout << endl << "Could not find match" << endl;
		  }
		  else if ('F' == option)
		  {
			   user_LTL.display();
		  }
		  else if ('G' == option)
		  {
			   Dinner temp_din;
			   cout << "Username: ";
			   cin.get(user_name, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Hour(0-24): ";
			   cin >> hour;
			   cin.ignore(TEMP, '\n');
			   cout << "Minutes(0-60): ";
			   cin >> minute;
			   cin.ignore(TEMP, '\n');
			   cout << "Enter the Dinner order: ";
			   cin.get(misc, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Enter the party size: ";
			   cin >> size;	
			   cin.ignore(TEMP, '\n');

			   temp_din.add_dinner(user_name, hour, minute, misc, size);
			   user_DD.insert(temp_din);
		  }
		  else if ('H' == option)
		  {
			   cout << "Enter the reservation name to add people: ";
			   cin.get(misc, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Enter the number of people to add: ";
			   cin >> size;
			   cin.ignore(100, '\n');
			   user_DD.add_person(misc, size);
		  }
		  else if ('I' == option)
		  {
			   cout << "Enter the reservation name to remove people: ";
			   cin.get(misc, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Enter the number of people to remove: ";
			   cin >> size;
			   cin.ignore(100, '\n');
			   user_DD.remove_person(misc, size);
		  }
		  else if ('J' == option)
		  {
			   cout << "Enter the reservation name to change order: ";
			   cin.get(user_name, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   cout << "Enter the order: ";
			   cin.get(misc, TEMP, '\n');
			   cin.ignore(TEMP, '\n');
			   user_DD.place_order(user_name, misc);
		  }
		  else if ('K' == option)
		  {
			   user_DD.display();
		  }
		  else if ('L' == option)
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

