EXECUTABLES = main backend_test_program 

UI_OBJS = sdl_chess_game.o
GAME_OBJS = piece.o chessboard.o pawn.o rook.o knight.o bishop.o queen.o king.o 
STATE_OBJS =  state.o main_menu.o playing.o help.o credits.o
                                                                                   
PIECE_HEADERS = ../include/piece.h ../include/pawn.h ../include/rook.h ../include/knight.h ../include/bishop.h ../include/queen.h ../include/king.h
STATE_HEADERS = ../include/playing.h ../include/help.h ../include/credits.h ../include/main_menu.h
UI_HEADERS = ../include/sdl_chess_game.h $(STATE_HEADERS)
                                                                                   
SHARED = ../include/globals.h
OPTIONS = -Wall -Wextra
                                                                                   

all: $(EXECUTABLES)

main: main.cpp chess_controller.o $(GAME_OBJS) $(STATE_OBJS) $(UI_OBJS) 
	@echo "\nbuilding state machine"
	g++ $(OPTIONS) main.cpp chess_controller.o $(GAME_OBJS) $(STATE_OBJS) $(UI_OBJS) -o $@
                                                                                   
backend_test_program: backend_test_program.cpp  $(GAME_OBJS)                                                         
	@echo "\nbuilding main"                                                         
	g++ $(OPTIONS) backend_test_program.cpp $(GAME_OBJS) -o $@                                                

#=============================================================================
#	MODULES
#=============================================================================

sdl_chess_game.o: ../src/sdl_chess_game.cpp ../include/sdl_chess_game.h ../include/chess_controller.h $(STATE_HEADERS) $(SHARED)
	@echo "\nsdl_chess_game.o needs updating"
	g++ $(OPTIONS) -c $<

                                                                                   
chessboard.o: ../src/chessboard.cpp ../include/chessboard.h  $(PIECE_HEADERS) $(SHARED)
	@echo "\nchessboard.o needs updating"                                           
	g++ $(OPTIONS) -c $<                                                         

chess_controller.o: ../src/chess_controller.cpp ../include/chess_controller.h ../include/chessboard.h $(SHARED)
	@echo "\nchess_controller.o needs updating"
	g++ $(OPTIONS) -c $<                                                         

#=============================================================================
#	PIECES
#=============================================================================
piece.o: ../src/piece.cpp ../include/piece.h ../include/chessboard.h $(SHARED)  
	@echo "\npiece.o needs updating"                                                
	g++ $(OPTIONS) -c $<                                                         
                                                                                   
pawn.o: ../src/pawn.cpp ../include/pawn.h ../include/piece.h $(SHARED)             
	@echo "\npawn.o needs updating"                                                 
	g++ $(OPTIONS) -c $<                                                         

rook.o: ../src/rook.cpp ../include/rook.h ../include/piece.h $(SHARED)             
	@echo "\nrook.o needs updating"                                                 
	g++ $(OPTIONS) -c $<                                                         

knight.o: ../src/knight.cpp ../include/knight.h ../include/piece.h $(SHARED)             
	@echo "\nknight.o needs updating"                                                 
	g++ $(OPTIONS) -c $<                                                         

bishop.o: ../src/bishop.cpp ../include/bishop.h ../include/piece.h $(SHARED)             
	@echo "\nbishop.o needs updating"                                                 
	g++ $(OPTIONS) -c $<                                                         

queen.o: ../src/queen.cpp ../include/queen.h ../include/piece.h $(SHARED)             
	@echo "\nqueen.o needs updating"                                                 
	g++ $(OPTIONS) -c $<                                                         

king.o: ../src/king.cpp ../include/king.h ../include/piece.h $(SHARED)             
	@echo "\nking.o needs updating"                                                 
	g++ $(OPTIONS) -c $<                                                         


#=============================================================================
#	STATES
#=============================================================================

state.o: ../src/state.cpp ../include/state.h
	@echo "\nstate.o needs updating"
	g++ $(OPTINOS) -c $<

playing.o: ../src/playing.cpp ../include/playing.h ../include/state.h
	@echo "\nplaying.o needs updating"
	g++ $(OPTIONS) -c $<

help.o: ../src/help.cpp ../include/help.h ../include/state.h
	@echo "\nhelp.o needs updating"
	g++ $(OPTIONS) -c $<

credits.o: ../src/credits.cpp ../include/credits.h ../include/state.h
	@echo "\ncredits.o needs updating"
	g++ $(OPTIONS) -c $<

main_menu.o: ../src/main_menu.cpp ../include/main_menu.h ../include/state.h
	@echo "\nmain_menu.o needs updating"
	g++ $(OPTIONS) -c $<
                                                                                   
#=============================================================================
#	PHONY
#=============================================================================

clean:                                                                             
	rm chess_controller.o $(GAME_OBJS) $(UI_OBJS) $(STATE_OBJS) $(EXECUTABLES) 
