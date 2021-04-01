/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: Fisherman.cpp is the class implementation file for
** the Fisherman class.  This class contains data for the main player
** in the game.  Member methods defined within.
*********************************************************************/
#include "Fisherman.hpp"
#include <cstdlib>
#include <ctime>

/*********************************************************************
** Description: Default constructor
*********************************************************************/
Fisherman::Fisherman() {
	srand(static_cast<unsigned int>(time(0)));	// Seed random number generator
	energy = 100;
	biteOdds = 0;
	landingOdds = 0;
}

/*********************************************************************
** Description: Set function adds energy to the player's enegy level
*********************************************************************/
void Fisherman::setEnergy(int e) {
	energy += e;
	if (energy < 0) {
		energy = 0;
	}
}

/*********************************************************************
** Description: Get function returns player's energy
*********************************************************************/
int Fisherman::getEnergy() {
	return energy;
}

/*********************************************************************
** Description: Set function takes int arg and sets odds var to 
** be used in dieRoll()
*********************************************************************/
void Fisherman::setBiteOdds(int b) {
	biteOdds = b;
}

/*********************************************************************
** Description: Get function gets bite odds and returns int
*********************************************************************/
int Fisherman::getBiteOdds() {
	return biteOdds;
}

/*********************************************************************
** Description: Set function takes int arg and sets landing odds var
** to be used in dieRoll()
*********************************************************************/
void Fisherman::setLandingOdds(int g) {
	landingOdds = g;
}

/*********************************************************************
** Description: Get function gets landing odds and returns int
*********************************************************************/
int Fisherman::getLandingOdds() {
	return landingOdds;
}

/*********************************************************************
** Description: Int function generates random number and returns 
** number to be used to respond to fish bite
*********************************************************************/
int Fisherman::jig() {
	return dieRoll(100, biteOdds);
}

/*********************************************************************
** Description: Int function generates random number and returns
** number to be used to respond to fish fighting
*********************************************************************/
int Fisherman::net() {
	return dieRoll(100, landingOdds);
}

/*********************************************************************
** Description: Int function generates random number between range
** passed in args
*********************************************************************/
int Fisherman::dieRoll(int high, int low) {
	return rand() % high + low;				// Return roll value
}

/*********************************************************************
** Description: Int function generates random number for defense
*********************************************************************/
int Fisherman::defense1() {
	return dieRoll(40, 10);
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Fisherman::~Fisherman() {

}