#include "BST.h"
using namespace std;

// Chase Verbout
// CS202 Spring 2022
// Program 3
// main.cpp

// The purpose of this file is to test out the functionality of program 3

// Current testing is on interface to demonstrate various functionalities
// NON INTERFACE TESTING BELOW

int main()
{
	 //response variable that keeps track of user's menu selection.
	 char response {'z'};

	 cout << "\n\n\n\n\n";
	 cout << "Welcome to Programmer's Pallette" << endl;
	 //constructs the user's bst for them to interact with.
	 BST user_BST;

	 cout << "Please select an option from the menu below." << endl << endl;
	 do
	 {
		  response = menu();
	 } while (translate(response, user_BST));	

	 // PRE-UI TESTING BELOW

	 /*
		Modern m1;
		m1.add("zoogle.com", "This is for effeciency handling practices", "Credible authors", "Difficult to understand");
		Concept * cptr = &m1;
		STL s1;
		s1.add("google.com", "vector", "push_back()", "add to the end of the vector");
		Concept * cptr2 = &s1;
		Modern m2;
		m2.add("aoogle.com", "This is for effeciency handling practices", "Credible authors", "Difficult to understand");
		Concept * cptr3 = &m2;
		BST bst;
		bst.insert(cptr);
		bst.insert(cptr2);
		bst.insert(cptr3);
		bst.display_all();
	  */
	 /*
		Node *nodey = new Node;
		Modern m1;
		m1.add("google.com", "This is for effeciency handling practices", "Credible authors", "Difficult to understand");
		Concept * cptr = &m1;
		nodey->add(cptr);

		Node *nodey2 = new Node;
		STL s1;
		s1.add("google.com", "vector", "push_back()", "add to the end of the vector");
		Concept * cptr2 = &s1;
		nodey2->add(cptr2);
		nodey->set_next(nodey2);
		Node *temp = nodey;
		temp->display();
		temp = nodey->get_next();
		temp->display();
	  */
	 /*
		STL stl;
		Modern m1;
	 //Concept * cptr = &stl;
	 Concept * cptr = &m1;
	 Modern * mptr = dynamic_cast<Modern*>(cptr);
	 if (mptr)
	 {
	 mptr->add("google.com", "This is for effeciency handling practices", "Credible authors", "Difficult to understand");
	 mptr->display();
	 mptr->match("google.com");
	 }

	 STL * sptr = dynamic_cast<STL*>(cptr);
	 if (sptr)
	 {
	 sptr->add("google.com", "vector", "push_back()", "add to the end of the vector");
	 sptr->display();
	 sptr->match("vector");
	 }
	  */

	 return 0;
}
