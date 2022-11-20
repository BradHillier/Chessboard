// main.cpp used for testing state machine to be demoed on 19/11                
                                                                                
#include "../include/main_menu.h"                                                          
#include "../include/help.h"                                                               
#include "../include/playing.h"                                                            
#include "../include/credits.h"                                                            
                                                                                
#include <iostream>                                                             
                                                                                
using namespace std;                                                            
                                                                                
State * State::mainMenu = new MainMenu();                                       
State * State::help = new Help();                                               
State * State::credits = new Credits();                                         
State * State::playing = new Playing();                                         
                                                                                
State * State::currState = State::mainMenu;                                     
                                                                                
int main()
{                                                                     
   while (true) {                                                                
      State::currState->enter();                                              
      State::currState->update();                                             
   }                                                                           
   return 0;                                                                   
}  
