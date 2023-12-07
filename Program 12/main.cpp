#include "reservation.h"
#include "list.h"

using namespace std;

// Chase Verbout
// CS202 Spring 2022
// Program 2
// main.cpp

// The purpose of this file is to test out the functionality of program 2

// Current testing is on interface to demonstrate various functionalities
// NON INTERFACE TESTING BELOW

int main()
{

	 //response variable that keeps track of user's menu selection.
	 char response {'z'};

	 cout << "\n\n\n\n\n";
	 cout << "Tropical Resort Iternary Placement System(TRIPS)" << endl;
	 //constructs the user's bst table for them to interact with.
	 DLL<Zoo> user_DLL;
	 LTL user_LTL;
	 DinDeque user_DD;
	 cout << "Please select an option from the menu below." << endl << endl;
	 do
	 {
		  response = menu();
	 } while (translate(response, user_DLL, user_LTL, user_DD));	

	 // NON INTERFACE TESTING **** COMMENT OUT ABOVE AND UNCOMMENT SECTIONS BELOW

	 /*
		BAD_OUTPUT bad_output;
		BAD_INPUT bad_input;
		ALREADY_EXISTS already_exists;

	 // Reservation Functionality

	 try
	 {
	 Reservation res;
	 Reservation res2;

	 res.add_reservation("Craigggg Robinson", 12, 30);
	 cout << res << endl;
	 if (res == "Craigggg Robinson")
	 res.change_name("Craig Robinson");

	 cout << res << endl;
	 res.change_time(12, 45);

	 res2 = res;

	 cout << res2 << endl;

	 Reservation res3(res);

	 res3.display();

	 // Catch Demonstration

	 //Reservation res4;
	 //res4.add_reservation(nullptr, 4, 45);
	 //res4.display();
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
	  */
	 // LazerTag Functionality Testing
	 /*
		try
		{
		LazerTag ltag;
		LazerTag ltag2;
		ltag.add_reservation("Deku", 4, 50);
		ltag.add_lazertag("beasts", 4);
		ltag.display();
		ltag2 = ltag;
		cout << endl;
		ltag2.display();
		ltag.change_team_name("team gon");
		ltag.change_team_size(3);

		LazerTag ltag3(ltag);
		cout << endl;

		cin >> ltag3;
		ltag3.display();
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
		cout << endl;
	  */
	 /*
	 // Zoo Functionality Testing
	 try
	 {
	 Zoo zoo1;
	 Zoo zoo2;

	 zoo1.add_zoo("John Doe", 1, 30, "Lions, Tigers, Bears", true);
	 zoo1.display();
	 cout << endl;

	 zoo2 = zoo1;
	 zoo2.display();
	 cout << endl;

	 zoo2 += "Turtles";
	 zoo2.change_member_status(false);
	 zoo2.display();
	 cout << endl;

	 Zoo zoo3(zoo1);
	 cin >> zoo3;
	 zoo3.change_exhibits("Dingos, Dolphins");
	 zoo3.display();
	 cout << endl;

	 zoo1 = zoo3 + "Pandas";
	 zoo1.display();
	 cout << endl;	
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

	  */
	 /*
	 // Dinner Functionality Testing
	 try
	 {
	 Dinner din1;
	 Dinner din2;

	 din1.add_dinner("John Doe", 1, 30, "Steak and Pommed de Terre", true);
	 din1.display();
	 cout << endl;

	 din2 = din1;
	 din2.display();
	 cout << endl;

	 din2 += 3;
	 din2.change_pre_order("Frite aux Gratin et Jus des Fraises");
	 din2.display();
	 cout << endl;

	 din1 += 4;
	 Dinner din3(din1);
	 cin >> din3;
	 din3 -= 2;
	 din3.display();
	 cout << endl;

	 din1 = din3 + 10;
	 din1.display();
	 cout << endl;

	 din1 = din1 - 5;
	 din1.display();
	 cout << endl;
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
	  */
	 return 0;
}

