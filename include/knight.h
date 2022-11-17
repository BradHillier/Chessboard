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
      virtual list<Position> LegalMoves() override;
};

#endif
