EXECUTABLES = main state_machine
OBJECTS = piece.o chessboard.o pawn.o rook.o knight.o bishop.o queen.o king.o

STATE_OBJS = playing.o help.o credits.o main_menu.o
                                                                                   
PIECE_HEADERS = ../include/piece.h ../include/pawn.h ../include/rook.h ../include/knight.h ../include/bishop.h ../include/queen.h ../include/king.h
                                                                                   
SHARED = ../include/globals.h
OPTIONS = -Wall -Wextra
                                                                                   

all: $(EXECUTABLES)

state_machine: test_state_machine.cpp $(STATE_OBJS)
	@echo "\nbuilding state machine"
	g++ $(OPTIONS) test_state_machine.cpp $(STATE_OBJS) -o $@
                                                                                   
main: main.cpp  $(OBJECTS)                                                         
	@echo "\nbuilding main"                                                         
	g++ $(OPTIONS) main.cpp $(OBJECTS) -o $@                                                
                                                                                   
chessboard.o: ../src/chessboard.cpp ../include/chessboard.h  $(PIECE_HEADERS) $(SHARED)
	@echo "\nchessboard.o needs updating"                                           
	g++ $(OPTIONS) -c $<                                                         
                                                                                   
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
                                                                                   
clean:                                                                             
	rm $(OBJECTS) $(STATE_OBJS) $(EXECUTABLES) 
