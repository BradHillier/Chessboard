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
   if (IsWithinBoard(destination) && !IsFriendly(destination)) 
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

/**
bool Piece::IsNotFriendly(Position position)
{
   Piece* occupant = chess_->PieceAt(position); 

   if(occupant == NULL || IsFriendly(position))
   {
      return false;
   }
   return true;
}
*/

unordered_set<Position> Piece::straights()
{
   unordered_set <Position> strts;
   Position up = position_;
   Position down = position_;
   Position right = position_;
   Position left = position_;

   //goes through the vertical upward straight
   up.column++;
   while (IsLegalMove(up))
   {
      strts.insert(up);
      //checks if current pos is an enemy and if yes stores the pos and break loop
      if ((!IsFriendly(up)) && (chess_->PieceAt(up) != NULL)) 
      {
         break;
      }   
      up.column++;
   }

   //goes through the downward vertical straight
   down.column--;
   while (IsLegalMove(down))
   {
      strts.insert(down);
      //checks if current pos is an enemy and if yes stores the pos and break loop
      if((!IsFriendly(down)) && (chess_->PieceAt(down) != NULL)) 
      {
         break;
      }
      down.column--;
   }

   //goes through the right horizontal straight
   right.row++;
   while (IsLegalMove(right))
   {
      strts.insert(right);
      //checks if current pos is an enemy and if yes stores the pos and break loop
      if(!IsFriendly(right) && (chess_->PieceAt(right) != NULL)) 
      {
         break;
      }
      right.row++;
   }

   //goes through the left horizontal straight
   left.row--;
   while (IsLegalMove(left))
   { 
      strts.insert(left);
      //checks if current pos is an enemy and if yes stores the pos and breaks loop
      if(!IsFriendly(left) && (chess_->PieceAt(left) != NULL)) 
      {
         break;
      }
      left.row--;
   }
   //returns the complete unordered list of straights
   return strts;
}

unordered_set<Position> Piece::diagonal();
{
   unordered_set <Position> dgnls;
   Position quad1 = position_;
   Position quad2 = position_;
   Position quad3 = position_;
   Position quad4 = position_;

   //goes through the upper right quadrant (quadrant 1)
   quad1.row++;
   quad1.column++;
   while (IsLegalMove(quad1))
   {
      strts.insert(quad1);
      //checks if current pos is an enemy and if yes stores the pos and break loop
      if(!IsFriendly(quad1) && (chess_->PieceAt(quad1) != NULL))
      {
         break;
      }
      quad1.column++;
      quad1.row++;
   }

   //goes through the upper left quadrant (quadrant 2)
   quad1.row-- ;
   quad1.column++;
   while (IsLegalMove(quad2))
   {
      strts.insert(quad2);
      //checks if current pos is an enemy and if yes stores the pos and break loop
      if(!IsFriendly(quad2) && (chess_->PieceAt(quad2) != NULL))
      {
         break;
      }
      quad1.column++;
      quad1.row--;
   }

   //goes through the bottom left quadrant (quadrant 3)
   quad1.row-- ;
   quad1.column--;
   while (IsLegalMove(quad3))
   {
      strts.insert(quad3);
      //checks if current pos is an enemy and if yes stores the pos and break loop
      if(!IsFriendly(quad3) && (chess_->PieceAt(quad3) != NULL))
      {
         break;
      }
      quad1.column--;
      quad1.row--;
   }

   //goes through the bottom right quadrant (quadrant 4)
   quad1.row++ ;
   quad1.column--;
   while (IsLegalMove(quad4))
   {
      strts.insert(quad4);
      //checks if current pos is an enemy and if yes stores the pos and break loop
      if(!IsFriendly(quad4) && (chess_->PieceAt(quad4) != NULL))
      {
         break;
      }
      quad1.column--;
      quad1.row++;
   }
   return dgnls; //returns complete unordered set of diogonals
}

bool Piece::IsAvailable(Position destination)
{
   bool dest_is_empty = chess_->PieceAt(destination) == NULL;
   bool in_bounds = IsWithinBoard(destination);
   bool not_curr_pos = destination != position();

   if (dest_is_empty && in_bounds && not_curr_pos) 
   {
      return true;
   }
   return false;
}


bool Piece::IsWithinBoard(Position destination)
{
   bool row_in_range = 0 <= destination.row && destination.row < kBoardSize;
   bool col_in_range = 0 <= destination.col && destination.col < kBoardSize;

   if (row_in_range && col_in_range) 
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
