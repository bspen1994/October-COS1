#pragma once
#include "creature.h"
#include <string>

class display
{
public:

	std::string getArt(const Creature& creature);

	void clearScreen();
};

