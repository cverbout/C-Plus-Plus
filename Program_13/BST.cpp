#include "BST.h"
using namespace std;

// Chase Verbout
// CS202 Spring 2022
// Program 3
// BST.cpp

// This file contains the Node and bNode derivative in addtion to
// the BST class defintions. The bNode contains BST node functionality (left and right)
// while the Node conatins LLL functionality (next). In this way the BST is able to use both
// bNodes and Nodes to effectivly operate as a BST with nodes that contain LLLs of duplicate website
// data. The deciscion to try and imlplement 2 data strucutres in one class, while fun and interesting,
// has left this implementation more complicated than one should be. Duly noted.


// Node Constructor
Node::Node(void) : data(nullptr), next(nullptr)
{}



// Node Destructor
Node::~Node(void)
{
	 if (data)
		  delete data;
	 next = nullptr;
}



// Returns this Node's next node
Node*& Node::get_next(void)
{
	 return this->next;
}



// Sets this Node's next ptr
void Node::set_next(Node*& a_node)
{
	 next = a_node;
	 return;
}



// Returns true if this Node's next ptr is a Node
bool Node::has_next(void) const
{
	 return next;
}



// Point this Node's data to the given concept derivation
void Node::add(Concept*& a_concept)
{
	 BAD_INPUT bad_input;
	 ALREADY_EXISTS already_exists;

	 if (!a_concept)
		  throw bad_input;
	 if (data)
		  throw already_exists;


	 data = a_concept;
	 return;
}



// swaps the data in this node with that in another
void Node::swap(Node* a_Node)
{
	 BAD_INPUT bad_input;
	 if (!data || !a_Node->data)
		  throw bad_input;

	 Concept * temp = this->data;
	 data = a_Node->data;
	 a_Node->data = temp;
	 return;
}



// Display this Node's data
void Node::display(void) const
{
	 BAD_OUTPUT bad_output;
	 if (!data)
		  throw bad_output;

	 data->display();
	 return;
}



// Display this Node if its data matches the given string
bool Node::match(const string toMatch) const
{
	 BAD_OUTPUT bad_output;
	 if (!data)
		  throw bad_output;

	 return data->match(toMatch);
}



// Add a method to an existing Python concept
void Node::listAdd(const string toAdd)
{
	 // Dynamic casting 

	 Python * pptr = dynamic_cast<Python*>(data);
	 if (pptr)
		  pptr->addMethod(toAdd);

	 return;
}



// Operator overload '>' Compares this data's website to a given concept's
bool Node::operator > (const Concept & a_concept) const
{
	 return *data > a_concept;

}



// Operator overload '<' Compares this data's website to a given concept's
bool Node::operator < (const Concept & a_concept) const
{
	 return *data < a_concept;
}



// Operator overload '>=' Compares this data's website to a given concept's
bool Node::operator >= (const Concept & a_concept) const
{
	 return *data >= a_concept;

}



// Operator overload '<=' Compares this data's website to a given concept's
bool Node::operator <= (const Concept & a_concept) const
{
	 return *data <= a_concept;
}



// Operator overload '>' Compares this data's website to a given string
bool Node::operator > (const string a_website) const
{
	 return *data > a_website;

}



// Operator overload '<' Compares this data's website to a given string
bool Node::operator < (const string a_website) const
{
	 return *data < a_website;
}



// Operator overload '>=' Compares this data's website to a given string
bool Node::operator >= (const string a_website) const
{
	 return *data >= a_website;

}



// Operator overload '<=' Compares this data's website to a given string
bool Node::operator <= (const string a_website) const
{
	 return *data <= a_website;
}



// Operator overload "==" compares this website to a given string
bool Node::operator == (const string a_website) const
{
	 return *data == a_website;
}



// Operator overload "!=" compares this website to a given string
bool Node::operator != (const string a_website) const
{
	 return *data != a_website;
}



