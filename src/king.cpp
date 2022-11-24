#include "../include/king.h"
#include "../include/chessboard.h"


King::King(Chessboard* board, Position position, bool colour)
   : Piece(board, position)
{
   piece_num_ = colour ? kWKing : kBKing;
}


unordered_set<Position> King::LegalMoves()
{
}
