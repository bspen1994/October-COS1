#include "display.h"
#include <iostream>

std::string display::getArt(const Creature& creature)
{
    std::string creatureArt = ""; //created string that acts like a char array

    const char* headLines = "  /\\ ___/\\"; //Top of pet art

    std::string currentEyes; //Empty eyes string to change depending on personality
    std::string currentMouth; //Empty mouth string to chage depending on personality

    bool sickState = false; 
    bool hungerState = false; //Initial sick and hunger state for eye/mouth personality

    bool isCriticalHealth = creature.health() <= 30;
    bool isCriticalHunger = creature.hunger() <= 20; //Setting threshold for sick and hungry eyes/mouth

    if (isCriticalHealth || creature.personality() == Creature::Personality::Sick)
    {
        sickState = true; //Check threshold for sick and adds sickstate mouth/eyes set
    }
    if (isCriticalHunger || creature.personality() == Creature::Personality::Hungry)
    {
        hungerState = true; //Check threshhol for Hungry and adds hungrystate mouth/eyes set
    }

    const char* normalEyes = " (  o   o )";
    const char* normalMouth = " \\  >#<  /"; //Default eyes and mouth set

    if (sickState)
    {
        currentEyes = " (  x   x )";
        currentMouth = " \\ >x< / "; //sickset eyes and mouth
    }
    else if (hungerState)
    {
        currentEyes = " (   >o<   )";
        currentMouth = " \\  <---> / "; //hungryset eyes and mouth
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

    return creatureArt; //returns drawn creature with the set string/char array above

}

void display::clearScreen()
{
#ifdef _WIN32 || defined(__CYGWIN__)
    std::system("cls");
#else
    std::system("clear");
#endif //OS agnostic clearscreen
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
    //Pretty straightforward UI drawing for the instructions
    std::string dummy;
    std::getline(std::cin, dummy); //Pauses the console to allow player to read the instructions
}

void display::showMainMenu() const
{
    std::cout << "\t=== Pet Keeper ===\n";
    std::cout << "Welcome to your friend caretaker app!\n\n";
    std::cout << "Please select an option below:\n";
    std::cout << "1: New Game\n";
    std::cout << "2: Load Saved Game\n";
    std::cout << "3: Instructions\n";
    std::cout << "4: Exit game\n\n";
    std::cout << "Enter choice (1-4): ";
    //Main menu UI
}

void display::showGameMenu() const
{
    std::cout << "\n1. Feed\n";
    std::cout << "2: Play\n";
    std::cout << "3: Give Medication\n";
    std::cout << "0: Return to Pet Selection\n";
    std::cout << "Choose an action: ";
    //Main game UI to care for your pet
}

void display::showStableMenu() const
{
    std::cout << "=== Pet Stable ===\n\n";
    std::cout << "\nOptions:\n";
    std::cout << "1: Select a creature to manage\n";
    std::cout << "2: Hatch a new creature\n";
    std::cout << "3: Save Game\n";
    std::cout << "0: Quit to Main Menu\n\n";
    std::cout << "Choice: ";
    //Pet managment menu UI
}

int display::inputValidate(int min, int max) const
{
    std::string input;
    int number;
    //User validation that uses the range specified to allow selection of items
    while (true)
    {
        std::getline(std::cin, input);
        try
        {
            number = std::stoi(input);
            if (number >= min && number <= max)
            {
                return number;
            }
            std::cout << "Invalid choice. Please enter a number between " << min << ", and " << max << ": ";
        }
        catch (...)
        {
            std::cout << "Invalid choice. Please enter a number between " << min << ", and " << max << ": ";
        }
    }
}
