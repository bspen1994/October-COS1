#include "creature.h"
#include <random>

Creature::Creature()
	: personality_(randomPersonality()),
	affection_(50),
	growth_(0),
	hunger_(100),
	interaction_(0),
	health_(100),
	name_("")
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

const std::string& Creature::name() const
{
	return name_;
}

int Creature::getModifiedAffection(int amount) const
{
	double multiplier = 1.0;

	switch (personality_)
	{
	case Personality::Shy:
		multiplier = 0.6;
	case Personality::Hungry:
		multiplier = 1.4;
	case Personality::Sick:
		multiplier = 0.8;
	case Personality::Hurt:
		multiplier = 0.7;
	case Personality::Playful:
		multiplier = 1.5;
	case Personality::Calm:
		multiplier = 1.0;
	default:
		multiplier = 1.0;
	}

	return static_cast<int>(amount * multiplier);
}

int Creature::getModifiedHunger(int amount) const
{
	double multiplier = 1.0;

	switch (personality_)
	{
	case Personality::Shy:
		multiplier = 0.6;
	case Personality::Hungry:
		multiplier = 1.4;
	case Personality::Sick:
		multiplier = 0.8;
	case Personality::Hurt:
		multiplier = 0.7;
	case Personality::Playful:
		multiplier = 1.5;
	case Personality::Calm:
		multiplier = 1.0;
	default:
		multiplier = 1.0;
	}

	return static_cast<int>(amount * multiplier);
}

int Creature::getModifiedGrowth(int amount) const
{
	double multiplier = 1.0;

	switch (personality_)
	{
	case Personality::Shy:
		multiplier = 0.6;
	case Personality::Hungry:
		multiplier = 1.4;
	case Personality::Sick:
		multiplier = 0.8;
	case Personality::Hurt:
		multiplier = 0.7;
	case Personality::Playful:
		multiplier = 1.5;
	case Personality::Calm:
		multiplier = 1.0;
	default:
		multiplier = 1.0;
	}

	return static_cast<int>(amount * multiplier);
}

int Creature::getModifiedInteraction(int amount) const
{
	double multiplier = 1.0;

	switch (personality_)
	{
	case Personality::Shy:
		multiplier = 0.6;
	case Personality::Hungry:
		multiplier = 1.4;
	case Personality::Sick:
		multiplier = 0.8;
	case Personality::Hurt:
		multiplier = 0.7;
	case Personality::Playful:
		multiplier = 1.5;
	case Personality::Calm:
		multiplier = 1.0;
	default:
		multiplier = 1.0;
	}

	return static_cast<int>(amount * multiplier);
}

void Creature::changeAffection(int amount)
{
	int finalChange = getModifiedAffection(amount);
	affection_ = limitStat(affection_ + finalChange);
}

void Creature::changeGrowth(int amount)
{
	int finalChange = getModifiedGrowth(amount);
	growth_ = limitStat(growth_ + finalChange);
}

void Creature::changeHunger(int amount)
{
	int finalChange = getModifiedHunger(amount);
	hunger_ = limitStat(hunger_ + finalChange);
}

void Creature::changeInteraction(int amount)
{
	int finalChange = getModifiedInteraction(amount);
	interaction_ = limitStat(interaction_ + finalChange);
}

void Creature::changeHealth(int amount)
{
	health_ = limitStat(health_ + amount);
}

void Creature::setName(const std::string& name)
{
	name_ = name;
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
	std::uniform_int_distribution<int> distribution(0, 6);

	return static_cast<Personality>(distribution(rng));
}
