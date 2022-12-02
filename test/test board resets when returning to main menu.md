# Test Board Resets When Returning to Menu

Start the program and enter the playing state. Move several pieces around the board, and then return to the main menu. Upon doing so, the state of the chessboard should reset, putting all pieces back in their default position. Can should be observewd when reentering the playing state.

## Running the test
After entering the input in the left side of the table below, the program should display the screen in its associated result. If at any point the screen being displayed by the program does not match the screen associated with the most recent input, test fails. If every input entered produces the anticipated screen, this test passes.

| Input | Result|
|---|---|
| Program start | Main Menu     |
| press '1'     | Playing State   |
| press '3'     | Prompted for input     |
| type 'e2'; press 'enter'     | pawn in e2 should become highlighted green   |
| press '3'     | Prompted for input     |
| type 'e4'; press 'enter'     | pawn in e2 should move to e4 |
| press '1'     | Main Menu     |
| press '1'     | Playing state with all pieces in their original positions |
