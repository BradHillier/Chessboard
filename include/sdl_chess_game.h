#ifndef SDLCHESSGAME
#define SDLCHESSGAME

#include "main_menu.h"
#include "playing.h"
#include "help.h"
#include "credits.h"
#include "globals.h"


class SDLChessGame 
{
   public:

      enum state { main_menu, playing, help, credits };
      SDLChessGame();
      ~SDLChessGame();

      const char* game_title;
      state current_state();

      bool ChangeState(state next);
      void RunLoop();
      void center(string text);

   private:
       state current_state_;
       State* InstanceOf(state s);

       MainMenu* main_menu_state_;
       Playing* playing_state_;
       Help* help_state_;
       Credits* credits_state_;

};

#endif
