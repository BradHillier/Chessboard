#include "../include/piece.h"
#include "../include/chessboard.h"


Piece::Piece(Chessboard* board, Position position)
{
   chess_ = board;
   position_ = kOffTheBoard;
   set_position(position);
   starting_position_ = position_;
}


void Piece::set_position(Position destination)
{
   chess_->board_[destination.row][destination.col] = this;
   position_ = destination;
}

bool Piece::isLegalMove(Position destination)
{
   if (IsWithinBoard(destination) && !IsFriendly(destination)) {
      return true;
   }
   return false;
}


bool Piece::IsFriendly(Position position)
{
   Piece* occupant = chess_->PieceAt(position); 

   if (occupant != NULL && occupant->Colour() == Colour()) {
      return true;
   }
   return false;
}

unordered_set<Position> straights()
{
   unordered_set <Position> strts;
   Position pos1 = position_;
   Position pos2 = position_;
   Position pos3 = position_;
   Position pos4 = position_;

   //goes through the vertical upward straight
   while(isLegalMove(pos1.column + 1) && IsAvailable(pos1.column + 1))
   {
      //checks if next pos is an enemy and if yes stores the pos and break loop
      if(!IsFriendly(pos1.column + 1)) 
      {
         strts.insert(pos1.column + 1);
         break;
      }
      strts.insert(pos1.column + 1);
      pos1.column++;

   }

   //goes through the downward vertical straight
   while(isLegalMove(pos2.column - 1) && IsAvailable(pos2.column - 1))
   {
      //checks if next pos is an enemy and if yes stores the pos and break loop
      if(!IsFriendly(pos2.column - 1)) 
      {
         strts.insert(pos2.column - 1);
         break;
      }
      strts.insert(pos2.column - 1);
      pos1.column--;

   }

   //goes through the right horizontal straight
   while(isLegalMove(pos3.row + 1) && IsAvailable(pos3.row + 1))
   {
      //checks if next pos is an enemy and if yes stores the pos and break loop
      if(!IsFriendly(pos3.row + 1)) 
      {
         strts.insert(pos3.row + 1);
         break;
      }
      strts.insert(pos3.row + 1);
      pos3.row++

   }

   //goes through the left horizontal straight
   while(isLegalMove(pos4.row - 1) && IsAvailable(pos4.row - 1))
   {
      //checks if next pos is an enemy and if yes stores the pos and breaks loop
      if(!IsFriendly(pos4.row - 1)) 
      {
         strts.insert(pos4.row - 1);
         break;
      }
      strts.insert(pos4.row - 1);
      pos1.row--;

   }
   return strts;
}


bool Piece::IsAvailable(Position destination)
{
   bool dest_is_empty = chess_->PieceAt(destination) == NULL;
   bool in_bounds = IsWithinBoard(destination);
   bool not_curr_pos = destination != position();

   if (dest_is_empty && in_bounds && not_curr_pos) {
      return true;
   }
   return false;
}


bool Piece::IsWithinBoard(Position destination)
{
   bool row_in_range = 0 <= destination.row && destination.row < kBoardSize;
   bool col_in_range = 0 <= destination.col && destination.col < kBoardSize;

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
   if (IsAvailable(destination)) {
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
