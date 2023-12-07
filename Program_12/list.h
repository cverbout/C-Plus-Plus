#pragma once
#include "reservation.h"

// Chase Verbout
// Prog 2
// CS202 Spring 2022
// list.h

// This file contains the DLL and Node Template class declarations.
// The template classes will be showcased with Zoo Reservations.
// It also contains an STL list implementation for LazerTag Reservations
// and an STL Array implementation for Dinner Reservations.

// Generic Node created for implementation in a DLL
// Uses shared_ptr for next and prev
template <typename T>
class Node 
{
	 typedef std::shared_ptr<Node<T>> node_ptr_type;

	 public:
	 Node(void);
	 Node<T>(const T &source);
	 node_ptr_type& get_next(void);
	 node_ptr_type& get_prev(void);
	 node_ptr_type& set_next(const node_ptr_type&);
	 node_ptr_type& set_prev(const node_ptr_type&);
	 bool has_next(void) const;
	 bool has_prev(void) const;
	 bool le(const T&) const;
	 bool ge(const T&) const;
	 bool less(const T&) const;
	 bool greater(const T&) const;
	 T get_data(void) const;
	 void display() const;

	 protected:
	 T data;
	 node_ptr_type next;
	 node_ptr_type prev;
};

// Generic DLL
// Uses Node in current file as well as shared_ptr from STL
// Ordered by value, least in front, largest in back
// Has head and tail variables
template <typename T>
class DLL 
{
	 typedef std::shared_ptr<Node<T>> node_ptr_type;

	 public:
	 DLL(void);
	 ~DLL(void);
	 DLL(const DLL &);
	 DLL& operator=(const DLL&);
	 int insert(const T&);
	 int display(void) const;

	 protected:
	 int copy(node_ptr_type &, node_ptr_type &, const node_ptr_type &);
	 int insert(node_ptr_type &, node_ptr_type &, const T&);
	 int display(const node_ptr_type &) const;
	 int remove_all(node_ptr_type &);

	 node_ptr_type head;
	 node_ptr_type tail; 
};

// LazerTag List - Uses STL list
// Ordered by value, least in front, largest in back
// Works with LazerTag class in reservation.h
class LTL
{
	 public:
		  LTL(void);
		  bool display(void) const;
		  int insert(const LazerTag&);
		  bool find_team(const char*);
		  bool remove_team(const char*);	

	 protected:
		  std::list<LazerTag> reservations;
};

// Dinner Deque - Uses STL deque
// Ordered by value, least in front, largest in back
// Works with Dinner class in reservation.h
class DinDeque
{
	 public:
		  DinDeque(void);
		  bool display(void);
		  int insert(const Dinner&);
		  bool add_person(const char*, const int);
		  bool remove_person(const char*, const int);
		  bool place_order(const char*, const std::string);

	 protected:
		  std::deque<Dinner> reservations;
};

// UI Function Prototypes
// ~Only for function demonstration in ui.cpp~
bool yes_no(void);
bool translate(char response, class DLL<Zoo> &user_DLL, class LTL &user_LTL, class DinDeque &user_DD);
bool goodbye(void);
char menu(void);

#include "list.tpp"

