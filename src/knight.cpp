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
    if(IsLegalMove(position() + Position(1,2)) != false){
        moves.insert(position() + Position(1,2));
    }
    if(IsLegalMove(position() + Position(1,-2)) != false){
        moves.insert(position() + Position(1,-2));
    }
    if(IsLegalMove(position() + Position(-1,2)) != false){
        moves.insert(position() + Position(-1,2));
    }
    if(IsLegalMove(position() + Position(-1,-2)) != false){
        moves.insert(position() + Position(-1,-2));
    }
    if(IsLegalMove(position() + Position(2,1)) != false){
        moves.insert(position() + Position(2,1));
    }
    if(IsLegalMove(position() + Position(2,-1)) != false){
        moves.insert(position() + Position(2,-1));
    }
    if(IsLegalMove(position() + Position(-2,1)) != false){
        moves.insert(position() + Position(-2,1));
    }
    if(IsLegalMove(position() + Position(-2,-1)) != false){
        moves.insert(position() + Position(-2,-1));
    }

    return moves;
}
