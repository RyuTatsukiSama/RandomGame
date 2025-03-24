#include "randMenu.h"

STATE RandMenu::Update()
{
    std::fstream file("settings.txt", std::ios::in);

    if (!file.is_open())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        std::cout << "ERROR : No settings file detected please go create it in the settings menu" << std::endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        system("pause");
        system("cls");
        return MAINMENU;
    }
    else
    {
        if (file.peek() == std::ifstream::traits_type::eof())
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            std::cout << "ERROR : The settings file is empty, please go to settings menu to fill it" << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            system("pause");
            system("cls");
            return MAINMENU;
        }

        system("pause");
        system("cls");
        return MAINMENU;
    }
}