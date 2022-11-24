#ifndef CREDITS_H
#define CREDITS_H

#include "state.h"

class Credits : public State
{
private:
   virtual bool LoopCondition() override;
public:
    Credits(SDLChessGame* parent);
    virtual ~Credits();

    void enter();
    void leave();
    virtual void DisplayOptions() override;
    virtual void HandleInput() override;
};

#endif
