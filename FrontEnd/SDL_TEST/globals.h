#pragma once
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

using namespace std; // i know this is not like b everyone but did not wanna use std:: everywhere, thats why in the global

// NOTE : highly recomment in VS code hover over each SDL function and parameter to read about them before implementing them
// maybe create images as pngs in paint for testing, diff images for each state

static int k = SDL_Init(SDL_INIT_EVERYTHING); // initialised everything

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 562;

/////////pieces/////////////

const int PIECE_WIDTH = SCREEN_WIDTH / 8; 
const int PIECE_HEIGHT = PIECE_WIDTH;

const int PIECE_X_OFFSET = PIECE_WIDTH / 12;
const int PIECE_Y_OFFSET = PIECE_X_OFFSET;


const int fps = 30;



