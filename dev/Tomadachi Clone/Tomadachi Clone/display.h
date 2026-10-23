#pragma once
#include "creature.h"
#include <string>

class display
{
public:

	std::string getArt(const Creature& creature);

	void clearScreen();
	void getInstructions();

	void showMainMenu() const;
	void showGameMenu() const;
	void showStableMenu() const;

	int inputValidate(int min, int max) const;
};

