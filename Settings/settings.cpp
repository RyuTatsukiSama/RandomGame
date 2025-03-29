
#include "settings.h"

STATE Settings::Update()
{
    file = std::fstream("settings.txt", std::ios::out);

    if (!file.is_open())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        std::cout << "ERROR : The file settings.txt isn't open" << std::endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        system("pause");
        system("cls");
        return MAINMENU;
    }
    else
    {
        WritePathInFile();

        BrowseSettingsFile();

        WriteExeInFile();

        system("pause");
        system("cls");
        return MAINMENU;
    }
}

void Settings::WritePathInFile()
{
    std::cout << "Please enter the path where you'r game are install\nSperate them with \" _ \" \nEnter \"0\" to exit" << std::endl;
    std::string path = "";
    std::string input = "";

    do
    {
        std::cin >> input;

        if (input == "_")
        {
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
    } while (input != "0");

    file.close();
}

void Settings::BrowseSettingsFile()
{
    file = std::fstream("settings.txt", std::ios::in);

    std::vector<std::string> pathVec;
    std::string currentPath;
    std::string input;

    while (!file.eof())
    {
        file >> input;
        currentPath += input;
        if (input[input.length()-1] == '\n')
        {
            currentPath += input;
            std::cout << currentPath << std::endl;
            pathVec.push_back(currentPath);
            currentPath = "";
        }
    }

    for (const auto& path : pathVec)
    {
        std::cout << path << std::endl;
        std::filesystem::directory_entry directory(path);
        SearchInDirectory(directory);
    }
        
    file.close();
}

void Settings::SearchInDirectory(std::filesystem::directory_entry directory)
{
    for (const std::filesystem::directory_entry &entry : std::filesystem::directory_iterator(directory.path()))
    {
        if (entry.is_directory())
        {
            SearchInDirectory(entry);
        }
        else
        {
            if (entry.path().filename().extension() == ".exe")
            {
                exeVec.push_back(entry.path().filename().string());
            }
        }
    }
}

void Settings::WriteExeInFile()
{
    file = std::fstream("exeList.txt", std::ios::out);

    for (const auto &s : exeVec)
    {
        file << s << std::endl;
    }

    file.close();
}