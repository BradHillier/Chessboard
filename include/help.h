#ifndef HELP_H
#define HELP_H

#include "state.h"

class Help : public State
{
private:
    /* data */
public:
    Help(/* args */);
    virtual ~Help();

    void enter();
    void update();
    void leave();
};

#endif