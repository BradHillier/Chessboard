# Test Plan

## Testing Techniques

## Test Cases

### Menu Testing
#### Entering a different state from the main menu
Entering Play from Main Menu
Entering Help from Main Menu
Entering Credits from Main Menu
#### Returning to the Main Menu
Entering Main Menu from Help 
Entering Main Menu from Play 
#### Quitting the Program
Quit from Main Menu
Quit from Play
Quit by clicking the windows `x` button

### Play State Testing
Reset the Board 
Select a Piece
Make a valid move (individual piece moves will get taken care of in unit testing)
cant make invalid move 
promote pawn when reaching other end of the board
cant take friendly piece
take enemy piece

victory check
   description:
      checks if the king is dead and discerns the winner
   input: 
      user moves their piece onto the enemy king
   output: 
      displays the winning colour in the console

return to main menu upon victory by hitting enter




RISHABH

Entering Play from Main Menu
Entering Help from Main Menu
Entering Credits from Main Menu
return to main menu upon victory by hitting enter


BRAD

Entering Main Menu from Help 
Entering Main Menu from Play 
Reset the Board 
Select a Piece


JOSH

Quit by clicking the windows `x` button
Quit from Main Menu
Make a valid move (individual piece moves will get taken care of in unit testing)
cant make invalid move 


RICARDO 

promote pawn when reaching other end of the board
cant take friendly piece
take enemy piece
Quit from Play
