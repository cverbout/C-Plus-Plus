#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

// Chase Verbout
// CS 163
// Program 5
// graph.h

// This is the header file for the graph ADT. In this file we have
// the UI funciton prototypes that are used for the interface, The
// structs for our node and vertex, and the class for our graph.
// Nodes contain a vertex pointer and a node pointer.
// Vertexes contain a char pointer for concept name and a node
// pointer for the head of the list.
// Graphs contain a pointer to what will be an array of vertexes,
// an int for the vertex amount limit and a current counter for
// vertexes added.

// UI Function Prototypes
bool yes_no(void);
bool translate(char response, class graph& user_graph);
void goodbye(void);
char menu(void);

// Structures
struct node
{
	 struct vertex * adjacent;
	 node * next;
};

struct vertex
{
	 char * concept;
	 node * head;
};

// CLASS INTERFACE
class graph 
{
	 public:
		  graph(int size);
		  ~graph(void);
		  int build(char * name_toadd);
		  int insert(char * concept_one, char * concept_two);
		  int display(void);
		  bool isFull(void);

	 private:
		  int display_edgelist(node * head);
		  int connect(node * & head, vertex * & c2);
		  void remove_list(node * & head);

		  vertex * adjacency_list;
		  int adj_size;
		  int vertex_count;
};

