#ifndef PIECE
#define PIECE
#include "globals.h"
#include <vector>

using std::vector;

// forward declaration
// this prevents Chessboard undefined error.
// since chessboard.h and piece.h include eachother, this is needed
// there may be a better way of handling this
class Chessboard;

/** @brief an abstract chess piece used as the basis to implement 
*   the various pieces used in a game of chess
*/
class Piece 
{
    protected:

        /** reference to the Chessboard the piece exists on */
        Chessboard* board_;

        /** an integer value used to indicate the piece'ss type and colour */
        PieceNum piece_num_;

        /** the pieces current position on the chessboard it exists on */
        Position position_;

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

        /** @brief move the piece to the provided position
        *
        *   move the piece from it's current position on the 
        *   chessboard to the one provided. Acts as a setter method 
        *   for the `position_` data member
        *
        *   @param position on the chessboard to move the piece to 
        *   @return bool operation success
        */
        bool set_position(Position position);

        /** @brief the colour of the piece
        *
        *   @return true if white, false if black
        */
        bool Colour();

        /** @brief get all legal moves for the piece
        *
        *   @return all legal moves from the pieces current position
        */
        virtual vector<Position> AvailableMoves() = 0;
};

#endif
