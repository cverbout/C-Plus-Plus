#include "contest.h"
#include <iostream>
using namespace std;

// Chase Verbout
// CS202 Spring 2022
// Program 1
// contest.cpp

// This file contains the class definitions for the Contest class and its derivative
// classes: LandRace, SwimRace, ClimbRace. These classes have functions that are intended
// to store respective animals and manage the races. 

// LANDRACE FUNCTIONS: 94
// SWIMRACE FUNCTIONS: 293
// CLIMBRACE FUNCTIONS: 514

// Contest Constructor
Contest::Contest(void): ended(false), first_score(0), second_score(0), name(""), skill(""), animal_type("")
{}



// Displays a contest's name, skill and animal type
bool Contest::display(void) const
{
	 cout << "---------------------------\n";
	 cout << "Name: " << name << endl;
	 cout << "Skill: " << skill << endl;
	 cout << "Animal Type: " << animal_type;
	 cout << endl;
	 return true;
}



// Prompts the user for a contest name, skill and animal type 
int Contest::add_info(void)
{
	 string add_name;
	 string add_skill;
	 string add_animal_type;

	 cout << "\nName: ";
	 getline(cin, add_name);
	 cout << "\nSkill Level: ";
	 getline(cin, add_skill);
	 cout << "\nAnimal Type: ";
	 getline(cin, add_animal_type);
	 cout << endl;
	 return add_info(add_name, add_skill, add_animal_type);
}



// Assigns a name skill and animal type to a contest from the given arguments
int Contest::add_info(string add_name, string add_skill, string add_animal_type)
{
	 name = add_name;
	 skill = add_skill;
	 animal_type = add_animal_type;
	 return 1;
}



// Initiates the starting message and displays the contest information
bool Contest::start_race(void) const
{
	 if (!ended)
	 {
		  cout << "\nWelcome one and all!! You're in for a treat today!\n\n";
		  cout << "Race Details: \n";
		  display();
		  cout << "---------------------------\n"; 
		  cout << "\nRace is now beginning in 3... 2... 1... \n\n\n" << endl;
	 }

	 return !ended;
}



// Signals that the race has ended and sets the race to ended
bool Contest::end_race(void) 
{
	 cout << "\n\n\nAnd here comes our winners!\n" << endl;
	 ended = true;
	 return ended;
}



// LandRace:

// LandRace Constructor
LandRace::LandRace(void): rear(nullptr)
{} // Initializer list ensures rear is null



// LandRace Copy Constructor
LandRace::LandRace(const LandRace& a_land_race): Contest(a_land_race), rear(nullptr)
{
	 if (a_land_race.rear) // If the given argument has at least one node
	 {
		  rear = new CheetahNode(*(a_land_race.rear)); // Dynamic Allocation
		  copy_construct(a_land_race.rear, a_land_race.rear->get_next(), rear->get_next());
	 }
}



// LandRace private copy helper - recursive
int LandRace::copy_construct(CheetahNode *source_rear, CheetahNode *source_curr, CheetahNode *&dest)
{
	 if(source_rear == source_curr) // If we reach the sources rear we are done
	 {
		  dest = rear;	
		  return 0;
	 }
	 dest = new CheetahNode(*source_curr); // Dynamic Allocation
	 return 1 + copy_construct(source_rear, source_curr->get_next(), dest->get_next());
}



// LandRace Destructor
LandRace::~LandRace(void)
{
	 if (rear) // If we have nodes deal with the allocated memory and delete them all
		  remove_all(rear->get_next());
	 rear = nullptr;
}



// LandRace private destructor helper - recursive
int LandRace::remove_all(CheetahNode*& current)
{
	 if (current == rear)
	 {
		  delete current;
		  return 1;
	 }
	 CheetahNode *temp = current->get_next();
	 delete current;
	 current = nullptr;
	 return 1 + remove_all(temp);
}	



// Adds a cheetah to the LandRace
bool LandRace::add_cheetah(void)
{
	 if (ended)	
		  return false;
	 CheetahNode *temp;
	 temp = new CheetahNode; // Dynamic Allocation
	 temp->give_name();
	 temp->give_sponsor();
	 if (!rear) // If no rear make this the first node
	 {
		  rear = temp;
		  rear->set_next(rear);
	 }
	 else // Otherwise add it and set rear to it
	 {
		  temp->set_next(rear->get_next());
		  rear->set_next(temp);
		  rear = temp;
	 }		
	 return true;
}



// Displays all the cheetahs in the LandRace - returns the number of cheetahs
int LandRace::display_contestants(void) const
{
	 if (!rear)
		  return 0;
	 return display_contestants(rear->get_next());
}



// Private display helper function to display cheetahs in LandRace - recursive
int LandRace::display_contestants(CheetahNode*& current) const
{
	 if (current == rear)
	 {
		  current->display();
		  return 1;
	 }
	 current->display();
	 return 1 + display_contestants(current->get_next());
}



