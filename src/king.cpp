#include "../include/king.h"
#include "../include/chessboard.h"


King::King(Chessboard* board, Position position, bool colour)
   : Piece(board, position)
{
   piece_num_ = colour ? kWKing : kBKing;
}


unordered_set<Position> King::LegalMoves()
{
    unordered_set<Position> moves;
    for(int i = 0; i < 1; i++){
        moves.insert(position() + Position(0,1));
        moves.insert(position() + Position(0,-1));
        moves.insert(position() + Position(1,0));
        moves.insert(position() + Position(-1,0));
        moves.insert(position() + Position(1,1));
        moves.insert(position() + Position(-1,1));
        moves.insert(position() + Position(1,-1));
        moves.insert(position() + Position(-1,-1));
    }

    return moves;
}
