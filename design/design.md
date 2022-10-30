## Software Design Document
---
# Chessboard

## Contributors:
**Team Prometheus**

- Brad 
- Josh
- Ricardo
- Rishabh

## Contents
1. [Introduction](#intro)
2. [Design Overview](#overview)
3. [SDLChessGame](#sdl-chess-game)
4. [State](#state)
5. [Playing](#playing)
5. [Main Menu](#main-menu)
7. [Help](#help)
8. [Credits](#credts)
9. [ChessController](#chess-controller)
10. [Chessboard](#chessboard-model)
11. [Piece](#piece)
12. [Globals](#global)

## 1. Introduction <a name="intro" />
### 1.1 Purpose
The purpose of this document is to provide a detailed description of the implementation of the chess software built by the team Prometheus. Software is a c++ based chess game.
### 1.2 Scope
The document describes the implementation details of the chess program. The program consists of 3 major constituents, namely Model, Controller, View (Names are subject to change). The document will not be concerned with any testing of the program.
## 2. Design Overview <a name="overview" />
![Class Diagram](assets/class_diagram.png)
### 2.1 Description of the Program
Chessboard is a two-player pass-and-play chess game. The game will take place on a traditional 64-tile chessboard in a graphical environment. Upon launching Chessboard, the user can start a game via the main menu. On their turn, a player can select one of their chess pieces and move it to any legal tile. When a player selects a piece, the piece will follow the mouse until the player selects a valid tile to place it, after which the next player will take their turn using the same keyboard and mouse. The game will follow all rules outlined in http://www.fraserheightschess.com/Documents/BasicChessRules.pdf.
### 2.2 Technologies Used
The chess program is entirely based on C++. The program uses SDL libraries for the graphical components. OpenGL libraries maybe used.

The target platforms are Microsoft Windows, Linux and MacOS.


## 3. SDLChessGame <a name="sdl-chess-game" />
```
assets
controller 
dirty
curr_ state

change_state(state)
run_loop()
```
The central component of the user interface, `SDLChessGame` manages the UI's current state. It is in charge of switching between menus and running the game loop. It also acts as a container for all of the game's assets.`SDLChessGame` is also in charge of passing information to the `ChessController` when necessary so it can update the games internal representation.
### 3.1 Attributes
#### 3.2.1 Public
- **assets :** Dictionary
    - Contains all images used in the game. The images associated with a specific `Piece` can be accessed using its related `PieceNum` as a key.
<br>

- **controller :** ChessController
    - The controller acts as a proxy between the games model (`ChessBoard`), and `SDLChessGame`, providing it with method for seeing and interacting with the games internal state, without being able to directly modify it.
<br>

- **dirty :** boolean
    - a flag denoting whether or not an event has occured that requires the screen to be redrawn. This prevents the program from having to redraw the entire screen on each iteration of the game loop.
<br>


#### 3.1.1 Private
- **curr_state :** State
    - the screen the player is currently interacting with. This property provides `SDLChessGame` with methods for processing events and displaying the current screen to the user.
<br>

### 3.2 Methods
#### 3.2.1 Public
- **change_state(state:** State **)**
    - This is used to transition the program from one screen to another. It deletes the current state and replaces it with the provided one. `SDLChessGame` will use this newly created states methods inside of `run_loop`.
<br>

- **run_loop()**
    ```
    while the programming is running:
        process events
        update the games internal representation
        render the represention to the screen
    ```
    - continuously processes events from the user, updates the progams internal state then renders the screen using the methods provided by the user interface's current state.

## 4. State <a name="state" />

ABSTRACT STATE DOCUMENTATION GOES HERE

## 5. Playing <a name="playing" />
```
position_to_sdl_rect(position)
sdl_point_to_position(point)
click(position)
```
Playing is the in-game state. One of its main functions is to process the users mouse click events. If a board tile is clicked `Playing` will try to determine which one, passing this information to the `ChessController` which will use it to update the `Chessboard` if necessary. This state will also check if any of the on-screen buttons have been clicked, in which case it will change `SDLChessGame`'s state appropiately.
<div style="text-align: center">                                                
<img alt="turn diagram" src="../specifications/assets/playing.png" width=600>                   
</div>                   

### 5.1 Methods
#### 5.1.1 Private
- **position_to_sdl_rect(position:** Position **) :** SDL_Rect
    - Takes a `Position` on the game board, and converts it into a rectangular area on the screen. This is used to draw game piece assets in the correct area of the screen.
<br>

- **sdl_point_to_position(point:** SDL_Point **) :** Position
    - Takes the cooridinates of the mouse on screen when the user clicked the left-mouse button and attempts to convert it into a `Position` on the game boards grid. 
<br>

- **click(position:** Position **)**
    -  passes a Position, recently converted from an SDL_Point, to the `ChessController` to be processed.
<br>


## 6. Main Menu <a name="main-menu" />
<div style="text-align: center">                                                
<img alt="turn diagram" src="../specifications/assets/main_menu.png" width=600>                   
</div>                   
The Main Menu is the Startup screen of the application. From here, users can navigate to all sections of the application. The Main Menu gives the user the following options:

- Start – Start a pass-and-play game of chess with another player.
- Help – Read the instruction for the app.
- Credits – Credits screen credits all the developers with a short description of their role. Exit – Stops the program.

The Main Menu is also accessible after a game ends and from the in-game state if any player chooses to do so.

## 7. Help <a name="help" />
<div style="text-align: center">                                                
<img alt="turn diagram" src="../specifications/assets/help_menu.png" width=600>                   
</div>                   
The Help screen is accessible from the main menu. This page contains basic instructions on how to use the app. Instructions like what type of input the app expects, what’s considered a bad input, and what other bounds there are on the user.
It also presents a brief overview of some basic chess rules and piece movements, acting as an introduction for new players to chess.

## 8. Credits <a name="credits" />
<div style="text-align: center">                                                
<img alt="turn diagram" src="../specifications/assets/credits.png" width=600>                   
</div>                   
The “credits” page’s objective is to recognize the individuals involved in producing the product. The page’s style is straightforward: identify everyone engaged in the program’s creation and provide a summary of their role or contribution.
Any outside help and references are also listed here.


## 9. ChessController <a name="controller" />
```
game

process_click(position)
get_selected_piece()
get_available_moves()
get_board_state()
get_current_player()
is_game_over()
reset()
```
Exposing only necessary aspects of `game`, The chess controller acts as an intermediary between the user interface and the game's internal representation and logic. It provides `SDLChessGame` with enough information about the state of `game`to represent it on the screen. The only input `SDLChessGame` needs to provide the chess controller is the `Position` on the `game` board a player has clicked. Using the internal state of the `game`, `ChessController` can then assume the users intent.
### 9.1 Attributes
#### 9.1.1 Private
- **game :** Chessboard
    - The internal representation of the gameboard.
### 9.2 Methods
#### 9.2.1 Public
- **process_click(position:** Position **)**
    ```
    if a piece is currently selected:
        move it to the clicked position
    else if the clicked position is the tile of the selected piece:
        deselect the currently selected piece
    otherwise, if the clicked tile contains a piece:
        select the clicked piece
    ```
    - If the player doesn't currently have a piece selected, select the piece in the provided `position` if one exists, otherwise, attempt to move the currently selected piece to the clicked `position`.
<br>

- **get_selected_piece( ) :** PieceNum
    - return the `PieceNum` associated with the currently selected `Piece`. If no piece is selected, return `Null`.
<br>

- **get_available_moves( ) :** Array\<Position\>
    - get all available moves for the currently selected piece. If a piece is selected, call its `available_moves()` method and return the resulting array. If no piece is selected, return an empty array.

- **get_board_state( ) :** Array\<Array\<PieceNum\>\>
    - return the current layout of pieces on the gameboard. `PieceNum` is used to limit direct access to the games'`Piece` objects. See `get_board()` under section 10.2.1 for an example of the array returned when the board is in its default state.
<br>

- **get_current_player( ) :** boolean
    - return `game`'s current player
<br>

 - **reset( )**
    - return the gameboard to its initial state, putting all the pieces back to their default tiles by utilizing `game`'s `reset_board()` method.
<br>

## 10. Chessboard (Model)  <a name="chessboard" />
```
game_over
curr_player
selected
board

move(piece, destination)
select(piece)
deselect_piece()
reset_board()
get_board()
take(piece)
is_valid_move(piece, destination)
get_moves(piece)
```
Chessboard directly manages the internal representation of the game board's state, and contains all its related logic. It is completely independent from the user interface and can exist on its own.
### 10.1. Attributes
#### 10.1.1 Public
- **game_over :** boolean
    - A flag denoting whether or not the game has reached a terminal state either by checkmate, or resignation   
<br>

- **curr_player :** boolean
    - A boolean value indicating which player is currently taking their turn. True if it is the white players turn, and false if it is the black players turn.
<br>

- **selected :** Piece
    - stores the currently selected `Piece` if there is one, otherwise `Null` if no piece is selected.
#### 10.1.2 Private
- **board :** Array\<Array\<Piece\>\> 
    - a 2-dimensional array containing pointers to `Piece` objects. If the pointer in a given cell is `Null` it indicates that the tile is empty.
<br> 

### 10.2. Methods

#### 10.2.1 Public
- **move( piece:** Piece, **destination:** Position **) :** boolean
    - If destination is a valid move for the provided piece, move the piece from its current position on the board to `destination` and return true, otherwise return false.
<br>

- **select( piece:** Position **) :** boolean
    - If there is a piece at the provided position on the board, update the object's `selected` property to said piece and return true, otherwise return false.
<br>

- **deselect( ) :** boolean
    - If there is currently a piece selected, set the `selected` property to `Null` and return true. If no piece is selected return false.
<br>

- **reset_board( ) :** void
    - re-initialize Chessboard's `board` array, putting all pieces back to the default positions
<br>

- **get_board( ) :** Array\<Array\<PieceNum\>\>
    ```
    [
        [-2, -3, -4, -6, -5, -4, -3, -2],
        [-1, -1, -1, -1, -1, -1, -1, -1],
        [ 0,  0,  0,  0,  0,  0,  0,  0],
        [ 0,  0,  0,  0,  0,  0,  0,  0],
        [ 0,  0,  0,  0,  0,  0,  0,  0],
        [ 0,  0,  0,  0,  0,  0,  0,  0],
        [ 1,  1,  1,  1,  1,  1,  1,  1],
        [ 2,  3,  4,  6,  5,  4,  3,  2]
    ]
    ```
    - returns a simplified representation of the `board` array. This simplified 2-dimensional array will contain the `PieceNum` counterpart for each element in the original `board` array.
<br>

#### 10.2.2 Private
- **take( piece:** Position **) :** boolean
    - removes the piece at the provide position from the game and then return true. If the provided position is empty, return false.
<br>

- **is_valid_move( piece:** Piece, **destination:** Position **) :** boolean
    - checks if available moves for `piece` contains `destination`. If so, return true, otherwise false.
<br>



## 11. Piece <a  name="piece" />
Piece is an abstract base class which will be implemented by the following classes:

- Pawn
- Rook
- Knight
- Bishop
- Queen
- King

### 11.1. Attributes
#### 11.1.1 Public 
- position: Position
    - the location on the `board` at which the piece is located.
<br>

#### 11.1.2 Private
- colour: bool
<br>

- board: Chessboard
### 11.2. Methods
### 11.2.1 Public
- get_colour() : bool


## 12. Globals  <a  name="globals" />
### 12.1 Position
### 12.2 PieceNum
### 12.3 Constants
- WHITE : true
    - a constant boolean representing the white player
- BLACK : false
    - a constant boolean representing the black player
