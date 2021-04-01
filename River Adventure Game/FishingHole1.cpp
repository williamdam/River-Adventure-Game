/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: FishingHole1.cpp is the implementation file for the
** FishingHole1 class. FishingHole1 is an inherited class of the Space class.
** Member functions defined within.
*********************************************************************/
#include "FishingHole1.hpp"
#include <iostream>

/*********************************************************************
** Description: Default constructor for FishingHole1 class
*********************************************************************/
FishingHole1::FishingHole1() {

}

/*********************************************************************
** Description: Print function displays space intro
*********************************************************************/
void FishingHole1::spaceIntro() {
	Space::lineSeparator();
	std::cout << "HATCHERY HOLE ON THE UPPER ROGUE RIVER - Salmon are jumping! \n";
	Space::lineSeparator();
}

/*********************************************************************
** Description: Int function used for fish bite, returns random val
*********************************************************************/
int FishingHole1::action1() {
	return dieRoll(100, 1);		// Return random 1-100
}

/*********************************************************************
** Description: Int function used for fish fight, returns random val
*********************************************************************/
int FishingHole1::action2() {
	return dieRoll(100, 1);		// Return random 1-100
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
FishingHole1::~FishingHole1() {

}