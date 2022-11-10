#include "../include/piece.h"
#include "../include/chessboard.h"


Piece::Piece(Chessboard* board, Position position)
{
   chess_ = board;
   position_ = kOffTheBoard;
   set_position(position);
   starting_position_ = position_;
}


void Piece::set_position(Position dest)
{
   chess_->board_[dest.row][dest.col] = this;
   position_ = dest;
}


// bool Piece::IsPotentialMove(Position destination)
// {
//    Piece* dest_occupant = chess_->PieceAt(destination); 
//    bool occupant_is_friendly = dest_occupant && dest_occupant->Colour() == Colour();
// 
//    if (IsWithinBoard(destination) && !occupant_is_friendly) {
//       return true;
//    }
//    return false;
// }


bool Piece::IsValidMove(Position destination)
{
   bool dest_is_empty = chess_->PieceAt(destination) == NULL;
   bool in_bounds = IsWithinBoard(destination);
   bool different = destination != position();
   bool OffBoard = destination == kOffTheBoard;

   if ((dest_is_empty && in_bounds && different) || OffBoard) {
      return true;
   }
   return false;
}


bool Piece::IsWithinBoard(Position dest)
{
   bool row_in_range = 0 <= dest.row && dest.row <= kBoardSize;
   bool col_in_range = 0 <= dest.col && dest.col <= kBoardSize;

   if (row_in_range && col_in_range) {
      return true;
   }
   return false;
}


PieceNum Piece::piece_num() 
{
   return piece_num_;
}


Position Piece::position() 
{
   return position_;
}


bool Piece::MoveTo(Position destination)
{
   if (IsValidMove(destination)) {
      RemoveFromBoard();
      set_position(destination);
      return true;
   }
   return false;
}


bool Piece::Colour() 
{
   if (piece_num_ < 0) { 
      return kBlack;
   } 
   return kWhite;
}


bool Piece::RemoveFromBoard()
{
   if (position_ != kOffTheBoard) {
      chess_->board_[position().row][position().col] = NULL;
      position_ = kOffTheBoard;
      return true;
   }
   return false;
}
