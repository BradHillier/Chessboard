#include "../include/chessboard.h"
#include "../include/piece.h"
#include "../include/pawn.h"
#include "../include/rook.h"
#include "../include/knight.h"
#include "../include/bishop.h"
#include "../include/queen.h"
#include "../include/king.h"



Chessboard::Chessboard()
{
   SetDefaultValues();

   // cleaner to use integers and typecast them to PieceNum
   // rather than writing {kBPawn,  kBpawn, ... kBPawn}
   int initial_layout[kBoardSize][kBoardSize] = {
      {-2,-3,-4,-6,-5,-4,-3,-2},
      {-1,-1,-1,-1,-1,-1,-1,-1},
      { 0, 0, 0, 0, 0, 0, 0, 0},
      { 0, 0, 0, 0, 0, 0, 0, 0},
      { 0, 0, 0, 0, 0, 0, 0, 0},
      { 0, 0, 0, 0, 0, 0, 0, 0},
      { 1, 1, 1, 1, 1, 1, 1, 1},
      { 2, 3, 4, 6, 5, 4, 3, 2}
   };
   for (int row = 0; row < kBoardSize; row++) {
      for (int col = 0; col < kBoardSize; col++) {
         PieceNum piece_type = (PieceNum)initial_layout[row][col];
         CreatePiece(piece_type, Position(row, col));
      }
   }
}


Chessboard::~Chessboard()
{
}


list<Position> Chessboard::LegalMoves()
{
}


bool Chessboard::is_game_over()
{
   return is_game_over_;
}


bool Chessboard::current_player()
{
   return current_player_;
}


Piece* Chessboard::selected()
{
   return selected_;
}


PieceNum** Chessboard::board()
{
}


bool Chessboard::Move(Position destination)
{
   // below is just for testing, this will get replaced

    if (selected() != NULL && selected()->MoveTo(destination)) {
       selected_ = NULL;
       return true;
    }
    return false;

}


bool Chessboard::Select(Position position)
{
   // below is just for testing, this will get replaced

    if (PieceAt(position) != NULL) {
       selected_ = PieceAt(position);
       return true;
    }
    return false;
}


bool Chessboard::DeselectPiece()
{
}


Piece* Chessboard::PieceAt(Position position)
{
   return board_[position.row][position.col];
}


void Chessboard::SetDefaultValues()
{
   is_game_over_ = false;
   current_player_ = kWhite;
   selected_ = NULL;
}


void Chessboard::Reset()
{
   SetDefaultValues();
   PlacePiecesInStartingPositions();
}


void Chessboard::PlacePiecesInStartingPositions()
{
}


bool Chessboard::CreatePiece(PieceNum piece_type, Position position)
{
   Piece* piece;            // reference to the soon to be created piece object
   PieceColour colour;      // The colour of the piece being created

   // Parse colour from PieceNum
   if (piece_type < 0) {
      colour = kBlack;
   } else {
      colour = kWhite;
   }
   // create a new piece
   switch (piece_type) {
      case kWPawn:
      case kBPawn:
         piece = new Pawn(this, position, colour);
         break;
      case kWRook:
      case kBRook:
         piece = new Rook(this, position, colour);
         break;
      case kWKnight:
      case kBKnight:
         piece = new Knight(this, position, colour);
         break;
      case kWBishop:
      case kBBishop:
         piece = new Bishop(this, position, colour);
         break;
      case kWQueen:
      case kBQueen:
         piece = new Queen(this, position, colour);
         break;
      case kWKing:
      case kBKing:
         piece = new King(this, position, colour);
         break;
      default:
         board_[position.row][position.col] = NULL;
         return false;
   }
   // add the piece to the set containing all pieces of the same colour
   board_[position.row][position.col] = piece;
   if (colour == kWhite) {
      white_pieces.insert(piece);
   } else {
      black_pieces.insert(piece);
   }
   return true;
}


void Chessboard::Print()
{
    int cell_width = 4;
    int content_size = 2;

   cout << endl;
   for (int i = 0; i < kBoardSize; i++) {
      cout << string(kBoardSize * cell_width + 1, '-') << endl;
      for (int j = 0; j < kBoardSize; j++) {
         if (board_[i][j] != NULL) {
            cout << "|" << setw(content_size) << board_[i][j]->piece_num() << " ";
         } else {
            cout << "|   ";
         }
      }
      cout << "|" << endl;
   }
   cout << string(kBoardSize * cell_width + 1, '-') << endl << endl;
}
