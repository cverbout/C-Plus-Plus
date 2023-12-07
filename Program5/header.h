#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//Chase Verbout
//CS162
//
//This is the header file for program 5 in CS162.
//This program will help a user summarize interesting syntax that was learned
//during the term. it uses a structure to group together data about concept names,
//exampls, descriptions, difficulty level, and frequency rating. In addition to
//this, it uses a list class that will provide dynamic storage.The user will be
//able to add new syntax items, display them, search for a specific difficulty,
//and edit existing items. 
//
//***ADDED IN PROGRAM 5***
//This program will now contain a LLL that keeps track of the entries in a alphabetic
//order and will allow the user to display them in such a way as well.
//
//Constants
const int SMALL {20};
const int MEDIUM {100};
const int LARGE {200};

//Structures
struct syntax
{
	 char name[SMALL];
	 char example[MEDIUM];
	 char description[LARGE];
	 int difficulty;
	 int frequency;
};

struct node
{
	 node * next;
	 syntax data;
};

//Classes
class syntax_list
{
	 public:
		  syntax_list();
		  ~syntax_list();
		  void add_syntax();
		  void display_all();
		  void display_LLL();
		  void display_difficulty(int);
		  void edit_syntax(char[]);
	 private:
	      void sort_syntax();
		  syntax * array;
		  int size;
		  int count;
		  node * head;
};

//Prototypes
char menu();
bool translate(char, syntax_list&);
bool yes_no();
void goodbye();


