#include "../include/chessboard.h"
#include "../include/piece.h"
#include <iostream>
using namespace std;


char get_cmd()
{
   char c;
   cout << "enter either 'M', 'S', 'R'  or 'Q': ";
   cin >> c;
   return toupper(c);
}

int main()
{
   Chessboard board;

   int c;
   int x, y;
   do {
      
      if (board.selected() != kOffTheBoard) { 
         cout << endl << "currently selected: Position(";
         cout << board.selected().col << ", "; 
         cout << board.selected().row << ")";
      } else {
         cout << endl << "no piece selected";
      }
      board.Print();
      c= get_cmd();

      switch (c) {
         case 'M':
            cout << "enter the position: ";
            cin >> x >> y;
            cout << "You entered " << x << ", " << y << endl;;
            if (board.Move(Position(x, y))) {
               cout << "successfully move the piece" << endl;
            } else {
               cout << "no piece to move" << endl;
            }
            break;
         case 'S':
            cout << "enter the position: ";
            cin >> x >> y;
            cout << "You entered " << x << ", " << y << endl;;
            board.Select(Position(x, y));
            break;
         case 'R':
            cout << "reseting the board";
            board.Reset();
      }
   } while (c != 'Q');
}