// bNode Constructor
bNode::bNode(void) : left(nullptr), right(nullptr)
{}



// bNode Destructor
bNode::~bNode(void)
{
	 left = right = nullptr;
}



// Returns this bNode's left ptr
bNode*& bNode::get_left(void)
{
	 return left;
}



// Set this bNodes left ptr
void bNode::set_left(bNode*& a_bNode)
{
	 left = a_bNode;
	 return;
}



// Return this bNodes right ptr
bNode*& bNode::get_right(void)
{
	 return right;
}



// Set this bNodes right ptr
void bNode::set_right(bNode*& a_bNode)
{
	 right = a_bNode;
}



// BST Constructor
BST::BST(void) : root(nullptr)
{

}



// BST Destructor
BST::~BST(void)
{
	 if (root)
		  remove_all(root);

	 root = nullptr;
}



// Inserts a given concept into the BST ordered alphabetically by website
void BST::insert(Concept*& a_concept)
{
	 BAD_INPUT bad_input;
	 if (!a_concept)
		  throw bad_input;

	 insert(root, a_concept);		
	 return;
}



// Remove the concept with a matching identifier
void BST::remove(const string website, const string identifier)
{
	 BAD_INPUT bad_input;
	 if (identifier == "" || website == "")
		  throw bad_input;

	 return remove(root, website, identifier);	
}



// Displays all entries with a matching website
void BST::display(const string website) const
{
	 BAD_INPUT bad_input;
	 BAD_OUTPUT bad_output;

	 if (website == "")
		  throw bad_input;
	 if (!root)
		  throw bad_output;

	 display(root, website);
	 return;
}



// Displays all of the items in the BST
void BST::display_all(void) const
{
	 BAD_OUTPUT bad_output;
	 if (!root)
		  throw bad_output;

	 display_all(root);
	 return;
}



// Recursively finds the correct spot to add the new concept
void BST::insert(bNode*& curr, Concept*& a_concept)
{
	 if (!curr)
	 {
		  bNode *temp = new bNode;
		  temp->add(a_concept);
		  curr = temp;
		  return;	
	 }
	 if (curr->Node::operator<(*a_concept))
		  insert(curr->get_right(), a_concept);
	 else if (curr->Node::operator>(*a_concept))
		  insert(curr->get_left(), a_concept);
	 else
	 {
		  Node *temp = new Node;				
		  temp->add(a_concept);
		  if (curr->has_next())
			   temp->set_next(curr->get_next());
		  curr->set_next(temp);
	 }
	 return;
}



// Recursively searches for the item we are trying to remove
void BST::remove(bNode*& curr, const string website, const string an_identifier)
{
	 if (!curr)
		  return;

	 if (curr->Node::operator>(website))
		  remove(curr->get_left(), website, an_identifier);
	 else if (curr->Node::operator<(website))
		  remove(curr->get_right(), website, an_identifier);
	 else
	 {
		  if (!curr->match(an_identifier))
		  {
			   Node * temp = curr;
			   remove(curr->get_next(), temp, an_identifier);		
		  }
		  else
			   remove(curr);
	 }
	 return;
}



// Recursively finds the objects with the website we are trying to display
void BST::display(bNode* curr, const string website) const
{
	 if (!curr)
		  return;	
	 if (curr->Node::operator>(website))
		  display(curr->get_left(), website);
	 else if (curr->Node::operator<(website))
		  display(curr->get_right(), website);
	 else
		  display(curr->get_next());
	 return;
}



// Recursively traverse BST and Display items by alphabetic order (website)
void BST::display_all(bNode* curr) const
{
	 if (!curr)
		  return;

	 display_all(curr->get_left());
	 curr->display();
	 cout << "\n";
	 if (curr->has_next())
		  display(curr->get_next());	
	 display_all(curr->get_right());
	 return;	
}



