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
      //checks if next pos is an enemy and if yes stores the pos and break loop
      if ((!IsFriendly(up)) && (chess_->PieceAt(up) != NULL)) 
      {
         strts.insert(up);
         break;
      }
      strts.insert(up);
      up.column++;

   }

   //goes through the downward vertical straight
   down.column--;
   while (IsLegalMove(down))
   {
      //checks if next pos is an enemy and if yes stores the pos and break loop
      if((!IsFriendly(down)) && (chess_->PieceAt(down) != NULL)) 
      {
         strts.insert(down);
         break;
      }
      strts.insert(down);
      down.column--;
   }

   //goes through the right horizontal straight
   right.row++;
   while (IsLegalMove(right))
   {
      //checks if next pos is an enemy and if yes stores the pos and break loop
      if(!IsFriendly(right) && (chess_->PieceAt(right) != NULL)) 
      {
         strts.insert(right);
         break;
      }
      strts.insert(right);
      right.row++;

   }

   //goes through the left horizontal straight
   left.row--;
   while (IsLegalMove(left))
   { 
      //checks if next pos is an enemy and if yes stores the pos and breaks loop
      if(!IsFriendly(left) && (chess_->PieceAt(left) != NULL)) 
      {
         strts.insert(left);
         break;
      }
      strts.insert(left);
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
   while (IsLegalMove(quad1.column + 1 && quad1.row + 1)
   {
      //checks if next pos is an enemy and if yes stores the pos and break loop
      if(!IsFriendly(quad1.column + 1 && quad1.row + 1))
      {
         quad1.column++;
         quad1.row++;
         strts.insert(quad1));
         break;
      }
      quad1.column++;
      quad1.row++;
      strts.insert(quad1));

   }

      //goes through the upper left quadrant (quadrant 2)
   while (IsLegalMove(quad1.column + 1 && quad1.row - 1)
   {
      //checks if next pos is an enemy and if yes stores the pos and break loop
      if(!IsFriendly(quad2.column + 1 && quad2.row - 1))
      {
         quad2.column++;
         quad2.row--;
         strts.insert(quad2));
         break;
      }
      quad2.column++;
      quad2.row--;
      strts.insert(quad2));

   }

      //goes through the bottom left quadrant (quadrant 3)
   while (IsLegalMove(quad3.column - 1 && quad3.row - 1)
   {
      //checks if next pos is an enemy and if yes stores the pos and break loop
      if(!IsFriendly(quad3.column - 1 && quad3.row - 1))
      {
         quad3.column--;
         quad3.row--;
         strts.insert(quad3));
         break;
      }
      quad3.column--;
      quad3.row--;
      strts.insert(quad3));

   }

      //goes through the bottom right quadrant (quadrant 4)
   while (IsLegalMove(quad4.column - 1 && quad4.row + 1)
   {
      //checks if next pos is an enemy and if yes stores the pos and break loop
      if(!IsFriendly(quad4.column - 1 && quad4.row + 1))
      {
         quad4.column--;
         quad4.row++;
         strts.insert(quad4));
         break;
      }
      quad4.column--;
      quad4.row++;
      strts.insert(quad4));

   }

  
   return dgnls;
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
