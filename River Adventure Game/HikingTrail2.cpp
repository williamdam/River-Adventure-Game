/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: HikingTrail2.cpp is the implementation file for the
** HikingTrail2 class. HikingTrail2 is an inherited class of the Space class.
** Member functions defined within.
*********************************************************************/
#include "HikingTrail2.hpp"
#include <iostream>

/*********************************************************************
** Description: Default constructor for HikingTrail2 class
*********************************************************************/
HikingTrail2::HikingTrail2() {

}

/*********************************************************************
** Description: Print function displays space intro
*********************************************************************/
void HikingTrail2::spaceIntro() {
	Space::lineSeparator();
	std::cout << "LOWER ROGUE RIVER TRAIL - Connects the Hatchery Hole to Secret Truffle Spot.\n";
	std::cout << "Snakes are known to lay on the trail to warm up. If you stay on the trail,\n";
	std::cout << "you will conserve energy, but risk getting bitten by a snake. You can hike\n";
	std::cout << "off the trail, but now you risk injury, which would zap your energy.\n";
	Space::lineSeparator();
}

/*********************************************************************
** Description: Int function used for snake bite. Returns
** damage value.
*********************************************************************/
int HikingTrail2::action1() {
	int attack = Space::dieRoll(100, 1);
	if (attack >= 60) {
		std::cout << "Snake bite!!! -35 energy" << std::endl;
		return -35;
	}
	else if (attack > 30 && attack < 60) {
		std::cout << "You stepped on a snake!!! But it tried to bite your boot. -20 energy" << std::endl;
		return -20;
	}
	else {
		std::cout << "You were able to avoid the snakes!" << std::endl;
		return 0;
	}
}

/*********************************************************************
** Description: Int function used for hiking through off trail.
** Generates injuries and returns damage.
*********************************************************************/
int HikingTrail2::action2() {
	int hike = Space::dieRoll(100, 1);
	if (hike >= 75) {
		std::cout << "You fell face-first into poison oak!!! -25 energy" << std::endl;
		return -25;
	}
	else if (hike > 40 && hike < 75) {
		std::cout << "You just slipped and hurt your tail bone! -20 energy" << std::endl;
		return -20;
	}
	else {
		std::cout << "You made it through without getting hurt." << std::endl;
		return 0;
	}
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
HikingTrail2::~HikingTrail2() {

}