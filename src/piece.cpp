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
   // only checks if position is within bounds
   position_ = position;
}


bool Piece::Colour() 
{
   return piece_num_ < 0 ? kBlack : kWhite;
}

