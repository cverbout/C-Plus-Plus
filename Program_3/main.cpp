#include "header.h"

//Chase Verbout
//CS162
//
//This files contains the main function that manages all of the other
//functions in a clear and concise order.
//
int main()
{
	//This is the array that will contain all of the animals
	animal zoo[SMALL];
	//This will keep track of the current number of animals in the array
	int count {0};
	//This variable keeps track of the user's selection in the menu
	char response {'z'};
	//This variable keeps track of whether the program should continue or not
	bool again = true;

	welcome();
	do
	{
	response = menu();
	again = translate(response, zoo, count);
	} while (again);

	goodbye();	

	return 0;
}

