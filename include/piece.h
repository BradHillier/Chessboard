#ifndef PIECE
#define PIECE
#include "../globals.h"
#include "../chessboard.h"
#include <vector>
using std::vector;

// this prevents Chessboard undefined error. 
// since chessboard.h and piece.h include eachother, this is needed
// there may be a better way of handling this
class Chessboard;

 /// @brief an abstract chess piece used to implement the various pieces on a chessboard
class Piece 
{
    private:

        /// referenceChessboard the piece exists on 
        Chessboard* board_;

        /// a number value used to indicate the pieces type and colour 
        PieceNum piece_num_;

        /// the pieces current position on the chessboard it exists on
        Position position_;

    public:

        Piece(Chessboard* board, Position position);
        ~Piece() {};

        /// @brief get the pieces associated integer value
        /// @details Acts as a getter method for the `piece_num_` data member
        /// @return an integer representing the piece's type and colour. 
        PieceNum piece_num();

        /// @brief get the pieces current position on the board
        /// @details a getter method for the `position_` data member
        /// @return 
        Position position();

        /// @brief move the piece to the provided position
        /// @details  move the piece from it's current position on the 
        ///           chessboard to the one provided. Acts as a setter method 
        ///           for the `position_` data member
        /// @param position on the chessboard to move the piece to 
        /// @return bool operation success
        bool set_position(Position position);

        /// @brief the colour of the piece
        /// @return bool representing the piece's colour (true if white, false if black)
        bool Colour();

        /// @brief get all legal moves for the piece
        /// @return a vector containing all positions on the chessboard the piece can be moved to
        virtual vector<Position> AvailableMoves();
}

#endif
