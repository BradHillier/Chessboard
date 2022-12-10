#ifndef PLAYING_H
#define PLAYING_H

#include "state.h"
#include "chess_controller.h"

typedef array<array<PieceNum, kBoardSize>, kBoardSize> Board;

class Playing : public State
{
   private:
      Controller* controller_;
      int cell_width;
      int content_size;
      string left_padding;
      string right_padding;
      PieceColour current_bg_colour;

      virtual bool LoopCondition() override;

      void DisplaySelectedPiece();

      void PrintBoard();

      void DisplayMenuOptions(); 

      void SetBackgroundColour(int row, int col);

      void DisplayCell(const Board board, int row, int col);

      void DisplayRowNumber(int i, int padding=0);

      void DisplayColumnLetters(int padding=0);

      Position position_from_coords(char row, int col);

      string GetPieceUnicode(PieceNum piece);

   public:
       Playing(SDLChessGame* parent);
       virtual ~Playing();

       void enter() override;

       void leave() override;

       virtual void Render() override;

       virtual void HandleInput() override;
};

#endif
