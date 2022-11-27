#include "../include/effects.h"

// if no key has been pressed return false
// otherwise copy the character to c and return true
bool keyQuick(char &c)
{
    // remember the previous terminal settings
    struct termios original;
    tcgetattr(0,&original);

    // setup new temporary values
    struct termios temporary = original;
    temporary.c_lflag &= ~ICANON; // toggle off eof/eoln/kill/etc
    temporary.c_lflag &= ~ECHO;   // toggle off keyboard echo
    temporary.c_lflag &= ~ISIG;   // toggle off interrupt/suspend/quit
    temporary.c_cc[VMIN] = 1;     // min characters for successful read
    temporary.c_cc[VTIME] = 0;    // timeout duration in deciseconds

    // apply the temporary settings
    tcsetattr(0, TCSANOW, &temporary);

    // check for a key hit waiting to be processed
    unsigned char newCh;
    int numRead;
    temporary.c_cc[VMIN]=0;
    tcsetattr(0, TCSANOW, &temporary);
    numRead = read(0,&newCh,1);
    temporary.c_cc[VMIN]=1;
    tcsetattr(0, TCSANOW, &temporary);

    // if the read actually captured characters, 
    //    copy the value read in, reset the terminal, 
    //    and return true
    // otherwise reset the terminal and return false
    //    after a brief pause to prevent excessive polling
    if(numRead > 0) {
        c = (char)(newCh);
        tcsetattr(0, TCSANOW, &original);
        return true;
    } else {
        tcsetattr(0, TCSANOW, &original);
        sysPause(0.05);
        return false;
    }
}

// =============================================================
//       OUTPUT FUNCTIONS
//

void getTermSize(long &h, long &w)
{
   struct winsize wn;
   ioctl(0, TIOCGWINSZ, &wn);
   h = wn.ws_row;
   w = wn.ws_col;
}

// clear the screen and move the cursor to the top left
void clear()
{
   printf("\033[2J\033[H");
}

// jump the cursor to the specified row and column,
//    where 1,1 is top left
void moveCursor(long row, long col) 
{
   printf("\033[%ld;%ldH", row, col);
}

void chgFormat(FormType t)
{
   switch (t) {
       case Clear: printf("\033[0m"); break;
       case Bold: printf("\033[1m"); break;
       case Underline: printf("\033[4m"); break;
       case Faint: printf("\033[5m"); break;
       case Negative: printf("\033[7m"); break;
       case Normal: printf("\033[10m"); break;
       case Alt: printf("\033[12m"); break;
      default: printf("\033[0m"); break;
   }
}

void chgText(Colour c)
{
   switch (c) {
       case Black: printf("\033[30m"); break;
       case Red: printf("\033[31m"); break;
       case Green: printf("\033[32m"); break;
       case Yellow: printf("\033[33m"); break;
       case Blue: printf("\033[34m"); break;
       case Purple: printf("\033[35m"); break;
       case Pale: printf("\033[36m"); break;
       case Grey: printf("\033[37m"); break;
      default: printf("\033[0m"); break;
   }
}

void chgBack(Colour c)
{
   switch (c) {
       case Black: printf("\033[40m"); break;
       case Red: printf("\033[41m"); break;
       case Green: printf("\033[42m"); break;
       case Yellow: printf("\033[43m"); break;
       case Blue: printf("\033[44m"); break;
       case Purple: printf("\033[45m"); break;
       case Pale: printf("\033[46m"); break;
       case Grey: printf("\033[47m"); break;
      default: printf("\033[0m"); break;
   }
}


// =============================================================
//       TIMING ROUTINES
//
// pauses the game for t seconds, t in 0.05 to 1800
void sysPause(float t)
{
   long pauseTime;
   if (t < 0.05) pauseTime = 50000;
   else if (t > 1800) pauseTime = 1800000000;
   else pauseTime = t * 1000000;
   usleep(pauseTime);
}

// =============================================================
//       2D ARRAY ROUTINES
//
// allocates a two-dimensional array with the specified
//    number of rows and columns, returns a pointer to it
ROW *alloc(int rows, int cols)
{
   ROW *t = new ROW[rows];
   if (t) {
      for (int r = 0; r < rows; r++) {
          t[r] = new long[cols];
      }
   }
   return t;
}

// deallocate the two-dimensional array
void dealloc(ROW* t, int rows, int cols)
{
   if (t) {
      for (int r = 0; r < rows; r++) {
          if (t[r]) delete [] t[r];
      }
      delete [] t;
   }
}