// Displays the first and second place cheetahs
int LandRace::display_winners(void) const
{
	 if (!rear)
		  return 0;
	 CheetahNode *first = rear; // Assign first place to an existing cheetah
	 CheetahNode *second = rear->get_next(); // Assign second place to another existing cheetah
	 if (rear->compare(*second) < 0) // Check if they are in the right order or swap
	 {
		  first = rear->get_next();
		  second = rear;
	 }

	 return display_winners(rear->get_next(), first, second);
}



// Private display helper function to display first and second place - recursive
int LandRace::display_winners(CheetahNode*& current, CheetahNode* first, CheetahNode* second) const
{
	 int diff1 = 0; 
	 int diff2 = 0;
	 if (current == rear)
	 {
		  cout << "\nIn first place we have:\n";
		  first->display_score();
		  cout << "---------------------------";
		  cout << "\nIn second place we have:\n";
		  second->display_score();
		  cout << "---------------------------";
		  return 1;
	 }
	 diff1 = current->compare(*first); // Compare current to first
	 diff2 = current->compare(*second); // Compare current to second
	 if (diff2 > 0 && diff1 > 0) // If current bigger than both first is current and second is the former first
	 {
		  second = first;
		  first = current;
	 }
	 else if (diff2 >= 0 && diff1 < 0) // If current bigger than only second swap with second
		  second = current;
	 return display_winners(current->get_next(), first, second);
}



// Simulates a round in the LandRace - returns number of cheetahs
int LandRace::sim_round(void) const
{
	 if (!rear)
		  return 0;
	 else 
		  return sim_round(rear->get_next());
}



// Private sim helper function - recursive
int LandRace::sim_round(CheetahNode*& current) const
{
	 if (current == rear)
	 {
		  current->calculate_score();
		  return current->display_score();
	 }
	 current->calculate_score();
	 return current->display_score() + sim_round(current->get_next());
}



// LandRace '=' operator overload function
LandRace& LandRace::operator=(const LandRace& a_land_race)
{
	 if (this == &a_land_race)
		  return *this;
	 else if (this->rear)
		  return *this;

	 Contest::operator=(a_land_race);

	 rear = new CheetahNode(*(a_land_race.rear)); // Dynamic Allocation
	 copy_construct(a_land_race.rear, a_land_race.rear->get_next(), rear->get_next());

	 return *this;
}



// SWIMRACE:

// SwimRace Constructor
SwimRace::SwimRace(void)
{
	 contestants = new DolphinNode*[SIZE]; // Dynamic Allocation
	 for (int i = 0; i < SIZE; ++i) // Set all DolphinNode Ptrs to nullptr
		  contestants[i] = nullptr;
}



// SwimRace Copy Constructor
SwimRace::SwimRace(const SwimRace& a_swim_race):Contest(a_swim_race), contestants(nullptr)
{
	 contestants = new DolphinNode*[SIZE]; // Dynamic Allocation
	 for (int i = 0; i < SIZE; ++i) 
	 {
		  contestants[i] = nullptr; // Set index to nullptr before we copy
		  copy_construct(a_swim_race.contestants[i], contestants[i]);
	 }
}



// Private copy constuctor helper function 
int SwimRace::copy_construct(DolphinNode* source, DolphinNode *& dest)
{
	 if (!source)
		  return 0;
	 DolphinNode* temp = new DolphinNode; // Dynamic Allocation
	 *temp = *source;
	 dest = temp;

	 return 1 + copy_construct(source->get_next(), dest->get_next());
}



// SwimRace Destructor
SwimRace::~SwimRace(void)
{
	 if (contestants) // If we have contestants we have to check all arr indexes
	 {
		  for (int i = 0; i < SIZE; ++i)
			   remove_all(contestants[i]); // Delete the LLL in the index
	 }
	 delete [] contestants;
	 contestants = nullptr;
}



// Private destructor helper function - recursive - returns number removed
int SwimRace::remove_all(DolphinNode*& current)
{
	 if (!current)
		  return 0;
	 DolphinNode *temp = current->get_next();
	 delete current;
	 return 1 + remove_all(temp);	
}



// Adds a dolphin to the SwimRace - returns true if successful
bool SwimRace::add_dolphin(void)
{	
	 if (!contestants)
		  return false;
	 else if (ended)
		  return false;
	 DolphinNode *to_add = new DolphinNode; // Dynamic Allocation
	 to_add->give_name();
	 int hash = to_add->hash_function();

	 if (!contestants[hash])
		  contestants[hash] = to_add;
	 else
	 {
		  DolphinNode *temp = contestants[hash];
		  to_add->set_next(temp);
		  contestants[hash] = to_add;
	 }

	 return true;
}



// Displays all dolphins the SwimRace - return the count of dolphins
int SwimRace::display_contestants(void) const
{
	 if (!contestants)
		  return 0;
	 int count = 0;	
	 for (int i = 0; i < SIZE; ++i)
		  count += display_contestants(contestants[i]);

	 return count;
}



