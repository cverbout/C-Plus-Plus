#include "reservation.h"
using namespace std;

// Chase Verbout
// CS202 Spring 2022
// Prog 2
// reservation.cpp

// This file contains the Reservation class function definitions and its derivatves
// function definitions:
// Derivatives: LazerTag, Dinner, and Zoo
// The classes contain functionality for creating and filling out information as well
// as altering existing iformation.
// They also incorporate the use of some operator overloaded functions. See specific
// functions to understand usage(not totally intuitive - some for fun/testing out overloading)



// Reservation Constructor
Reservation::Reservation(void)
{
	 user_name = nullptr;
	 time.fill(99);
}



// Reservation Copy Constructor
Reservation::Reservation(const Reservation & a_reservation): user_name(nullptr), time({99, 99})
{
	 if (a_reservation.user_name)
	 {
		  user_name = new char[strlen(a_reservation.user_name) + 1];
		  strcpy(user_name, a_reservation.user_name);
	 }
	 time = a_reservation.time;
}



// Reservation Destructor
Reservation::~Reservation(void)
{
	 if (user_name)
		  delete [] user_name;
	 user_name = nullptr;
	 time.fill(99);	
}



// Reservation Operator '=' overload
// Sets Reservation to data of given Reservation
Reservation & Reservation::operator=(const Reservation & a_reservation)
{
	 if (this == &a_reservation)
		  return *this;

	 if (user_name)
	 {
		  delete [] user_name;
		  user_name = nullptr;
	 }

	 if (a_reservation.user_name)
	 {
		  user_name = new char[strlen(a_reservation.user_name) + 1];
		  strcpy(user_name, a_reservation.user_name);
	 }

	 time = a_reservation.time;
	 return *this;
}



// Reservation Operator '==' overload
// Checks if the reservation has the given user_name
bool Reservation::operator == (const char* a_name) const
{
	 if (strcmp(user_name, a_name) == 0)
		  return true;
	 return false;
}



// Reservation Operator '!=' overload
// Checks if the reservation has the given user_name
bool Reservation::operator != (const char* a_name) const
{
	 if (strcmp(user_name, a_name) != 0)
		  return true;
	 return false;
}



// Reservation Operator '>=' overload
// Checks if the reservation has a time greater than or equal to another reservation
bool Reservation::operator >= (const Reservation& a_reservation) const
{
	 if (time[0] > a_reservation.time[0])
		  return true;	
	 else if (time[0] == a_reservation.time[0])
	 {
		  if (time[1] >= a_reservation.time[1])
			   return true;
	 }
	 return false;
}



// Reservation Operator '<=' overload
// Checks if the reservation has a time less than or equal to another reservation
bool Reservation::operator <= (const Reservation& a_reservation) const
{
	 if (time[0] < a_reservation.time[0])
		  return true;
	 else if (time[0] == a_reservation.time[0])
	 {
		  if (time[1] < a_reservation.time[1])
			   return true;
	 }
	 return false;
}



// Reservation Operator '>' overload
// Checks if the reservation has a time greater than another reservation
bool Reservation::operator > (const Reservation& a_reservation) const
{
	 if (time[0] > a_reservation.time[0])
		  return true;	
	 else if (time[0] == a_reservation.time[0])
	 {
		  if (time[1] > a_reservation.time[1])
			   return true;
	 }
	 return false;
}



// Reservation Operator '<' overload
// Checks if the reservation has a time less than another reservation
bool Reservation::operator < (const Reservation& a_reservation) const
{
	 if (time[0] < a_reservation.time[0])
		  return true;
	 else if (time[0] == a_reservation.time[0])
	 {
		  if (time[1] <= a_reservation.time[1])
			   return true;
	 }
	 return false;
}



// Reservation Operator '<<' overload
// Outputs the reservation user and time
ostream& operator << (ostream& out, const Reservation& a_reservation)
{
	 BAD_OUTPUT bad_output;

	 if (!a_reservation.user_name)
		  throw bad_output;

	 out << a_reservation.user_name << " " << a_reservation.time[0] << ":" << a_reservation.time[1] << " ";
	 return out;
}



// Reservation operator '>>' overload
istream& operator >> (istream& in, Reservation& a_reservation)
{
	 BAD_INPUT bad_input;
	 char temp[TEMP];

	 in.get(temp, 100, '\n');
	 in.ignore(100, '\n');
	 if (!in)
		  throw bad_input;

	 if (a_reservation.user_name)
		  delete [] a_reservation.user_name;	

	 a_reservation.user_name = new char [strlen(temp) + 1];
	 strcpy(a_reservation.user_name, temp);

	 return in;
}




