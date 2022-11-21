// main.cpp used for testing state machine to be demoed on 19/11                
                                                                                
#include "../include/main_menu.h"                                                          
#include "../include/help.h"                                                               
#include "../include/playing.h"                                                            
#include "../include/credits.h"                                                            
#include "../include/sdl_chess_game.h"
                                                                                
#include <iostream>                                                             
using namespace std;                                                            
                                                                                

int main()
{                                                                     
   SDLChessGame* game = new SDLChessGame();
   game->RunLoop();
   delete game;
   return 0;                                                                   
}  
