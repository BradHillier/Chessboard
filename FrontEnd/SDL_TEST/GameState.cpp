#include "GameState.h"

//////////////////////////////
/////////Global space/////////
//////////////////////////////

// i tried putting it in .h but with whatever lil testing i did it seems to like it here
SDL_Window * GameState::win = SDL_CreateWindow("STATE MACHINE" , SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, 960,960,0); // width and height are hard coded for now
SDL_Renderer * GameState::ren = SDL_CreateRenderer(win,-1,0); //rendererer

GameState * GameState::menu = new Menu;
GameState * GameState::help = new Help;
GameState * GameState::credits = new Credits;
GameState * GameState::play = new Play;

GameState * GameState::currGameState = menu;

//Mouse* GameState::mouse = new Mouse(ren);

void GameState::shutdown(){

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    exit();

}

void GameState::limit_Fps(Uint32 start_tick){

    if ((1000/fps) > SDL_GetTicks() - start_tick)
        {
            //SDL delay slows down SDL
            SDL_Delay(1000/fps - (SDL_GetTicks()- start_tick));
        }

}

///////////////////////////
//////////menu/////////////
///////////////////////////

Menu::Menu(/* args */)
{
    backgroundTexture = IMG_LoadTexture(ren,"MENU_SCREEN.png"); //menu background.png (temp for now) path to the background

    //error checking 
    if(!backgroundTexture){
        cout << "Menu constructor: Load background" << SDL_GetError()<<endl;
    }    
}

Menu::~Menu()
{

    SDL_DestroyTexture(backgroundTexture); //it only loads it once but just for good measure, we prevent any memory leaks 

}

void Menu::enter(){}

void Menu::update(){

    Uint32 starting_tick;

    while (currGameState == GameState::menu)
    {
        starting_tick = SDL_GetTicks();
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type){
                case SDL_QUIT:
                    shutdown();
                    break;
                case SDL_KEYDOWN:
                   if(e.key.keysym.sym == SDLK_ESCAPE){
                       shutdown();
                       break;
                   }
                   if(e.key.keysym.sym == SDLK_1){
                       //change state by pressing 1
                       currGameState = play; //get outta the loop when change state
                        break;
                   }
                   if(e.key.keysym.sym == SDLK_2){
                       //change state by pressing 1
                       currGameState = help; //get outta the loop when change state
                        break;
                   }
                   if(e.key.keysym.sym == SDLK_3){
                       //change state by pressing 1
                       currGameState = credits; //get outta the loop when change state
                        break;
                   }
            }
        }

        //using sdl enums for all gamestates

        SDL_RenderClear(ren);
        SDL_Rect rect = {0,0,960,960};
        SDL_RenderCopy(ren,backgroundTexture,NULL,&rect); // NULL stretches the image to the entire screen
        SDL_RenderPresent(ren);
        limit_Fps(starting_tick);
    }//menu loop
}


void Menu::exit(){}


///////////////////////////
//////////help/////////////
///////////////////////////

Help::Help(/* args */){

    backgroundTexture = IMG_LoadTexture(ren,"HELP_SCREEN.png"); //menu background.png (temp for now) path to the background

    //error checking 
    if(!backgroundTexture){
        cout << "Help constructor: Load background" << SDL_GetError()<<endl;
    }    


}

Help::~Help(){

    SDL_DestroyTexture(backgroundTexture); //it only loads it once but just for good measure, we prevent any memory leaks 

}

void Help::enter(){}

void Help::update(){

    Uint32 starting_tick;

    while (currGameState == GameState::help)
    {   
        starting_tick = SDL_GetTicks();
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type){
                case SDL_QUIT:
                    shutdown();
                    break;
                 case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_ESCAPE){
                        shutdown();
                        break;
                    }
                    if(e.key.keysym.sym == SDLK_1){
                        //change state, go back to main menu
                        currGameState = menu; //get outta the loop when change state
                        break;
                    }
            }
        }


        SDL_RenderClear(ren);
        SDL_Rect rect = {0,0,960,960};
        SDL_RenderCopy(ren,backgroundTexture,NULL,&rect); // NULL stretches the image to the entire screen
        SDL_RenderPresent(ren);
        limit_Fps(starting_tick);
        
    }


}

