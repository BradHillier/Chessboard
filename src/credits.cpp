#include "../include/credits.h"
#include "../include/sdl_chess_game.h"

Credits::Credits(SDLChessGame* parent)
   :State(parent)
{
}


Credits::~Credits()
{
}


void Credits::enter()
{
    cout<<"Entered Credits State"<<endl;
    cout<<endl;

}

bool Credits::LoopCondition()
{
   return parent_->current_state() == SDLChessGame::credits;
}


void Credits::DisplayOptions() 
{
   cout<<"Brad"<<endl;
   cout<<"Josh"<<endl;
   cout<<"Ricardo"<<endl;
   cout<<"Rishabh"<<endl;

   cout<<endl;
   cout<<endl;

   cout<<"********************"<<endl;
   cout<<"********************"<<endl;

   cout<<endl;
   cout<<endl;

   cout<<"1. Main Menu"<<endl;
   cout<<"2. Quit"<<endl;
}


void Credits::HandleInput() 
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


void Credits::leave()
{
    cout<<"Leaving Credits State"<<endl;
    cout<<endl;
}
