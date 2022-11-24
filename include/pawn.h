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
      virtual unordered_set<Position> LegalMoves() override;
};

#endif