void Help::exit(){}

///////////////////////////
//////////play/////////////
///////////////////////////

Play::Play(/* args */){

    controller = new Controller();

    backgroundTexture = IMG_LoadTexture(ren,"PLAY_SCREEN.png"); //menu background.png (temp for now) path to the background

    W_King_Texture = IMG_LoadTexture(ren,"W_King.png");
    W_Queen_Texture = IMG_LoadTexture(ren,"W_Queen.png");
    W_Rook_Texture = IMG_LoadTexture(ren,"W_Rook.png");
    W_Knight_Texture = IMG_LoadTexture(ren,"W_Knight.png"); 
    W_Bishop_Texture = IMG_LoadTexture(ren,"W_Bishop.png");
    W_Pawn_Texture = IMG_LoadTexture(ren,"W_Pawn.png");

    B_King_Texture = IMG_LoadTexture(ren,"B_King.png");
    B_Queen_Texture = IMG_LoadTexture(ren,"B_Queen.png");
    B_Rook_Texture = IMG_LoadTexture(ren,"B_Rook.png");
    B_Knight_Texture = IMG_LoadTexture(ren,"B_Knight.png"); 
    B_Bishop_Texture = IMG_LoadTexture(ren,"B_Bishop.png");
    B_Pawn_Texture = IMG_LoadTexture(ren,"B_Pawn.png");
    //error checking 
    if(!backgroundTexture){
        cout << "Play constructor: Load background" << SDL_GetError()<<endl;
    }    
}

Play::~Play(){

    SDL_DestroyTexture(backgroundTexture); //it only loads it once but just for good measure, we prevent any memory leaks 

    SDL_DestroyTexture(W_King_Texture);
    SDL_DestroyTexture(W_Queen_Texture);
    SDL_DestroyTexture(W_Rook_Texture);
    SDL_DestroyTexture(W_Knight_Texture);
    SDL_DestroyTexture(W_Bishop_Texture);
    SDL_DestroyTexture(W_Pawn_Texture);

    SDL_DestroyTexture(B_King_Texture);
    SDL_DestroyTexture(B_Queen_Texture);
    SDL_DestroyTexture(B_Rook_Texture);
    SDL_DestroyTexture(B_Knight_Texture);
    SDL_DestroyTexture(B_Bishop_Texture);
    SDL_DestroyTexture(B_Pawn_Texture);
}

void Play::enter(){}

