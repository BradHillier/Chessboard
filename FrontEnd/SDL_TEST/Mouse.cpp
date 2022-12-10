#include "Mouse.h"

Mouse::Mouse(SDL_Renderer* ren)
{
    tex = IMG_LoadTexture(ren, "mouse.png");
    rect = {0,0,50,50};
    point = {0,0,1,1};

    SDL_ShowCursor(false);
}

Mouse::~Mouse()
{
}

void Mouse:: update(){

    SDL_GetMouseState(&rect.x,&rect.y);
    point.x = rect.x;
    point.y = rect.y;

}

void Mouse:: draw(SDL_Renderer* ren){

    SDL_RenderCopy(ren,tex,NULL,&rect);

}