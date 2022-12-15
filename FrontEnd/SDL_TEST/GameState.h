#pragma once
#include "globals.h"
#include "../../include/chess_controller.h"
#include <map>

//#include "Mouse.h"

////////game state/////////
//base class
class GameState{

    public:

        GameState() {}
        virtual ~GameState() {}

        //abstract class, any class derived has to provide definition for these functions
        virtual void enter() = 0 ;
        virtual void update() = 0 ;
        virtual void exit() = 0 ;

        void shutdown();
        void limit_Fps(Uint32 start_tick);

        static SDL_Window * win ; 
        static SDL_Renderer * ren ; //rendererer

        SDL_Texture * backgroundTexture;// background of each class

        static GameState * menu;
        static GameState * help;
        static GameState * credits;
        static GameState * play;

        static GameState * currGameState;

        //static Mouse* mouse;
        

};

////////menu state//////////////

class Menu : public GameState{

public:
    Menu(/* args */);
    virtual ~Menu();

    void enter();
    void update();
    void exit();
};

////////////help state///////////

class Help : public GameState{

public:
    Help(/* args */);
    virtual ~Help();

    void enter();
    void update();
    void exit();

    

};

////////////play state///////////

class Play : public GameState
{
private:
   map<PieceNum, SDL_Texture*> pieces;
   void AdjustRectSizes();
   void DrawTileBackground(int row, int col);
   void HighlightSelectedPiece();
   void HighlightLegalMoves();
   void DrawPieces();
   void AddPadding(SDL_Rect &rect, int padding);
   SDL_Rect TileAt(Position position);
   void FillCenterOfRect(SDL_Rect rect, Position position);

   int start_x;
   int piece_width;
   int piece_height; 
   int tile_height;
   int top_padding;
   int board_pixels;
   int piece_y_offset;

public:
    Play();
    ~Play();

    void enter();
    void update();
    void exit();

    Controller* controller;
    int width;
    int height;
};

////////////credits state///////////

class Credits : public GameState{

public:
    Credits(/* args */);
    virtual ~Credits();

    void enter();
    void update();
    void exit();
};