void Play::update(){

    Uint32 starting_tick;

    while (currGameState == GameState::play)
    {
        starting_tick = SDL_GetTicks();
        int source_x,source_y, dest_x,dest_y;
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type){
                case SDL_QUIT:
                    shutdown();
                    break;
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_ESCAPE){
                        shutdown();
                        break;
                    }
                    if(e.key.keysym.sym == SDLK_1){
                        //change state, go back to main menu
                        currGameState = menu; //get outta the loop when change state
                        controller->ResetGame();
                        break;
                    }
                case SDL_MOUSEBUTTONDOWN:
                    SDL_GetMouseState(&source_x,&source_y);
                    source_x = 7 - (abs(source_x-960)) / 120;
                    source_y = 7 - (abs(source_y - 960)) /120 ;
                    controller->ProcessClick(Position(source_y, source_x));
                    break;
                    
            }
        }
        map<int,SDL_Texture*> pieces = {{-1,B_Pawn_Texture} , {-2,B_Rook_Texture} , {-3, B_Knight_Texture},
                                 {-4,B_Bishop_Texture} , {-5,B_Queen_Texture }, {-6 ,B_King_Texture},
                                 {1,W_Pawn_Texture} , {2,W_Rook_Texture} , {3, W_Knight_Texture},
                                 {4,W_Bishop_Texture} , {5,W_Queen_Texture } , {6 ,W_King_Texture}};

        SDL_RenderClear(ren);
        //background rect
        SDL_Rect rect = {0,0,960,960};
        //background copied to renderer
        SDL_RenderCopy(ren,backgroundTexture,NULL,&rect); // NULL stretches the image to the entire screen


        for (int row = 0; row < 8; row++) 
        {
            for (int col = 0; col < 8; col++) 
            {
                rect.x = PIECE_X_OFFSET + (120*col);
                rect.y = PIECE_Y_OFFSET + (120*row);
                rect.w = PIECE_WIDTH;
                rect.h = PIECE_HEIGHT;
                if (controller->GetSelectedPiece() == Position(row, col)) {
                   SDL_SetRenderDrawColor(ren, 0, 255, 0, SDL_ALPHA_OPAQUE);
                   SDL_RenderFillRect(ren, &rect);
                } else if (controller->GetLegalMoves().contains(Position(row, col))) {
                   SDL_SetRenderDrawColor(ren, 255, 255, 0, SDL_ALPHA_OPAQUE);
                   SDL_RenderDrawRect(ren, &rect);
                }
                switch(controller->GetBoard()[row][col]){
                case -1:
                    SDL_RenderCopy(ren,pieces[-1],NULL,&rect);
                    break;
                case -2:
                    SDL_RenderCopy(ren,pieces[-2],NULL,&rect);
                    break;
                case -3:
                    SDL_RenderCopy(ren,pieces[-3],NULL,&rect);
                    break;
                case -4:
                    SDL_RenderCopy(ren,pieces[-4],NULL,&rect);
                    break;
                case -5:
                    SDL_RenderCopy(ren,pieces[-5],NULL,&rect);
                    break;
                case -6:
                    SDL_RenderCopy(ren,pieces[-6],NULL,&rect);
                    break;
                case 1:
                    SDL_RenderCopy(ren,pieces[1],NULL,&rect);
                    break;
                case 2:
                    SDL_RenderCopy(ren,pieces[2],NULL,&rect);
                    break;
                case 3:
                    SDL_RenderCopy(ren,pieces[3],NULL,&rect);
                    break;
                case 4:
                    SDL_RenderCopy(ren,pieces[4],NULL,&rect);
                    break;
                case 5:
                    SDL_RenderCopy(ren,pieces[5],NULL,&rect);
                    break;
                case 6:
                    SDL_RenderCopy(ren,pieces[6],NULL,&rect);
                    break;
                  
                default:
                    break;
                }
            }
        }
        SDL_RenderPresent(ren);
        limit_Fps(starting_tick);   
    }

}

void Play::exit(){}


//////////////////////////////
//////////credits/////////////
//////////////////////////////

Credits::Credits(/* args */){

    backgroundTexture = IMG_LoadTexture(ren,"CREDITS_SCREEN.png"); //menu background.png (temp for now) path to the background

    //error checking 
    if(!backgroundTexture){
        cout << "Credits constructor: Load background" << SDL_GetError()<<endl;
    }    


}

Credits::~Credits(){

    SDL_DestroyTexture(backgroundTexture); //it only loads it once but just for good measure, we prevent any memory leaks 
    
}

void Credits::enter(){}

void Credits::update(){

    Uint32 starting_tick;
    
    while (currGameState == GameState::credits)
    {
        starting_tick = SDL_GetTicks();
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type){
                case SDL_QUIT:
                    shutdown();
                    break;
                case SDL_KEYDOWN:
                   if(e.key.keysym.sym == SDLK_ESCAPE){
                       shutdown();
                       break;
                   }
                   if(e.key.keysym.sym == SDLK_1){
                       //change state, go back to main menu
                       currGameState = menu; //get outta the loop when change state
                        break;
                   }
            }
        }

        SDL_RenderClear(ren);
        SDL_Rect rect = {0,0,960,960};
        SDL_RenderCopy(ren,backgroundTexture,NULL,&rect); // NULL stretches the image to the entire screen
        SDL_RenderPresent(ren);
        
        limit_Fps(starting_tick);
    }

}

void Credits::exit(){}
