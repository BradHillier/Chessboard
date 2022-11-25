// the `k` prefix used in this file follows Google's C++ style guide
// for constant values. 
// https://google.github.io/styleguide/cppguide.html#Constant_Names
#ifndef GLOBALS
#define GLOBALS
#include <bits/stdc++.h>


/** @brief the colour of a specific chess piece or player
* 
*   Since there are only two possible players in a game of chess,
*   it is convientent to use a boolean value to represent them. 
*   This typedef helps clarify situations where a bool is used
*   for this purpose.
*/
typedef bool PieceColour;

const PieceColour kWhite = true;
const PieceColour kBlack = false;

const int kBoardSize = 8;


/** @brief used to represent the type and colour of a piece or state of a tile
*
*   if used to represent the state of a tile, 0 indicates an empty tile
*   while any non-zero value indicates the piece residing on the tile.
*   A positive value indicates a white piece, prefixed with `kW` and
*   a negative number indicates a black piece, prefixed with `kB`.
*/
enum PieceNum
{
   kBKing = -6,
   kBQueen = -5,
   kBBishop = -4,
   kBKnight = -3,
   kBRook = -2,
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

   Position() {
      row = INT_MIN;
      col = INT_MIN;
   }

   Position(int x, int y)
   {
      row = x;
      col = y;
   }

   /** @brief Check if the destination is within the bounds of the gameboard
   *
   *   Check if the Piece's row and column are greater than or equal to 0 
   *   and less then the size of the board.
   *
   *   @return bool True if within bounds, otherwise false;
   */
   bool IsWithinBoard()
   {
      bool row_in_range = 0 <= row && row < kBoardSize;
      bool col_in_range = 0 <= col && col < kBoardSize;

      if (row_in_range && col_in_range) 
      {
         return true;
      }
      return false;
   }


   friend bool operator==(const Position lhs, const Position rhs)
   {
      return lhs.row == rhs.row && lhs.col == rhs.col;
   }

   friend bool operator!=(const Position lhs, const Position rhs)
   {
      return lhs.row != rhs.row || lhs.col != rhs.col;
   }

   /**these work like vector addition and subtraction
   *
   *   @example 
   *   Position(2, 3) + Position(1, 1) // = Position(3, 4)
   */
   friend Position operator+(const Position lhs, const Position rhs)
   {
      return  Position(lhs.row + rhs.row, lhs.col + rhs.col);
   }
   friend Position operator-(const Position lhs, const Position rhs)
   {
      return  Position(lhs.row - rhs.row, lhs.col - rhs.col);
   }

   /** these work like scalar multiplication
   *
   *   @example 
   *   -1 * Position(2, 3) // = Position(-2, -3)
   */
   friend Position operator*(const int lhs, const Position rhs)
   {
      return Position(lhs * rhs.row, lhs * rhs.col);
   }
   friend Position operator*(const Position lhs, const int rhs)
   {
      return Position(lhs.row * rhs, lhs.col * rhs);
   }
};

const Position kOffTheBoard = Position(INT_MIN, INT_MIN);


namespace std 
{
   template<>
   struct hash<Position> 
   {
      size_t operator()(const Position &p) const {
         return hash<int>() (p.row * p.col);
      }
   };
 }


#endif
