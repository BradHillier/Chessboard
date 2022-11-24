#include "globals.h"
#include "chessboard.h"
#include <unordered_set>
#include <list>
using std::unordered_set;
using std::list;


class Controller
{
    private:
    
        /** The internal representation of the game chessboard */
        Chessboard game_;
    
    public:

        Controller();
        ~Controller();

        /** @brief Processes each click made by the player
        *
        *   If no selected piece current exists for the player
        *   select the piece in the provided position. If one exists,
        *   attempt to move the currently selected piece to the clicked
        *   position
        *    
        *   @param position:Position
        *   @return void
        */
        void ProcessClick(Position position);
        
        /** @brief gets all the legal moves for a current selcted piece
        *
        *   Get all available moves for the currently selected piece. 
        *   If a piece is selected, call its LegalMoves() method and return
        *   the resulting set. If no piece is selected, 
        *   return an empty set 
        *
        *   @return vector<Position>
        */
        unordered_set<Position> GetLegalMoves();

        /** @brief Returns the Position of the game_'s current piece
        *
        *   Checks if a piece is selected and if not returns NULL. 
        *   Otherwise returns the Position associated with game_'s
        *   currently selected piece.
        *    
        *   @return Position
        */ 
        Position GetSelectedPiece();

        /** @brief Returns the Current Matrix of pieces on the gameboard
        *
        *   return the current layout of pieces on the gameboard. 
        *   PieceNum is used to limit direct access to the games Piece objects
        *       
        *   @return Position
        */ 
        PieceNum** GetBoard();

        /** @brief Returns game_'s current player
        *       
        *   @return bool
        */ 
        bool GetCurrentPlayer();

        /** @brief Get the game over status from the game_
        *   and return it.
        *    
        *   @return bool
        */ 
        bool GetIsGameOver();

        /** @brief Resets the gameboard to its initial state
        *
        *   return the gameboard to its initial state, putting all the pieces 
        *   back to their default tiles by utilizing game_'s Reset() method
        *       
        *   @return void
        */ 
        void ResetGame();
};   
