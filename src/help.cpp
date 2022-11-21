#include "../include/help.h"
#include "../include/sdl_chess_game.h"


Help::Help(SDLChessGame* parent)
   : State(parent)
{
}


Help::~Help()
{
}


void Help::enter()
{
    cout<<"Entered Help State"<<endl;
    cout<<endl;
}


bool Help::LoopCondition()
{
   return parent_->current_state() == SDLChessGame::help;
}


void Help::DisplayOptions()
{
   cout<<"############################"<<endl;
   cout<<"######SOME HELP TEXT########"<<endl;
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


void Help::HandleInput()
{
   int num;
   cin >> num;

   switch (num)
   {
      case 1:
         parent_->ChangeState(SDLChessGame::main_menu);
         break;
      case 2:
         leave();
         exit(0); 
   }
}


void Help::leave()
{
    cout<<"Leaving Help State"<<endl;
    cout<<endl;
}
