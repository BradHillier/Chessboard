#include "../include/queen.h"
#include "../include/chessboard.h"


Queen::Queen(Chessboard* board, Position position, bool colour)
   : Piece(board, position)
{
   piece_num_ = colour ? kWQueen : kBQueen;
}


unordered_set<Position> Queen::LegalMoves()
{
    unordered_set<Position> moves = straights_and_diagonal();
    
    return moves;
}
