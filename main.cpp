#include "Common/common.h"
#include "MainMenu/mainMenu.h"
#include "Settings/settings.h"
#include "RandMenu/randMenu.h"

int main()
{
    MainMenu mainMenu;
    Settings settings;
    RandMenu randMenu;

    STATE state = mainMenu.Update();

    while (state != QUIT)
    {
        switch (state)
        {
        case MAINMENU:
            state = mainMenu.Update();
            break;
        case SETTINGS:
            state = settings.Update();
            break;
        case RAND:
            state = randMenu.Update();
            break;
        default:
            break;
        }
    }

    return 0;
}