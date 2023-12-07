#pragma once
#include <array>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <iostream>
#include <cctype>
#include <cstring>

// Chase Verbout
// CS202 Spring 2022
// program 3
// error.h

// This file contains the exception handling error structs

// For detecting bad outputs
struct BAD_OUTPUT
{
	 std::string message{"\nBad output detected\n"};
};

// For detecting a bad input
struct BAD_INPUT
{
	 std::string message{"\nBad input detected\n"};
};

// For detecting if something already exists
struct ALREADY_EXISTS
{
	 std::string message{"\nExisting variable detected - try a different function\n"};
};
