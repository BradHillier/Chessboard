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


void MainMenu::Render()
{
   chgText(Yellow);
   parent_->center(parent_->game_title);
   chgText(DefCol);

   cout << string(2, '\n');
   const char* menu_options = 
   "1. start   \n"
   "2. help    \n"
   "3. credits \n"
   "4. exit    \n";
   parent_->center(menu_options);
}


void MainMenu::HandleInput()
{
   char num;
   bool isSuccessful = false;
   do
   {
      isSuccessful = keyQuick(num);
   } while (!isSuccessful);

   switch (num)
   {
      case '1':
         parent_->ChangeState(SDLChessGame::playing);
         break;
      case '2':
         parent_->ChangeState(SDLChessGame::help);
         break;
      case '3':
         parent_->ChangeState(SDLChessGame::credits);
         break;
      case '4':
         leave();
         exit(0);
   }
}


void MainMenu::leave()
{
   cout<<"Leaving Main Menu State"<<endl;
   cout<<endl;
}
