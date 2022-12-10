ifeq ($(OS),Windows_NT)                                                            
   OS_NAME = windows                                                               
	LINKER_FLAGS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image

	LIBRARY_PATHS+=-Lsrc\SDL2_image-2.6.2\i686-w64-mingw32\lib
	LIBRARY_PATHS+=-Lsrc\lib

	INCLUDE_PATHS+=-Isrc\SDL2_image-2.6.2\i686-w64-mingw32\include\SDL2
	INCLUDE_PATHS+=-Isrc\include
else                                                                               
   OS_NAME = macOS                                                                 
   LIBRARY_PATHS=$(shell pkg-config --cflags --libs sdl2 sdl2_ttf sdl2_image)   
endif   





EXECUTABLES = bin/main FrontEnd/SDL_TEST/graphical

UI_OBJS = objects/sdl_chess_game.o
GAME_OBJS = objects/piece.o objects/chessboard.o objects/pawn.o objects/rook.o objects/knight.o objects/bishop.o objects/queen.o objects/king.o 
STATE_OBJS =  objects/state.o objects/main_menu.o objects/playing.o objects/help.o objects/credits.o
                                                                                   
PIECE_HEADERS = include/piece.h include/pawn.h include/rook.h include/knight.h include/bishop.h include/queen.h include/king.h
STATE_HEADERS = include/playing.h include/help.h include/credits.h include/main_menu.h
UI_HEADERS = include/sdl_chess_game.h $(STATE_HEADERS)
                                                                                   
SHARED = include/globals.h
OPTIONS = -g -Wall -Wextra -std=c++17
                                                                                   

all: $(EXECUTABLES)




#=============================================================================
# FRONT END
#=============================================================================

FrontEnd/SDL_TEST/graphical: FrontEnd/SDL_TEST/graphical.o FrontEnd/SDL_TEST/GameState.o objects/chess_controller.o  $(GAME_OBJS)
	@echo "Building executable file"
	g++ $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(OPTIONS) $^ -o $@ $(LINKER_FLAGS)

FrontEnd/SDL_TEST/graphical.o: FrontEnd/SDL_TEST/main.cpp FrontEnd/SDL_TEST/Gamestate.cpp
	@echo "buiding main object"
	g++ -c $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(OPTIONS) $< -o $@ $(LINKER_FLAGS)

FrontEnd/SDL_TEST/GameState.o: FrontEnd/SDL_TEST/GameState.cpp FrontEnd/SDL_TEST/globals.h
	@echo "Building gamestate object"
	g++ -c $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(OPTIONS) $< -o $@ $(LINKER_FLAGS)

#=============================================================================
#	ORIGINAL MAKEFILE
#=============================================================================

bin/main: src/main.cpp objects/chess_controller.o objects/effects.o $(GAME_OBJS) $(STATE_OBJS) $(UI_OBJS) 
	@echo "\nbuilding state machine"
	g++ $(OPTIONS) src/main.cpp objects/chess_controller.o objects/effects.o $(GAME_OBJS) $(STATE_OBJS) $(UI_OBJS) -o $@

#=============================================================================
#	MODULES
#=============================================================================

objects/sdl_chess_game.o: src/sdl_chess_game.cpp include/sdl_chess_game.h include/chess_controller.h $(STATE_HEADERS) $(SHARED)
	@echo "\nsdl_chess_game.o needs updating"
	g++ $(OPTIONS) -c $< -o $@

                                                                                   
objects/chessboard.o: src/chessboard.cpp include/chessboard.h  $(PIECE_HEADERS) $(SHARED)
	@echo "\nchessboard.o needs updating"                                           
	g++ $(OPTIONS) -c $< -o $@                                                         

objects/chess_controller.o: src/chess_controller.cpp include/chess_controller.h include/chessboard.h $(SHARED)
	@echo "\nchess_controller.o needs updating"
	g++ $(OPTIONS) -c $< -o $@                                                         

#=============================================================================
#	PIECES
#=============================================================================
objects/piece.o: src/piece.cpp include/piece.h include/chessboard.h $(SHARED)  
	@echo "\npiece.o needs updating"                                                
	g++ $(OPTIONS) -c $< -o $@                                                         
                                                                                   
objects/pawn.o: src/pawn.cpp include/pawn.h include/piece.h $(SHARED)             
	@echo "\npawn.o needs updating"                                                 
	g++ $(OPTIONS) -c $< -o $@                                                         

objects/rook.o: src/rook.cpp include/rook.h include/piece.h $(SHARED)             
	@echo "\nrook.o needs updating"                                                 
	g++ $(OPTIONS) -c $< -o $@                                                         

objects/knight.o: src/knight.cpp include/knight.h include/piece.h $(SHARED)             
	@echo "\nknight.o needs updating"                                                 
	g++ $(OPTIONS) -c $< -o $@                                                         

objects/bishop.o: src/bishop.cpp include/bishop.h include/piece.h $(SHARED)             
	@echo "\nbishop.o needs updating"                                                 
	g++ $(OPTIONS) -c $< -o $@                                                         

objects/queen.o: src/queen.cpp include/queen.h include/piece.h $(SHARED)             
	@echo "\nqueen.o needs updating"                                                 
	g++ $(OPTIONS) -c $< -o $@                                                         

objects/king.o: src/king.cpp include/king.h include/piece.h $(SHARED)             
	@echo "\nking.o needs updating"                                                 
	g++ $(OPTIONS) -c $< -o $@                                                         


#=============================================================================
#	STATES
#=============================================================================

objects/state.o: src/state.cpp include/state.h
	@echo "\nstate.o needs updating"
	g++ $(OPTIONS) -c $< -o $@

objects/playing.o: src/playing.cpp include/playing.h include/state.h
	@echo "\nplaying.o needs updating"
	g++ $(OPTIONS) -c $< -o $@

objects/help.o: src/help.cpp include/help.h include/state.h
	@echo "\nhelp.o needs updating"
	g++ $(OPTIONS) -c $< -o $@

objects/credits.o: src/credits.cpp include/credits.h include/state.h
	@echo "\ncredits.o needs updating"
	g++ $(OPTIONS) -c $< -o $@

objects/main_menu.o: src/main_menu.cpp include/main_menu.h include/state.h
	@echo "\nmain_menu.o needs updating"
	g++ $(OPTIONS) -c $< -o $@

#=============================================================================
#	Extra
#=============================================================================
objects/effects.o: src/effects.cpp include/effects.h                                                                                
	@echo "\neffects needs updating"
	g++ $(OPTIONS) -c $< -o $@
#=============================================================================
#	PHONY
#=============================================================================

clean:                                                                             
	rm objects/effects.o objects/chess_controller.o $(GAME_OBJS) $(UI_OBJS) $(STATE_OBJS) $(EXECUTABLES) 
	rm FrontEnd/SDL_TEST/*.o FrontEnd/SDL_TEST/graphical
