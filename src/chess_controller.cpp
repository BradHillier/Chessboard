#include "../include/chess_controller.h"

Controller::Controller()
{
    game_ = new Chessboard;
}

Controller::~Controller()
{
    delete game_;       
}

void Controller::ProcessClick(Position position)
{
    // Assumes that ChessBoard's selected() getter method 
    // returns NULL if no piece is currently selected
    if (game_->selected() == kOffTheBoard)
    {
        game_->Select(position);
    }
    else
    {
        game_->Move(position);
    }
}

unordered_set<Position> Controller::GetLegalMoves()
{   
    return game_->LegalMoves();    
}

Position Controller::GetSelectedPiece()
{
    return game_->selected();
}

PieceNum** Controller::GetBoard()
{
    return game_->board();
}

bool Controller::GetCurrentPlayer()
{
    return game_->current_player();
}

bool Controller::GetIsGameOver()
{
    return game_->is_game_over();
}

void Controller::ResetGame()
{
    game_->Reset();
}
