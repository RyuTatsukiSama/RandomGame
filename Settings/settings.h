#ifndef SETTINGS_H
#define SETTINGS_H

#include "../Common/common.h"

class Settings
{
public:
    Settings() {}
    ~Settings() {}
    STATE Update();

private:
    void WritePathInFile();
    void BrowseSettingsFile();
    void SearchInDirectory(std::filesystem::directory_entry directory);
    void WriteExeInFile();

    std::fstream file;
    std::unordered_map<std::string,int> ignore;
    std::vector<std::string> exeVec;
};

#endif
