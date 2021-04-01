/*********************************************************************
** Author: William Dam
** Date: 12-09-2019
** Description: Gameplay.cpp is the implementation file for the
** Gameplay class.  Member functions defined within. This class is the
** game controller, that calls on all components of the game.
*********************************************************************/
#include "GamePlay.hpp"
#include <iostream>
#include "Validate.hpp"
#include <string>

/*********************************************************************
** Description: Default constructor initializes pointers to all 3
** objects that work together to form the game. 
** 1. player - Fisherman class object is the first person player
** 2. current - Map class object is the space that the player is in
** 3. stringer - FishStringer class object is a stack that holds the fish
*********************************************************************/
GamePlay::GamePlay() {
	player = new Fisherman();		// First person player object
	current = new Map();			// Linked list of space objects
	stringer = new FishStringer();	// Stack container to hold the fish
}

/*********************************************************************
** Description: Print function displays a horizontal line
*********************************************************************/
void GamePlay::lineSeparator() {
	for (int i = 0; i < 75; i++) {
		std::cout << "-";			// Print 75 hyphens
	}
	std::cout << std::endl;
}

/*********************************************************************
** Description: Print function displays game intro and objective
*********************************************************************/
void GamePlay::printIntro() {
	lineSeparator();
	std::cout << "SALMON FISHING ADVENTURE ON THE ROGUE RIVER IN OREGON" << std::endl;
	std::cout << "The Rogue River in Southwestern Oregon flows about 215 miles (346 km) in\n";
	std::cout << "a generally westward direction from the Cascade Range to the Pacific Ocean.\n";
	std::cout << "Known for its salmon runs, whitewater rafting, and rugged scenery, it was\n";
	std::cout << "one of the original eight rivers named in the Wildand Scenic Rivers Act of 1968.\n";
	// Source: https://en.wikipedia.org/wiki/Rogue_River_(Oregon)
	lineSeparator();
	std::cout << "You will start at the bait shop to buy your fishing tackle. You only have enough\n";
	std::cout << "money for two items, so choose wisely.  Once you leave the bait shop, you're on your\n";
	std::cout << "own.  Watch out for bears, mountain lions, snakes, and rugged terrain! Conserve your\n";
	std::cout << "energy, catch fish or collect truffles to gain more energy, and try to make it out alive!\n";
	std::cout << "To win the game, you must make it out alive with at least 1 fish.\n";
	lineSeparator();
}

/*********************************************************************
** Description: Void function navigates interaction space to the
** next space in the linked list sequence.  Aka move to the next level.
*********************************************************************/
void GamePlay::nextLevel() {
	current->moveForward();		// Move to next space
}

/*********************************************************************
** Description: Void function navigates interaction space to the
** previous space in the linked list sequence.  Aka back to previous
** level.
*********************************************************************/
void GamePlay::prevLevel() {
	current->moveBackward();	// Move to prev space
}

/*********************************************************************
** Description: Bool function checks to see if player is alive.
** Return true if alive, false if dead.
*********************************************************************/
bool GamePlay::isAlive() {
	if (player->getEnergy() > 0) {
		return true;
	}
	else {
		return false;
	}
}

/*********************************************************************
** Description: Void function allows player to interact with the 
** bait shop. Items purchased will result in different odds for player.
*********************************************************************/
void GamePlay::playBait() {

	int count = 0;				// Count max 2 items
	int item1 = 0;				// Item 1
	int item2 = 0;				// Item 2

	current->printIntro();		// Print space intro

	// Player chooses 2 items to buy
	while (count < 2) {
		count++;				// Increment item counter (max 2)
		if (count == 1) {
			std::cout << "Choose item " << count << " of 2: ";
			item1 = integerInput(1, 3);	// Get item 1 choice
		}
		else if (count == 2) {
			std::cout << "Choose item " << count << " of 2: ";
			item2 = integerInput(1, 3);	// Get item 2 choice
		}
	}

	// Adjust odds/energy, based on items purchased
	if (item1 == 1 || item2 == 1) {
		std::cout << "You got a bottle of secret bait sauce for 10% more bites!" << std::endl;
		player->setBiteOdds(10);
	}
	if (item1 == 2 || item2 == 2) {
		std::cout << "You got a landing net to land 20% more fish!" << std::endl;
		player->setLandingOdds(20);
	}
	if (item1 == 3 || item2 == 3) {
		std::cout << "You got a sack lunch to increase your energy by 20%!" << std::endl;
		player->setEnergy(20);
	}

	// Print current energy
	std::cout << "Your Energy is Now: " << player->getEnergy() << std::endl;
}

