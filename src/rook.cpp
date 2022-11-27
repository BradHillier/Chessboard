#include "../include/rook.h"
#include "../include/chessboard.h"


Rook::Rook(Chessboard* board, Position position, bool colour)
   : Piece(board, position)
{
   piece_num_ = colour ? kWRook : kBRook;
}


unordered_set<Position> Rook::LegalMoves()
{
    unordered_set<Position> moves = straights();
        
    return moves;
}
