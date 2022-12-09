#pragma once
#include "globals.h"

class Mouse
{
private:
    /* data */
public:
    Mouse(SDL_Renderer* ren);
    ~Mouse();
    void update();
    void draw(SDL_Renderer* ren);

    SDL_Texture * tex;

    SDL_Rect rect;      //mouse cursor
    SDL_Rect point;     //point of contact

    
};


