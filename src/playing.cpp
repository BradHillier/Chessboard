#include "../include/playing.h"
#include "../include/sdl_chess_game.h"

Playing::Playing(SDLChessGame* parent)
   :State(parent)
{
}


Playing::~Playing()
{
}


bool Playing::LoopCondition()
{
   return parent_->current_state() == SDLChessGame::playing;
}


void Playing::enter()
{
    cout<<"Entered Playing State"<<endl;
    cout<<endl;
}


void Playing::DisplayOptions()
{
   cout<<"############################"<<endl;
   cout<<"PLAYING STATE"<<endl;
   cout<<"GAME PLAYED HERE"<<endl;
   cout<<"############################"<<endl;

   cout<<endl;
   cout<<endl;

   cout<<"********************"<<endl;
   cout<<"********************"<<endl;

   cout<<endl;
   cout<<endl;

   cout<<"1. Main Menu"<<endl;
   cout<<"2. Quit"<<endl;
}


void Playing::HandleInput()
{
   int num;
   cin >> num;

   switch (num)
   {
   case 1:
      leave();
      parent_->ChangeState(SDLChessGame::main_menu);
      break;
   case 2:
      leave();
      exit(0); 
   }
}


void Playing::leave()
{
    cout<<"Leaving Playing State"<<endl;
    cout<<endl;
}
