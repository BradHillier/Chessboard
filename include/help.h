#ifndef HELP_H
#define HELP_H

#include "state.h"

class Help : public State
{
private:
   virtual bool LoopCondition() override;
public:
    Help(SDLChessGame* parent);
    virtual ~Help();

    void enter();
    void leave();

    virtual void DisplayOptions() override;
    virtual void HandleInput() override;
};

#endif
