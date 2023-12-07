#pragma once
#include "error.h"

// Chase Verbout
// CS202 Spring 2022
// Prog 2
// reservation.h
//
// This file contains the reservation parents class declaration as well as its derivatives:
// LazerTag, Zoo, Dinner.
// It also contains the UI functions at the bottom

// Size of temp arrays in ui.cpp interface
const int TEMP{100};

// Reservation Base Class that can be created, displayed, and altered
// Holds a name and time variable
class Reservation
{
	 public:
		  Reservation(void);
		  Reservation(const Reservation &);
		  ~Reservation(void);
		  void display(void) const;
		  void add_reservation(const char *, const int, const int);
		  void change_name(const char *);
		  void change_time(const int, const int);
		  Reservation& operator = (const Reservation &);
		  bool operator == (const char* a_name) const;
		  bool operator != (const char* a_name) const;
		  bool operator >= (const Reservation &) const;
		  bool operator <= (const Reservation &) const;;
		  bool operator > (const Reservation &) const;
		  bool operator < (const Reservation &) const;

		  friend std::ostream& operator << (std::ostream&, const Reservation &);
		  friend std::istream& operator >> (std::istream& in, Reservation &);

	 protected:
		  char * user_name;
		  std::array<int, 2> time;
};

// Derivative of Reservation class
// Can be created, changed, displayed, and be equality assessed by team name
// Holds a team_name and team_size  
class LazerTag : public Reservation
{
	 public:
		  LazerTag(void);
		  LazerTag(const LazerTag &);
		  ~LazerTag(void);
		  void display(void) const;
		  void add_lazertag(const char *, const int);
		  void add_lazertag(const char*, const int, const int, const char*, const int);
		  int change_team_size(const int);
		  char* change_team_name(const char *);
		  LazerTag & operator=(const LazerTag &);
		  bool operator == (const char*) const;
		  bool operator != (const char*) const;

		  friend std::ostream& operator << (std::ostream&, const LazerTag&);
		  friend std::istream& operator >> (std::istream&, LazerTag&);

	 protected:
		  char * team_name;
		  int team_size;
};

// Derivative of Reservation class
// Can be created, changed, displayed
// Holds an exhibits_visited and member_status variable
class Zoo : public Reservation
{
	 public:
		  Zoo(void);
		  void display(void) const;
		  void add_zoo(const std::string, const bool);
		  void add_zoo(const char *, const int, const int, const std::string, const bool);
		  std::string change_exhibits(const std::string);
		  bool change_member_status(const bool);
		  Zoo& operator += (const std::string);
		  Zoo operator + (const std::string) const;

		  friend std::ostream& operator << (std::ostream&, const Zoo&);
		  friend std::istream& operator >> (std::istream&, Zoo&);

	 protected:
		  std::string exhibits_visiting;
		  bool member_status;
};

// Derivative of Reservation class
// Can be created, changed, displayed
// Holds a pre_order and party_size variable
class Dinner : public Reservation
{
	 public: 
		  Dinner(void);
		  void display(void) const;
		  void add_dinner(const std::string, const int);
		  void add_dinner(const char*, const int, const int, const std::string, const int);
		  std::string change_pre_order(const std::string);
		  int change_party_size(const int);
		  Dinner& operator += (const int);
		  Dinner& operator -= (const int);
		  Dinner operator + (const int) const;
		  Dinner operator - (const int) const;

		  friend std::ostream& operator << (std::ostream&, const Dinner&);
		  friend std::istream& operator >> (std::istream&, Dinner&);

	 protected:
		  std::string pre_order;
		  int party_size;
};

