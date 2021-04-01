/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: Space.cpp is the implementation file for the
** Space class. Space is a base class with virtual functions and
** polymorphism. Member functions defined within.
*********************************************************************/
#include "Space.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

/*********************************************************************
** Description: Default constructor
*********************************************************************/
Space::Space() {
	srand(static_cast<unsigned int>(time(0)));	// Seed random number generator
	top = nullptr;		// Top ptr to null
	right = nullptr;	// Right ptr to null
	bottom = nullptr;	// Bottom ptr to null
	left = nullptr;		// Left ptr to null
	spaceName = "";		// String for space name to null
}

/*********************************************************************
** Description: Print function prints horizontal line
*********************************************************************/
void Space::lineSeparator() {
	for (int i = 0; i < 75; i++) {
		std::cout << "-";		// Print 75 hyphens
	}
	std::cout << std::endl;
}

/*********************************************************************
** Description: Virtual void function overridden by inherited classes
** prints space introduction.
*********************************************************************/
void Space::spaceIntro() {
	// Virtual function
}

/*********************************************************************
** Description: Set function assigns string name to space
*********************************************************************/
void Space::setName(std::string n) {
	spaceName = n;
}

/*********************************************************************
** Description: Get function gets string name of space
*********************************************************************/
std::string Space::getName() {
	return spaceName;
}

/*********************************************************************
** Description: Set function assigns space object to top ptr
*********************************************************************/
void Space::setTop(Space* s) {
	top = s;
}

/*********************************************************************
** Description: Set function assigns space object to right ptr
*********************************************************************/
void Space::setRight(Space* s) {
	right = s;
}

/*********************************************************************
** Description: Set function assigns space object to bottom ptr
*********************************************************************/
void Space::setBottom(Space* s) {
	bottom = s;
}

/*********************************************************************
** Description: Set function assigns space object to left ptr
*********************************************************************/
void Space::setLeft(Space* s) {
	left = s;
}

/*********************************************************************
** Description: Get function returns ptr to top space
*********************************************************************/
Space* Space::getTop() {
	return top;
}

/*********************************************************************
** Description: Get function returns ptr to right space
*********************************************************************/
Space* Space::getRight() {
	return right;
}

/*********************************************************************
** Description: Get function returns ptr to bottom space
*********************************************************************/
Space* Space::getBottom() {
	return bottom;
}

/*********************************************************************
** Description: Get function returns ptr to left space
*********************************************************************/
Space* Space::getLeft() {
	return left;
}

/*********************************************************************
** Description: Int function generates random number between 2 args
** returns integer
*********************************************************************/
int Space::dieRoll(int high, int low) {
	return rand() % high + low;				// Return roll value
}

/*********************************************************************
** Description: Virtual void function overridden by inherited classes
** returns int. Used for inherited space actions.
*********************************************************************/
int Space::action1() {
	// Virtual funtion
	return 0;
}

/*********************************************************************
** Description: Virtual void function overridden by inherited classes
** returns int. Used for inherited space actions.
*********************************************************************/
int Space::action2() {
	// Virtual funtion
	return 0;
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Space::~Space() {

}