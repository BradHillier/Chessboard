#include "../include/state.h"
#include "../include/sdl_chess_game.h"


 State::State(SDLChessGame* parent) 
 { 
    parent_ = parent; 
 }

       
void State::loop() 
{
    enter();
    do {
       DisplayOptions();
       HandleInput();
    } while (LoopCondition());
    leave();
}
