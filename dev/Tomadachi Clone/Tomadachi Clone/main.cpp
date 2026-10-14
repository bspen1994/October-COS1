#include <iostream>
#include "mainLoop.h"
#include "display.h"

int main()
{


    while (true)
    {
        display display;
        //display.clearScreen();

        std::cout << "\t=== Pet Keeper ===\n";
        std::cout << "Welcome to your friend caretaker app!\n\n";
        std::cout << "Please select an option below:\n";
        std::cout << "1: New Game\n";
        std::cout << "2: Instructions\n";
        std::cout << "3: Exit game\n";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            mainLoop game;
            game.run();
            break;
        }
        case 2:
            //TODO: Fill out game instructions at a later time
            display.clearScreen();
            display.getInstructions();
            std::cin.get();
            break;
        case 3:
            std::cout << "Thank you for playing!\n";
            return 0;
        default:
            std::cout << "Invalid option. Please selecet 1 - 3.\n";
            break;
        }

    }

}

