# Test Selecting a Piece

## Description 
Start the program. You should see the main menu screen from here, Pressing '1' should take you to the Playing screen. Upon entering the playing state, Press '3' and the game should prompt you to enter the position of a piece. Upon entering a valid position, the selected piece should be highlighted with green and all of its available moves should be highlighted yellow.

## Running the test
After entering the input in the left side of the table below, the program should display the screen in its associated result. If at any point the screen being displayed by the program does not match the screen associated with the most recent input, test fails. If every input entered produces the anticipated screen, this test passes.

| Input | Result|
|---|---|
| Program start | Main Menu     |
| press '1'     | Playing State   |
| press '3'     | prompted for input     |
| type 'e2'; press enter     | the pawn at e2 should be highlighted green and e3 and e4 should be highlighted yellow   |
