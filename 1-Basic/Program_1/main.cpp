//Chase Verbout
//CS162
//Program Assingnment 1
//
//******************************************************
//This program will help a user calculate the total cost
//of their travel housing with the appropriate fees and
//discounts applied. It will take in the user's nightly
//rate, the number of days they are staying, and the 
//number of days until their trip. It will then output
//the result and prompt the user to quit or try again.
//******************************************************
//
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	 //variables
	 float nightlyRate{0.0}; // The nightly rate of the user's  housing
	 float baseCost{0.0};    // The cost before discounts and fees
	 float finalCost{0.0};   // The final cost of the user's inquiry
	 float discount{0.0};    // The discount based on the users answers
	 float fee{0.0};	     // The fee based on the user's answer
	 int numStaying{0};      // The number of days the users is staying
	 int daysTil{0};         // The number of days until the user's trip
	 char response{'y'};     // Keeps track of the user's response

	 // Set decimals to show and only show 2 digits
	 cout << fixed << showpoint << setprecision(2);

	 // Welcome the user
	 cout << endl << "Hello!\n" << "Welcome to the Travel"
		  << " Housing Cost Calculator!" << endl << endl;

	 // Explain how the program works
	 cout << "This program will ask you to provide the "
		  << "nightly rate of your chosen residence, the "
		  << "number of days you plan to stay, and the "
		  << "number of days before your trip." << endl
		  << endl << "It will then calculate the total cost"
		  << " of your stay after applying the appropriate"
		  << " discounts and fees." << endl << endl;

	 // Check if the user is still interested
	 cout << "Would you like to continue? (y/n): ";
	 cin >> response;
	 if ('y' == response)
	 {
		  do
		  {
			   do
			   {	    
					// Get the nightly rate, number of days staying and
					// number of days until the trip
					do
					{
						 cout << endl << "What is the nightly rate of your housing?"
							  << endl << "Nightly rate: $";
						 cin >> nightlyRate;
						 if (0 > nightlyRate)
							  cout << endl << "Error - negative input detected. Please Try Again!" << endl;
					} while (0 > nightlyRate);

					do
					{
						 cout << endl << "What is the number of days you will be staying?" << endl
							  << "Number of days: ";
						 cin >> numStaying;
						 if (0 > numStaying)
							  cout << endl << "Error - negative input detected. Please Try Again!" << endl;
					} while (0 > numStaying);

					do
					{
						 cout << endl << "How many days until your trip occurs?" << endl
							  << "Days until trip: ";
						 cin >> daysTil; 
						 if (0 > daysTil)
							  cout << endl << "Error - negative input detected. Please Try Again!" << endl;
					} while (0 > daysTil);

					// Echo their answers and ask if they look correct if not loop back and try again
					cout << endl << "Your input was:" << endl << "Nightly Rate: $"
						 << nightlyRate << ", Days Staying: " << numStaying
						 << ", and Days Until: " << daysTil << endl;

					cout << endl << "Is this correct? (y/n): ";
					cin >> response;

					// Repeat the process if the input was no or there was a negative input
			   } while ('n' == response);

			   // Calculate the base cost of their stay
			   baseCost = nightlyRate * (numStaying - 1);
			   cout << endl << "Your cost before discounts and fees is:"
					<< " $" << baseCost << endl << endl;

			   // Make sure variables are zero incase this is not the first time through
			   discount = 0.0;
			   finalCost = 0.0;
			   fee = 0.0;

			   // Calculate discounts based on user's answers
			   if (5 < daysTil)
					discount += .2;

			   if (3 < numStaying)
					discount += .1;

			   // calculate the cost after discounts
			   finalCost = baseCost * (1.0 - discount);

			   // Calculate the fees based on user's answers
			   if (3 < numStaying)
					fee += 50.00;

			   fee += finalCost * .01;

			   // Add the fees and display results to the user
			   finalCost += fee;
			   cout << "The total cost of your trip will be $" << finalCost << endl << endl;

			   // See if the user would like to repeat this proccess
			   cout << "Would you like to do this again? (y/n): ";
			   cin >> response;

		  } while ('y' == response);		

		  cout << endl << "Thank you for using this application!" << endl << endl;
	 }
	 return 0;
}
