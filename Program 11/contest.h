#pragma once
#include "animal.h"
#include <vector>

// Chase Verbout
// CS202 Spring 2022
// Program 1
// contest.h

// This file contains the class declarations for the contest class and its derived
// classes: LandRace, SwimRace, ClimbRace. This file requires the use of the
// Animal class and its derivations: Cheetah, Dolphin, and Gorilla. These are
// stored in animal.h and animal.cpp.

class Contest {
	 public:
		  Contest(void);
		  bool display(void) const;
		  bool start_race(void) const;
		  bool end_race(void);
		  int add_info(void);

	 protected:
		  bool ended;
		  int first_score;
		  int second_score;
		  string name;
		  string skill;
		  string animal_type;

		  int add_info(string, string, string);
};

// CLL implamentation
class LandRace : public Contest {
	 public:
		  LandRace(void);
		  LandRace(const LandRace&);
		  ~LandRace(void);
		  bool add_cheetah(void);
		  int display_winners(void) const;
		  int display_contestants(void) const;
		  int sim_round(void) const;
		  LandRace& operator=(const LandRace&);

	 protected:
		  CheetahNode *rear;

		  int copy_construct(CheetahNode*, CheetahNode*, CheetahNode*&);
		  int remove_all(CheetahNode*&);
		  bool add_cheetah(CheetahNode*&);
		  int display_winners(CheetahNode *&, CheetahNode*, CheetahNode*) const;
		  int display_contestants(CheetahNode *&) const;
		  int sim_round(CheetahNode *&) const;
};	

// ARR of LLL Hashtable implementation
class SwimRace : public Contest {
	 public:
		  SwimRace(void);
		  SwimRace(const SwimRace&);
		  ~SwimRace(void);
		  bool add_dolphin(void);
		  int display_winners(void) const;
		  int display_contestants(void) const;
		  int sim_round(void) const;
		  SwimRace& operator=(const SwimRace&);

	 protected:
		  DolphinNode **contestants;

		  int copy_construct(DolphinNode*, DolphinNode *&);
		  int remove_all(DolphinNode*&);
		  int sim_round(DolphinNode*&) const;
		  bool add_dolphin(DolphinNode*&);
		  int display_winners(DolphinNode *, DolphinNode*&, DolphinNode*&) const;
		  int display_contestants(DolphinNode *) const;
};	

// STL Vector
class ClimbRace : public Contest {
	 public:
		  bool add_gorilla(void);
		  int display_winners(void);
		  int display_contestants(void);
		  int sim_round(void);
		  ClimbRace& operator=(const ClimbRace&);

	 protected:
		  vector<Gorilla> contestants;
};	

// UI Function Prototypes
bool yes_no(void);
bool translate(char response, class LandRace& user_lr, class SwimRace& user_sr, ClimbRace& user_cr);
bool goodbye(void);
char menu(void);
