# Chessboard

## Table of Contents
1. [Overview](#overview)
2. [Platforms](#platforms)
3. [Scenarios](#scenarios)
4. [Screens](#screens)
   - [Main Menu](#main-menu)
   - [Help](#help)
   - [Credits](#credits)
   - [In Game](#in-game)
   - [End Game](#end-game)
- [Rules](#rules)
- [Controls](#controls)
   - [Selecting a Piece](#selecting-a-piece)
      - [Deselecting a Piece](#deselecting-a-piece)
      - [Selecting a Different Piece](#selecting-a-different-piece)
   - [Moving a Piece](#moving-a-piece)
      - [If the Player Moves the Mouse Out of the Window](#mouse-off-screen)

##Overview <a name="overview" />
A two-player chess game in a pass-and-play GUI environment (both players use the same computer and interface to input their moves). The game will take place on a two-dimensional 64-square board with letters labelling the board’s columns and numbers labelling the rows. The game will contain some sort of marker indicating which player is currently taking their turn. On a player’s turn, they can select one of their chess pieces and move it to any legal tile. When a player selects their piece, the piece’s tile will follow the mouse until a move is selected. If the player clicks on one of their other pieces while they already have a piece selected, the clicked piece will become their new selected piece. If the player tries to select one of the opponent’s pieces or move their selected piece to an invalid spot, nothing will happen. Once the player has made a valid move, the next player will take their turn. Once the game is over, the winner will be displayed, and the player will be presented with a list of options, such as restarting the game, quitting the program, or returning to the main menu.

## Platforms <a name="platforms" />
Linux, macOS, Windows


<div style="page-break-after: always;"></div>


## Scenarios <a name="scenarios" />
Two users can sit down together with a laptop, no matter where they are they will be able to open the chess game and can sit together at the same computer. They will be able to start a game together and pass the laptop between one another and play a full, complete game of chess together without the need of having a physical chess board where you will need to set up the board and reset every time a new game is started.

## Screens <a name="screens" />
<img alt="turn diagram" style="margin: auto; display: block; padding: 20px" src="state_diagram.png" width=600>
The game will have several screens with which the user can interact. The above diagram demonstrates how the user can move between the different screens. Below, each screen is described in detail and accompanied by a mockup.


<div style="page-break-after: always;"></div>


### Main Menu <a name="main-menu" />
<img alt="turn diagram" style="margin: auto; display: block; padding: 20px" src="main_menu.png" width=600>
The Main Menu is the Startup screen of the application. From here, users can navigate to all sections of the application. The Main Menu gives the user the following options:

- **Start** – Start a pass n play game of chess with another player.
- **Help** – Read the instruction for the app and the rules of chess.
- **Credits** – Credits screen credits all the developers with a short description of their role.
- **Quit** – Stops the program.

The Main Menu is also accessible after a game ends and from the in-game state if any player chooses to do so.
### In Game<a name="in-game" />
The chess game starts with the white's turn and alternates legal moves between black and white until one of the kings is checkmated. Players can navigate the application's different states, even in the in-game state. The applications allow users to quit the program or go to the main menu. Users also have the option to reset the game if they wish to start a new game from this state itself.


<div style="page-break-after: always;"></div>


### Help<a name="help" />
<img alt="turn diagram" style="margin: auto; display: block; padding: 20px" src="help_menu.png" width=600>
The Help screen is accessible from the main menu. This page contains basic instructions on how to use the app. Instructions like what type of input the app expects, what's considered a bad input, and what other bounds there are on the user.
It also presents a brief overview of some basic chess rules and piece movements, acting as an introduction for new players to chess. The page also has links to the FIDE official rules webpage for an in-depth review of the rules.


<div style="page-break-after: always;"></div>


### Credits<a name="credits" />
<img alt="turn diagram" style="margin: auto; display: block; padding: 20px" src="credits.png" width=600>
The "credits" page's objective is to recognize the individuals involved in producing the product. The page's style is straightforward: identify everyone engaged in the program's creation and provide a summary of their role or contribution.
Any outside help and references are also listed here.

### End Game<a name="end-game" />
The end game screen appears when one of the players has won the game by either checkmating the opponent or one of the players resigns. This state is a dialogue box that lets users choose from the following options:

-  **Restart** – This option restarts the game and takes the users directly to the in-game state.
-	**Return to menu** – This option takes the user back to the main menu state.
-	**Quit** – This option stops and ends the program.


## Rules<a name="rules" />


<div style="page-break-after: always;"></div>


## Controls <a name="controls" /> 
There will be two distinct phases on a given player's turn: selecting a piece and then choosing a position to move it.
<img alt="turn diagram" style="margin: auto; display: block; padding: 20px" src="turn_diagram.png" width=600>
### Selecting a piece <a name="selecting-a-piece" />
At the start of the player's turn, they can select any of their pieces by left-clicking on it and then releasing the mouse button. Once selected, the piece will follow the player's cursor around the screen. Nothing will happen if a player tries to select one of their opponent's pieces.
#### Deselecting a Piece <a name="deselecting-a-piece" />
The player can return a selected piece to its original position by left-clicking the tile from which the piece came. Doing so will result in no pieces following the cursor.
#### Selecting a different piece <a name="selecting-a-different-piece" />
If the player decides they want to move a different piece instead, they can select a new piece by left-clicking on it. The initially selected piece will return to its original position after the mouse button is released.
### Moving a piece <a name="moving-a-piece" />
Once the player has selected a piece, they can choose a new position for it by left-clicking one of the highlighted tiles. Once the mouse button is released, the piece will instantly move on to the clicked tile and no longer follow the cursor. Nothing will happen if the player clicks an invalid tile, and the selected piece will continue to follow the cursor.
#### If the player moves the mouse out of the window <a name="mouse-off-screen" />
The selected piece will remain in the position the player moved the cursor out of the window. However, once the player moves the cursor back inside the window, the piece will immediately jump to the cursor's position.
