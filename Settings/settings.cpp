
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
        std::cout << "Please enter the path where you'r game are install\nSperate them with \" _ \" \nEnter \"0\" to exit" << std::endl;
        std::string path = "";
        std::string input = "";

        int count = 0;
        do
        {
            std::cin >> input;

            if (input == "_")
            {
                std::cout << "Path enter " << path << std::endl;
                file << path << std::endl;
                path = "";
            }
            else
            {
                if (path != "")
                {
                    path += " ";
                }

                path += input;
            }
            std::cout << "input : " << input << std::endl;
            count++;
        } while (input != "0");

        file.close();

        system("pause");
        system("cls");
        return MAINMENU;
    }
}

void Settings::WriteInFile(std::string _path)
{
}