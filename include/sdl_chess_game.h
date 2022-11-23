#ifndef SDLCHESSGAME
#define SDLCHESSGAME

#include "main_menu.h"
#include "playing.h"
#include "help.h"
#include "credits.h"
#include "globals.h"
#include "chess_controller.h"


class SDLChessGame 
{
   private:
     State* currState; 
     Controller* controller;

     MainMenu* main_menu_state_;
     Playing* playing_state_;
     Help* help_state_;
     Credits* credits_state_;

   public:
      SDLChessGame();
      ~SDLChessGame();

      enum state
      { 
         main_menu, 
         playing,
         help,
         credits
      };

      state current_state();

      bool  ChangeState(state next);
      void RunLoop();
};

#endif
