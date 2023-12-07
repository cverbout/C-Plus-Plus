#include "foodcart.h"
using namespace std;

//Chase Verbout
//163
//Program 1
//foodcart.cpp
//
//This file contains the foodcart class member functions. The foodcart
//class contains a constructor and destructor as well as an add function
//for individual foodcart input, an add function for a whole foodcart input,
//a function to check if the foodcart is open, a function to check if another foodcart
//has the same name, and a display function.
/*
   class foodcart
   {
   char * name;
   int open;
   int close;
   char * location;
   float stars;
   int weekends;
   int weekdays;
   };
 */

//This is the constructor for a foodcart object
foodcart::foodcart()
{
	 name = nullptr;
	 open = 0;
	 close = 0;
	 location = nullptr;
	 stars = 0.0;
	 weekdays = 0;
	 weekends = 0;
}



//This is the destructor for the the foodcart object
foodcart::~foodcart()
{
	 if (name)
		  delete [] name;
	 if (location)
		  delete [] location;
	 name = location = nullptr;
	 stars = 0.0;
	 open = close = weekdays = weekends = 0;
}



//This function adds information to a foodcart object given a name, open time, close time, location, and stars.
// Precondition: a char array name_toadd for the name of the foodcart, integers for open_add and close_add that
// are between 0 and 24 to represent open time and closing time, integers for weekdays_add and weekends_add that
// represent 1 for open and 0 for close, a char array location_toadd that is the location of the fc, and a float
// stars_toadd that is a between 0.0 and 5.0.
// Postcondition: The data inputed will now exist in the foodcart
int foodcart::add(char * name_toadd, int open_add, int close_add, int weekdays_add, int weekends_add, char * location_toadd, float stars_toadd)
{
	 if (!name_toadd || !location_toadd)
		  return 0;

	 name = new char[strlen(name_toadd) + 1];
	 strcpy(name, name_toadd);	
	 open = open_add;
	 close = close_add;
	 weekdays = weekdays_add;
	 weekends = weekends_add;
	 location = new char[strlen(location_toadd) +1];
	 strcpy(location, location_toadd);
	 stars = stars_toadd;

	 return 1;
}



//This function will add a foodcart given a whole foodcart item by reference
// Precondition: A whole foodcart object
// Postcondition: The information from the input foodcart will be copied to this foodcart.
int foodcart::add(const foodcart & new_fc)
{
	 return add(new_fc.name, new_fc.open, new_fc.close, new_fc.weekdays, new_fc.weekends, new_fc.location, new_fc.stars);
}



//This function will display the information held in a foodcart
int foodcart::display()
{
	 if (!name || !location)
		  return 0;
	 cout << "-------------------------------------------" << endl;
	 cout << "Foodcart: " << name << endl;
	 cout << "Hours: " << open << ":00 - " << close << ":00" << endl;
	 if (weekdays)
		  cout << "Open: Weekdays" << endl;
	 else
		  cout << "Closed: Weekdays" << endl;
	 if (weekends)
		  cout << "Open: Weekends" << endl;
	 else
		  cout << "Closed: Weekends" << endl;
	 cout << "Location: " << location << endl;
	 cout << "Stars: "<< stars << "/5.0" << endl;
	 return 1;
}



// This function will take in the wanted hours and days available and return
// whether or not the foodcart is open. The criteria for being open is that 
// open can be earlier or equal to the time wanted, close can be later or equal to the
// time wanted and one of the users wanted week availability must match.
// Precondition: want_open and want_close are inclusively between 0 and 24 and
// want_weekends and want_weekdays are 1 or 0
bool foodcart::is_Open(int want_open, int want_close, int want_weekdays, int want_weekends)
{
	 if((open <= want_open && close >= want_close) && (weekdays == want_weekdays || weekends == want_weekends))
		  return true;
	 return false;
}



// This function will return whether the foodcart has the same name as the input foodcart
// Precondition: name_toCheck is char array
bool foodcart::sameName(char * name_toCheck)
{
	 if (strcmp(name_toCheck, name) == 0)
		  return true;
	 return false;
}

