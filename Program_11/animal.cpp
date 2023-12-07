#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "animal.h"

using namespace std;

// Chase Verbout
// CS202 Spring 2022
// Program 1
// Animal.cpp

// This file contains the functions for the Animal class and its 
// derived classes Cheetah, Dolphin, Gorilla. The Animal class and
// its derived classes were created to supplement the Contest class
// and its derived classes. These classes support functions that yield
// to competing in competitions based on randomized characteristics

// CHEETAH FUNCTIONS: Line 174
// DOLPHIN FUNCTIONS: Line 337
// GORILLA FUNCTIONS: Line 435

// This is the base constructor for an Animal
Animal::Animal(void)
{
	 name = nullptr;
	 age = get_rand(); 
	 weight = get_rand();
	 speed = get_rand();
	 agility = get_rand();
	 strength = get_rand();
	 current_score = 0;
}



// This is a constructor for an Animal where the argument is the name for
// the animal.
Animal::Animal(char *add_name)
{
	 name = new char[strlen(add_name) + 1]; // Dynamic Allocation
	 strcpy(name, add_name);

	 age = get_rand(); 
	 weight = get_rand();
	 speed = get_rand();
	 agility = get_rand();
	 strength = get_rand();
	 current_score = 0;
}



// This is a copy constructor for the Animal class
Animal::Animal(const Animal& an_animal)
{
	 if(an_animal.name)
	 {
		  name = new char[strlen(an_animal.name) + 1]; // Dynmaic Allocation
		  strcpy(name, an_animal.name);

		  age = an_animal.age;
		  weight = an_animal.weight;
		  speed = an_animal.speed;
		  agility = an_animal.agility;
		  strength = an_animal.strength;
		  current_score = an_animal.current_score;
	 }
}



// This is the destructor for the Animal class
Animal::~Animal(void)
{
	 if (name)
		  delete [] name;
	 name = nullptr;
	 age = 0;
	 weight = 0;
	 speed = 0;
	 agility = 0;
	 strength = 0;
	 current_score = 0;
}



// Pre: An animal object
// Post: Prompts the user for a name and applies the name to the animal object
bool Animal::give_name(void)
{
	 if (name)
		  delete [] name;

	 char temp[100];
	 cout << "Enter a name: ";
	 cin.get(temp, 100, '\n');
	 cin.ignore(100, '\n');
	 name = new char[strlen(temp) + 1]; // Dynamic Allocation
	 strcpy(name, temp);
	 return true;
}



// Compares two Cheetahs and returns the difference
int Animal::compare(const Animal &an_animal)
{
	 return current_score - an_animal.current_score;
}



// Pre: An animal object
// Post: Displays the animal's data
int Animal::display(void) const
{
	 if (name)
		  cout << "Name: " << name << endl;
	 else
		  cout << "Name: NONE" << endl;
	 cout << endl;
	 cout << "Age: " << age << endl;
	 cout << "Weight: " << weight << endl;
	 cout << "Speed: " << speed << endl;
	 cout << "Agility: " << agility << endl;
	 cout << "Strength: " << strength << endl;
	 cout << endl;
	 return 1;
}



// Pre: An animal object
// Post: Returns a number that fits with the animal stat scoring (1-10)
int Animal::get_rand(void) const
{
	 return 1 + (rand() % SCALE); // Using a 1-10 scale 
}



// Operator overload for '='
// Post: If the animal is not itself, it copies and returns
//       a reference to the animal with the copied info
Animal& Animal::operator=(const Animal& an_animal)
{
	 if (this == &an_animal)
		  return *this;
	 if (name)
		  delete [] name;

	 if (an_animal.name)
	 {
		  name = new char[strlen(an_animal.name) + 1]; // Dynamic Allocation
		  strcpy(name, an_animal.name);
	 }
	 else
		  name = nullptr;

	 age = an_animal.age;
	 weight = an_animal.weight;
	 speed = an_animal.speed;
	 agility = an_animal.agility;
	 strength = an_animal.strength;
	 current_score = an_animal.current_score;

	 return *this;
}



