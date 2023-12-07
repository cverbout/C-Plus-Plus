#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//Chase Verbout
//CS162
//program 2
//10/21/2021
//
//************************************************************************************************
//This program will allow the university to encode how they offer courses and help user's decipher
//what those course offering designators mean. It will asssess the course for Remote,
//Attend Anywhere, In-person, Hybrid, and Non-occuring activities. The user can continue to use
//the program as long as they would like.
//************************************************************************************************
//Constants
//The size limit for the whole class input
int SIZE {201};
//The size of smaller sub arrays
int SMALLSIZE {21};

//Prototypes
void welcome();
void instructions();
int get_class(char[]);
void yes_no(char&);
void extract_cname(int&, char[], int, char[]);
void extract_class_type(int&, char&, char[], int);
void type_output(char, char[]);
void hybrid_extractor(int&, char[], int);
void hybrid_display(char[], char, int);
void display_helper(char[], char);
bool again(int&);

int main()
{
	 //Variables
	 //The array to hold course input from the user
	 char classArr[SIZE];
	 //The length of the course input from the user
	 int classLen {0};
	 //The array to hold the name of the course
	 char courseName[SMALLSIZE];
	 //A counter to keep track of the index we left off at in the
	 //course array
	 int count {0};
	 //A char to differentiate which type of class has been entered
	 char class_type {'a'};

	 welcome();
	 do
	 {
		  instructions();
		  classLen = get_class(classArr);
		  extract_cname(count, classArr, classLen, courseName);	
		  extract_class_type(count, class_type, classArr, classLen);
		  type_output(class_type, courseName);

		  if ('h' == class_type)
			   hybrid_extractor(count, classArr, classLen);

	 } while (again(count));

	 return 0;
}



//This function returns the welcome paragraph explaining the basics of using the app
void welcome()
{
	 cout << endl << "Welcome to the class encoder!" << endl << endl;
	 cout << "You will enter in a class and its designation as a single sentence. The format "
		  << "will be the class name followed by \"R\" for remote, \"AA\" for attend anywhere "
		  << ", left blank for in-person, or \"Hybrid\" for a mixture. If the class is hybrid "
		  << "follow with a list of each activity, a dash(-), and the specific indicator. if "
		  << "the activity is in-person do not list it at all and if the activity is not "
		  << "occuring use \"N\" otherwise, \"R\" and \"AA\" have their same meaning. These are "
		  << "the activities we check: \"Lec\" (Lecture), \"Lab\", \"Ex\" (Exams), and \"Mat\" "
		  << "(Course Materials)." << endl << endl;
	 cout << "Ex: CS162 Hybrid: Lab-R, Ex-N, Mat-R" << endl << endl;
}



//This function gives the user the opportunity to see more information about
//the program
void instructions()
{	
	 //A local repsonse variable to record if they want to see more instructions
	 char response {'n'};

	 cout << "Would you like to see a designator guide and more examples?";
	 yes_no(response);
	 if ('Y' == response) {
		  cout << "R : Remote - fully online" << endl;
		  cout << "AA : Attend Anywhere - online and remote available" << endl;
		  cout << "Blank (do not type blank): In-Person - in-person only" << endl;
		  cout << "Hybrid - a mix of in-person, AA and R activities" << endl;
		  cout << "In-Person example: CS163" << endl;
		  cout << "Remote example: CS163 R" << endl;
		  cout << "Hybrid example: CS163 Hybrid: Lec-AA, Lab-N, Ex-R, Mat-R" << endl << endl;
	 }
}



//This function allows the user to enter in their class and will repeat the
//proccess if they do not like what they typed in.
int get_class(char classArr[])
{
	 //A local repsonse variable to record if their input was correct
	 char response {'n'};
	 do
	 {
		  cout << "Enter class: ";
		  cin.get(classArr, SIZE, '\n');
		  cin.ignore(100, '\n');
		  cout << endl << "You entered: " << classArr << endl;
		  cout << endl << "Is this correct?"; 
		  yes_no(response);
	 } while ('N' == response);

	 return strlen(classArr);
}



//This is a function that will record a user's response to a yes or no
//question and convert it to uppercase
void yes_no(char& response)
{
	 cout << "(y/n): ";
	 cin >> response;
	 cin.ignore(100, '\n');
	 cout << endl;
	 response = toupper(response);
}



