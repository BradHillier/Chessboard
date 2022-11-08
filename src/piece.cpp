#include "../include/piece.h"
#include "../include/chessboard.h"


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
   // No error checking currently
   // assume the user is not trying to set invalid positions
   position_ = position;
}


bool Piece::Colour() 
{
   if (piece_num_ < 0) { 
      return kBlack  
   } 
   return kWhite;
}
