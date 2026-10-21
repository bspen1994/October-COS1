#include <iostream>
#include "mainLoop.h"
#include "display.h"

int main()
{
    display display;

    while (true)
    {
        display.clearScreen();
        display.showMainMenu();

        int choice;
        if (!(std::cin >> choice))
        {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            mainLoop game;
            game.run();
            
        }
            break;
        case 2:
            display.clearScreen();
            display.getInstructions();
            std::cin.get();
            break;
        case 3:
            std::cout << "Thank you for playing!\n";
            return 0;
        default:
            std::cout << "Invalid option. Please selecet 1 - 3.\n";
            std::cin.get();
            break;
        }

    }

}