//This fuction cycles through the course array and transfers the characters of the
//course name into a new array while moving our index counter forward. It then
//outputs the name of the course.
void extract_cname(int& count, char course[], int courseLen, char name[])
{
	 while (course[count] != ' ' && count != courseLen)
	 {
		  name[count] = course[count];
		  ++count;
	 }
	 name[count] = '\0';

	 return;
}



//This function continues from the index counter we left off at in the name
//extraction function and continues to cycle through the course array. The
//class type is extracted into a new array and analyzed to convert it into
//a character that signifies that type.
void extract_class_type(int& count, char& class_type, char classArr[], int classLen)
{
	 //This array holds the character string of the class type.
	 char typeArr[SMALLSIZE];
	 //This is a local index count for our type array
	 int localCount {0};

	 if (classLen != count)
	 {
		  ++count;

		  while (count != classLen && classArr[count] != ' ')
		  {
			   typeArr[localCount] = toupper(classArr[count]);
			   ++localCount;
			   ++count;
		  }
		  typeArr[localCount] = '\0';

		  if (strcmp(typeArr, "R") == 0)
			   class_type = 'r';
		  else if (strcmp(typeArr, "AA") == 0)
			   class_type = 'a';
		  else
			   class_type = 'h';
	 }
	 else
		  class_type = 'b';
}



//This function will display what the class type means for the user if it is not hybrid
void type_output(char classType, char courseName[])
{
	 cout << "This class, " << courseName << ", will be held ";

	 if ('r' == classType)
		  cout << "remotely: Lectures, Labs, Exams, and Materials will be available remotely."
			   << endl;
	 else if ('a' == classType)
		  cout << "as attend anywhere: Lectures, Labs, Exams, and Materials will be available"
			   << " remotely and in-person." << endl;
	 else if ('b' == classType)
		  cout << "in-person: Lectures, Labs, Exams, and Materials will be available in-person."
			   << endl;
	 else
		  cout << "as hybrid: ";
}



//This function is applied if the class is found to be hybrid.
//It continues cycling through the class array and extracts each activity and its type so that it
//can plug them into the display function and have the correct output displayed.
void hybrid_extractor(int& count, char classArr[], int classLen)
{
	 //This is an array to hold an activity name
	 char actArr[SMALLSIZE];
	 //This is a char to represent the activity designation
	 char actType {'a'};
	 //This is a local count variable to cycle through actArr
	 int localCount {0};
	 //This int keeps track of how many activities were used 
	 int numActs {0};

	 ++count;
	 while (count != classLen)
	 {
		  ++numActs;
		  localCount = 0;

		  while (classArr[count] != '-')
		  {
			   if(classArr[count] != ' ' && classArr[count] != ',')
			   {
					actArr[localCount] = toupper(classArr[count]);
					++localCount;
			   }
			   ++count;
		  }
		  actArr[localCount] = '\0';
		  ++count;
		  actType = toupper(classArr[count]);	

		  if (actType == 'A')
			   ++count;		

		  ++count;
		  hybrid_display(actArr, actType, numActs);
	 }
	 if (numActs < 4)
		  cout << "and all remaining activites will be in-person." << endl;
}



//This function takes in the activity array and activity type to determine the correct output
//It uses the numeber of activies outputed for contextual grammar decisions.
void hybrid_display(char actArr[], char actType, int numActs)
{									
	 if (numActs - 1 == 3)
		  cout << "and ";

	 if (strcmp("LAB", actArr) == 0)
		  cout << "Labs";
	 else if (strcmp("LEC", actArr) == 0)
		  cout << "Lectures";
	 else if (strcmp("MAT", actArr) == 0)
		  cout << "Class Materials";
	 else 
		  cout << "Exams";

	 if ('R' == actType)
		  cout << " will be available remotely";
	 else if ('A' == actType)
		  cout << " will be available attending anywhere";
	 else if ('N' == actType)
		  cout << " will be non-occuring";

	 if (numActs == 4)
		  cout << ".";
	 else
		  cout << ", ";
}



//A function to record if the user would like to repeat the proccess and if not
//thanks them for using it.
bool again(int& count)
{
	 bool goAgain {false};
	 char response {'n'};

	 cout << endl << "Would you like to do this again?";
	 yes_no(response);

	 if (response == 'Y')
	 {
		  goAgain = true;
		  count = 0;
	 }
	 else 
		  cout << "Thank you for using this application!" << endl;

	 return goAgain;
}

