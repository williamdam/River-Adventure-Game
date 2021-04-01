/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: TrailOut.cpp is the implementation file for the
** TrailOut class. TrailOut is an inherited class of the Space class.
** Member functions defined within.
*********************************************************************/
#include "TrailOut.hpp"
#include <iostream>

/*********************************************************************
** Description: Default constructor for TrailOut class
*********************************************************************/
TrailOut::TrailOut() {

}

/*********************************************************************
** Description: Print function displays space intro
*********************************************************************/
void TrailOut::spaceIntro() {
	Space::lineSeparator();
	std::cout << "CANYON EDGE TRAIL - Direct route to the bait shop, where you parked your car.\n";
	std::cout << "This trail is treacherous and goes through bear territory. Be careful of \n";
	std::cout << "rugged terrain and keep your bear spray handy in case of an attack.\n";
	Space::lineSeparator();
}

/*********************************************************************
** Description: Int function used for bear attack.  Returns damage.
*********************************************************************/
int TrailOut::action1() {
	int attack = Space::dieRoll(100, 1);
	if (attack >= 50) {
		std::cout << "Bear is attacking!!!" << std::endl;
		return -45;
	}
	else {
		std::cout << "Good news! You didn't disturb any bears." << std::endl;
		return 0;
	}
}

/*********************************************************************
** Description: Int function not utilized.
*********************************************************************/
int TrailOut::action2() {
	return 0;
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
TrailOut::~TrailOut() {

}