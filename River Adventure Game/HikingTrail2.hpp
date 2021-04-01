/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: HikingTrail2.hpp is the specification file for the
** HikingTrail2 class.  HikingTrail2 is an inherited class of the Space class.
** Member functions defined in separate implementation file, HikingTrail2.cpp.
*********************************************************************/
#ifndef HikingTrail2_hpp
#define HikingTrail2_hpp
#include "Space.hpp"

class HikingTrail2 : public Space
{
public:
	HikingTrail2();		// Default constructor
	~HikingTrail2();	// Class destructor
	void spaceIntro();	// Space intro
	int action1();		// Action 1 (polymorphic)
	int action2();		// Action 2 (polymorphic)

private:

};

#endif