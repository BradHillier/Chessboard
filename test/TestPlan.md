# Test Plan        
        
We will use a combination of record and playback style test cases and descriptive user "scripts" detailing actions that must be taking to test a specific feature.        
        
## Menu Testing        
### Entering play from main menu      
**Description :** Starts the game from the main menu.        
**Input :** User presses "1" on the keyboard to start the game.        
**Output :** The playing state with the default configuration of the chessboard.        
        
### Entering help from main menu       
**Description :** Enter the Help screen from the main menu.        
**Input :** User presses "2" on the keyboard to go to the help.        
**Output :** The Help screen.        
        
### Entering credits from main menu       
**Description :** Enter the Credits screen from the main menu.        
**Input :** User presses "3" on the keyboard to go to the credits.        
**Output :** The Credits screen.        
        
### Entering Credits from Main Menu        
        
### Entering Main Menu from Help     
**Description :** Start the game in main menu proceed to help help screen by pressing the key indicated by the program. Then, return to the main menu by the same process.        
**Input :** User presses "3" to enter the help state, then presses "1" to return to the main menu        
**Output :** The program should display the main menu, then help screen, and finally the main menu again.        
        
### Entering Main Menu from Playing State       
**Description :** Start the game in main menu proceed to playing state by pressing the key indicated by the program. Then, return to the main menu by the same process.        
**Input :** User presses "1" to enter the playing state, then presses "1" again to return to the main menu        
**Output :** The program should display the main menu, then a chessboard in its initial state, and finally the main menu again.        
        
### Quit from Main Menu
**Description :** Have a quit option accessible from the main menu to exit the program        
**Input :** Have the user enter the quit command (or click the quit button)        
**Output :** Quits out of the program        
        
## Quit from Play        
        
### Quit by clicking window’s X button
**Description :** Quits the program when the user clicks the X button on the game window        
**Input :** User clicks the X button with the mouse        
**Output :** Quits out of the program        

### Reset the Board 
**description :** Test if the game properly resets to its initial state, putting all pieces back in thier original positions        
**Input :** User presses "1" to enter the playing state. Move one black piece and one white piece, then pressing the button associated with reseting the game.        
**Output :** Pieces should immediately appear back in their initial positons upon hitting reset        
        
### Select a Piece*        
**Description :** Clicking on a friendly piece on your turn should select it        
**Input :** Press "1" to enter the playing state and click on any white piece         
**Output :** the clicked piece should follow the mouse around the game window        
        
### Make a valid move (individual piece moves will get taken care of in unit testing)
**Description :** Select a piece and make a valid move with the piece        
**Input :** User selects a piece and a legal tile in which to move the piece        
**Output :** Piece is moved on the board to its new position        
        
### Can’t make invalid move
**Description :** Select a piece and make an invalid move and piece remains in the same tile        
**Input :** User selects a piece and an illegal move with the piece        
**Output :** Piece returns to it’s original position and user must select a valid move        
        
### promote pawn when reaching other end of the board        
        
### cant take friendly piece        
        
### take enemy piece        
          
### victory check
**description:** checks if the king is dead and discerns the winner        
**input:** user moves their piece onto the enemy king        
**output:** displays the winning colour in the console        
        
### Return to main menu upon victory by hitting enter
**Description :** Once the game is concluded, either player can press enter to go back to the main menu.        
**Input :** Either user presses the "Enter" upon the conclusion of the game.        
**Output :** The Main Menu screen.        
