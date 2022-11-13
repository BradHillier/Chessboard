#ifndef PAWN
#define PAWN

#include "piece.h"


class Pawn: public Piece 
{
   public:
      Pawn(Chessboard* board, Position position, PieceColour colour);
      ~Pawn();

      /** @brief 
      */
      virtual list<Position> AvailableMoves() override;
};

#endif
