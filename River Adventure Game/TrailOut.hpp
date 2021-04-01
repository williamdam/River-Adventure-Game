/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: TrailOut.hpp is the specification file for the
** TrailOut class.  TrailOut is an inherited class of the Space class.
** Member functions defined in separate implementation file, TrailOut.cpp.
*********************************************************************/
#ifndef TrailOut_hpp
#define TrailOut_hpp
#include "Space.hpp"

class TrailOut : public Space
{
public:
	TrailOut();			// Default constructor
	~TrailOut();		// Class destructor
	void spaceIntro();	// Space intro
	int action1();		// Action 1 (polymorphic)
	int action2();		// Action 2 (polymorphic)

private:

};

#endif