#include "../include/main_menu.h"
#include "../include/sdl_chess_game.h"


MainMenu::MainMenu(SDLChessGame* parent)
   : State(parent)
{
}


MainMenu::~MainMenu()
{
}


bool MainMenu::LoopCondition()
{
   return parent_->current_state() == SDLChessGame::main_menu;
}


void MainMenu::enter()
{
    cout<<"Entered Main Menu State"<<endl;
    cout<<endl;
}


void MainMenu::DisplayOptions()
{
   cout<<"1. play"<<endl;
   cout<<"2. credits"<<endl;
   cout<<"3. help"<<endl;
   cout<<"4. quit"<<endl;
}


void MainMenu::HandleInput()
{
   int num;
   cin >> num;

   switch (num)
   {
      case 1:
         parent_->ChangeState(SDLChessGame::playing);
         break;
      case 2:
         parent_->ChangeState(SDLChessGame::credits);
         break;
      case 3:
         parent_->ChangeState(SDLChessGame::help);
         break;
      case 4:
         leave();
         exit(0);
   }
}


void MainMenu::leave()
{
   cout<<"Leaving Main Menu State"<<endl;
   cout<<endl;
}
