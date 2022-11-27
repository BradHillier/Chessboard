#include "../include/knight.h"
#include "../include/chessboard.h"


Knight::Knight(Chessboard* board, Position position, bool colour)
   : Piece(board, position)
{
   piece_num_ = colour ? kWKnight : kBKnight;
}


unordered_set<Position> Knight::LegalMoves()
{
    unordered_set<Position> moves;
    for(int i = 0; i < 1; i++){
        moves.insert(position() + Position(1,2));
        moves.insert(position() + Position(1,-2));
        moves.insert(position() + Position(-1,2));
        moves.insert(position() + Position(-1,-2));
        moves.insert(position() + Position(2,1));
        moves.insert(position() + Position(2,-1));
        moves.insert(position() + Position(-2,1));
        moves.insert(position() + Position(-2,-1));
    }

    return moves;
}
