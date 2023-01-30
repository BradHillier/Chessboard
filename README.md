# Chessboard

## Description


This software was designed and implemented as part of a [semester-long team project](http://csci.viu.ca/~wesselsd/courses/csci265/project.html) for CSCI 265 - Sofware Engineering at Vancouver Island University. 

- [Technical Specifications](https://github.com/BradHillier/Pixel-Chess/blob/main/design/design.md)
- [User Requirements](https://github.com/BradHillier/Pixel-Chess/blob/main/specifications/specifications.md)

![Gameplay GIF](./assets/screenshots/chessboard.gif)

## Architecture

Pixel-Chess uses the MVC architecture to break the system down in loosely coupled components.  All logic regarding the state of the gameboard is strictly seperated from the code related to graphics. The frontend can only interact with a controller object that allows it to query the internal state of the game and report actions taken by the user. The frontend is managed by a state machine, allowing smooth and easy transitions through the various menus and playing state.

## Installation

### macOS

#### Install Dependencies

##### With Homebrew

Run the following command to install dependencies

```bash
brew install sdl2 sdl2_image sdl2_ttf
```

#### Clone and Build
Run the following command to clone a copy of the repository to your local machine and build the program

```bash
git clone https://github.com/BradHillier/Pixel-Chess.git
cd Pixel-Chess
make
```

#### Run the Program
You can run this program from the project's root directory using

```bash
./bin/chessboard
```