// Displays a reservation's data
void Reservation::display(void) const
{
	 BAD_INPUT bad_input;

	 if (!user_name)
		  throw bad_input;	  

	 cout << "\nUser: " << *this << " Time: " << time[0] << ":" << time[1];
	 return;
}



// Adds information to the reservation object given a char*, int, int
void Reservation::add_reservation(const char * name, const int hour, const int minute)
{
	 BAD_INPUT bad_input;
	 ALREADY_EXISTS already_exists;

	 if (!name || hour > 24 || hour < 0 || minute > 60 || minute < 0)
		  throw bad_input;
	 if (user_name)
		  throw already_exists;

	 user_name = new char[strlen(name) + 1];
	 strcpy(user_name, name);

	 time[0] = hour;
	 time[1] = minute;
	 return;
}



// Changes the name of the reservation given a char*
void Reservation::change_name(const char * name)
{
	 BAD_INPUT bad_input;

	 if (!name)
		  throw bad_input;

	 if (user_name)
		  delete [] user_name;

	 user_name = new char[strlen(name) + 1];
	 strcpy(user_name, name);
	 return;
}



// Changes the time of the resrevation given int, int
void Reservation::change_time(const int hour, const int minute)
{
	 BAD_INPUT bad_input;

	 if (hour > 24 || hour < 0 || minute > 60 || minute < 0)
		  throw bad_input;
	 time[0] = hour;
	 time[1] = minute;
	 return;
}



/*********** LazerTag Functionality ***********/

// LazerTag Constructor
LazerTag::LazerTag(void): team_name(nullptr), team_size(0) {}



// LazerTag Copy Constructor
LazerTag::LazerTag(const LazerTag & a_lazertag): Reservation(a_lazertag), team_name(nullptr), team_size(0)
{
	 if (a_lazertag.team_name)
	 {
		  team_name = new char[strlen(a_lazertag.team_name) + 1];
		  strcpy(team_name, a_lazertag.team_name);
	 }
	 team_size = a_lazertag.team_size;
}



// LazerTag Destructor
LazerTag::~LazerTag(void)
{
	 if (team_name)
		  delete [] team_name;
	 team_name = nullptr;
	 team_size = 0;
}



// LazerTag operator '=' overload
// Copies a_lazertag data into this LazerTag
LazerTag & LazerTag::operator = (const LazerTag & a_lazertag)
{ 
	 if (this == &a_lazertag)
		  return *this;
	 Reservation::operator=(a_lazertag);
	 if (team_name)
	 {
		  delete [] team_name;
		  team_name = nullptr;
	 }
	 if (a_lazertag.team_name)
	 {
		  team_name = new char[strlen(a_lazertag.team_name) + 1];
		  strcpy(team_name, a_lazertag.team_name);
	 }
	 team_size = a_lazertag.team_size;
	 return *this;
}



// LazerTag operator '==' overload
// Returns true if this LazerTag has the same team_name as the given char*
bool LazerTag::operator==(const char* a_name) const
{
	 if (strcmp(team_name, a_name) == 0)
		  return true;
	 return false;
}



// LazerTag operator '!=' overload
// Returns true if this LazerTag has the same team_name as the given char*
bool LazerTag::operator != (const char* a_name) const
{
	 if (strcmp(team_name, a_name) != 0)
		  return true;
	 return false;
}



// LazerTag operator '<<' overload
// Returns ostream containing team_name
ostream& operator << (ostream& out, const LazerTag& a_lazertag)
{
	 out << static_cast<const Reservation &>(a_lazertag);
	 return out;
}



// LazerTag operator '>>' overload
istream& operator >> (istream& in, LazerTag& a_lazertag)
{
	 in >> static_cast<Reservation &>(a_lazertag);
	 return in;
}



// Displays a LazerTag's data
void LazerTag::display(void) const
{
	 BAD_INPUT bad_input;

	 Reservation::display();

	 if (!team_name)
		  throw bad_input;

	 cout << "\nTeam Name: " << team_name << " Team Size: " << team_size;
}



// Adds information to a LazerTag object given a char* and int
void LazerTag::add_lazertag(const char * name, const int size)
{
	 BAD_INPUT bad_input;
	 ALREADY_EXISTS already_exists;

	 if (!name || size < 0)
		  throw bad_input;
	 if (team_name)
		  throw already_exists;

	 team_name = new char[strlen(name) + 1];
	 strcpy(team_name, name);
	 team_size = size;
}



// Adds information to a LazerTag object given a char*, int, int, char* and int
void LazerTag::add_lazertag(const char* uname, const int hour, const int minute, const char* tname, const int size)
{
	 Reservation::add_reservation(uname, hour, minute);
	 add_lazertag(tname, size);
}



// Changes the team_size given an int
int LazerTag::change_team_size(const int size)
{
	 BAD_INPUT bad_input;

	 if (size < 0)
		  throw bad_input;

	 team_size = size;
	 return team_size;
}



