#include "mainLoop.h"
#include <iostream>
#include <string>


void mainLoop::run()
{
	display display;
	std::string creatureName;
	Creature* currentPet = new Creature();
	
	display.clearScreen();

	//Asks to name your creature before the mainloop actually runs.
	std::cout << "Your creature has hatched! What will you name it? ";
	std::getline(std::cin >> std::ws, creatureName);

	//Sets the creatures name
	currentPet->setName(creatureName);

	stable_.push_back(currentPet);

	bool running = true;

	//Main loop that uses the handleChoice as a switch to deliniate all the code going in one spot.
	//Allows for some level of modularity if I want to change things later
	while (running)
	{
		display.clearScreen();
		showStable();
		display.showStableMenu();

		int stableChoice;
		if (std::cin >> stableChoice)
		{
			if (stableChoice == 0)
			{
				running = false;
			}
			else if (stableChoice == 1)
			{
				selectPet();
			}
			else if (stableChoice == 2)
			{
				display.clearScreen();
				Creature* newPet = new Creature();

				std::cout << "A new egg is cracking! What will you name this creature? ";
				std::string newCreatureName;
				std::getline(std::cin >> std::ws, newCreatureName);
				newPet->setName(newCreatureName);

				stable_.push_back(newPet);

				std::cout << "\n" << newPet->name() << " has joined your stable! Press Enter...";
				std::cin.get();
			}
			else
			{
				std::cout << "Invalid choice. Press Enter to continue...";
				std::cin.ignore(10000, '\n'); std::cin.get();
			}
		}
		else
		{
			std::cout << "Please enter a valid number.\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
}

mainLoop::~mainLoop()
{
	for (Creature* ptr : stable_)
	{
		delete ptr;
	}
	stable_.clear();
}

void mainLoop::showStats(const Creature* creature) const
{
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

void mainLoop::selectPet()
{
	display display;
	display.clearScreen();
	std::cout << "=== Select a Creature ===\n\n";
	showStable();
	std::cout << "\nEnter the number of the creature: ";

	size_t index;
	if (std::cin >> index)
	{
		if (index > 0 && index <= stable_.size())
		{
			interactWithPet(stable_[index - 1]);
		}
		else
		{
			std::cout << "Invalid creature number. Press Enter to return...";
			std::cin.ignore(10000, '\n'); std::cin.get();
		}
	}
	else
	{
		std::cout << "Invalid input. Press Enter to return...";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin.get();
	}
}

void mainLoop::interactWithPet(Creature* creature)
{
	display display;
	bool running = true;

	while (running)
	{
		showStats(creature);
		display.showGameMenu();

		int choice;
		if (std::cin >> choice)
		{
			running = handleChoice(choice, creature);

			if (running)
			{
				advanceTime(creature);
			}
		}
		else
		{
			std::cout << "Please enter a number.\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
}

void mainLoop::showStable() const
{
	if (stable_.empty())
	{
		std::cout << "[ No creatures available ]\n";
		return;
	}

	for (size_t i = 0; i < stable_.size(); ++i)
	{
		std::cout << (i + 1) << ": " << stable_[i]->name() << "\n";
	}
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