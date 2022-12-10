#ifndef MAINMENU_H
#define MAINMENU_H

#include "state.h"

class MainMenu : public State
{
private:
   virtual bool LoopCondition() override;
public:
    MainMenu(SDLChessGame* parent);
    virtual ~MainMenu();

    void enter() override;
    void leave() override;
    virtual void Render() override;

    virtual void HandleInput() override;
};

#endif
