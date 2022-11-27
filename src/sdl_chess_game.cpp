#include "../include/sdl_chess_game.h"
#include "../include/playing.h"


SDLChessGame::SDLChessGame()
{
   main_menu_state_ = new MainMenu(this);
   playing_state_ = new Playing(this);
   help_state_ = new Help(this);
   credits_state_ = new Credits(this);

   current_state_ = main_menu;

   game_title = 
   "  _____ _                   _                         _ \n"
   " / ____| |                 | |                       | |\n"
   "| |    | |__   ___  ___ ___| |__   ___   __ _ _ __ __| |\n"
   "| |    | '_ \\ / _ \\/ __/ __| '_ \\ / _ \\ / _` | '__/ _` |\n"
   "| |____| | | |  __/\\__ \\__ \\ |_) | (_) | (_| | | | (_| |\n"
   " \\_____|_| |_|\\___||___/___/_.__/ \\___/ \\__,_|_|  \\__,_|\n";
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
      InstanceOf(current_state())->loop();
   }
}


bool  SDLChessGame::ChangeState(state next)
{
   current_state_ = next;
}


SDLChessGame::state SDLChessGame::current_state() 
{
   return current_state_;
}

void SDLChessGame::center(string text)
{
   long width, height;
   getTermSize(height, width);
   float padding_size; 

   stringstream strm(text);
   string line;

   while (getline(strm, line))
   {
      padding_size = (width / 2) - (line.size() / 2);
      string padding = string(padding_size, ' ');
      cout << padding << line << endl;
   }
}

State* SDLChessGame::InstanceOf(state s)
{
   switch (s) {
      case main_menu:
         return main_menu_state_;
      case playing:
         return playing_state_;
      case credits:
         return credits_state_;
      case help:
         return help_state_;
   }
}
