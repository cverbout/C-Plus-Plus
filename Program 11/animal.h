#pragma once
#include <string>
using namespace std;

const int SIZE = 5;
const int SCALE = 10;
// Chase Verbout
// CS202 Spring 2022
// Program 1
// animal.h
//
// This file contains the animal class definition as well as
// its derived classes: cheetah, dolphin, and gorilla. These classes
// were created to operate with the Contest class hierarchy.

// The Animal class establishes the common characterstics of an animal
// object. It also holds a shared function to get a random number in the
// range of the ratings we want.
class Animal {
	 public:
		  Animal(void);
		  Animal(char*);
		  Animal(const Animal&);
		  ~Animal(void);
		  int compare(const Animal&);
		  bool give_name(void);
		  int display(void) const;
		  Animal& operator=(const Animal &);

	 protected:
		  char *name;
		  int age;
		  int weight;
		  int speed;
		  int agility;
		  int strength;
		  int current_score;

		  int get_rand(void) const;
};

// The Cheetah class is a derivative of the Animal class.
// It contains node functionality and cheetah specific characteristic
// modifications.
class Cheetah : public Animal {
	 public:
		  Cheetah(void);
		  Cheetah(const Cheetah&);
		  ~Cheetah(void);
		  bool give_sponsor(void);
		  int calculate_score(void);
		  int display(void) const;
		  int display_score(void) const;
		  Cheetah& operator=(const Cheetah &a_cheetah);

	 protected: 
		  char* sponsor;
		  int acceleration;
		  int paw_durability;
		  int leg_muscle;
};

// The CheetahNode is a derivative of the Cheetah Class.
// It contains node functionality for the Cheetah object.
class CheetahNode : public Cheetah {
	 public:
		  CheetahNode(void);
		  CheetahNode*& get_next(void);
		  int set_next(CheetahNode*&);
		  bool has_next(void);
	 protected:
		  CheetahNode* next;
};

// The Dolphin class is a derivative of the Animal class.
// It contains Dolphin specific functionality
class Dolphin : public Animal {
	 public:
		  Dolphin(void);
		  ~Dolphin(void);
		  int calculate_pace(void);
		  int display(void) const;
		  int hash_function(void) const;
		  int display_pace(void) const;

	 protected: 
		  int dorsal_height;
		  int flipper_push;
		  int fin_size;
};

// The DolphinNode is a derivative of the Dolphin Class.
// It contains node functionality for the Dolphin object.
class DolphinNode : public Dolphin {
	 public:
		  DolphinNode(void);
		  DolphinNode*& get_next(void);
		  int set_next(DolphinNode*&);
		  bool has_next(void) const;
	 protected:
		  DolphinNode* next;
};

// The Gorilla class will be store in an STL vector.
// Unlike the other animal derivatives it does not have node functionality
class Gorilla : public Animal {
	 public:
		  Gorilla(void);
		  ~Gorilla(void);
		  int calculate_score(void);
		  int display(void) const;
		  int display_score(void) const;

	 protected: 
		  int arm_power;
		  int hand_size;
		  int foot_grip;
};

