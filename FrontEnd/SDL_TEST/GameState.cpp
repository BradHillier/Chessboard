#include "GameState.h"


//////////////////////////////
/////////Global space/////////
//////////////////////////////

string APP_PATH = SDL_GetPrefPath("Prometheus", "Chessboard"); // the location of Assets and user data


// i tried putting it in .h but with whatever lil testing i did it seems to like it here
SDL_Window * GameState::win = SDL_CreateWindow(
   "Pixel Chess" ,
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
   font = TTF_OpenFont( (APP_PATH + "ARCADECLASSIC.ttf").c_str(), 60);
   if (!font) {
       // Handle error
   }
   }

Menu::~Menu()
{

    SDL_DestroyTexture(backgroundTexture); //it only loads it once but just for good measure, we prevent any memory leaks 

}

void Menu::enter(){}

void Menu::update(){

 Uint32 starting_tick;

   starting_tick = SDL_GetTicks();
   SDL_Event e;
   while (SDL_PollEvent(&e))
   {
      switch (e.type)
      {
         case SDL_QUIT:
            shutdown();
            break;
         case SDL_MOUSEBUTTONDOWN:
            int mouse_x, mouse_y;
            SDL_GetMouseState(&mouse_x,&mouse_y);
            if (button_rect.x <= mouse_x && mouse_x <= button_rect.x + button_rect.w  && 
                button_rect.y <= mouse_y && mouse_y <= button_rect.y + button_rect.h
               )
            {
              currGameState = play; //get outta the loop when change state
              return;
            }
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

   SDL_GetRendererOutputSize(ren, &width, &height);
   SDL_Rect rect = {0, 0, width, height};
   SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
   SDL_RenderFillRect(ren, &rect);

   SDL_RenderCopy(ren, backgroundTexture, NULL, &rect); // NULL stretches the image to the entire screen
   DrawTitle();
   DrawButtons();


   SDL_RenderPresent(ren);
   limit_Fps(starting_tick);
}
void Menu::DrawTitle()
{
   TTF_SetFontSize(font, height / 8);
   SDL_Surface *textSurface = TTF_RenderText_Solid(
         font, 
         "Pixel Chess", 
         {255, 255, 255});
   if (!textSurface) {
      cout << "Error: Unable to load font" << endl;
   }
   SDL_Texture *textTexture = SDL_CreateTextureFromSurface(ren, textSurface);
   if (!textTexture) {
      cout << "Error: NULL textSurfac" << endl;
   }
   SDL_Rect textRect = { width / 2 - textSurface->w / 2,
         height / 3, 
         textSurface->w,
         textSurface->h 
   };
   SDL_RenderCopy(ren, textTexture, NULL, &textRect);
}

void Menu::DrawButtons()
{
   TTF_SetFontSize(font, height / 8);

   int bw = width / 4;
   SDL_Color font_colour;
   button_rect = {width / 2 - bw / 2, height / 2, bw, bw / 3};

   int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    if (button_rect.x <= mouse_x && mouse_x <= button_rect.x + button_rect.w && 
        button_rect.y <= mouse_y && mouse_y <= button_rect.y + button_rect.h
       )
    {
       SDL_SetRenderDrawColor(ren, 255, 255, 255, SDL_ALPHA_OPAQUE);
       font_colour = {0, 0, 0};

    }
    else 
    {
       SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
       font_colour = {255, 255, 255};
    }
    SDL_RenderFillRect(ren, &button_rect);

   TTF_SetFontSize(font, height / 16);

   button_surface = TTF_RenderText_Solid(font, "Play", font_colour);
   button_texture = SDL_CreateTextureFromSurface(ren, button_surface);

   SDL_Rect textRect = { 
         width / 2 - button_surface->w / 2,
         button_rect.y + (button_rect.h / 2) - (button_surface->h / 2),
         button_surface->w,
         button_surface->h 
   };

   SDL_RenderCopy(ren, button_texture, NULL, &textRect);
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
            if(e.key.keysym.sym == SDLK_ESCAPE)
            {
               shutdown();
            } 
            else if (e.key.keysym.sym == SDLK_1)
            {
               //change state, go back to main menu
               currGameState = menu; //get outta the loop when change state
               controller->ResetGame();
               return;
            }
         case SDL_MOUSEBUTTONDOWN:
            SDL_GetMouseState(&source_x,&source_y);
            source_x = (source_x - left_padding) / piece_width;
            source_y = (source_y - top_padding) / tile_height;
            controller->ProcessClick(Position(source_y, source_x));
            break;
      }
   }

   SDL_SetRenderDrawColor(ren, 144, 148, 156, SDL_ALPHA_OPAQUE);
   SDL_RenderClear(ren);

   DrawBoard();
   HighlightSelectedPiece();
   HighlightLegalMoves();
   DrawPieces();
   DrawEdgeOfBoard();

   SDL_RenderPresent(ren);
   limit_Fps(starting_tick);   
}

