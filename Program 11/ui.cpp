#include "contest.h"
#include <iostream>
using namespace std;

// Chase Verbout
// CS202
// Program 1
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
		  << "* a) Add Cheetah to LandRace *" << endl 
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* b) Simulate LandRace       *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* c) Add Dolphin to SwimRace *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* d) Simulate SwimRace       *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* e) Add Gorilla to ClimbRace*" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* f) Simulate ClimbRace      *" << endl
		  << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl
		  << "* g) Quit                    *" << endl
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
bool translate(char option, LandRace& user_lr, SwimRace& user_sr, ClimbRace& user_cr)
{
	 // This is a boolean to keep track of whether the program should continue.
	 bool again {true};
	 // Item inputs

	 if ('A' == option)
	 {
		  if(!user_lr.add_cheetah())
			   cout << "Sorry, the time to sign up for this race has passed!\n";
	 }
	 else if ('B' == option)
	 {
		  if(user_lr.display_contestants() >= 2)
		  { 
			   if(user_lr.start_race())
			   {
					do
					{
						 user_lr.sim_round();
						 cout << endl << "Another round?";	
					} while (yes_no());
					user_lr.end_race();
			   }
			   else
					cout << "Sorry, this race has already been run! These were the winners: \n";
			   user_lr.display_winners();
		  }
		  else
			   cout << endl << "Add more contestants first!\n";
	 }
	 else if ('C' == option)
	 {

		  if(!user_sr.add_dolphin())
			   cout << "Sorry, the time to sign up for this race has passed!\n";
	 }
	 else if ('D' == option)
	 {
		  if(user_sr.display_contestants() >= 2)
		  {
			   if (user_sr.start_race())
			   {
					do
					{
						 user_sr.sim_round();
						 cout << endl << "Another round?";	
					} while (yes_no());
					user_sr.end_race();
			   }
			   else
					cout << "Sorry, this race has already been run! These were the winners: \n";

			   user_sr.display_winners();

		  }
		  else
			   cout << endl << "Add some more contestants first!\n";
	 }
	 else if ('E' == option)	
	 {
		  if(!user_cr.add_gorilla())
			   cout << "Sorry, the time to sign up for this race has passed!\n";
	 }
	 else if ('F' == option)
	 {
		  if(user_cr.display_contestants() >= 2)
		  {
			   if(user_cr.start_race())
			   {
					do
					{
						 user_cr.sim_round();
						 cout << endl << "Another round?";	
					} while (yes_no());
					user_cr.end_race();
			   }
			   else
					cout << "Sorry, this race has already been run! The winners were: \n";
			   user_cr.display_winners();
		  } 
		  else 
			   cout << endl << "Add some more contestants first!\n";

	 }
	 else if ('G' == option)
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

