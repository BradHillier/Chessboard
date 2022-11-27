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
   if (Colour() == kBlack)
   {
      moves.insert(position() + Position(1, 0));
   }
   else 
   {
      moves.insert(position() + Position(-1, 0));
   }
   return moves;
}