void Play::DrawEdgeOfBoard()
{
   for (int col = 0; col < 8; col++) 
   {
      // Adjust rect for drawing bottom of board
      SDL_Rect rect = TileAt(Position(kBoardSize, col));
      rect.h /= 4;
      if (col % 2 == 0) {
         SDL_SetRenderDrawColor(ren,31, 31, 40, SDL_ALPHA_OPAQUE);
      } 
      else 
      {
         SDL_SetRenderDrawColor(ren,152, 161, 177, SDL_ALPHA_OPAQUE);
      }
      SDL_RenderFillRect(ren, &rect);
   }
}

void Play::AdjustRectSizes()
{
   SDL_GetRendererOutputSize(ren, &width, &height);

   board_pixels = min(width, height);
   if (board_pixels == height || height - width < height / 12 ) {
     // stops pieces from clipping the bottom of the screen
     board_pixels -= board_pixels / 8;
   }
   left_padding = (width - board_pixels) / 2;
   piece_width = round(board_pixels / kBoardSize);
   piece_height = 2 * piece_width;
   tile_height = 5 * piece_width / 6;
   top_padding = (height - tile_height * 8) / 2;
   piece_y_offset = tile_height / 2;
}

void Play::SetTileRenderColor(int row, int col)
{
   if ( (col + row) % 2 == 0 ) 
   {   
      // current tile is white
      SDL_SetRenderDrawColor(ren, 235, 240, 218, SDL_ALPHA_OPAQUE);
   } 
   else 
   {    
      // current tile is black                    
      SDL_SetRenderDrawColor(ren, 90, 96, 111, SDL_ALPHA_OPAQUE); 
   }
}

void Play::DrawBoard()
{
   for (int row = 0; row < kBoardSize; row++) 
   {
      for (int col = 0; col < kBoardSize; col++) 
      {
         SDL_Rect rect = TileAt(Position(row, col));
         SetTileRenderColor(row, col);
         SDL_RenderFillRect(ren, &rect);
      }
   }
}

void Play::HighlightSelectedPiece()
{
   Position piece_pos = controller->GetSelectedPiece();
   if (piece_pos != kOffTheBoard)
   {
      SDL_Rect selected_rect = TileAt(piece_pos);
      SDL_SetRenderDrawColor(ren, 0, 255, 0, SDL_ALPHA_OPAQUE);
      SDL_RenderFillRect(ren, &selected_rect);
      FillCenterOfRect(selected_rect, piece_pos);
   }
}

// used to adjust the border size of a highlighted tile
void Play::FillCenterOfRect(SDL_Rect rect, Position position)
{
   AddPadding(rect, tile_height / 16);
   SetTileRenderColor(position.row, position.col);
   SDL_RenderFillRect(ren, &rect);
}

SDL_Rect Play::TileAt(Position position)
{
   SDL_Rect rect;
   rect.x = left_padding + piece_width * position.col;
   rect.y = top_padding + tile_height * position.row;
   rect.w = piece_width;
   rect.h = tile_height;
   return rect;
}

void Play::AddPadding(SDL_Rect &rect, int padding)
{
   rect.x += padding;
   rect.y += padding;
   rect.w -= 2 * padding;
   rect.h -= 2 * padding;
}

void Play::HighlightLegalMoves()
{
   SDL_Rect rect;

   unordered_set<Position> legal_moves = controller->GetLegalMoves();
   for (const auto &move : legal_moves)
   {
      rect = TileAt(move);
      SDL_SetRenderDrawColor(ren,255, 200, 0, SDL_ALPHA_OPAQUE);
      SDL_RenderFillRect(ren, &rect);
      FillCenterOfRect(rect, move);
   }
}

void Play::DrawPieces()
{
   SDL_Rect rect;

   for (int row = 0; row < kBoardSize; row++) 
   {
      for (int col = 0; col < kBoardSize; col++) 
      {
         PieceNum piece = controller->GetBoard()[row][col];
         if (piece != kEmpty)
         {
            rect.x = left_padding + piece_width * col;
            rect.y = (top_padding - piece_width) + tile_height * row - piece_y_offset;
            rect.w = piece_width;
            rect.h = piece_height;
            SDL_RenderCopy(ren, pieces[piece], NULL, &rect);
         }
      }
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

void Credits::exit() {}
