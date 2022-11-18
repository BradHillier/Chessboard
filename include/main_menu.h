#ifndef MAINMENU_H
#define MAINMENU_H

#include "state.h"

class MainMenu : public State
{
private:
    /* data */
public:
    MainMenu(/* args */);
    virtual ~MainMenu();

    void enter();
    void update();
    void leave();
};

#endif
