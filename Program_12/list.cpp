#include "list.h"
using namespace std;
// Chase Verbout
// CS202 Spring 2022
// Prog 2
// list.cpp

// This file contains the functions for the list class variations in the list.h 
// file. This includes an STL list with LazerTag objects, an STL deque with Dinner reservations.
// The structures are organized by their Time variable which is maintained by the insert functions.

// These classes utilize the Dinner Class and LazerTag Class found in reservation.h


// LTL Constructor
LTL::LTL(void): reservations({})
{}



// Displays all LazerTag objects in the list
bool LTL::display(void) const
{
	 for (LazerTag res : reservations)
	 {
		  res.display();
		  cout << endl;
	 }
	 return true;
}



// Inserts a LazerTag object ordering by time (early -> later)
// Returns the current size
int LTL::insert(const LazerTag& a_lazertag)
{
	 list<LazerTag>::iterator itr = reservations.begin();
	 while (itr != reservations.end() && (*itr) < a_lazertag)
		  ++itr;

	 if (itr == reservations.end())
		  reservations.push_back(a_lazertag);
	 else
		  reservations.insert(itr, 1, a_lazertag);

	 return reservations.size();
}



// Display the LazerTag obejct matching the given name
// Return false if not found
bool LTL::find_team(const char* a_team_name)
{
	 if (reservations.empty())
		  return false;

	 list<LazerTag>::iterator itr = reservations.begin();
	 while (itr != reservations.end() && !(*itr == a_team_name))
		  itr++;

	 if(itr == reservations.end())
		  return false;

	 itr->display();
	 return true;	
}



// Remove the Lazertag object matching the given team name
// Return false if not found
bool LTL::remove_team(const char* a_team_name)
{
	 if (reservations.empty())
		  return false;

	 list<LazerTag>::iterator itr = reservations.begin();
	 while (itr != reservations.end() && !(*itr == a_team_name))
		  itr++;

	 if (itr == reservations.end())
		  return false;

	 reservations.erase(itr);
	 return true;
}



// DinDeque Constructor 
DinDeque::DinDeque(void) : reservations({})
{}



// Display all Dinner objects in the DinDeque
bool DinDeque::display(void)
{
	 if (reservations.empty())
		  return false;

	 for (Dinner din : reservations)
	 {
		  din.display();	
     	  cout << endl;
     }

	 return true;
}



// Insert a Dinner object into DinDeque ordered by time (Early->Late)
// Return current size
int DinDeque::insert(const Dinner& a_dinner)
{
	 deque<Dinner>::iterator itr = reservations.begin();
	 while(itr != reservations.end() && (*itr) < a_dinner)
		  ++itr;

	 if (itr == reservations.end())
		  reservations.push_back(a_dinner);
	 else
		  reservations.insert(itr, a_dinner);

	 return reservations.size();
}



// Add an amount to a given Dinner objects party size
bool DinDeque::add_person(const char* a_name, const int people)
{
	 if (reservations.empty())
		  return false;

	 deque<Dinner>::iterator itr = reservations.begin();
	 while(itr != reservations.end() && !(*itr == a_name))
		  ++itr;

	 if (itr == reservations.end())
		  return false;

	 *itr += people;
	 return true;
}



// Remove an amount from a given Dinner objects party size
bool DinDeque::remove_person(const char* a_name, const int people)
{
	 if (reservations.empty())
		  return false;

	 deque<Dinner>::iterator itr = reservations.begin();
	 while(itr != reservations.end() && !(*itr == a_name))
		  ++itr;

	 if (itr == reservations.end())
		  return false;

	 *itr -= people;
	 return true;
}



// Change the order of a given Dinner object
bool DinDeque::place_order(const char* a_name, const string order)
{
	 if (reservations.empty())
		  return false;

	 deque<Dinner>::iterator itr = reservations.begin();
	 while(itr != reservations.end() && !(*itr == a_name))
		  ++itr;

	 if(itr == reservations.end())
		  return false;

	 itr->change_pre_order(order);
	 return true;
}


