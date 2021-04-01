/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: Space.hpp is the specification file for the Space class.  
** Map class is a linked list of Space objects. Member functions defined 
** in separate implementation file, Space.cpp.
*********************************************************************/
#ifndef Map_hpp
#define Map_hpp
#include "Space.hpp"
#include <string>

class Map
{
public:
	Map();					// Default constructor
	~Map();					// Class destructor
	void printIntro();		// Print space intro
	void moveForward();		// Move to next space
	void moveBackward();	// Move to prev space
	int getAction1();		// Call action1() of Space object
	int getAction2();		// Call action2() of Space object
	bool isFirstSpace();	// Check if first space in line
	bool isLastSpace();		// Check if last space in line
	std::string nameNextSpace();	// Get name of next space
	std::string namePrevSpace();	// Get name of prev space
	std::string nameCurrentSpace();	// Get name of existing space
	bool isEmpty();			// Check if linked list is empty

private:
	Space* s;			// Space ptr s
	Space* head;		// Space ptr head
	Space* tail;		// Space ptr tail
	Space* navigator;	// Space ptr navigator

};

#endif