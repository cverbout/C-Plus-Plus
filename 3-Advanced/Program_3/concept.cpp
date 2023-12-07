#include "concept.h"
using namespace std;

// Chase Verbout
// CS202 Spring 2022
// Program 3
// concept.cpp

// This file contains the Concept Abstract Base Class(ABC) function definitions and its
// derivative classes: STL, Modern, Python. There are 4 functionst that have been written as
// pure virtual and thus operate different internally from derivaitive to derivative. The Concept
// class accordingly cannot exist on it's own and will not afford construction.


// Concept Constructor
Concept::Concept(void) : website(""), rate(0)
{}



// Concept Destructor
Concept::~Concept(void)
{
	 website.clear();
	 rate = 0;
}



// Adds a rate to the Concept object given an int
void Concept::addRate(const int rating)
{
	 BAD_INPUT bad_input;
	 if (rating < 0 || rating > 10)
		  throw bad_input;

	 rate = rating;	
	 return;
}



// Adds a website to the concept object given a string
void Concept::addWebsite(const string a_website)
{
	 BAD_INPUT bad_input;
	 if (a_website == "")
		  throw bad_input;

	 website = a_website;	
}



void Concept::reset(void)
{
	 website.clear();
	 rate = 0;
}



// Returns true if the given concept has the same website
bool Concept::operator == (const Concept & a_concept) const
{
	 return a_concept.website == website;
}



// Returns true if the given Concept does not have the same website as this one
bool Concept::operator != (const Concept & a_concept) const
{
	 return a_concept.website != website;
}



// Returns true if website is alphabetically larger than the given concept's
bool Concept::operator > (const Concept & a_concept) const
{
	 return website > a_concept.website;

}



// Returns true if website is alphabetically smaller than the given concept's
bool Concept::operator < (const Concept & a_concept) const
{
	 return website < a_concept.website;
}



// Returns true if website is alphabetically larger than or equal to the given concept's
bool Concept::operator >= (const Concept & a_concept) const
{
	 return website >= a_concept.website;

}



// Returns true if website is alphabetically smaller than or equal to the given concept's
bool Concept::operator <= (const Concept & a_concept) const
{
	 return website <= a_concept.website;
}



// Operator overload "==" compares this website to a given string
bool Concept::operator == (const string a_website) const
{
	 return website == a_website;
}



// Operator overload "!=" compares this website to a given string
bool Concept::operator != (const string a_website) const
{
	 return website != a_website;
}



// Operator overload '>' Compares this website to a given website
bool Concept::operator > (const string a_website) const
{
	 return website > a_website;

}



// Operator overload '<' Compares this website to a given website
bool Concept::operator < (const string a_website) const
{
	 return website < a_website;
}



// Operator overload '>=' Compares this website to a given string
bool Concept::operator >= (const string a_website) const
{
	 return website >= a_website;

}



// Operator overload '<=' Compares this website to a given string
bool Concept::operator <= (const string a_website) const
{
	 return website <= a_website;
}



// STL Constructor
STL::STL(void): keyword(""), methods()
{} 



// STL Destructor
STL::~STL(void)
{
	 keyword.clear();
	 methods.clear();
}



// add info to and STL given 4 strings
void STL::add(const string addWebsite, const string addKeyword, const string addMethod, const string addDesc, const int addRate)
{
	 BAD_INPUT bad_input;
	 if (addWebsite == "" || addKeyword == "" || addMethod == "" || addDesc == "")
		  throw bad_input;

	 website = addWebsite;
	 rate = addRate;
	 keyword = addKeyword;
	 array<string, 2> tempArr = {addMethod, addDesc};
	 methods.push_back(tempArr);
	 return;
}



// Display Keyword for this STL
void STL::displayDescriptive(void) const
{
	 cout << "\nKeyword: " << keyword;
	 return;
}



// Display all STL info including all methods and descriptions
void STL::display(void) const
{
	 cout << "\nWebsite: " << website;
	 cout << "\nRate: " << rate;
	 displayDescriptive();
	 for (auto elem : methods)
	 {
		  cout << "\nMethod: " << elem[0];
		  cout << "\nDescription: " << elem[1];
	 }
	 return;
}



// If the keyword matches the given string, display it
bool STL::match(const string a_keyword)
{
	 if (a_keyword == keyword)
		  return true;
	 return false;
}



// Modern Constructor
Modern::Modern(void) : description(""), prosAndCons() 
{}



// Modern Destructor
Modern::~Modern(void)
{
	 website.clear();
	 description.clear();
}



// Add info to Modern given 4 strings
void Modern::add(const string addWebsite, const string addDesc, const string addPros, const string addCons, const int addRate)
{
	 BAD_INPUT bad_input;
	 if (addWebsite == "" || addDesc == "" || addPros == "" || addCons == "")
		  throw bad_input;

	 website = addWebsite;
	 rate = addRate;
	 description = addDesc;
	 prosAndCons[0] = addPros;
	 prosAndCons[1] = addCons;
	 return;
}



// Display all of this Modern objects information
void Modern::display(void) const
{
	 cout << "\nWebsite: " << website;
	 cout << "\nRate: " << rate;
	 displayDescriptive();
	 cout << "\nPros: " << prosAndCons[0];
	 cout << "\nCons: " << prosAndCons[1];
	 return;
}



// Display Keyword for this Modern
void Modern::displayDescriptive(void) const
{
	 cout << "\nDescription: " << description;
	 return;
}



// If the string given matches this objects website, display
bool Modern::match(const string a_website)
{
	 if (a_website == website)
		  return true;
	 return false;
}



// Python Constructor
Python::Python(void) : library(""), description("")
{}



// Python Destructor
Python::~Python(void)
{
	 website.clear();
	 library.clear();
	 description.clear();
}



// Add info to a Python Object given 4 strings
void Python::add(const string addWebsite, const string addLibrary, const string addDesc, const string addMethod, const int addRate)
{
	 BAD_INPUT bad_input;
	 if (addWebsite == "" || addLibrary == "" || addDesc == "" || addMethod == "")
		  throw bad_input;

	 website = addWebsite;
	 rate = addRate;
	 library = addLibrary;
	 description = addDesc;
	 methods.push_back(addMethod);	
	 return;
}



// Display all info of this Python object
void Python::display(void) const
{
	 cout << "\nWebsite: " << website;
	 cout << "\nRate: " << rate;
	 displayDescriptive();
	 cout << "\nMethods: ";
	 for (auto method : methods)
		  cout << "\n" << method;
	 return;
}



// Display Library and Description for this Python
void Python::displayDescriptive(void) const
{
	 cout << "\nLibrary: " << library;
	 cout << "\nDescription: " << description;
	 return;
}



// If the given string matches this objects library, display
bool Python::match(const string a_library)
{
	 if (library == a_library)
		  return true;
	 return false;
}



// Add the given string to this python objects method list
void Python::addMethod(const string a_method)
{
	 BAD_INPUT bad_input;
	 if (a_method == "")
		  throw bad_input;

	 methods.push_back(a_method);	
	 return;
}

