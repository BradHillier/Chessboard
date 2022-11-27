#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../include/effects.h"
using namespace std;


class SDLChessGame;


class State
{
   private:

      virtual bool LoopCondition() = 0;

   protected:

       SDLChessGame* parent_;

   public:

       State(SDLChessGame* parent);
       virtual ~State() {}

       virtual void enter() = 0; //initialize
       virtual void Render() = 0;
       virtual void leave() = 0; //leave state, free memory

       virtual void HandleInput() = 0;
       
       void loop();
};


#endif
