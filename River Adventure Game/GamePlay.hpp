/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: Gameplay.hpp is the specification file for the
** Gameplay class.  Member functions defined in separate implementation
** file, Gameplay.cpp.
*********************************************************************/
#ifndef GamePlay_hpp
#define GamePlay_hpp
#include "Fisherman.hpp"
#include "Space.hpp"
#include "Map.hpp"
#include "FishStringer.hpp"
#include <string>

class GamePlay
{
public:
	GamePlay();				// Default constructor
	~GamePlay();			// Class destructor

	void lineSeparator();	// Horizontal line
	void printIntro();		// Print class intro
	void nextLevel();		// Go to next space
	void prevLevel();		// Go to prev space
	bool isAlive();			// Check if player alive

	void playBait();		// Bait shop level
	void playTrail1();		// Trail 1 level
	void playFish1();		// Fishing hole levle
	void playTrail2();		// Trail 2 level
	void playTruffles();	// Truffle dig level
	void playTrailOut();	// Trail 3 level

	void weighIn();			// Game summary

	void play();			// Main game function

private:
	Fisherman* player;		// Player object
	Map* current;			// Level object
	FishStringer* stringer;	// Stack to hold fish
};

#endif
