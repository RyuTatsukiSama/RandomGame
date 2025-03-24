
#include "settings.h"

STATE Settings::Update()
{
    file = std::fstream("settings.txt", std::ios::out);

    if (!file.is_open())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        std::cout << "ERROR : The file setteings.txt isn't open" << std::endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        system("pause");
        system("cls");
        return MAINMENU;
    }
    else
    {
        std::cout << "Please enter the path where you'r game are install" << std::endl;
        std::string path;
        std::getline(std::cin, path);
        std::cout << path << std::endl;

        system("pause");
        system("cls");
        return MAINMENU;
    }
}

void Settings::WriteInFile()
{

}