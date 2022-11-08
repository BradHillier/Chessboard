#include "../include/chessboard.h"
#include "../include/piece.h"


Chessboard::Chessboard()
{
   is_game_over_ = false;
   current_player_ = kWhite;
   selected_ = NULL;

   // need to add board initialization
}

Chessboard::~Chessboard()
{
}

vector<Position> Chessboard::LegalMoves()
{
}

bool Chessboard::Take(Position piece)
{
}

bool Chessboard::IsValidMove(Position destination)
{
}

bool Chessboard::is_game_over()
{
}

bool Chessboard::current_player()
{
}

Piece* Chessboard::selected()
{
}

int** Chessboard::board()
{
}

bool Chessboard::Move(Position destination)
{
}

bool Chessboard::Select(Position position)
{
}

bool Chessboard::DeselectPiece()
{
}

Piece* PieceAt(Position position)
{
}

void Chessboard::Reset()
{
}
