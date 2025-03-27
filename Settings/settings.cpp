
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
        int count = 0;
        do
        {
            std::cin >> path;
            file << path << std::endl;
            std::cout << path << "/" << count << std::endl;
            count++;
        } while (path != "\n" && count < 3);
        
        file.close();

        system("pause");
        system("cls");
        return MAINMENU;
    }
}

void Settings::WriteInFile(std::string _path)
{
    
}