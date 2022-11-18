#ifndef CREDITS_H
#define CREDITS_H

#include "state.h"

class Credits : public State
{
private:
    /* data */
public:
    Credits(/* args */);
    virtual ~Credits();

    void enter();
    void update();
    void leave();
};

#endif