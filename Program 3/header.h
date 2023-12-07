#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

//Chase Verbout
//CS 162
//This program allows a user to maintain a list of animals that can perform
//service activities. It will keep track of an animals breed, species,
//service, special information, and cuteness rating. The program will 
//provide a menu interface that allows a user to add animals, display
//everything, save and load files, and search for a specific breed and
//species to display.
//

//Constants
const int SMALL {10};
const int MEDIUM {30};
const int LARGE {100};

//Structures
struct animal
{
	char breed[MEDIUM];     //The breed of the animal
	char species[MEDIUM];   //The species of the animals
	char service[MEDIUM];   //The service the animal provides
	char sinfo[LARGE];      //Any informatio the user wants to include
	int cute_rating {0};  //Cuteness rating out of 10
};

//Prototypes
void welcome();
char menu();
bool translate(char, animal[], int&);
void add_animal(animal[], int&);
void display_everything(animal[], int&);
void goodbye();

