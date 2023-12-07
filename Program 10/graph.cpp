#include "graph.h"
using namespace std;

// Chase Verbout
// CS 163
// Program 5
// graph.cpp

// This file contains the functions for the graph class. This includes a constructor,
// a destructor, a function to add vertexes(concepts), a function to connect one concept
// to another, and display function to show all concepts and the concepts that they are
// connected to. There are private helper recursive functions and a function to check if
// the vertex limit has been reached.
/*
   class graph 
   private:
   vertex * adjacency_list;
   int adj_size;
   int vertex_count;
 */

// Constructor
// Pre: Give a valid and positive integer.
// Post: An array of the given size is constructed and ready for the build function.
graph::graph(int size)
{
	 vertex_count = 0;
	 adj_size = size;
	 adjacency_list = new vertex[adj_size];
	 for (int i = 0; i < adj_size; ++i)
	 {
		  adjacency_list[i].head = nullptr;
		  adjacency_list[i].concept = nullptr;
	 }
}



// Destructor
// Pre: Nothing
// Post: Deletes all allocated memory used by the graph
graph::~graph(void)
{
	 if (adjacency_list)
	 {
		  for (int i = 0; i < adj_size; ++i)
		  {
			   if (adjacency_list[i].concept)
			   {
					remove_list(adjacency_list[i].head);
					delete [] adjacency_list[i].concept;
					adjacency_list[i].concept = nullptr;
			   }
		  }
		  delete [] adjacency_list;
	 }
	 adjacency_list = nullptr;
	 adj_size = vertex_count = 0;
}	



// This function removes all of the nodes in a LLL and deallocated the memory
// Pre: Give the head node of a LLL
// Post: The nodes in the LLL of given node are deallocated
void graph::remove_list(node * & head)
{
	 if (!head)
		  return;
	 node * temp = head;
	 head = head->next;
	 delete temp;
	 remove_list(head);
	 return;
}



// Add information to a vertex in the adjacency list
// Pre: A valid char array
// Post: The next available vertex in the array is filled out with the given name and the space remaining is returned
int graph::build(char * name_toadd)
{
	 if (!name_toadd || this->isFull())
		  return 0;

	 adjacency_list[vertex_count].concept = new char[strlen(name_toadd) + 1];
	 strcpy(adjacency_list[vertex_count].concept, name_toadd);
	 ++vertex_count;
	 return adj_size - vertex_count;
}



// Connect a vertex to another vertex
// Pre: Two char arrays that are existing vertex names
// Post: A node is added to the first char array's vertex edge list that
// points to the second one's vertex
int graph::insert(char * concept_one, char * concept_two)
{
	 if (!concept_one || !concept_two)
		  return 0;
	 vertex * c1 = nullptr;
	 vertex * c2 = nullptr;
	 for (int i = 0; i < vertex_count; ++i)
	 {
		  if (strcasecmp(adjacency_list[i].concept, concept_one) == 0)
			   c1 = & adjacency_list[i];	
		  if (strcasecmp(adjacency_list[i].concept, concept_two) == 0)
			   c2 = & adjacency_list[i];	
	 }	
	 if (!c1 || !c2 || c1 == c2)
		  return 0;

	 return connect(c1->head, c2);
}



// Traverses the edge list LLL and adds a node to connect to the given c2 vertex
// Pre: The head node of the edge list and the location of the consequents vertex
// Post: The LLL of head now contains a node where adjacent points to vertex c2
int graph::connect(node * & head, vertex * & c2)
{
	 if (!head)
	 {
		  head = new node;
		  head->adjacent = c2;
		  head->next = nullptr;
		  return 1;
	 }
	 else if (head->adjacent == c2)
		  return 0;
	 return connect(head->next, c2);
}



// Display all vertexes
// Pre: An adjacency list with vertex entries
// Post: Displays all vertexes and their corresponding connections
int graph::display(void)
{
	 if (!adjacency_list || vertex_count == 0)
		  return 0;
	 for (int i = 0; i < vertex_count; ++i)
	 {
		  cout << "Concept #" << i + 1 << ": " << adjacency_list[i].concept << endl;
		  cout << "--------------Connected To----------------" << endl;
		  display_edgelist(adjacency_list[i].head);
		  cout << "------------------------------------------" << endl;
	 }
	 return 1;
}



// Displays each node in the edge list
// Pre: The node of a LLL
// Post: Displays the adjacent vertex of each node in the LLL
int graph::display_edgelist(node * head)
{
	 if (!head)
		  return 1;
	 cout << "Concept: " << head->adjacent->concept << endl;
	 return display_edgelist(head->next);
}



// Checks if the adjacency list is full
// Pre: Nothing
// Post: Returns true if full, false if not
bool graph::isFull(void)
{
	 if (vertex_count >= adj_size)
		  return true;
	 return false;
}

