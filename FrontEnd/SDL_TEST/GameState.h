#pragma once
#include "globals.h"
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

class Play : public GameState{

public:
    Play(/* args */);
    virtual ~Play();

    void enter();
    void update();
    void exit();

    SDL_Texture * W_King_Texture;
    SDL_Texture * W_Queen_Texture;
    SDL_Texture * W_Rook_Texture;
    SDL_Texture * W_Knight_Texture;
    SDL_Texture * W_Bishop_Texture;
    SDL_Texture * W_Pawn_Texture;

    SDL_Texture * B_King_Texture;
    SDL_Texture * B_Queen_Texture;
    SDL_Texture * B_Rook_Texture;
    SDL_Texture * B_Knight_Texture;
    SDL_Texture * B_Bishop_Texture;
    SDL_Texture * B_Pawn_Texture;

    int layout[8][8] = {
      {-2,-3,-4,-6,-5,-4,-3,-2},
      {-1,-1,-1,-1,-1,-1,-1,-1},
      { 0, 0, 0, 0, 0, 0, 0, 0},
      { 0, 0, 0, 0, 0, 0, 0, 0},
      { 0, 0, 0, 0, 0, 0, 0, 0},
      { 0, 0, 0, 0, 0, 0, 0, 0},
      { 1, 1, 1, 1, 1, 1, 1, 1},
      { 2, 3, 4, 6, 5, 4, 3, 2}
   };
    
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


