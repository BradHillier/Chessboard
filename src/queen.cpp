#include "../include/queen.h"
#include "../include/chessboard.h"


Queen::Queen(Chessboard* board, Position position, bool colour)
   : Piece(board, position)
{
   piece_num_ = colour ? kWQueen : kBQueen;
}


list<Position> Queen::LegalMoves()
{
}
