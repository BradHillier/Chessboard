#ifndef CHESSBOARD
#define CHESSBOARD
#include "globals.h"
#include <unordered_set>
#include <array>
using std::unordered_set;
using std::array;

// These are all included specifically for Print()
#include <iostream>
#include <iomanip>
#include <string>
using std::setw;
using std::cout;
using std::endl;
using std::string;


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

      /** @brief A 2D array of Pieces representing the current state of the game board 
      *
      *   This should never be directly modified by the Chessboard itself.
      *   Read the description above `friend class Piece` for more info.
      */
      Piece* board_[kBoardSize][kBoardSize];

      /** set of all white pieces on and off the gameboard */
      unordered_set<Piece*> white_pieces;

      /** set of all black pieces on and off the gameboard */
      unordered_set<Piece*> black_pieces;

      /** @brief create a new Piece of the specified type and place it on the board
      *
      *   Using a simplified integer representation of the initial piece setup, *   clear all old piece from the board and replace them with new ones
      *   in  there initial positions
      *
      *   @param piece_type The PieceNum representation of the piece being created
      *   @param position The Position on the board to place the newly created piece
      *
      *   @example 
      *   if (CreatePiece(kBPawn, Position(1, 1))) {
      *      cout << "You succesfully created a Black Pawn" << endl;
      *   }
      *
      *   @return bool True if space was allocated for a new piece, otherwise false
      */
      bool CreatePiece(PieceNum piece_type, Position position);

      /** @brief Get a reference to the piece at the provided position
      *
      *   If a piece exists at the provided position on the board, return
      *   a pointer to it. If no piece exists return NULL.
      *
      *   @example 
      *   PieceAt(Position(1, 1));          // kBPawn at the start of game 
      *   PieceAt(Position(-1, -1));        // NULL as (-1,-1) is out of bounds 
      *
      *   @param position The location on the board to check for a piece
      *   @return A reference to the piece if one exists.
      */
      Piece* PieceAt(Position position);

      /** @brief Reset the game flags to their default state
      *
      *   Resets the games current player, selected piece and its flag
      *   denoting whether the game is over or not.
      */
      void SetDefaultValues();

      /** @brief Move all the game pieces to their intial position on the board
      *
      *   iterates through the sets of white and black pieces, moving each piece
      *   to their respective starting position. If a different piece is currently
      *   in another pieces starting position it first removes the incorrectly 
      *   placed piece from the board and then replaces it with the correct piece.
      */
      void PlaceInStartingPositions(unordered_set<Piece*> pieces);

      /** This allows all Piece movement on the board to happen directly on
      *   the piece objects. This was done to prevent the possibility of the 
      *   array representing the gameboard getting out of sync with the
      *   Position stored on each individual Piece.
      */
      friend class Piece;

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

      /** @brief get the position the currently selected piece is in
      *  
      *   Acts as a getter method for the selected_ property without
      *   directly making the pointer available for manipulation
      */
      Position selected();

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
      array< array<PieceNum, kBoardSize>, kBoardSize> board();

      /** @brief Attempt to move the selected piece to the provided position
      *
      *   If a piece is currently selected, get its available moves and check
      *   if the provide move is in the set. If so, use the piece's set
      *   position method to move it and return true. otherwise return false
      *   if no piece is selected return false.
      *
      *   @param destination The position to move the selected piece to
      *   @return success of the operation
      */
      bool Move(Position destination);

      /** @brief Get a all legal moves for the currently select piece
      *
      *   Get the set containing all available Positions on the board that 
      *   are legal move for the piece currently selected
      *
      *   @return all legal moves or an empty set if no piece selected
      */
      unordered_set<Position> LegalMoves();

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
      *   @example
      *   if (DeselectPiece()) {
      *     cout << "Successfully deselected a piece" << endl;
      *   } else {
      *     cout << "No piece was selected" << endl;
      *   }
      *   cout << Selected()  // prints NULL
      *
      *   @return true is a piece was successfully deselected otherwise false
      */
      bool DeselectPiece();


      /** @brief Reset the game board to its initial state
      *
      *   Resets all the games flags and values to their default state
      *   and move all of the game pieces to their initial position.
      */
      void Reset();

      /** @brief Display the current layout of the game board
      *
      *   Display a ascii art representation of the game board with 
      *   each Piece represented by their associated PieceNum integer.
      */
      void Print();
};

#endif
