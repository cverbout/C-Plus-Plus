#include "contest.h"
#include <iostream>

using namespace std;

// Chase Verbout
// CS202 Spring 2022
// Program 1
// main.cpp

// The purpose of this file is to test out the Animal hierarchy classes
// as well as the Contest hierarchy classes.

int main()

{
	 //response variable that keeps track of user's menu selection.
	 char response {'z'};

	 srand(time(0));
	 cout << "Welcome to Animal Bananza 5!" << endl;
	 //constructs the user's bst table for them to interact with.
	 LandRace user_lr;
	 cout << "\n~LandRace~\n";
	 user_lr.add_info();
	 SwimRace user_sr;
	 cout << "\n~SwimRace~\n";
	 user_sr.add_info();
	 ClimbRace user_cr;
	 cout << "\n~ClimbRace~\n";
	 user_cr.add_info();
	 cout << "Please select an option from the menu below." << endl << endl;
	 do
	 {
		  response = menu();
	 } while (translate(response, user_lr, user_sr, user_cr));	

	 return 0;
}

