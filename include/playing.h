#ifndef PLAYING_H
#define PLAYING_H

#include "state.h"

class Playing : public State
{
private:
   virtual bool LoopCondition() override;
public:
    Playing(SDLChessGame* parent);
    virtual ~Playing();

    void enter();
    void leave();
    virtual void DisplayOptions() override;
    virtual void HandleInput() override;
};

#endif
