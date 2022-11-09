// the `k` prefix used in this file follows Google's C++ style guide
// for constant values. 
// https://google.github.io/styleguide/cppguide.html#Constant_Names
#ifndef GLOBALS
#define GLOBALS


/** @brief the colour of a specific chess piece or player
* 
*   Since there are only two possible players in a game of chess,
*   it is convientent to use a boolean value to represent them. 
*   This typedef helps clarify situations where a bool is used
*   for this purpose.
*/
typedef bool = PieceColour;

const PieceColour kWhite = true;
const PieceColour kBlack = false;


/** @brief used to represent the type and colour of a piece or state of a tile
*
*   if used to represent the state of a tile, 0 indicates an empty tile
*   while any non-zero value indicates the piece residing on the tile.
*   A positive value indicates a white piece, prefixed with `kW` and
*   a negative number indicates a black piece, prefixed with `kB`.
*/
{
   kBKing = -6,
   kBQueen = -5,
   kBBishop = -4,
   kBKnight = -3,
   KBRook = -2,
   kBPawn = -1,
   kEmpty = 0,
   kWPawn = 1,
   kWRook = 2,
   kWKnight = 3,
   kWBishop = 4,
   kWQueen = 5,
   kWKing = 6
};


/**
*   @brief used to reference a specific position on the chessboard 
*
*   The top right corner of the board would be `Position(0, 7)`
*   and the bottom leeft corner would be `Position(7, 0)`
*/
struct Position
{
   int row, col;
};


#endif
