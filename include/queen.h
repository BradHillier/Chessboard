#ifndef QUEEN
#define QUEEN

#include "piece.h"


class Queen: public Piece 
{
   public:
      Queen(Chessboard* board, Position position, PieceColour colour);
      ~Queen();

      /** @brief 
      */
      virtual list<Position> AvailableMoves() override;
};

#endif
