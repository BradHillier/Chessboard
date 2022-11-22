#include "../include/knight.h"
#include "../include/chessboard.h"


Knight::Knight(Chessboard* board, Position position, bool colour)
   : Piece(board, position)
{
   piece_num_ = colour ? kWKnight : kBKnight;
}


unordered_set<Position> Knight::LegalMoves()
{
}
