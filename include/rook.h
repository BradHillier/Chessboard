#ifndef ROOK
#define ROOK

#include "piece.h"


class Rook: public Piece 
{
   public:
      Rook(Chessboard* board, Position position, PieceColour colour);
      ~Rook();

      /** @brief 
      */
      virtual list<Position> AvailableMoves() override;
};

#endif
