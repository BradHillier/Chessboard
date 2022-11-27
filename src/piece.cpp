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


bool Piece::IsLegalMove(Position destination)
{
   if (destination.IsWithinBoard() && !IsFriendly(destination)) 
   {
      return true;
   }
   return false;
}


bool Piece::IsFriendly(Position position)
{
   Piece* occupant = chess_->PieceAt(position); 

   if (occupant != NULL && occupant->Colour() == Colour()) 
   {
      return true;
   }
   return false;
}


bool Piece::IsEnemy(Position position)
{
   Piece* occupant = chess_->PieceAt(position); 

   if (occupant != NULL && occupant->Colour() != Colour()) 
   {
      return true;
   }
   return false;
}



void Piece::ExploreOffset(unordered_set<Position> &set, Position offset, int depth)
{
   Position direction = position() + offset;

   while (IsLegalMove(direction) && position().Within(depth, direction))
   {
      set.insert(direction);
      if (IsEnemy(direction))
      {
         break;
      }
      direction = direction + offset;
   }
}



unordered_set<Position> Piece::straights(int depth)
{
   unordered_set <Position> strts;

   ExploreOffset(strts, Position(0,1));
   ExploreOffset(strts, Position(0,-1));
   ExploreOffset(strts, Position(1,0));
   ExploreOffset(strts, Position(-1,0));
   
   return strts;
}


unordered_set<Position> Piece::diagonal(int depth)
{
   unordered_set <Position> diags;

   ExploreOffset(diags, Position(1,1));
   ExploreOffset(diags, Position(1,-1));
   ExploreOffset(diags, Position(-1,-1));
   ExploreOffset(diags, Position(-1,1));

   return diags;
}


bool Piece::IsAvailable(Position destination)
{
   bool dest_is_empty = chess_->PieceAt(destination) == NULL;
   bool in_bounds = destination.IsWithinBoard();
   bool not_curr_pos = destination != position();

   if (dest_is_empty && in_bounds && not_curr_pos) 
   {
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

Position Piece::starting_position() 
{
   return starting_position_;
}


bool Piece::MoveTo(Position destination)
{
   if (IsAvailable(destination)) 
   {
      RemoveFromBoard();
      set_position(destination);
      return true;
   }
   return false;
}


bool Piece::Colour() 
{
   if (piece_num_ < 0) 
   { 
      return kBlack;
   } 
   return kWhite;
}


bool Piece::RemoveFromBoard()
{
   if (position_ != kOffTheBoard) 
   {
      chess_->board_[position().row][position().col] = NULL;
      position_ = kOffTheBoard;
      return true;
   }
   return false;
}
