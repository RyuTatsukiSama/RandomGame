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

            file.close();
            system("pause");
            system("cls");
            return MAINMENU;
        }

        std::string path;
        file >> path;

        std::cout << path << std::endl;

        std::filesystem::directory_entry directory(path);
        SearchInDirectory(directory);

        file.close();
        system("pause");
        system("cls");
        return MAINMENU;
    }
}

void RandMenu::SearchInDirectory(std::filesystem::directory_entry directory)
{
    for (const std::filesystem::directory_entry &entry : std::filesystem::directory_iterator(directory.path()))
    {
        if (entry.is_directory())
        {
            SearchInDirectory(entry);
        }
        else
        {
            // For checking if the path is an exe, try to turn it into a array and check the four last char to know if they are 'e' 'x' 'e' '.'

            if (entry.path().filename().extension() == ".exe")
            {
                std::cout << entry.path().filename() << std::endl;
            }
        }
    }
}