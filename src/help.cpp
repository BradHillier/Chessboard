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


void Help::Render()
{
   const char* help_text =
   "Navigation: Follow the instructions\n"
   "on each screen to navigate using\n"
   "using the numbers\n"
   "The game follows standard chess\n"
   "rules and a winner is determined by\n"
   "the taking of a king piece\n";

   chgText(Yellow);
   parent_->center(parent_->game_title);
   chgText(DefCol);

   cout << string(2, '\n');

   chgFormat(Bold);
   parent_->center("HELP");
   chgFormat(DefForm);

   cout << string(1, '\n');

   parent_->center(help_text);

   cout << string(2, '\n');

   long width, height;
   getTermSize(height, width);
   cout << string(width, '_') << endl;

   cout<<"1. Main Menu"<<endl;
   cout<<"2. Quit"<<endl;
}


void Help::HandleInput()
{
   char num;
   bool input_recieved = false;
   do 
   {
      input_recieved = keyQuick(num);
   } 
   while (!input_recieved);

   switch (num)
   {
      case '1':
         parent_->ChangeState(SDLChessGame::main_menu);
         break;
      case '2':
         leave();
         exit(0); 
   }
}


void Help::leave()
{
    cout<<"Leaving Help State"<<endl;
    cout<<endl;
}
