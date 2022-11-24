#ifndef KNIGHT
#define KNIGHT

#include "piece.h"


class Knight: public Piece 
{
   public:
      Knight(Chessboard* board, Position position, PieceColour colour);
      ~Knight();

      /** @brief 
      */
      virtual unordered_set<Position> LegalMoves() override;
};

#endif
