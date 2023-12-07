#include "error.h"
// Chase Verbout
// CS202 Spring 2022
// Program 3
// concept.h

// This file contains the Concept Class along with its derivative classes:
// STL, Modern, Python. The Concept class is an Abstract Base Class.
// This hierarchy utilizes dynamic binding as seen through the virtual functions.

// This is the ABC Concept class
// It will ensure all derivatives have add, display, and match functionality

// static array size for UI
const int TEMP{100};

class Concept
{
	 public:
		  Concept(void);
		  virtual ~Concept(void);
		  void addRate(const int);
		  void addWebsite(const std::string);
		  void reset(void);
		  bool operator == (const Concept &) const;
		  bool operator != (const Concept &) const;
		  bool operator > (const Concept &) const;
		  bool operator < (const Concept &) const;
		  bool operator >= (const Concept &) const;
		  bool operator <= (const Concept &) const;

		  bool operator == (const std::string) const;
		  bool operator != (const std::string) const;
		  bool operator > (const std::string) const;
		  bool operator < (const std::string) const;
		  bool operator >= (const std::string) const;
		  bool operator <= (const std::string) const;

		  virtual void add(const std::string, const std::string, const std::string, const std::string, const int) = 0;
		  virtual void display(void) const = 0;
		  virtual bool match(const std::string) = 0;	
		  virtual void displayDescriptive(void) const = 0;

	 protected:
		  std::string website;
		  int rate;
};



// This is the STL Class - derivative of Concept
// It represents C++ Standard Template Library resources
class STL : public Concept 
{
	 public:
		  STL(void);
		  ~STL(void);
		  void add(const std::string, const std::string, const std::string, const std::string, const int);
		  void displayDescriptive(void) const;
		  bool match(const std::string);	
		  void display(void) const;
		  //void add_method(const std::string, const std::string);

	 protected:
		  std::string keyword;
		  std::vector<std::array<std::string, 2>> methods;
};



// This is the Modern Class - derivative of Concept
// It represents Modern C++ programming resources
class Modern : public Concept 
{
	 public:
		  Modern(void);
		  ~Modern(void);
		  void add(const std::string, const std::string, const std::string, const std::string, const int);
		  void displayDescriptive(void) const;
		  bool match(const std::string);	
		  void display(void) const;
	 protected:
		  std::string description;
		  std::array<std::string, 2> prosAndCons;
};



// This is the Python Class - derivative of Concept
// It represents Python programming resources
class Python : public Concept 
{
	 public:
		  Python(void);
		  ~Python(void);
		  void add(const std::string, const std::string, const std::string, const std::string, const int);
		  void displayDescriptive(void) const;
		  bool match(const std::string);	
		  void display(void) const;
		  void addMethod(const std::string);
	 protected:
		  std::string library;
		  std::string description;
		  std::list<std::string> methods;
};

