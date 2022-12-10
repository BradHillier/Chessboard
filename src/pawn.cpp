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
   int sign = (Colour() == kBlack) ? 1 : -1;

   if (IsEnemy(position() + Position(sign * 1, 1))) 
   {
      moves.insert(position()+Position(sign * 1, 1));
   }
   if (IsEnemy(position() + Position(sign * 1, -1))) 
   {
      moves.insert(position() + Position(sign * 1, -1));
   }

   if (IsAvailable(position() + Position(sign * 1, 0)))
   {
      moves.insert(position() + Position(sign * 1, 0));
   }

   if (position() == starting_position())
   {
      if (IsAvailable(position() + Position(sign * 2, 0)))
      {
         moves.insert(position() + Position(sign * 2, 0));
      }
   }
   return moves;
}