// Changes the team_name given a char*
char* LazerTag::change_team_name(const char * name)
{
	 BAD_INPUT bad_input;

	 if (!name)
		  throw bad_input;
	 if (team_name)
		  delete [] team_name;

	 team_name = new char[strlen(name) + 1];
	 strcpy(team_name, name);
	 return team_name;
}



// Zoo Functions 

// Zoo Constructor
Zoo::Zoo(void):exhibits_visiting(""), member_status(false) {}



// Zoo operator '+=' overload
// Adds given string to exhisting exhibits_visiting
Zoo& Zoo::operator += (const string exhibit)
{
	 if (exhibit.empty())
		  return *this;
	 exhibits_visiting += (", " + exhibit);
	 return *this;
}



// Zoo operator '+' overload
// Adds given string to exhisting exhibits_visiting
Zoo Zoo::operator + (const string exhibit) const
{
	 Zoo temp(*this);
	 temp += exhibit;
	 return temp;
}



// Zoo operator '<<' overload
// Return ostream of user_name
ostream& operator << (ostream& out, const Zoo& a_zoo)
{
	 out << static_cast<const Reservation&>(a_zoo);
	 out << a_zoo.exhibits_visiting << " " << a_zoo.member_status;
	 return out;
}



// Zoo operator '>>' overload
// Return istream of new user_name
istream& operator >> (istream& in, Zoo& a_zoo)
{
	 in >> static_cast<Reservation &>(a_zoo);
	 return in;
}



// Displays the data in a Zoo object
void Zoo::display(void) const
{
	 Reservation::display();

	 cout << "\nExhibits Planned: " << exhibits_visiting;
	 cout << "\nMember Status: " << member_status;
}



// Add data to Zoo given a string and bool
void Zoo::add_zoo(const string exhibits, const bool membership)
{
	 exhibits_visiting = exhibits;
	 member_status = membership;
}



// Add data to Zoo given a char*, int, int, string and bool
void Zoo::add_zoo(const char * name, const int hour, const int minute, const string exhibits, const bool membership)
{
	 Reservation::add_reservation(name, hour, minute);
	 add_zoo(exhibits, membership);
}



// Change the exhibits_visiting of this Zoo object
string Zoo::change_exhibits(const string exhibits)
{
	 exhibits_visiting = exhibits;
	 return exhibits_visiting;
}



// Change the member_status of this Zoo object
bool Zoo::change_member_status(const bool membership)
{
	 member_status = membership;
	 return member_status;	
}



// Dinner Functions

// Dinner Constructor
Dinner::Dinner(void): pre_order(""), party_size(0) {}



// Dinner operator '+=' overload
Dinner& Dinner::operator += (const int size)
{
	 party_size += size;	
	 return *this;
}



// Dinner operator '-=' overload
Dinner& Dinner::operator -= (const int size)
{
	 party_size -= size;
	 if (party_size < 0)
		  party_size = 0;
	 return *this;
}



// Dinner operator '+=' overload
Dinner Dinner::operator + (const int size) const
{
	 Dinner temp(*this);
	 temp.party_size += size;
	 return temp;
}



// Dinner operator '-' overload
Dinner Dinner::operator - (const int size) const
{
	 Dinner temp(*this);
	 temp.party_size -= size;
	 return temp;
}



// Dinner operator '<<' overload
// Returns ostream of user_name
ostream& operator << (ostream& out, const Dinner& a_dinner)
{
	 out << static_cast<const Reservation&>(a_dinner);
	 return out;
}



// Dinner operator '>>' overload
// Returns istream of in
istream& operator >> (istream& in, Dinner& a_dinner)
{
	 in >> static_cast<Reservation&>(a_dinner);
	 return in;
}	



// Displays Dinner's data
void Dinner::display(void) const
{
	 Reservation::display();

	 cout << "\nOrder: " << pre_order;
	 cout << "\nParty Size: " << party_size;
}



// Adds data to Dinner object given string, and int
void Dinner::add_dinner(const string order, const int size)
{
	 pre_order = order;
	 party_size = size;
}



// Adds data to Dinner object given a char*, int, int, string, and int
void Dinner::add_dinner(const char* name, const int hour, const int minute, const string order, const int size)
{
	 Reservation::add_reservation(name, hour, minute);
	 add_dinner(order, size);
}



// Change this Dinner object's pre_order
string Dinner::change_pre_order(const string order)
{
	 pre_order = order;	
	 return pre_order;
}



// Chage this Dinner object's party_size
int Dinner::change_party_size(const int size)
{
	 BAD_INPUT bad_input;

	 if (size < 0)
		  throw bad_input;

	 party_size = size;
	 return party_size;
}

