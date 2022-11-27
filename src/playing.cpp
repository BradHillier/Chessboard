#include "../include/playing.h"
#include "../include/sdl_chess_game.h"


Playing::Playing(SDLChessGame* parent)
   :State(parent)
{
   controller_ = new Controller;

   // these cane be modified to style the board
   cell_width = 2;
   content_size = 1;
   
   // these should not be changed as they use the above variables to
   // center the content of each cell. Alternating these may result
   // in an unevenly formatted grid.
   float average_padding = (cell_width - content_size) * 0.5;
   left_padding = string(floor(average_padding), ' ');
   right_padding = string(ceil(average_padding), ' ');
   PieceColour current_bg_colour = kWhite;
}


Playing::~Playing()
{
}


bool Playing::LoopCondition()
{
   return parent_->current_state() == SDLChessGame::playing;
}


void Playing::enter()
{
    cout<<"Entered Playing State"<<endl;
    cout<<endl;
}


void Playing::HandleInput()
{
   char num, col;
   int row;

   bool input_recieved = false;
   do 
   {
      input_recieved = keyQuick(num);
   } 
   while (!input_recieved);

   switch (num)
   {
   case '1':
      leave();
      parent_->ChangeState(SDLChessGame::main_menu);
      break;
   case '2':
      leave();
      exit(0); 
   case '3':
      moveCursor(15, 0);
      cout << "Enter the row and column: ";
      cin >> col >> row;
      controller_->ProcessClick(position_from_coords(row, col));
      break;
   }
}

void Playing::Render()
{
   const string white_space = string(2, '\n');

   DisplaySelectedPiece();   

   cout << white_space;

   PrintBoard();

   cout << white_space;;

   long width, height;
   getTermSize(height, width);
   cout << string(width, '_') << endl;
   DisplayMenuOptions();
}


void Playing::leave()
{
    controller_->ResetGame();
}


void Playing::DisplaySelectedPiece()
{
   PieceColour player = controller_->GetCurrentPlayer();

   cout << "Current Player: ";
   cout << ((player == kWhite) ? "White" : "Black") << endl;
}


void Playing::DisplayMenuOptions()
{
   cout << "1. Main Menu" << endl;
   cout << "2. Quit" << endl;

   if (controller_->GetSelectedPiece() != kOffTheBoard) 
   {
      cout << "3. Move currently selected piece" << endl;
   } 
   else 
   {
      cout << "3. select a piece" << endl;
   }
}


void Playing::PrintBoard()
{
   long width, height;
   getTermSize(height, width);

   int board_size = (kBoardSize + 2)  * cell_width;
   int padding = (width - board_size) / 2;

   const Board board = controller_->GetBoard();

   DisplayColumnLetters(padding);
   for (int i = 0; i < kBoardSize; i++) 
   {
      DisplayRowNumber(i, padding);
      for (int j = 0; j < kBoardSize; j++) 
      {
         DisplayCell(board, i, j);
      }
      DisplayRowNumber(i);
      cout << endl;

      // alternates starting colour for each row
      current_bg_colour = !current_bg_colour;
   }
   DisplayColumnLetters(padding);
   chgText(DefCol);
}


string Playing::GetPieceUnicode(PieceNum piece)
{
   switch (piece)
   {
      case kWKing:
         return "\u2654";
      case kWQueen:
         return "\u2655";
      case kWRook:
         return "\u2656";
      case kWBishop:
         return "\u2657";
      case kWKnight:
         return "\u2658";
      case kWPawn:
         return "\u2659";
      case kBKing:
         return "\u265A";
      case kBQueen:
         return "\u265B";
      case kBRook:
         return "\u265C";
      case kBBishop:
         return "\u265D";
      case kBKnight:
         return "\u265E";
      case kBPawn:
         return "\u265F";
   }
}

Position Playing::position_from_coords(char row, int col)
{
   int r = kBoardSize - row;
   int c = (int)col - (int)'a'; 
   return Position(r, c);
}


void Playing::SetBackgroundColour(int row, int col)
{
   if (controller_->GetSelectedPiece() == Position(row, col))
   {
      // highlight the currently selected piece
      chgBack(Green);
   } 
   else if (controller_->GetLegalMoves().count(Position(row, col)) != 0)
   {
      // highlight LegalMoves for the selected piece
      chgBack(Yellow);
   }
   else if (current_bg_colour == kWhite)
   {
      chgBack(Pale);
   }
   else
   {
      chgBack(Grey);
   }
}


void Playing::DisplayCell(const Board board, int row, int col)
{
   string empty_cell = string(cell_width, ' ');

   chgText(Black);
   SetBackgroundColour(row, col);

   if (board[row][col] == kEmpty) 
   {
      cout << empty_cell;
   } 
   else 
   {
      cout << left_padding;
      cout << GetPieceUnicode(board[row][col]);
      cout << right_padding;
   }
   current_bg_colour = !current_bg_colour;
}


void Playing::DisplayRowNumber(int i, int padding)
{
   chgText(DefCol);
   cout << string(padding, ' ');
   chgBack(Black);
   cout << kBoardSize - i << " ";
}


void Playing::DisplayColumnLetters(int padding)
{
   chgText(DefCol);
   cout << string(padding, ' ');
   chgBack(Black);
   cout << "  a b c d e f g h   " << endl;
}
