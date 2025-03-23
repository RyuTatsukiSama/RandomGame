#include "mainMenu.h"

STATE MainMenu::Update()
{
    int choice;
    std::cout << "[1] Launch Random\n [2] Settings\n [0] Quit" << std::endl;
    std::cin >> choice;

    while (choice < 0 || choice > 2)
    {
        std::cout << "Error ! Please enter a number gfrom the following options" << std::endl;
        std::cout << "[1] Launch Random\n[2] Settings\n[0] Quit" << std::endl;
        std::cin >> choice;
    }

    return (STATE)choice;
}