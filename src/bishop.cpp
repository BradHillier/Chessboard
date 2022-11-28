#include "../include/bishop.h"
#include "../include/chessboard.h"


Bishop::Bishop(Chessboard* board, Position position, bool colour)
   : Piece(board, position)
{
   piece_num_ = colour ? kWBishop : kBBishop;
}


unordered_set<Position> Bishop::LegalMoves()
{
    return diagonal();
}
