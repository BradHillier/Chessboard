#ifndef EFFECTS_H
#define EFFECTS_H

// =============================================================
// The functions in this library have four key sections:
// timing routines, input routines, output routines,
// and allocation/deallocation routines for a 2d array

// =============================================================
//       LIBRARIES AND DEFINITIONS 
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>  
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
enum Colour { DefCol, Black, Red, Green, Yellow, 
                      Blue, Purple, Pale, Grey };
enum FormType { DefForm, Clear, Bold, Underline, Faint, 
                         Negative, Normal, Alt };

// =============================================================
//       USING THE TIMING ROUTINES
// Pause the system for t seconds, t between 0.05 and 1800
void sysPause(float t);

// =============================================================
//       USING THE OUTPUT ROUTINES
//
// Obtain the height and width of the terminal window using
void getTermSize(long &h, long &w);

// Jump the cursor to a specific row and column (1,1 is top left)
void moveCursor(long row, long col);

// Clear the screen and move the cursor to the top left
void clear();

// Change the colour of the text or the background 
//    where the colours can be any of
//       Black, Red, Green, Yellow, Blue, Purple, Pale, Grey
//    or DefCol to restore all defaults
void chgText(Colour c);
void chgBack(Colour c);

// Change highlighting and other effects 
//    where the format can be any of
//       Clear, Bold, Underline, Faint, Negative, Normal, Alt
//       (Normal and Alt toggle between the two character fonts)
//    or DefForm to restore all defaults
void chgFormat(FormType t);

// =============================================================
//       USING THE INPUT ROUTINES
//
// This routine returns true if the user has pressed a key
//    (false otherwise) and returns the key in c
bool keyQuick(char &c);

// =============================================================
//       USING THE 2D ARRAY ROUTINES
//
// type definition to allow allocation/deallocation of
//    a two-dimensional array of longs
typedef long* ROW;

// allocates a two-dimensional array with the specified
//    number of rows and columns, returns a pointer to it
ROW *alloc(int rows, int cols);

// deallocate the two-dimensional array
void dealloc(ROW* table, int rows, int cols);


#endif
