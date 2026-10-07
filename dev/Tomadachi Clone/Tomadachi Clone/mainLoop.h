#pragma once
#include "creature.h"

class mainLoop
{
public:
	void run();

private:
	Creature creature_;

	void showStats() const;
	void showMenu() const;
	bool handleChoice(int choice);
	void advanceTime();
};

