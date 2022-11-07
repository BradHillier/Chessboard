#include "../include/piece.h"


Piece::Piece(Chessboard* board, Position position)
{
   board_ = board;

   // We should check if the provided position is valid
   // we might need to do some sort of exception handling here
   position_ = position;
}


PieceNum Piece::piece_num() 
{
   return piece_num_;
}


Position Piece::position() 
{
   return position_;
}


bool Piece::set_position(Position position)
{
   // only checks if position is within bounds
   if (board_.isValidMove(self, destination) {
      position_ = position;
   }
}


bool Piece::Colour() 
{
   return piece_num_ < 0 ? wBlack : wWhite;
}

