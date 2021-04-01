/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: Truffles.hpp is the specification file for the
** Truffles class.  BaitShop is an inherited class of the Space class.
** Member functions defined in separate implementation file, Truffles.cpp.
*********************************************************************/
#ifndef Truffles_hpp
#define Truffles_hpp
#include "Space.hpp"

class Truffles : public Space
{
public:
	Truffles();			// Default constructor
	~Truffles();		// Class destructor
	void spaceIntro();	// Space intro
	int action1();		// Action 1 (polymorphic)
	int action2();		// Action 2 (polymorphic)

private:


};

#endif