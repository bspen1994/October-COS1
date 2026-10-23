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

        choice = display.inputValidate(1, 4);

        switch (choice)
        {
        case 1:
        {
            mainLoop game;
            game.run();
            break;
        }
            break;
        case 2:
        {
            mainLoop game;
            game.runWithLoad();
            break;
        }
        case 3:
            display.clearScreen();
            display.getInstructions();
            break;
        case 4:
            std::cout << "Thank you for playing!\n";
            return 0;
        default:
            break;
        }

    }

}