/*********************************************************************
** Description: Void function allows player to interact with the
** first hiking trail. Calls getAction1() and getAction2() from Space
** object.
*********************************************************************/
void GamePlay::playTrail1() {

	current->printIntro();		// Print space intro

	// Print current energy
	std::cout << "Starting Energy: " << player->getEnergy() << std::endl;

	// Prompt user for options
	std::cout << "1. Take the shortcut with no energy loss, but risk mountain lion attack." << std::endl;
	std::cout << "2. Take the long route with no mountain lion risk, but costs -30 energy." << std::endl;
	std::cout << "Enter an option: ";
	int option = integerInput(1, 2);	// Get user input

	int damage = 0;						// Int for damage

	// Based on user input, call corresponding action & save damage
	if (option == 1) {
		damage = current->getAction1();	
	}
	else if (option == 2) {
		damage = current->getAction2();
	}

	player->setEnergy(damage);			// Hit player energy with damage

	// Print current energy at end of level
	std::cout << "Ending Energy: " << player->getEnergy() << std::endl;
}

/*********************************************************************
** Description: Void function allows player to interact with the
** fishing hole. Making a cast costs energy, as does losing a fish. 
** But, landing a fish will result in positive energy gained.
*********************************************************************/
void GamePlay::playFish1() {

	current->printIntro();				// Print space intro

	// Print current energy
	std::cout << "Starting Energy: " << player->getEnergy() << std::endl;

	// Prompt user for options
	std::cout << "Starting Energy: " << player->getEnergy() << std::endl;
	std::cout << "1. Make a cast (-5 energy)" << std::endl;
	std::cout << "2. I don't want to fish" << std::endl;
	std::cout << "Enter an option: ";
	int option = integerInput(1, 2);	// Get user input

	int fishBite = 0;		// Int holds Space object action1() val
	int hookset = 0;		// Int holds player response action val
	int fishFight = 0;		// Int holds Space object action2() val
	int landing = 0;		// Int holds player response action val

	// Loop to go fishing
	while (option != 2) {

		player->setEnergy(-5);	// -5 energy per cast

		// Print current energy
		std::cout << "Current Energy: " << player->getEnergy() << std::endl;

		fishBite = current->getAction1();	// Fish bite
		hookset = player->jig();			// Player hookset

		// If player hookset value > fishBite, then fish gets hooked
		if (hookset > fishBite) {

			std::cout << "You got a bite! FISH ON!!!" << std::endl;

			fishFight = current->getAction2();	// Fish fights
			landing = player->net();			// Player tries to land fish

			// If player landing value > fishFight, then fish gets landed
			if (landing > fishFight) {

				std::cout << "You landed the fish! +20 energy" << std::endl;

				player->setEnergy(20);		// +20 to player energy
				stringer->addFish();		// Add fish to stringer
				stringer->printStringer();	// Print fish stringer
			}

			// If player landing value isn't sufficient, line breaks
			else {
				std::cout << "The line broke!!! -10 energy" << std::endl;
				player->setEnergy(-10);		// -10 from player energy
			}
		}

		// No bites
		else {
			std::cout << "Not even a nibble." << std::endl;
		}

		// Print current energy with each loop
		std::cout << "Current Energy: " << player->getEnergy() << std::endl;
		
		// Check if dead or display menu to loop
		if (player->getEnergy() <= 0) {
			std::cout << "You ran out of energy and died!!!" << std::endl;
			option = 2;
		}
		else {
			std::cout << "1. Make a cast (-5 energy)" << std::endl;
			std::cout << "2. I'm done fishing" << std::endl;
			std::cout << "Enter an option: ";
			option = integerInput(1, 2);
		}
	}

	// Print current energy at end of level
	std::cout << "Ending Energy: " << player->getEnergy() << std::endl;
}

/*********************************************************************
** Description: Void function allows player to interact with the
** second hiking trail. Calls getAction1() and getAction2() from Space
** object.
*********************************************************************/
void GamePlay::playTrail2() {

	current->printIntro();		// Print space intro

	// Print current energy
	std::cout << "Starting Energy: " << player->getEnergy() << std::endl;

	// Prompt user for options
	std::cout << "1. Stay on the trail to save energy, but risk a snake bite." << std::endl;
	std::cout << "2. Hike through the dense brush to avoid sunbathing snakes, but risk injury." << std::endl;
	std::cout << "Enter an option: ";
	int option = integerInput(1, 2);	// Get user input

	int damage = 0;		// Damage inflicted

	// Based on user input, call corresponding action & save damage
	if (option == 1) {
		damage = current->getAction1();
	}
	else if (option == 2) {
		damage = current->getAction2();
	}

	player->setEnergy(damage);		// Hit player energy with damage

	// Print current energy at end of level
	std::cout << "Ending Energy: " << player->getEnergy() << std::endl;
}

