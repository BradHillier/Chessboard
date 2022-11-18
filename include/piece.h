#ifndef PIECE_DEFINED
#define PIECE_DEFINED
#include "globals.h"
#include <list>
using std::list;


// forward declaration prevents Chessboard undefined error
class Chessboard;


/** @brief an abstract chess piece used as the basis to implement 
*   the various pieces used in a game of chess
*
*   This base class contains functionality shared by all chess pieces
*   allowing the user to move or remove the piece from the chessboard 
*   as well as access properties about the piece such as its colour, type
*   and current position on the board.
*/
class Piece 
{
    private:

      /** the pieces current position on the chessboard it exists on */
      Position position_;

      /** the intial position of the piece at the start of the game */
      Position starting_position_;

      /** @brief move the piece to the provided position
      *
      *   move the piece from it's current position, updating both its own
      *   `position_` attribute and the `chess_` board. Acts as a setter method 
      *   for the `position_` data member
      *
      *   @param position on the chessboard to move the piece to 
      *   @return bool operation success
      */
      void set_position(Position position);

      /** @brief check if a Position is a valid place to move the piece
      *
      *   Checks that the destination is empty, is not the position the piece is 
      *   already in, is within the bounds of the board, or the destinaion
      *   is off the board.
      *
      *    @warning This method does not check if a piece already residing
      *             at the desitination can be taken
      *    @param destination The Position being examinec
      *    @ return bool True if all requirements met, otherwise false
      */
      bool IsValidMove(Position destination);

    protected:

      /** an integer value used to indicate the piece'ss type and colour 
      *  this gets set by child class using the provided colour 
      */
      PieceNum piece_num_;

      /** reference to the Chessboard the piece exists on */
      Chessboard* chess_;

      /** Check if the target destination is within the bounds of the gameboard
      */
      bool IsWithinBoard(Position dest);

      /** This is supposed to be used to check if tile is within the
      *   bounds of the board and either empty or contains an enemy piece.
      *   Intended to be used by child classes to filter out invalid moves. 
      */ 
      // bool IsPotentialMove(Position destination);

      /** This is used to return an unordered set of the all diagonal Positions on the 
          board that are the available and legal Positions to move a piece.
      */
      unordered_set<Position> diagonal();

      /** This is used to return an unordered set of the all vertical and
          all horizontal Positions on the board that are the furthest 
          possible and legal Positions to move a piece.
      */
      unordered_set<Position> straights();        

   public:

      Piece(Chessboard* board, Position position);
      ~Piece() {};

      /** brief get the pieces associated integer value
      *
      *   Acts as a getter method for the `piece_num_` data member
      *   protecting the attribute from accidently being changed
      *
      *   @return an integer representing the piece's type and colour. 
      */
      PieceNum piece_num();

      /** @brief get the pieces current position on the board
      *
      *   a getter method for the `position_` data member
      *
      *   @return Position containing the piece's row and column
      */
      Position position();

      /** @brief Move the piece from its current positon to the provided one
      *
      *   First checking if the provided destinations is both within the
      *   bounds of the game board and not already occupied by another piece,
      *   remove the piece from its current position and move it to the
      *   destination.
      *
      *   @example
      *   Piece* piece = new Pawn(this, Position(1,0), kBlack);
      *   if (piece->MoveTo(Position(2, 0))) {
      *     cout << "piece successfully moved" << endl;
      *   }
      *
      *   @param dest The position to move the piece to
      *   @returns bool True if position was changed, otherwise false
      */
      bool MoveTo(Position dest);

      /** @brief Remove the piece from its current positon on the board
      *
      *   If the piece is currently on the gameboard, remove it and return 
      *   true, otherwise return false.
      *   
      *   @return bool Succcess of operation
      */
      bool RemoveFromBoard();

      /** @brief the colour of the piece
      *
      *   @return true if white, false if black
      */
      bool Colour();

      /** @brief get all legal moves for the piece
      *
      *   Virtual method to be implemented by child classes
      *
      *   @return all legal moves from the pieces current position
      */
      virtual list<Position> AvailableMoves() = 0;
};

#endif