// CHEETAH FUNCTIONS:

// The Cheetah base constructor
Cheetah::Cheetah(void)
{
	 sponsor = nullptr;
	 acceleration = get_rand();
	 paw_durability = get_rand();
	 leg_muscle = get_rand();
}



// The Cheetah copy constructor
// Does not copy the next ptr. Auto set to nullptr.
// User can decide to link it to the same cheetah at their own discretion.
Cheetah::Cheetah(const Cheetah &a_cheetah):Animal(a_cheetah), sponsor(nullptr), acceleration(0),
	 paw_durability(0), leg_muscle(0)
{
	 if (a_cheetah.sponsor)
	 {
		  sponsor = new char[strlen(a_cheetah.sponsor) + 1]; // Dynamic Allocation
		  strcpy(sponsor, a_cheetah.sponsor);
	 }
	 else
		  sponsor = nullptr;
	 acceleration = a_cheetah.acceleration;		
	 paw_durability = a_cheetah.paw_durability;
	 leg_muscle = a_cheetah.leg_muscle;
}



// The Cheetah destructor
Cheetah::~Cheetah()
{
	 if (sponsor)
		  delete [] sponsor;
	 sponsor = nullptr;
	 acceleration = 0;
	 paw_durability = 0;
	 leg_muscle = 0;
}



// Pre: An animal object
// Post: Prompts the user for a sponsor and applies the sponsor to the Cheetah object
bool Cheetah::give_sponsor(void)
{
	 if (sponsor)
		  delete [] sponsor;

	 char temp[100];
	 cout << "Enter a sponsor: ";
	 cin.get(temp, 100, '\n');
	 cin.ignore(100, '\n');
	 sponsor = new char[strlen(temp) + 1]; // Dynamic Allocation
	 strcpy(sponsor, temp);
	 return true;
}



// Pre: A cheetah object
// Post: Displays the Cheetah's info and stats
int Cheetah::display(void) const
{
	 Animal::display();
	 if (sponsor)
		  cout << "Sponsor: " << sponsor << endl;
	 cout << "Acceleration: " << acceleration << endl;
	 cout << "Paw Durability: " << paw_durability << endl;
	 cout << "Leg Muscle: " << leg_muscle << endl;
	 cout << endl;
	 return 1;
}



// Displays the Name and Score of the Cheetah
int Cheetah::display_score(void) const
{
	 cout << "\nContestant: " << name << endl;
	 cout << "Distance: " << current_score << " ft" << endl;
	 return current_score;
}



// Pre: A cheetah object
// Post: Returns the score for a cheetah in a LandRace based on its stats
int Cheetah::calculate_score(void)
{
	 int score = (((10 * speed) + (7 * agility) + (3 * strength) +
					(4 * age) + (6 * weight) + (acceleration * 10) + (paw_durability * 10) +
					(leg_muscle * 10)) / get_rand());
	 current_score += score;
	 return score;
}



// Operator overload for '=' 
Cheetah& Cheetah::operator=(const Cheetah &a_cheetah)
{
	 if (this == &a_cheetah)
		  return *this; 

	 Animal::operator=(a_cheetah);
	 // *this = static_cast<const Animal &> (a_cheetah); // Alternate Version

	 if (sponsor)
		  delete [] sponsor;
	 if(a_cheetah.sponsor)
	 {
		  sponsor = new char[strlen(a_cheetah.sponsor) + 1]; // Dynamic Memory
		  strcpy(sponsor, a_cheetah.sponsor);
	 }
	 else
		  sponsor = nullptr;

	 acceleration = a_cheetah.acceleration;		
	 paw_durability = a_cheetah.paw_durability;
	 leg_muscle = a_cheetah.leg_muscle;

	 return *this;
}


// CHEETAH NODE

// Cheetah Node Constructor
CheetahNode::CheetahNode(void): next(nullptr)
{} // Initializer list ensures next is null



