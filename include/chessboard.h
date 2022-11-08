#ifndef CHESSBOARD
#define CHESSBOARD
#include "globals.h"
#include <list>
using std::list;


// forward declaration
class Piece;

class Chessboard
{
   private:
      
      /** flag indicating if game is over, either by check mate or other */
      bool is_game_over_; 

      /** The player currently taking their turn; typedef for bool */
      PieceColour current_player_;

      /** The piece currently selected, waiting to be move */
      Piece* selected_;

      /** A 2D array of Pieces representing the current state of the game board */
      Piece** board_;

      list<Position> LegalMoves();

      bool Take(Position piece);

      bool IsValidMove(Position destination);
   public:
      Chessboard();
      ~Chessboard();

      /** @brief Check if the game is over.
      *
      *   A getter method for the `is_game_over_` attribute.
      *   This prevents entities from outside the class changing
      *   the game over status.
      *
      *   @return The value of `is_game_over_`.
      */
      bool is_game_over();

      /** @brief Get the player currently taking their turn
      *
      *   A getter method for the `current_player_  attribute.
      *   This gives external entities access to the games current player
      *   without allowing them to directly change it. PieceColour is 
      *   a typedef for bool.
      *
      *   @return bool, true if whites turn, false if blacks turn
      */
      PieceColour current_player();

      /** @brief get a reference to the 
      */
      Piece* selected();

      /** @brief A simplified representation of the board for external use
      *
      *   Maps each piece in `board_` to its associated PieceNum value.
      *   Using a simplified version of the array prevents passing pointers
      *   outside the scope of the Chessboard where they could be modified
      *   in unintended ways. This also passes the minimum amount of 
      *   information needed to display the current state of the board.
      *
      *   @return A pointer to an 8x8 2D array of PieceNums
      */
      PieceNum** board();

      /** @brief Attempt to move the selected piece to the provided position
      *
      *   If a piece is currently selected, get its available moves and check
      *   if the provide move is in the list. If so, use the piece's set
      *   position method to move it and return true. otherwise return false
      *   if no piece is selected return false.
      *
      *   @param destination The position to move the selected piece to
      *   @return success of the operation
      */
      bool Move(Position destination);

      /** @brief select the piece at the provided position
      *
      *   If a piece exists at the provided position, select it, updating 
      *   the board's `selected_` property and return true.  If a piece is 
      *   already selected, the newly selected piece will overwrite it. If the 
      *   provided position is empty return false.
      *
      *   @param position The position containing the piece to select
      *   @return Success of the operation
      */
      bool Select(Position position);

      /** @brief deselect the currently selected piece
      *
      *   If a piece is currently selected, set `selected_` to NULL and return
      *   true. If no piece is selected return false.
      *
      *   @return true is a piece was successfully deselected otherwise false
      */
      bool Deselectpiece();
      
      /** @brief Get a reference to the piece at the provided position
      *
      *   If a piece exists at the provided position on the board, return
      *   a pointer to it. If no piece exists return NULL.
      *
      *   @param position The location on the board to check for a piece
      *   @return A reference to the piece if one exists.
      */
      Piece* PieceAt(Position position);

      /** @brief Reset the game board to its initial state
      *
      *   TODO: add detailed implementation description here
      *
      *   @return Void
      */
      void Reset();
};

#endif
