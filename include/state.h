#ifndef STATE_H
#define STATE_H

#include <iostream>
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
       virtual void DisplayOptions() = 0;
       virtual void HandleInput() = 0;
       virtual void leave() = 0; //leave state, free memory
       
       void loop();
};


#endif
