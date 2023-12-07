#include "concept.h"

// Chase Verbout
// CS202 Spring 2022
// Program 3
// BST.h

// This file contains the Node, derivative bNode and BST class declarations.
// The Node class contains the proper functionality to operate with a Concept
// derivative including various equality and relational operation overloads. 
// The BST affords both BST and LLL functionality through the use of both
// Nodes and bNodes. It's an intriguing implementation that was more fun in
// concept than the actual programming process.


// This is the base class node that contains LLL node functionality
class Node
{
	 public:
		  Node();
		  ~Node();
		  Node*& get_next(void);
		  void set_next(Node*&);
		  bool has_next(void) const;
		  void display(void) const;
		  bool match(const std::string) const;
		  void add(Concept*&);
		  void swap(Node*);
		  void listAdd(const std::string);

		  bool operator > (const Concept &) const;
		  bool operator < (const Concept &) const;
		  bool operator >= (const Concept &) const;
		  bool operator <= (const Concept &) const;

		  bool operator > (const std::string) const;
		  bool operator < (const std::string) const;
		  bool operator >= (const std::string) const;
		  bool operator <= (const std::string) const;
		  bool operator == (const std::string) const;
		  bool operator != (const std::string) const;

	 protected:
		  Concept *data;
		  Node *next;
};	



// This is the derivative bNode that contains BST node functionality + LLL node functionality 
class bNode : public Node
{
	 public:
		  bNode();
		  ~bNode();
		  bNode*& get_left(void);
		  void set_left(bNode*&);
		  bNode*& get_right(void);
		  void set_right(bNode*&);

	 protected:
		  bNode *left;
		  bNode *right;
};	



class BST
{
	 public:
		  BST(void);
		  ~BST(void);
		  void insert(Concept*&);
		  void addMethod(const std::string, const std::string, const std::string);
		  void remove(const std::string, const std::string);
		  void display(const std::string) const;
		  void display_all(void) const;
	 protected:
		  bNode * root;

		  // BST Recursive
		  void insert(bNode*&, Concept*&);
		  void remove(bNode*&, const std:: string, const std::string);
		  void remove(bNode*&);
		  void display(bNode*, const std::string) const;
		  void display_all(bNode*) const;
		  void addMethod(bNode*, const std::string, const std::string, const std::string);
		  void remove_all(bNode*&);	

		  // LLL Recursive
		  void display(Node*) const;
		  void remove_all(Node*&);
		  void remove(Node*, Node*&, const std::string);		
		  void addMethod(Node*, const std::string, const std::string);

};


// UI functions
char menu(void);
bool goodbye(void);
bool yes_no(void);
bool translate(char option, BST &user_BST);