// Recursively remove all Nodes and bNodes in the BST
void BST::remove_all(bNode*& curr)
{
	 if (!curr)
		  return;

	 remove_all(curr->get_left());
	 remove_all(curr->get_right());
	 if (curr->has_next())
		  remove_all(curr->get_next());	

	 delete curr;
	 curr = nullptr;
	 return;
}



// Recursively display any items with the same website placed in bNodes LLL
void BST::display(Node* curr) const
{
	 if (!curr)
		  return;
	 curr->display();
	 cout << "\n";
	 display(curr->get_next());
	 return;
}



// Recursively remove any items with the same website placed in the bNodes LLL
void BST::remove_all(Node*& curr)
{
	 if (!curr)
		  return;
	 remove_all(curr->get_next());
	 delete curr;
	 curr = nullptr;
	 return;
}



// Adds a method to an exisiting python object
void BST::addMethod(const string website, const string identifier, const string method)
{
	 addMethod(root, website, identifier, method);
	 return;
}



// Recursively finds the Python object we are trying to add to
void BST::addMethod(bNode* curr, const string website, const string identifier, const string method)
{
	 if (!curr)
		  return;
	 if (curr->Node::operator>(website))
		  addMethod(curr->get_left(), website, identifier, method);	
	 else if (curr->Node::operator<(website))
		  addMethod(curr->get_right(), website, identifier, method);
	 else
	 {
		  if (curr->match(identifier))
			   curr->listAdd(method);
		  else
			   addMethod(curr->get_next(), identifier, method);
	 }	
	 return;
}



// Recursively searches the LLL for the matching Python object to add a method
void BST::addMethod(Node* curr, const string identifier, const string method)
{
	 if (!curr)
		  return;
	 if (curr->match(identifier))
		  curr->listAdd(method);
	 addMethod(curr->get_next(), identifier, method);
	 return;
}



// Recursively searches the LLL for the matching identifier to remove
void BST::remove(Node* curr, Node*& prev, const string identifier)
{
	 if (!curr)
		  return;

	 if (curr->match(identifier))
	 {
		  prev->set_next(curr->get_next());
		  delete curr;
		  curr = nullptr;
		  return;
	 }

	 remove(curr->get_next(), curr, identifier);
	 return;
}



// This is the remove function that gets called when we find the object we want to remove.
// It works with either an object directly in the BST or an object in the LLL in the BST node.
void BST::remove(bNode*& curr)
{
	 if (!curr->has_next())
	 {
		  if (!curr->get_left() && !curr->get_right()) // The item's node is a leaf
		  {
			   delete curr;
			   curr = nullptr;
		  }
		  else if (curr->get_left() && !curr->get_right()) // The item's node has only a left child
		  {	
			   bNode * temp = curr->get_left();
			   delete curr;
			   curr = temp;
		  }
		  else if (!curr->get_left() && curr->get_right()) // The item's node has only a right child
		  {
			   bNode * temp = curr->get_right();
			   delete curr;
			   curr = temp;
		  }
		  else // The item's node has both a left and right child - find IOS
		  {
			   bNode * temp = curr->get_right(); 
			   if (!temp->get_left()) // The right child does not have a left child so we are done
			   {
					curr->get_right() = temp->get_right();
					curr->swap(temp);
					delete temp; // problem?
			   }		
			   else // The right child has a left child so traverse to the last left child node
			   {
					bNode * parent = temp; // previous pointer to the parent node of the IOS after traversal
					while (temp->get_left()) // Traverse until the left child is null
					{
						 parent = temp;
						 temp = temp->get_left();
					}
					curr->swap(temp); // Fill out deleted item's node with this IOS item info
					parent->get_left() = temp->get_right(); // Connect parent to whatever was to the right of IOS
					delete temp; // Delete the IOS node
			   }
		  }
	 }
	 else
	 {
		  Node * temp = curr->get_next();
		  curr->swap(temp);
		  curr->set_next(temp->get_next());
		  delete temp;	
	 }
}


