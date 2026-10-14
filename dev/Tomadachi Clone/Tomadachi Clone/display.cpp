#include "display.h"
#include <iostream>

std::string display::getArt(const Creature& creature)
{
    std::string creatureArt = "";

    const char* headLines = "  /\\ ___/\\";

    std::string currentEyes;
    std::string currentMouth;

    bool sickState = false;
    bool hungerState = false;

    bool isCriticalHealth = creature.health() <= 30;
    bool isCriticalHunger = creature.hunger() <= 20;

    if (isCriticalHealth || creature.personality() == Creature::Personality::Sick)
    {
        sickState = true;
    }
    if (isCriticalHunger || creature.personality() == Creature::Personality::Hungry)
    {
        hungerState = true;
    }

    const char* normalEyes = " (  o   o )";
    const char* normalMouth = " \\  >#<  /";

    if (sickState)
    {
        currentEyes = " (  x   x )";
        currentMouth = " \\ >x< / ";
    }
    else if (hungerState)
    {
        currentEyes = " (   >o<   )";
        currentMouth = " \\  <---> / ";
    }
    else
    {
        currentEyes = normalEyes;
        currentMouth = normalMouth;
    }

    creatureArt += "\n";

    creatureArt += headLines;
    creatureArt += "\n";

    creatureArt += currentEyes;
    creatureArt += "\n";

    creatureArt += currentMouth;
    creatureArt += "\n";

    creatureArt += "/       \\\n";
    creatureArt += "/         \\\n";
    creatureArt += "|           |\n";
    creatureArt += "\\         /\n";
    creatureArt += "///  ///   --\n";

    return creatureArt;

}

void display::clearScreen()
{
#ifdef _WIN32 || defined(__CYGWIN__)
    std::system("cls");
#else
    std::system("clear");
#endif
}

void display::getInstructions()
{
    std::cout << "\t ~Instructions~\n";
    std::cout << "You must keep your pet happy and healthy.\n";
    std::cout << "You can do this by using the provided options: \n";
    std::cout << "1. Feed: This gives your pet food and fills their hunger bar.\n";
    std::cout << "2. Pet: This allows you to pet your pet and fills the affection bar.\n";
    std::cout << "3. Give Medicine: This heals your pet but also lowers their hunger bar.\n";
    std::cout << "Press enter to return to previous menu.\n";
    std::cin.get();
    
}