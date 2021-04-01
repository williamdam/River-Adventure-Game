/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: FishStringer.cpp is the class implementation file for the
** FishStringer class.  FishStringer is a stack container used to hold
** fish caught in the game.  Fish are pushed to the stack as string
** ascii art. Member methods defined within.
*********************************************************************/
#include "FishStringer.hpp"
#include <iostream>
#include <cstdlib>
#include <stack>
#include <list>

/*********************************************************************
** Description: Default constructor for FishStringer class
*********************************************************************/
FishStringer::FishStringer() {
	fish = "><(((*>";	// Initialize fish ascii art in string var

	// Initialize stack
	std::stack <std::string, std::list<std::string>> myStringer, myStringerTemp;
}

/*********************************************************************
** Description: Void function pushes values onto stack.  Used to
** add fish.  Fish var is ascii art initialized in constructor.
*********************************************************************/
void FishStringer::addFish() {
	myStringer.push(fish);
	std::cout << "There are " << myStringer.size() << " fish on the stringer." << std::endl;
}

/*********************************************************************
** Description: Void function pops values off the stack.  Used to 
** remove fish.
*********************************************************************/
void FishStringer::removeFish() {
	myStringer.pop();
	std::cout << "There are now " << myStringer.size() << " fish on the stringer." << std::endl;
}

/*********************************************************************
** Description: Print function makes a copy of the stack and prints
** and pops the values.
*********************************************************************/
void FishStringer::printStringer() {
	myStringerTemp = myStringer;	// Make a copy of stack

	// Check to see if stack is empty
	if (myStringerTemp.empty() == true) {
		std::cout << "Your fish stringer is empty!" << std::endl;
	}

	// Print values in stack
	else {
		std::cout << "Your fish stringer" << std::endl;

		// Print then pop each value until stack is empty
		while (!myStringerTemp.empty()) {
			std::cout << myStringerTemp.top() << std::endl;
			myStringerTemp.pop();								// Pop front of queue
		}
	}
}

/*********************************************************************
** Description: Bool function checks to see if stack is empty
*********************************************************************/
bool FishStringer::emptyStringer() {

	if (myStringer.empty()) {
		return true;			// Return true if empty
	}

	else {
		return false;			// Return false if not empty
	}

}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
FishStringer::~FishStringer() {

}