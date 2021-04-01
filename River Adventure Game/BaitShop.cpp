/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: BaitShop.cpp is the implementation file for the
** BaitShop class. BaitShop is an inherited class of the Space class.
** Member functions defined within.
*********************************************************************/
#include "BaitShop.hpp"
#include <iostream>

/*********************************************************************
** Description: Default constructor for BaitShop class
*********************************************************************/
BaitShop::BaitShop() {

}

/*********************************************************************
** Description: Print function displays space intro
*********************************************************************/
void BaitShop::spaceIntro() {
	Space::lineSeparator();
	std::cout << "WELCOME TO JOE'S BAIT SHOP--Where there's nuttin' fishy' goin' on here!" << std::endl;
	Space::lineSeparator();
	std::cout << "Choose two items to buy.  You only have enough money for two!" << std::endl;
	std::cout << "1. Secret Sauce - Dunk your bait in secret sauce for 10% more bites!" << std::endl;
	std::cout << "2. Landing Net - Land 20% more fish by using a landing net!" << std::endl;
	std::cout << "3. Sack Lunch - Increase your starting energy to 120% with a sack lunch." << std::endl;
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
BaitShop::~BaitShop() {

}