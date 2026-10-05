#include "mainLoop.h"
#include <iostream>
#include <string>


void mainLoop::run()
{
	std::string creatureName;
	
	std::cout << "Your creature has hatched! What will you name it? ";
	std::getline(std::cin, creatureName);

	creature_.setName(creatureName);

	bool running = true;

	while (running)
	{
		showStats();
		showMenu();
		
		int choice;
		std::cout << "Choose an action: ";
		
		if (std::cin >> choice)
		{
			running = handleChoice(choice);

			if (running)
			{
				advanceTime();
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

void mainLoop::showStats() const
{
	std::cout << "\n---" << creature_.name() << "---\n";
	std::cout << "Affection:   " << creature_.affection() << "\n";
	std::cout << "Growth:      " << creature_.growth() << "\n";
	std::cout << "Hunger:      " << creature_.hunger() << "\n";
	std::cout << "Interaction: " << creature_.interaction() << "\n";
	std::cout << "Health:      " << creature_.health() << "\n";
}

void mainLoop::showMenu() const
{
	std::cout << "\n1. Feed\n";
	std::cout << "2. Play\n";
	std::cout << "3. Give Medication\n";
	std::cout << "0. Quit\n";
}

bool mainLoop::handleChoice(int choice)
{
	switch (choice)
	{
	case 0:
		return false;
	case 1:
		creature_.changeHunger(15);
		creature_.changeAffection(2);
		std::cout << "You fed " << creature_.name() << ".\n";
		break;
	case 2:
		creature_.changeInteraction(10);
		creature_.changeAffection(5);
		creature_.changeHunger(-5);
		creature_.changeGrowth(2);
		std::cout << "You played with " << creature_.name() << ".\n";
		break;
	case 3:
		creature_.changeHealth(15);
		creature_.changeHunger(-3);
		std::cout << "You gave " << creature_.name() << " medicine.\n";
		break;
	default:
		std::cout << "Please choose 0, 1, 2, or 3.\n";
		break;
	}
	return true;
}

void mainLoop::advanceTime()
{
	creature_.changeHunger(-2);
	creature_.changeHealth(-1);
}
