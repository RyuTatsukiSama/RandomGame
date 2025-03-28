#ifndef RANDMENU_H
#define RANDMENU_H

#include "../Common/common.h"

class RandMenu
{
public:
    RandMenu() {}
    ~RandMenu() {}
    STATE Update();

private:
    void SearchInDirectory(std::filesystem::directory_entry directory);
};

#endif