/*********************************************************************
** Description: Void function allows player to interact with the
** forest floor with truffles. Calls getAction1() and getAction2() from 
** Space object.
*********************************************************************/
void GamePlay::playTruffles() {

	current->printIntro();		// Print space intro

	// Prompt user for options
	std::cout << "Starting Energy: " << player->getEnergy() << std::endl;
	std::cout << "1. Dig for individual truffles.  -5 energy per dig" << std::endl;
	std::cout << "2. Use the big shovel to get more truffles.  -20 per dig" << std::endl;
	std::cout << "3. I'm done collecting truffles" << std::endl;
	std::cout << "Enter an option: ";
	int option = integerInput(1, 3);	// Get user input

	int energy = 0;			// Energy value for truffles found

	// Truffle digging loop until quit
	while (option != 3) {

		// Dig with small shovel
		if (option == 1) {
			player->setEnergy(-5);			// -5 per dig
			energy = current->getAction1();	// Truffle energy
			player->setEnergy(energy);		// Update energy
		}
		// Dig with big shovel
		else if (option == 2) {
			player->setEnergy(-20);			// -20 per dig
			energy = current->getAction2();	// Truffle energy
			player->setEnergy(energy);		// Update energy
		}

		// Print current energy for each dig
		std::cout << "Current Energy: " << player->getEnergy() << std::endl;

		// Check if dead or display menu to loop
		if (player->getEnergy() <= 0) {
			std::cout << "You ran out of energy and died!!!" << std::endl;
			option = 3;
		}
		else {
			std::cout << "1. Dig for individual truffles.  -5 energy per dig" << std::endl;
			std::cout << "2. Use the big shovel to get more truffles.  -20 per dig" << std::endl;
			std::cout << "3. I'm done digging for truffles" << std::endl;
			std::cout << "Enter an option: ";
			option = integerInput(1, 3);
		}
		
	}

	// Print current energy at end of level
	std::cout << "Ending Energy: " << player->getEnergy() << std::endl;
}

/*********************************************************************
** Description: Void function allows player to interact with the
** hiking trail to get out of the canyon and finish the game. Calls 
** getAction1() from Space object, then calls weighIn() member function.
*********************************************************************/
void GamePlay::playTrailOut() {

	current->printIntro();		// Print space intro

	// Prompt user for options
	std::cout << "Starting Energy: " << player->getEnergy() << std::endl;
	std::cout << "1. Drop one of your fish and stay safe from bears, but -30 energy" << std::endl;
	std::cout << "2. Take your chances and hope the bear spray works" << std::endl;
	std::cout << "Choose an option: ";
	int option = integerInput(1, 2);	// Get user input

	int bear = 0;			// Bear attack value
	int fisherman = 0;		// Fisherman defense value
	int damage = 0;			// Damage = bear - fisherman

	// 1. Sacrifice a fish to keep the bears at bay
	if (option == 1) {

		// Drop a fish from stringer if player has any
		if (stringer->emptyStringer() == false) {
			std::cout << "The bears were busy eating the fish you left behind,\n";
			std::cout << "so they didn't notice you. -30 energy for the fish" << std::endl;
			damage = -30;			// Damage -30 for dropping fish
			stringer->removeFish();	// Pop fish from stack
		}

		// No fish on stringer, then default to take chances
		else {

			std::cout << "You don't have any fish to leave behind!" << std::endl;
			std::cout << "Let's hope the bear spray works!" << std::endl;
			bear = current->getAction1();		// Bear attack function

			// If bear attacks...
			if (bear == -45) {					
				fisherman = player->defense1();	// Player defense function

				// If bear spray works...
				if (fisherman > 20) {
					std::cout << "The bear spray worked!  Damage reduced by " << fisherman << std::endl;
					damage = bear - fisherman;	// Save damage
				}

				// If bear spray fails...
				else {
					std::cout << "The bear spray didn't work!  You took the full-force of the attack." << std::endl;
				}
				damage = bear;	// Save damage
			}
		}
	}

	// Taking a chance with the bears
	else {

		bear = current->getAction1();	// Call bear attack function

		// If bear attacks...
		if (bear == -45) {
			fisherman = player->defense1();		// Player defense function

			// If bear spray works...
			if (fisherman > 20) {
				std::cout << "The bear spray worked!  Damage reduced by " << fisherman << std::endl;
				damage = bear - fisherman;	// Save damage
			}

			// If bear spray fails...
			else {
				std::cout << "The bear spray didn't work!  You took the full-force of the attack." << std::endl;
			}
			damage = bear;	// Save damage
		}
	}

	player->setEnergy(damage);	// Hit player energy with damage

	// Print current energy at end of level
	std::cout << "Ending Energy: " << player->getEnergy() << std::endl;

	// Print game summary
	weighIn();
}

