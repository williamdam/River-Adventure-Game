/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: Truffles.cpp is the implementation file for the
** Truffles class. Truffles is an inherited class of the Space class.
** Member functions defined within.
*********************************************************************/
#include "Truffles.hpp"
#include <iostream>

/*********************************************************************
** Description: Default constructor for Truffles class
*********************************************************************/
Truffles::Truffles() {

}

/*********************************************************************
** Description: Print function displays space intro
*********************************************************************/
void Truffles::spaceIntro() {
	Space::lineSeparator();
	std::cout << "DIG FOR TRUFFLES - You made a friend on the river, who directed you to an\n";
	std::cout << "area off the trail, known to have truffles. Each time you dig, it will cost\n";
	std::cout << "you energy, but you will gain energy for each truffle discovered. Gather as\n";
	std::cout << "many as you can, to build up energy to hike out of the canyon!\n";
	Space::lineSeparator();
}

/*********************************************************************
** Description: Int function used for small shovel truffle dig
*********************************************************************/
int Truffles::action1() {
	int find = Space::dieRoll(10, 1);
	if (find >= 5) {
		std::cout << "You found a truffle!" << std::endl;
		return 10;
	}
	else {
		std::cout << "No truffles found." << std::endl;
		return 0;
	}
}

/*********************************************************************
** Description: Int function used for big shovel truffle dig
*********************************************************************/
int Truffles::action2() {
	int bigDig = Space::dieRoll(10, 1);
	int howMany = 0;
	if (bigDig >= 7) {
		howMany = Space::dieRoll(6, 1);
		std::cout << "You found " << howMany << " truffles!" << std::endl;
		return howMany * 10;
	}
	else {
		std::cout << "No truffles found." << std::endl;
		return 0;
	}
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Truffles::~Truffles() {

}