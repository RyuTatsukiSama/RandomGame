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
    void WriteInFile();

    std::fstream file;
};

#endif