// Private display helper function - recursive
int SwimRace::display_contestants(DolphinNode* current) const
{
	 if (!current)
		  return 0;

	 return current->display() + display_contestants(current->get_next());
}	



// Simulates a round of the SwimRace - Returns the total points accumulated that round
int SwimRace::sim_round(void) const
{
	 if (!contestants)
		  return 0;
	 int total = 0;	
	 for (int i = 0; i < SIZE; ++i)	
		  total += sim_round(contestants[i]);

	 return total;
}



// Private simulate helper function - recursive
int SwimRace::sim_round(DolphinNode*& current) const
{
	 if (!current)
	 {
		  return 0;
	 }
	 current->calculate_pace();
	 return current->display_pace() + sim_round(current->get_next());
}



// Displays the first and second place dolphins
int SwimRace::display_winners(void) const
{
	 if (!contestants)
		  return 0;
	 DolphinNode *first = nullptr; // Create temp dolphin nodes to pass in recursive function
	 DolphinNode *second = nullptr;

	 for (int i = 0; i < SIZE; ++i)
		  display_winners(contestants[i], first, second);
	 cout << "\nIn first place we have:\n";
	 first->display_pace();
	 cout << "---------------------------";
	 cout << "\nIn second place we have:\n";
	 second->display_pace();
	 cout << "---------------------------";
	 return 1;
}



// Private display winner helper function - recursive
int SwimRace::display_winners(DolphinNode* current, DolphinNode*& first, DolphinNode*& second) const
{
	 int diff1 = 0;
	 int diff2 = 0;
	 if (!current)
	 {
		  return 1;
	 }
	 if (!first)
		  first = current;  // Catches only the first gorilla and assigns it to first
	 else if (!second)  // Catches only the second gorilla through and assigns it to second
	 {
		  second = current;
		  if (first->compare(*second) < 0) // If they are in the wrong order swap them
		  {
			   second = first;
			   first = current;
		  }
	 }
	 else if (first && second) // If we have established first and second
	 {
		  diff1 = current->compare(*first); // Compare current to first
		  diff2 = current->compare(*second); // Compare current to second
		  if (diff2 > 0 && diff1 > 0) // Depending on which places current is larger than change assignments
		  {
			   second = first;
			   first = current;
		  }
		  else if (diff2 >= 0 && diff1 < 0)
			   second = current;
	 }
	 return display_winners(current->get_next(), first, second);
}



// SwimRace '=' operator overload
SwimRace& SwimRace::operator=(const SwimRace& a_swim_race)
{
	 if (this == &a_swim_race)
		  return *this;

	 Contest::operator=(a_swim_race);

	 for (int i = 0; i < SIZE; ++i)
	 {
		  if (contestants[i])
			   return *this;
	 }
	 for (int i = 0; i < SIZE; ++i)
		  copy_construct(a_swim_race.contestants[i], contestants[i]);	

	 return *this;
}



// STL Vector

// Adds a gorilla to the ClimbRace
bool ClimbRace::add_gorilla(void)
{
	 if (ended)
		  return false;
	 Gorilla to_add;
	 to_add.give_name();
	 contestants.push_back(to_add);
	 return true;
}



// Displays the first and second place winners of the ClimbRace
int ClimbRace::display_winners(void)
{
	 int diff1 = 0;
	 int diff2 = 0;
	 Gorilla first = contestants[0]; // Assign first place to a gorilla
	 Gorilla second = contestants[1]; // Assign second to a different gorilla

	 if (first.compare(second) < 0) // Make sure first has a higher score than second
	 {								// If not switch them
		  second = contestants[0];
		  first = contestants[1];
	 }
	 for (vector<Gorilla>::iterator itr = contestants.begin(); itr != contestants.end(); ++itr)
	 {
		  diff1 = (*itr).compare(first); // Compare first to the current gorilla
		  diff2 = (*itr).compare(second); // Compare second to the current
		  if (diff2 > 0 && diff1 > 0) // if its larger than both make first this gorilla and second the former first
		  {
			   second = first;
			   first = *itr;
		  }
		  else if (diff2 >= 0 && diff1 < 0) // If it is only larger than second - swap it
			   second = *itr;
	 }	
	 cout << "\nIn first place we have:\n";
	 first.display_score();
	 cout << "---------------------------";
	 cout << "\nIn second place we have:\n";
	 second.display_score();
	 cout << "---------------------------";
	 return 1;
}



// Displays all of the contestants in the ClimbRace
int ClimbRace::display_contestants(void)
{
	 int total = 0; // Go through the whole vector and display each gorilla
	 for (vector<Gorilla>::iterator itr = contestants.begin(); itr != contestants.end(); ++itr)
		  total += itr->display();	
	 return total;

}



// Simulates a round of the ClimbRace
int ClimbRace::sim_round(void)
{
	 int total = 0; // Go through the whole vector and calc the score for each gorilla
	 for (vector<Gorilla>::iterator itr = contestants.begin(); itr != contestants.end(); ++itr)
	 {
		  itr->calculate_score();   
		  total += itr->display_score();	
	 }
	 return total;
}

