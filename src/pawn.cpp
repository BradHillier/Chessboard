#include "../include/pawn.h"
#include "../include/chessboard.h"


Pawn::Pawn(Chessboard* board, Position position, bool colour)
   : Piece(board, position)
{
   piece_num_ = colour ? kWPawn : kBPawn;
}


unordered_set<Position> Pawn::LegalMoves()
{
    unordered_set<Position> moves;
    for(int i = 0; i < 1; i++){
        moves.insert(position() + Position(0,1));
    }
    
    return moves;
}

