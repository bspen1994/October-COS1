#pragma once
#include <vector>
#include "creature.h"
#include "display.h"

class mainLoop
{
public:
	void run(bool isLoad);
	~mainLoop();

private:
	//Creature creature_;
	std::vector<Creature*> stable_;

	void saveGame() const;
	bool loadGame();

	void selectPet();
	void interactWithPet(Creature* creature);

	void showStable() const;
	void showStats(const Creature* creature) const;
	bool handleChoice(int choice, Creature* creature);
	void advanceTime(Creature* creature);
};

