/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: HikingTrail1.hpp is the specification file for the
** HikingTrail1 class.  HikingTrail1 is an inherited class of the Space class.
** Member functions defined in separate implementation file, HikingTrail1.cpp.
*********************************************************************/
#ifndef HikingTrail1_hpp
#define HikingTrail1_hpp
#include "Space.hpp"

class HikingTrail1: public Space
{
public:
	HikingTrail1();		// Default constructor
	~HikingTrail1();	// Class destructor
	void spaceIntro();	// Space intro
	int action1();		// Action 1 (polymorphic)
	int action2();		// Action 2 (polymorphic)

private:

};

#endif