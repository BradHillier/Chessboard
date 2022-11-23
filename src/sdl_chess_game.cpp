#include "../include/sdl_chess_game.h"


SDLChessGame::SDLChessGame()
{
   main_menu_state_ = new MainMenu(this);
   playing_state_ = new Playing(this);
   help_state_ = new Help(this);
   credits_state_ = new Credits(this);

   currState = main_menu_state_;
   controller = new Controller();
}


SDLChessGame::~SDLChessGame()
{
   delete main_menu_state_; 
   delete playing_state_; 
   delete help_state_ ;
   delete credits_state_;
}


void SDLChessGame::RunLoop()
{
   while (true) {
      currState->loop();
   }
}


bool  SDLChessGame::ChangeState(state next)
{
   switch (next) {
      case main_menu:
         currState = main_menu_state_;
         break;
      case playing:
         currState = playing_state_;
         break;
      case credits:
         currState = credits_state_;
         break;
      case help:
         currState = help_state_;
         break;
   }
}


SDLChessGame::state SDLChessGame::current_state() 
{
   if (currState == main_menu_state_) {
      return main_menu;
   } 
   if (currState == playing_state_) {
      return playing;
   } 
   if (currState == help_state_) {
      return help;
   }
   if (currState == credits_state_) {
      return credits;
   }
}
