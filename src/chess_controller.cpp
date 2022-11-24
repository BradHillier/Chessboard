#include "../include/chess_controller.h"

Controller::Controller()
{
    game_ = new ChessBoard;
}

Controller::~Controller()
{
    delete game_;       
}

void Controller::ProcessClick(Position position)
{
    // Assumes that ChessBoard's selected() getter method 
    // returns NULL if no piece is currently selected
    if (ChessBoard.selected() == NULL)
    {
        Chessboard.Select(position);
    }
    else
    {
        ChessBoard.Move(position);
    }
}

unordered_set<Position> GetLegalMoves()
{   
    return ChessBoard.LegalMoves();    
}

Position GetSelectedPiece()
{
    return ChessBoard.Selected();
}

PieceNum** GetBoard()
{
    return ChessBoard.board();
}

bool GetCurrentPlayer()
{
    return ChessBoard.current_player();
}

bool GetIsGameOver()
{
    return ChessBoard.is_game_over();
}

void ResetGame()
{
    ChessBoard.Reset();
}
