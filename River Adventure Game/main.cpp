/*********************************************************************
** Author: William Dam
** Assignment: FINAL PROJECT
** Date: 12-08-2019
** Description: Salmon fishing adventure game involves going to the 
** bait shop, hiking, fishing, collecting truffles for more energy, and
** all the while, avoiding the dangers found in nature.  
** To win the game, you must make it out alive with at least 1 fish.
*********************************************************************/

#include <iostream>
#include "GamePlay.hpp"

int main() {
	GamePlay fishing;		// Instantiate GamePlay object
	fishing.printIntro();	// Print game introduction
	fishing.play();			// Play game

	return 0;
}