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


void Credits::Render() 
{
   const char* credits_text = 
   "Brad    - Awarded 3 war hero medals\n"
   "Josh    - First man on the moon    \n"
   "Ricardo - Last name Fernandes      \n"
   "Rishabh - Nobel peace prize winner \n";

   chgText(Yellow);
   parent_->center(parent_->game_title);
   chgText(DefCol);

   cout << string(2, '\n');

   chgFormat(Bold);
   parent_->center("CREDITS");
   chgFormat(DefForm);

   cout << endl;

   parent_->center(credits_text);

   cout << string(2, '\n');

   long width, height;
   getTermSize(height, width);
   cout << string(width, '_') << endl;

   cout<<"1. Main Menu"<<endl;
   cout<<"2. Quit"<<endl;
}


void Credits::HandleInput() 
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


void Credits::leave()
{
    cout<<"Leaving Credits State"<<endl;
    cout<<endl;
}

