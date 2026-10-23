#include <iostream>
#include "mainLoop.h"
#include "display.h"

int main()
{
    //Create display object to call ui functions
    display display;

    while (true)
    {
        display.clearScreen(); //Clears the screen pre-emptively for return to menu
        display.showMainMenu(); //Main menu function to show the ui for the main menu

        int choice;

        choice = display.inputValidate(1, 4); //Takes in user input and gives it 1-4 range

        switch (choice)
        {
        case 1:
        {
            mainLoop game; //Creates a mainLoop object to call funtions on
            game.run(false); //New game is false to avoid loading from file
            break;
        }
            break;
        case 2:
        {
            mainLoop game; //Create a mainLoop object to call functions on
            game.run(true); //Loading from save is true to run the loadGame method
            break;
        }
        case 3:
            display.clearScreen(); //Clears main menu UI
            display.getInstructions(); //Brings up the instructions for the game
            break;
        case 4:
            std::cout << "Thank you for playing!\n"; //This case quits the game
            return 0;
        default:
            break;
        }

    }

}

