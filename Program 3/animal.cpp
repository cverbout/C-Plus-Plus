#include "header.h"

//Chase Verbout
//CS162
//
//This file holds all of the functions that work with the animal strucure
//This includes adding new animals, displaying all animals, and searching
//specific breeds
//

void add_animal(animal zoo[], int& count)
{
	 if (9 >= count)
	 {
		  cout << "Animal breed: ";
		  cin.get(zoo[count].breed, MEDIUM, '\n');
		  cin.ignore(100, '\n');
		  cout << endl;

		  cout << "Animal Species: ";
		  cin.get(zoo[count].species, MEDIUM, '\n');
		  cin.ignore(100, '\n');
		  cout << endl;

		  cout << "Animal Service: ";
		  cin.get(zoo[count].service, MEDIUM, '\n');
		  cin.ignore(100, '\n');
		  cout << endl;

		  cout << "Special Information: ";
		  cin.get(zoo[count].sinfo, LARGE, '\n');
		  cin.ignore(100, '\n');
		  cout << endl;

		  cout << "Cuteness Rating: ";
		  cin >> zoo[count].cute_rating;
		  cin.ignore(100, '\n');

		  ++count;
	 }
	 else
		  cout << "There are already 10 animals in this list!";

}

void display_everything(animal zoo[], int& count)
{
	 if (count > 0)
	 {
		  cout << "-----------------------------------------------" << endl;
			   for (int i {0}; i < count; ++i)
			   {
					cout << "Animal Breed: " << zoo[i].breed << endl
						 << "Animal Species: " << zoo[i].species << endl
						 << "Animal Service: " << zoo[i].service << endl
						 << "Special Information: " << zoo[i].sinfo << endl
						 << "Cuteness Rating: " << zoo[i].cute_rating << endl;
					cout << "-----------------------------------------------"
						 << endl;
			   }
	 }
	else 
		cout << "There are no animals to show yet. Try adding one!";
}

