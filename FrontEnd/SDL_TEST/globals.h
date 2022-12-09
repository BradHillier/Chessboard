#pragma once
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

using namespace std; // i know this is not like b everyone but did not wanna use std:: everywhere, thats why in the global

// NOTE : highly recomment in VS code hover over each SDL function and parameter to read about them before implementing them
// maybe create images as pngs in paint for testing, diff images for each state

static int k = SDL_Init(SDL_INIT_EVERYTHING); // initialised everything

/////////pieces/////////////

const int PIECE_WIDTH = 100;
const int PIECE_HEIGHT = 100;

const int PIECE_X_OFFSET = 10;
const int PIECE_Y_OFFSET = 10;

const int fps = 30;