// Returns a cheetah node objects next ptr reference
CheetahNode*& CheetahNode::get_next(void)
{
	 return this->next;
}



// Sets the cheetah node objects next ptr to a given cheetah object
int CheetahNode::set_next(CheetahNode *&a_cheetah_node)
{
	 this->next = a_cheetah_node; 
	 return 1;
}



// Returns whether the cheetah node objects next ptr is null or not
bool CheetahNode::has_next(void)
{
	 return this->next;	
}



// DOLPHIN FUNCTIONS:

// Dolphin base class constructor
Dolphin::Dolphin(void)
{
	 dorsal_height = get_rand();
	 flipper_push = get_rand();
	 fin_size = get_rand();
}



// Dolphin destructor
Dolphin::~Dolphin(void)
{
	 dorsal_height = flipper_push = fin_size = 0;
}



// Post: Returns a score based on the SwimRace emphasized characteristics
int Dolphin::calculate_pace(void)
{
	 int pace = (((8 * speed) + (10 * agility) + (4 * strength) +
					(6 * age) + (3 * weight) + (10 * dorsal_height) +
					(10 * flipper_push) + (10 * fin_size)) /100) + get_rand() * 2;
	 current_score += pace;
	 return pace;
}



// Post: Displays Dolphin info and stats
int Dolphin::display(void) const
{
	 Animal::display();
	 cout << "Dorsal Height: " << dorsal_height << endl;
	 cout << "Flipper Push: " << flipper_push << endl;
	 cout << "Fin Size: " << fin_size << endl;
	 cout << endl;
	 return 1;
}



// Displays the dolphins score/pace of hoops jumped
int Dolphin::display_pace(void) const
{
	 cout << "\nContestant: " << name << endl;
	 cout << "Hoops Jumped: " << current_score << endl;
	 return 1;
}



// Hash Function for ARR LLL
int Dolphin::hash_function(void) const
{
	 int hash = 0;
	 for (int i = 0; i < (int)strlen(name); ++i) // Hash by name for future search functionality
		  hash += name[i] * 127;

	 return hash % SIZE;
}



// Dolphin Node:

DolphinNode::DolphinNode(void): next(nullptr)
{} // Initializer list ensures next is null


// Post: Returns whatever the next pointer is pointing to(nullptr or dolphin)
DolphinNode*& DolphinNode::get_next(void)
{
	 return this->next;
}



// Post: Sets the next pointer to the given dolphin argument
int DolphinNode::set_next(DolphinNode*& a_dolphin_node)
{
	 this->next = a_dolphin_node;
	 return 1;
}



// Post: Returns whether the Dolphin next ptr is null or not
bool DolphinNode::has_next(void) const
{
	 return this->next;
}



// GORILLA FUNCTIONS:

// Gorilla base constructor
Gorilla::Gorilla(void)
{
	 arm_power = get_rand();
	 hand_size = get_rand();
	 foot_grip = get_rand();
}



// Gorilla destructor
Gorilla::~Gorilla(void)
{
	 arm_power = hand_size = foot_grip = 0;	
}



// Post: Returns a score based on the ClimbRace emphasized characteristics
int Gorilla::calculate_score(void)
{
	 int score = (((3 * speed) + (6 * agility) + (10 * strength) +
					(8 * age) + (8 * weight) + (10 * hand_size) + (10 * arm_power) +
					(10 * foot_grip)) / 100) + get_rand();
	 current_score += score;
	 return current_score;
}



// Post: Displays gorilla info and stats
int Gorilla::display(void) const
{
	 Animal::display();
	 cout << "Arm Power: " << arm_power << endl;
	 cout << "Hand Size: " << hand_size << endl;
	 cout << "Foot Grip: " << foot_grip << endl;
	 cout << endl;
	 return 1;
}



// Displays the Gorilla current score
int Gorilla::display_score(void) const
{
	 cout << "\nContestant: " << name << endl;
	 cout << "Boulders Climbed: " << current_score << endl;
	 return 1;
}

