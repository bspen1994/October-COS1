#pragma once
#include <iostream>

class Creature
{
public:
	enum class Personality
	{
		Playful,
		Shy,
		Curious,
		Calm
	};

	Creature();

	int affection() const;
	int growth() const;
	int hunger() const;
	int interaction() const;
	int health() const;
	Personality personality() const;
	const std::string& name() const;

	void changeAffection(int amount);
	void changeGrowth(int amount);
	void changeHunger(int amount);
	void changeInteraction(int amount);
	void changeHealth(int amount);
	void setName(const std::string& name);

private:
	Personality personality_;
	int affection_;
	int growth_;
	int hunger_;
	int interaction_;
	int health_;
	std::string name_;

	static int limitStat(int value);
	static Personality randomPersonality();

};

