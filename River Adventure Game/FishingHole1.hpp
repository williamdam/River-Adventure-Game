/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: FishingHole1.hpp is the specification file for the
** FishingHole1 class.  FishingHole1 is an inherited class of the Space class.
** Member functions defined in separate implementation file, FishingHole1.cpp.
*********************************************************************/
#ifndef FishingHole1_hpp
#define FishingHole2_hpp
#include "Space.hpp"

class FishingHole1: public Space
{
public:
	FishingHole1();		// Default constructor
	~FishingHole1();	// Class destructor
	void spaceIntro();	// Space intro
	int action1();		// Action 1 (polymorphic)
	int action2();		// Action 2 (polymorphic)
private:

};

#endif