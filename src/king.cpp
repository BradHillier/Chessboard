#include "../include/king.h"
#include "../include/chessboard.h"


King::King(Chessboard* board, Position position, bool colour)
   : Piece(board, position)
{
   piece_num_ = colour ? kWKing : kBKing;
}

King::~King()
{
}


unordered_set<Position> King::LegalMoves()
{
    unordered_set<Position> moves;
        
    if(IsLegalMove(position() + Position(0,1)) != false){
        moves.insert(position() + Position(0,1));
    }
    if(IsLegalMove(position() + Position(0,-1)) != false){
        moves.insert(position() + Position(0,-1));
    }
    if(IsLegalMove(position() + Position(1,0)) != false){
        moves.insert(position() + Position(1,0));
    }
    if(IsLegalMove(position() + Position(-1,0)) != false){
        moves.insert(position() + Position(-1,0));
    }
    if(IsLegalMove(position() + Position(1,1)) != false){
        moves.insert(position() + Position(1,1));
    }
    if(IsLegalMove(position() + Position(-1,1)) != false){
        moves.insert(position() + Position(-1,1));
    }
    if(IsLegalMove(position() + Position(1,-1)) != false){
        moves.insert(position() + Position(1,-1));
    }
    if(IsLegalMove(position() + Position(-1,-1)) != false){
        moves.insert(position() + Position(-1,-1));
    }

    return moves;
}
