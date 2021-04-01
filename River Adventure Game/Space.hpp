/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: Space.hpp is the specification file for the
** Space class.  Space is a base class with virtual functions and
** polymorphism.  Member functions defined in separate implementation
** file, Space.cpp.
*********************************************************************/
#ifndef Space_hpp
#define Space_hpp
#include <string>

class Space
{
public:
	Space();					// Default constructor
	~Space();					// Class destructor
	void lineSeparator();		// Line separator

	// Virtual functions overridden by inherited class
	virtual int action1();		
	virtual int action2();		
	virtual void spaceIntro();

	void setName(std::string n);	// Set space name
	std::string getName();			// Get space name

	void setTop(Space* s);			// Set top ptr
	void setRight(Space* s);		// Set right ptr
	void setBottom(Space* s);		// Set bottom ptr
	void setLeft(Space* s);			// Set left ptr

	Space* getTop();				// Get top space
	Space* getRight();				// Get right space
	Space* getBottom();				// Get bottom space
	Space* getLeft();				// Get left space

	int dieRoll(int high, int low);	// Generate random number

private:
	Space* top;				// Declare top ptr
	Space* right;			// Declare right ptr
	Space* bottom;			// Declare bottom ptr
	Space* left;			// Declare left ptr
	std::string spaceName;	// Declare string to hold space nmae

};

#endif