EXECUTABLES = main
OBJECTS = piece.o chessboard.o pawn.o rook.o knight.o bishop.o queen.o king.o
                                                                                   
PIECE_HEADERS = ../include/piece.h ../include/pawn.h ../include/rook.h ../include/knight.h ../include/bishop.h ../include/queen.h ../include/king.h
                                                                                   
SHARED = ../include/globals.h
OPTIONS = -Wall -Wextra
                                                                                   
                                                                                   
main: main.cpp  $(OBJECTS)                                                         
	@echo "\nbuilding main"                                                         
	g++ -g main.cpp $(OBJECTS) -o $@                                                
                                                                                   
chessboard.o: ../src/chessboard.cpp ../include/chessboard.h  $(PIECE_HEADERS) $(SHARED)
	@echo "\nchessboard.o needs updating"                                           
	g++ -g -c $(OPTIONS) $<                                                         
                                                                                   
piece.o: ../src/piece.cpp ../include/piece.h ../include/chessboard.h $(SHARED)  
	@echo "\npiece.o needs updating"                                                
	g++ -g -c $(OPTIONS) $<                                                         
                                                                                   
pawn.o: ../src/pawn.cpp ../include/pawn.h ../include/piece.h $(SHARED)             
	@echo "\npawn.o needs updating"                                                 
	g++ -g -c $(OPTIONS) $<                                                         

rook.o: ../src/rook.cpp ../include/rook.h ../include/piece.h $(SHARED)             
	@echo "\nrook.o needs updating"                                                 
	g++ -g -c $(OPTIONS) $<                                                         

knight.o: ../src/knight.cpp ../include/knight.h ../include/piece.h $(SHARED)             
	@echo "\nknight.o needs updating"                                                 
	g++ -g -c $(OPTIONS) $<                                                         

bishop.o: ../src/bishop.cpp ../include/bishop.h ../include/piece.h $(SHARED)             
	@echo "\nbishop.o needs updating"                                                 
	g++ -g -c $(OPTIONS) $<                                                         

queen.o: ../src/queen.cpp ../include/queen.h ../include/piece.h $(SHARED)             
	@echo "\nqueen.o needs updating"                                                 
	g++ -g -c $(OPTIONS) $<                                                         

king.o: ../src/king.cpp ../include/king.h ../include/piece.h $(SHARED)             
	@echo "\nking.o needs updating"                                                 
	g++ -g -c $(OPTIONS) $<                                                         
                                                                                   
clean:                                                                             
	rm $(OBJECTS) $(EXECUTABLES) 
