#include "Common/common.h"
#include "Main Menu/mainMenu.h"

int main()
{
    MainMenu menu;

    STATE state = menu.Update();

    while (state != QUIT)
    {
        switch (state)
        {
        case MAINMENU:
            state = menu.Update();
            break;
        case SETTINGS:
            break;
        case RAND:
            break;
        default:
            break;
        }
    }

    return 0;
}