#ifndef PLAYING_H
#define PLAYING_H

#include "state.h"

class Playing : public State
{
private:
    /* data */
public:
    Playing(/* args */);
    virtual ~Playing();

    void enter();
    void update();
    void leave();
};

#endif