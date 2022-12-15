#include "GameState.h"

//////////////////////////////
/////////Global space/////////
//////////////////////////////

string APP_PATH = SDL_GetPrefPath("Prometheus", "Chessboard"); // the location of Assets and user data


// i tried putting it in .h but with whatever lil testing i did it seems to like it here
SDL_Window * GameState::win = SDL_CreateWindow(
   "Chessboard" ,
   SDL_WINDOWPOS_UNDEFINED,
   SDL_WINDOWPOS_UNDEFINED,
   SCREEN_WIDTH,
   SCREEN_HEIGHT,
   SDL_WINDOW_RESIZABLE
); // width and height are hard coded for now

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

Play::Play()
{
    controller = new Controller();

    width = SCREEN_WIDTH;
    height = SCREEN_HEIGHT;

    // load white pieces
    pieces[kWKing] = IMG_LoadTexture(ren, (APP_PATH + "W_King.png").c_str());
    pieces[kWQueen] = IMG_LoadTexture(ren, (APP_PATH + "W_Queen.png").c_str());
    pieces[kWRook] = IMG_LoadTexture(ren, (APP_PATH + "W_Rook.png").c_str());
    pieces[kWKnight] = IMG_LoadTexture(ren, (APP_PATH + "W_Knight.png").c_str()); 
    pieces[kWBishop] = IMG_LoadTexture(ren, (APP_PATH + "W_Bishop.png").c_str());
    pieces[kWPawn] = IMG_LoadTexture(ren, (APP_PATH + "W_Pawn.png").c_str());

    // load black pieces
    pieces[kBKing] = IMG_LoadTexture(ren, (APP_PATH + "B_King.png").c_str());
    pieces[kBQueen] = IMG_LoadTexture(ren, (APP_PATH + "B_Queen.png").c_str());
    pieces[kBRook] = IMG_LoadTexture(ren, (APP_PATH + "B_Rook.png").c_str());
    pieces[kBKnight] = IMG_LoadTexture(ren, (APP_PATH + "B_Knight.png").c_str()); 
    pieces[kBBishop] = IMG_LoadTexture(ren, (APP_PATH + "B_Bishop.png").c_str());
    pieces[kBPawn] = IMG_LoadTexture(ren, (APP_PATH + "B_Pawn.png").c_str());

   // check that pieces loaded successfully
   for (const auto &asset : pieces)
   {
      if (!asset.second)
      {
        cout << "Play constructor: " << SDL_GetError()<<endl;
      }
   }
}

Play::~Play()
{
   // delete all piece assets
   for (const auto &asset : pieces)
   {
      SDL_DestroyTexture(asset.second);
   }
}

void Play::enter(){}
void Play::update()
{
    Uint32 starting_tick;
    AdjustRectSizes();

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
                 source_y = (source_y - top_padding) / tile_height;
                 controller->ProcessClick(Position(source_y, source_x));
                 break;
         }
     }

     SDL_RenderClear(ren);
     for (int row = 0; row < 8; row++) 
     {
         for (int col = 0; col < 8; col++) 
         {
             DrawTileBackground(row, col);
             HighlightLegalMoves(row, col);
             DrawPiece(row, col);
         }
     }
     HighlightSelectedPiece();
     for (int col = 0; col < 8; col++) 
     {
          // Adjust rect for drawing bottom of board
          SDL_Rect rect;
          rect.x = start_x + piece_width * col;
          rect.y = top_padding + tile_height * 8;
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

void Play::AdjustRectSizes()
{
   SDL_GetRendererOutputSize(ren, &width, &height);

   board_pixels = min(width, height);
   if (board_pixels == height || height - width < height / 12 ) {
     // stops pieces from clipping the bottom of the screen
     board_pixels -= board_pixels / 8;
   }
   start_x = (width - board_pixels) / 2;
   piece_width = round(board_pixels / kBoardSize);
   piece_height = 2 * piece_width;
   tile_height = 5 * piece_width / 6;
   top_padding = (height - tile_height * 8) / 2;
   piece_y_offset = tile_height / 2;
}

void Play::DrawTileBackground(int row, int col)
{
   SDL_Rect rect;
   rect.x = start_x + piece_width * col;
   rect.y = top_padding + tile_height * (row);
   rect.w = piece_width;
   rect.h = tile_height;
   
   if ( (col + row) % 2 == 0 ) // current tile is white
   {   
      SDL_SetRenderDrawColor(ren, 235, 240, 218, SDL_ALPHA_OPAQUE);
   } 
   else // current tile is black
   {                        
      SDL_SetRenderDrawColor(ren, 90, 96, 111, SDL_ALPHA_OPAQUE); 
   }
   SDL_RenderFillRect(ren, &rect);
}

void Play::HighlightSelectedPiece()
{
   Position piece_pos = controller->GetSelectedPiece();
   if (piece_pos != kOffTheBoard)
   {
      SDL_Rect selected_rect = TileAt(piece_pos);
      SDL_SetRenderDrawColor(ren, 0, 255, 0, SDL_ALPHA_OPAQUE);
      SDL_RenderFillRect(ren, &selected_rect);
   }
}

SDL_Rect Play::TileAt(Position position)
{
   SDL_Rect rect;
   rect.x = start_x + piece_width * position.col;
   rect.y = top_padding + tile_height * position.row;
   rect.w = piece_width;
   rect.h = tile_height;
   return rect;
}

void Play::HighlightLegalMoves(int row, int col)
{
   SDL_Rect rect;
   // highlight legal moves
   rect.x = start_x + piece_width * col;
   rect.y = top_padding + tile_height * (row);
   rect.w = piece_width;
   rect.h = tile_height;

   if (controller->GetLegalMoves().count(Position(row, col)) != 0) 
   {
      SDL_SetRenderDrawColor(ren,255, 200, 0, SDL_ALPHA_OPAQUE);
      SDL_RenderFillRect(ren, &rect);
   }

   // fill in center so it looks like an outline
   int padding = tile_height / 16;
   padding *= 1;

   rect.x = start_x + piece_width * col + padding;
   rect.y = top_padding + tile_height * row + padding;
   rect.w = piece_width - 2 * padding;
   rect.h = tile_height - 2 * padding;

   if ( (col + row) % 2 == 0 ) 
   {   // current tile is white
      SDL_SetRenderDrawColor(ren, 235, 240, 218, SDL_ALPHA_OPAQUE);
      SDL_RenderFillRect(ren, &rect);
   } 
   else 
   {                        // current tile is black
      SDL_SetRenderDrawColor(ren, 90, 96, 111, SDL_ALPHA_OPAQUE); 
      SDL_RenderFillRect(ren, &rect);
   }
}

void Play::DrawPiece(int row, int col)
{
   PieceNum piece = controller->GetBoard()[row][col];
   SDL_Rect rect;

   if (piece != kEmpty)
   {
      rect.x = start_x + piece_width * col;
      rect.y = (top_padding - piece_width) + tile_height * row - piece_y_offset;
      rect.w = piece_width;
      rect.h = piece_height;
      SDL_RenderCopy(ren, pieces[piece], NULL, &rect);
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