/*********************************************************************
** Description: Void function is a score summary that prints the results
** of the game. Function called from member function playTrailOut().
*********************************************************************/
void GamePlay::weighIn() {

	// Congratulate if alive
	if (isAlive() == true) {
		std::cout << "CONGRATULATIONS! You made it out alive." << std::endl;
		std::cout << "Your energy level: " << player->getEnergy() << std::endl;

		// Fail if no fish
		if (stringer->emptyStringer() == true) {
			std::cout << "But you didn't come back with any fish.  You lose!" << std::endl;
		}

		// Win if alive and fish
		else {
			stringer->printStringer();
			std::cout << "YOU WIN!!!" << std::endl;
		}
	}
}

/*********************************************************************
** Description: Void function play() is the main game function that 
** runs the game.  Calls on all play..() functions and then this function
** gets called from the main method.
*********************************************************************/
void GamePlay::play() {

	int option = 0;		// User input option

	while (option != 1) {

		// Bait shop level
		if (current->nameCurrentSpace() == "Bait Shop") {
			playBait();
		}

		// Trail 1 level
		else if (current->nameCurrentSpace() == "Upper Rogue Trail") {
			playTrail1();
		}

		// Fishing hole level
		else if (current->nameCurrentSpace() == "Hatchery Hole") {
			playFish1();
		}

		// Trail 2 level
		else if (current->nameCurrentSpace() == "Lower Rogue Trail") {
			playTrail2();
		}

		// Truffle level
		else if (current->nameCurrentSpace() == "Secret Truffle Spot") {
			playTruffles();
		}

		// Exit trail level
		else if (current->nameCurrentSpace() == "Canyon Edge Trail") {
			playTrailOut();
		}

		lineSeparator();

		// Exit game if player dies
		if (player->getEnergy() <= 0) {
			std::cout << "You ran out of energy and died!  Game over." << std::endl;
			option = 1;
		}

		// Prompt game menu from first space
		else if (current->isFirstSpace() == true) {
			std::cout << "1. Exit game" << std::endl;
			std::cout << "2. Go to next level - " << current->nameNextSpace() << std::endl;
			std::cout << "Enter an option: ";
			option = integerInput(1, 2);

		}

		// Prompt game menu from second space
		else if (current->isFirstSpace() == false && current->isLastSpace() == false && current->namePrevSpace() == "Bait Shop") {
			std::cout << "1. Exit game" << std::endl;
			std::cout << "2. Go to next level - " << current->nameNextSpace() << std::endl;
			std::cout << "3. Can't go to prev level - " << current->namePrevSpace() << " is now closed." << std::endl;
			std::cout << "Enter an option: ";
			option = integerInput(1, 2);
		}

		// Prompt game menu from inside spaces
		else if (current->isFirstSpace() == false && current->isLastSpace() == false && current->namePrevSpace() != "Bait Shop") {
			std::cout << "1. Exit game" << std::endl;
			std::cout << "2. Go to next level - " << current->nameNextSpace() << std::endl;
			std::cout << "3. Go to prev level - " << current->namePrevSpace() << std::endl;
			std::cout << "Enter an option: ";
			option = integerInput(1, 3);
		}

		// Exit game from last space
		else {
			option = 1;
		}

		lineSeparator();

		// Move forward or backward 1 level based on user input
		if (option == 2) {
			current->moveForward();
		}
		else if (option == 3) {
			current->moveBackward();
		}
	}
}

/*********************************************************************
** Description: Class destructor.  Delete allocated memory.
*********************************************************************/
GamePlay::~GamePlay() {
	delete player;
	delete current;
	delete stringer;
}