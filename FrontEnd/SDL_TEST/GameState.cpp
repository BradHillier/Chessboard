#include "GameState.h"

//////////////////////////////
/////////Global space/////////
//////////////////////////////

string APP_PATH = SDL_GetPrefPath("Prometheus", "Chessboard"); // the location of Assets and user data


// i tried putting it in .h but with whatever lil testing i did it seems to like it here
SDL_Window * GameState::win = SDL_CreateWindow("Chessboard" , SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE); // width and height are hard coded for now
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
    ::exit(0);
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

    backgroundTexture = IMG_LoadTexture(ren,(APP_PATH + "MENU_SCREEN.png").c_str()); //menu background.png (temp for now) path to the background

    //error checking 
    if (!backgroundTexture){
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
        SDL_Rect rect = {0,0,SCREEN_WIDTH, SCREEN_HEIGHT};
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

    backgroundTexture = IMG_LoadTexture(ren, (APP_PATH + "HELP_SCREEN.png").c_str());

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
        SDL_Rect rect = {0,0,SCREEN_WIDTH, SCREEN_HEIGHT};
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

    width = SCREEN_WIDTH;
    height = SCREEN_HEIGHT;

    backgroundTexture = IMG_LoadTexture(ren,(APP_PATH + "PLAY_SCREEN.png").c_str()); //menu background.png (temp for now) path to the background

    W_King_Texture = IMG_LoadTexture(ren, (APP_PATH + "W_King.png").c_str());
    W_Queen_Texture = IMG_LoadTexture(ren, (APP_PATH + "W_Queen.png").c_str());
    W_Rook_Texture = IMG_LoadTexture(ren, (APP_PATH + "W_Rook.png").c_str());
    W_Knight_Texture = IMG_LoadTexture(ren, (APP_PATH + "W_Knight.png").c_str()); 
    W_Bishop_Texture = IMG_LoadTexture(ren, (APP_PATH + "W_Bishop.png").c_str());
    W_Pawn_Texture = IMG_LoadTexture(ren, (APP_PATH + "W_Pawn.png").c_str());

    B_King_Texture = IMG_LoadTexture(ren, (APP_PATH + "B_King.png").c_str());
    B_Queen_Texture = IMG_LoadTexture(ren, (APP_PATH + "B_Queen.png").c_str());
    B_Rook_Texture = IMG_LoadTexture(ren, (APP_PATH + "B_Rook.png").c_str());
    B_Knight_Texture = IMG_LoadTexture(ren, (APP_PATH + "B_Knight.png").c_str()); 
    B_Bishop_Texture = IMG_LoadTexture(ren, (APP_PATH + "B_Bishop.png").c_str());
    B_Pawn_Texture = IMG_LoadTexture(ren, (APP_PATH + "B_Pawn.png").c_str());
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
        SDL_GetRendererOutputSize(ren, &width, &height);
        int board_pixels = min(width, height);
        if (board_pixels == height || height - width < height / 12 ) {
           // stops pieces from clipping the bottom of the screen
           board_pixels -= board_pixels / 8;
        }
        int piece_width = round(board_pixels / kBoardSize);
        int piece_height = 2 * piece_width;
        int tile_height = 15 * piece_width / 16;
        int piece_x_offset = tile_height / 4;
        int piece_y_offset = piece_x_offset;


        int start_x = (width - board_pixels) / 2;

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
                    } else if (e.key.keysym.sym == SDLK_1){
                        //change state, go back to main menu
                        currGameState = menu; //get outta the loop when change state
                        controller->ResetGame();
                        break;
                    }
                case SDL_MOUSEBUTTONDOWN:
                    SDL_GetMouseState(&source_x,&source_y);
                    source_x = (source_x - start_x) / piece_width;
                    source_y = (source_y - piece_width) / tile_height;
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
        SDL_Rect rect = {0,piece_width + 1, board_pixels, board_pixels};

        for (int row = 0; row < 8; row++) 
        {
            for (int col = 0; col < 8; col++) 
            {
                // Adjust rect for drawing highlights
                rect.x = start_x + piece_width * col;
                rect.y = piece_width + tile_height * (row);
                rect.w = piece_width;
                rect.h = tile_height;

                // draw tile background color
                if ( (col + row) % 2 == 0 ) {   // current tile is white
                   SDL_SetRenderDrawColor(ren, 235, 240, 218, SDL_ALPHA_OPAQUE);
                   SDL_RenderFillRect(ren, &rect);
                } else {                        // current tile is black
                   SDL_SetRenderDrawColor(ren, 90, 96, 111, SDL_ALPHA_OPAQUE); SDL_RenderFillRect(ren, &rect);
                }

                // highlight selected player
                if (controller->GetSelectedPiece() == Position(row, col)) {
                   SDL_SetRenderDrawColor(ren, 0, 255, 0, SDL_ALPHA_OPAQUE);
                   SDL_RenderFillRect(ren, &rect);
                }
                // highlight legal moves
                if (controller->GetLegalMoves().count(Position(row, col)) != 0) {
                   SDL_SetRenderDrawColor(ren,255, 200, 0, SDL_ALPHA_OPAQUE);
                   SDL_RenderFillRect(ren, &rect);
                }

                // fill in center so it looks like an outline
                int padding = tile_height / 16;
                padding *= 1;

                rect.x = start_x + piece_width * col + padding;
                rect.y = piece_width + tile_height * row + padding;
                rect.w = piece_width - 2 * padding;
                rect.h = tile_height - 2 * padding;

                if ( (col + row) % 2 == 0 ) {   // current tile is white
                   SDL_SetRenderDrawColor(ren, 235, 240, 218, SDL_ALPHA_OPAQUE);
                   SDL_RenderFillRect(ren, &rect);
                } else {                        // current tile is black
                   SDL_SetRenderDrawColor(ren, 90, 96, 111, SDL_ALPHA_OPAQUE); 
                   SDL_RenderFillRect(ren, &rect);
                }
                // highlight legal moves
               
                // Adjust rect for drawing pieces
                rect.x = start_x + piece_width * col;
                rect.y = tile_height * row - (piece_width - tile_height) - piece_y_offset;
                rect.w = piece_width;
                rect.h = piece_height;
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
        for (int col = 0; col < 8; col++) 
        {
             // Adjust rect for drawing bottom of board
             rect.x = start_x + piece_width * col;
             rect.y = piece_width + tile_height * 8;
             rect.w = piece_width;
             rect.h = piece_width / 4;

             if (col % 2 == 0) {
                SDL_SetRenderDrawColor(ren,31, 31, 40, SDL_ALPHA_OPAQUE);
             } else {
                SDL_SetRenderDrawColor(ren,152, 161, 177, SDL_ALPHA_OPAQUE);
             }
             SDL_RenderFillRect(ren, &rect);
        }

        SDL_SetRenderDrawColor(ren, 144, 148, 156, SDL_ALPHA_OPAQUE);
        SDL_RenderPresent(ren);
        limit_Fps(starting_tick);   
    }

}

void Play::exit(){}


//////////////////////////////
//////////credits/////////////
//////////////////////////////

Credits::Credits(/* args */){

    backgroundTexture = IMG_LoadTexture(ren, (APP_PATH + "CREDITS_SCREEN.png").c_str()); //menu background.png (temp for now) path to the background

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
        SDL_Rect rect = {0,0,SCREEN_WIDTH, SCREEN_HEIGHT};
        SDL_RenderCopy(ren,backgroundTexture,NULL,&rect); // NULL stretches the image to the entire screen
        SDL_RenderPresent(ren);
        
        limit_Fps(starting_tick);
    }

}

void Credits::exit(){}
