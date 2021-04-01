/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: HikingTrail1.cpp is the implementation file for the
** HikingTrail1 class. HikingTrail1 is an inherited class of the Space class.
** Member functions defined within.
*********************************************************************/
#include "HikingTrail1.hpp"
#include <iostream>

/*********************************************************************
** Description: Default constructor for HikingTrail1 class
*********************************************************************/
HikingTrail1::HikingTrail1() {

}

/*********************************************************************
** Description: Print function displays space intro
*********************************************************************/
void HikingTrail1::spaceIntro() {
	Space::lineSeparator();
	std::cout << "UPPER ROGUE RIVER TRAIL - Connects the bait shop to the Upper Rogue River\n";
	std::cout << "Mountain lions frequent this trail. The long way around will keep you safe\n";
	std::cout << "from the big cats, but will zap your energy. The shortcut won't affect your\n";
	std::cout << "energy, but you risk being attacked." << std::endl;
	Space::lineSeparator();
}

/*********************************************************************
** Description: Int function used for mountain lion attack. Returns 
** damage value.
*********************************************************************/
int HikingTrail1::action1() {
	int attack = Space::dieRoll(100, 1);
	if (attack >= 50) {
		std::cout << "Mountain lion attack!!! -40 energy" << std::endl;
		return -40;
	}
	else if (attack > 30 && attack < 50) {
		std::cout << "Mountain lion attack, but you fought off the cat! -25 energy" << std::endl;
		return -25;
	}
	else {
		std::cout << "Close call.  The lion didn't attack!" << std::endl;
		return 0;
	}
}

/*********************************************************************
** Description: Int function used for avoiding mountain lion. Returns
** energy wasted by taking the long route.
*********************************************************************/
int HikingTrail1::action2() {
	std::cout << "You took the long way around, but you're safe. -30 energy" << std::endl;
	return -30;		
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
HikingTrail1::~HikingTrail1() {

}