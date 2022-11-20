#ifndef BISHOP
#define BISHOP

#include "piece.h"


class Bishop: public Piece 
{
   public:
      Bishop(Chessboard* board, Position position, PieceColour colour);
      ~Bishop();

      /** @brief 
      */
      virtual list<Position> LegalMoves() override;
};

#endif
