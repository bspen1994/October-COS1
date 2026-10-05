#include "creature.h"
#include <random>

Creature::Creature()
	: personality_(randomPersonality()),
	affection_(50),
	growth_(0),
	hunger_(100),
	interaction_(0),
	health_(100)
{
}

int Creature::affection() const
{
	return affection_;
}

int Creature::growth() const
{
	return growth_;
}

int Creature::hunger() const
{
	return hunger_;
}

int Creature::interaction() const
{
	return interaction_;
}

int Creature::health() const
{
	return health_;
}

Creature::Personality Creature::personality() const
{
	return personality_;
}

void Creature::changeAffection(int amount)
{
	affection_ = limitStat(affection_ + amount);
}

void Creature::changeGrowth(int amount)
{
	growth_ = limitStat(growth_ + amount);
}

void Creature::changeHunger(int amount)
{
	hunger_ = limitStat(hunger_ + amount);
}

void Creature::changeInteraction(int amount)
{
	interaction_ = limitStat(interaction_ + amount);
}

void Creature::changeHealth(int amount)
{
	health_ = limitStat(health_ + amount);
}

int Creature::limitStat(int value)
{
	if (value < 0) 
	{
		return 0;
	}
	else if (value > 100) 
	{
		return 100;
	}
	else 
	{
		return value;
	}
}

Creature::Personality Creature::randomPersonality()
{
	static std::mt19937 rng{ std::random_device{}() };
	std::uniform_int_distribution<int> distribution(0, 3);

	return static_cast<Personality>(distribution(rng));
}
