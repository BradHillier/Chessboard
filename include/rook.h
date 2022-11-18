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
      virtual unordered_set<Position> LegalMoves() override;
};

#endif
