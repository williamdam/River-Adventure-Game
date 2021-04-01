/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: Map.cpp is the implementation file for the Map class.  
** Map class is a linked list of Space objects. Member functions defined 
** within.
*********************************************************************/
#include "Map.hpp"
#include "Space.hpp"
#include "BaitShop.hpp"
#include "HikingTrail1.hpp"
#include "FishingHole1.hpp"
#include "HikingTrail2.hpp"
#include "Truffles.hpp"
#include "TrailOut.hpp"
#include <iostream>
#include <string>

/*********************************************************************
** Description: Default constructor
*********************************************************************/
Map::Map() {
	s = nullptr;			// Initialize s ptr
	head = nullptr;			// Initialize head ptr
	tail = nullptr;			// Initialize tail ptr
	navigator = nullptr;	// Initialize navigator ptr

	// Initialize bait shop at map position 1
	s = new BaitShop();			// Create BaitShop() object
	s->setName("Bait Shop");	// Assign name
	s->setLeft(nullptr);		// Set left to null
	s->setRight(nullptr);		// Set right to null
	head = s;					// Assign head
	tail = s;					// Assign tail
	navigator = s;				// Assign navigator
		
	// Initialize hiking trail 1 at map position 2
	s = new HikingTrail1();			// Create HikingTrail1() object
	s->setName("Upper Rogue Trail");// Assign name
	s->setLeft(tail);				// Set left
	s->setRight(nullptr);			// Set right to null
	tail->setRight(s);				// Connect previous tail
	tail = s;						// Update tail

	// Initialize fishing hole 1 at map position 3
	s = new FishingHole1();			// Create FishingHole1() object
	s->setName("Hatchery Hole");	// Assign name
	s->setLeft(tail);				// Set left
	s->setRight(nullptr);			// Set right to null
	tail->setRight(s);				// Connect previous tail
	tail = s;						// Update tail

	// Initialize hiking trail 2 at map position 4
	s = new HikingTrail2();			// Create HikingTrail2() object
	s->setName("Lower Rogue Trail");// Assign name
	s->setLeft(tail);				// Set left
	s->setRight(nullptr);			// Set right to null
	tail->setRight(s);				// Connect previous tail
	tail = s;						// Update tail

	// Initialize truffles at map position 5
	s = new Truffles();					// Create Truffles() object
	s->setName("Secret Truffle Spot");	// Assign name
	s->setLeft(tail);					// Set left
	s->setRight(nullptr);				// Set right to null
	tail->setRight(s);					// Connect previous tail
	tail = s;							// Update tail

	// Initialize trail out at map position 6
	s = new TrailOut();				// Create TrailOut() object
	s->setName("Canyon Edge Trail");// Assign name
	s->setLeft(tail);				// Set left
	s->setRight(nullptr);			// Set right to null
	tail->setRight(s);				// Connect previous tail
	tail = s;						// Update tail

}

/*********************************************************************
** Description: bool function checks to see if list is empty
*********************************************************************/
bool Map::isEmpty() {
	if (head == nullptr) {
		return true;			// Return true if list is empty
	}
	else {
		return false;			// Return false if list is not empty
	}
}

/*********************************************************************
** Description: Print function displays intro from space
*********************************************************************/
void Map::printIntro() {
	navigator->spaceIntro();	// Print intro
}

/*********************************************************************
** Description: Void function moves pointer to next space in line
*********************************************************************/
void Map::moveForward() {

	// If navigator ptr is not on the last space
	if (isLastSpace() == false) {
		navigator = navigator->getRight();	// Set navigator ptr to next
	}

	// If navigator ptr is already on last space
	else {
		std::cout << "You can't move forward anymore." << std::endl;
	}
}

/*********************************************************************
** Description: Void function moves pointer to prev space in line
*********************************************************************/
void Map::moveBackward() {

	// If navigator ptr is not on the first space
	if (isFirstSpace() == false) {
		navigator = navigator->getLeft();	// Set navigator ptr to prev
	}

	// If navigator ptr is already on first space
	else {
		std::cout << "You can't move backward anymore." << std::endl;
	}
}

/*********************************************************************
** Description: int function calls action1() from Space object
*********************************************************************/
int Map::getAction1() {
	return navigator->action1();	// Return action1() from Space obj
}

/*********************************************************************
** Description: int function calls action2() from Space object
*********************************************************************/
int Map::getAction2() {
	return navigator->action2();	// Return action2() from Space obj
}

/*********************************************************************
** Description: Bool function checks to see if pointer is on first 
** Space object
*********************************************************************/
bool Map::isFirstSpace() {

	// If navigator is on first space
	if (navigator->getLeft() == nullptr) {
		return true;
	}

	// If not
	else {
		return false;
	}
}

/*********************************************************************
** Description: Bool function checks to see if pointer is on last 
** space object
*********************************************************************/
bool Map::isLastSpace() {

	// If navigator is on last space
	if (navigator->getRight() == nullptr) {
		return true;
	}

	// If not
	else {
		return false;
	}
}

/*********************************************************************
** Description: String function returns name of next space
*********************************************************************/
std::string Map::nameNextSpace() {
	return navigator->getRight()->getName();	// Return name of next space
}

/*********************************************************************
** Description: String function returns name of prev space
*********************************************************************/
std::string Map::namePrevSpace() {
	return navigator->getLeft()->getName();		// Return name of prev space
}

/*********************************************************************
** Description: String function returns name of current space
*********************************************************************/
std::string Map::nameCurrentSpace() {
	return navigator->getName();		// Return name of current space
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Map::~Map() {

	// While linked list isn't empty
	while (isEmpty() != true) {
		navigator = head->getRight();	// Move navigator
		delete head;					// Delete head
		head = navigator;				// Update head
	}
}