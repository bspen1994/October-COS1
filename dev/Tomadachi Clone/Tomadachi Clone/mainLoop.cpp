#include "mainLoop.h"
#include <iostream>
#include <string>
#include <fstream>


void mainLoop::run(bool isLoad)
{
	display display; //Creates a new display object to call functions

	if (isLoad) //If the player selects to load game
	{
		if (!loadGame()) //If there is no save file
		{
			std::cout << "No save file found! Press Enter to return to main menu...";
			std::string dummy;
			std::getline(std::cin, dummy); //Pauses menu to allow player to read
			return;
		}
	}
	else //If it is a new game
	{
		std::string creatureName;
		Creature* currentPet = new Creature(); //New default creature

		display.clearScreen();

		//Asks to name your creature before the mainloop actually runs.
		std::cout << "Your creature has hatched! What will you name it? ";
		std::getline(std::cin, creatureName);

		//Sets the creatures name
		currentPet->setName(creatureName);

		stable_.push_back(currentPet);
	}

	bool running = true;

	//Main loop that uses the handleChoice as a switch to deliniate all the code going in one spot.
	//Allows for some level of modularity if I want to change things later
	while (running)
	{
		display.clearScreen();
		display.showStableMenu();

		int stableChoice = display.inputValidate(0, 3); //call input function to keep it within 0-3

		if (stableChoice == 0)
		{
			running = false; //Returns to main menu
		}
		else if (stableChoice == 1)
		{
			selectPet(); //Goes to main loop to care for pet
		}
		else if (stableChoice == 2)
		{
			//This is to add a new pet to your stable in the pet managment menu
			display.clearScreen();
			Creature* newPet = new Creature();

			std::cout << "A new egg is cracking! What will you name this creature? ";
			std::string newCreatureName;
			std::getline(std::cin, newCreatureName);
			newPet->setName(newCreatureName);

			stable_.push_back(newPet);

			std::cout << "\n" << newPet->name() << " has joined your stable! Press Enter...";
			std::string dummy;
			std::getline(std::cin, dummy);
		}
		else if (stableChoice == 3)
		{
			saveGame(); //Saves game to savegame.txt
		}
	}
}

mainLoop::~mainLoop()
{
	//destructor
	for (Creature* ptr : stable_)
	{
		delete ptr; //Safely frees the heap memory for each creature
	}
	stable_.clear();
}

void mainLoop::showStats(const Creature* creature) const
{
	//Shows stats of the pet/creature
	display display;
	display.clearScreen();

	std::cout << "\n---" << creature->name() << "---\n";
	std::cout << display.getArt(*creature);
	std::cout << "Affection:   " << creature->affection() << "\n";
	std::cout << "Growth:      " << creature->growth() << "\n";
	std::cout << "Hunger:      " << creature->hunger() << "\n";
	std::cout << "Interaction: " << creature->interaction() << "\n";
	std::cout << "Health:      " << creature->health() << "\n";
}

void mainLoop::saveGame() const
{
	//Save function to save the creature vector into the save file
	std::ofstream outFile("savegame.txt");
	if (!outFile)
	{
		std::cout << "Error: Could not create save file.\n";
		return;
	}

	outFile << stable_.size() << "\n";

	for (Creature* ptr : stable_)
	{
		ptr->serialize(outFile);
	}

	std::cout << "\nGame successfully saved! Press Enter to continue...";
	std::string dummy;
	std::getline(std::cin, dummy);
}

bool mainLoop::loadGame()
{
	//Loads the game from savegame to fill the creature vector
	std::ifstream inFile("savegame.txt");
	if (!inFile)
	{
		return false;
	}

	size_t count;
	if (inFile >> count)
	{
		for (size_t i = 0; i < count; ++i)
		{
			Creature* loadedPet = new Creature();
			loadedPet->deserialize(inFile);
			stable_.push_back(loadedPet);
		}
	}
	return true;
}

void mainLoop::selectPet()
{
	//Shows the vector of creatures and allows you to select one to "play" with
	display display;
	display.clearScreen();
	std::cout << "=== Select a Creature ===\n\n";
	showStable();
	std::cout << "\nEnter the number of the creature: ";

	int index = display.inputValidate(0, static_cast<int>(stable_.size()));

	if (index > 0)
	{
		interactWithPet(stable_[index - 1]);
	}
}

void mainLoop::interactWithPet(Creature* creature)
{
	//Brings in a pointer to a creature object to modify it's stats
	display display;
	bool running = true;

	while (running)
	{
		showStats(creature);
		display.showGameMenu();

		int choice = display.inputValidate(0, 3);
		running = handleChoice(choice, creature);

		if (running)
		{
			advanceTime(creature);
			std::cout << "\nPress Enter to continue...";
			std::string dummy;
			std::getline(std::cin, dummy);
		}
	}
}

void mainLoop::showStable() const
{
	//Simple vector print to show all the available pets
	if (stable_.empty())
	{
		std::cout << "[ No creatures available ]\n";
		return;
	}

	for (size_t i = 0; i < stable_.size(); ++i)
	{
		std::cout << (i + 1) << ": " << stable_[i]->name() << "\n";
	}
	std::cout << "0: Return to Stable Menu\n";
}

bool mainLoop::handleChoice(int choice, Creature* creature)
{
	//Handles all of the stat changes through interaction
	//Can be expanded or changed to be more involved later
	switch (choice)
	{
	case 0:
		return false;
	case 1:
		creature->changeHunger(15);
		creature->changeAffection(2);
		std::cout << "You fed " << creature->name() << ".\n";
		break;
	case 2:
		creature->changeInteraction(10);
		creature->changeAffection(5);
		creature->changeHunger(-5);
		creature->changeGrowth(2);
		std::cout << "You played with " << creature->name() << ".\n";
		break;
	case 3:
		creature->changeHealth(15);
		creature->changeHunger(-3);
		std::cout << "You gave " << creature->name() << " medicine.\n";
		break;
	default:
		std::cout << "Please choose 0, 1, 2, or 3.\n";
		break;
	}
	return true;
}

void mainLoop::advanceTime(Creature* creature)
{
	//Basic input turn end to make the creature hungrier and less healthy over time
	creature->changeHunger(-2);
	creature->changeHealth(-1);
}