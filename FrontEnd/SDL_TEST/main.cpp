#include  "GameState.h"

int main(int argc, char ** args){

 //Uint32 starting_tick;

 //for testing create a state object(any state)
 //call update see if image loads
    
   while(true)
   {
      //starting_tick = SDL_GetTicks();
      GameState:: currGameState->enter();
      GameState:: currGameState->update();
      //limit_Fps(starting_tick);
   }
   delete GameState::menu;
   delete GameState::help;
   delete GameState::credits;
   delete GameState::play;
   return 0;
}
