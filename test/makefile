OBJECTS = piece.o chessboard.o pawn.o
EXECUTABLES = main
PIECE_HEADERS = ../include/piece.h ../include/pawn.h
OPTIONS = -Wall -Wextra

main: main.cpp  $(OBJECTS)
	@echo "\nbuilding main"
	g++ -g main.cpp $(OBJECTS) -o $@

chessboard.o: ../include/chessboard.h ../src/chessboard.cpp $(PIECE_HEADERS) ../include/globals.h 
	@echo "\nchessboard.o needs updating"
	g++ -g -c $< ../src/chessboard.cpp ../include/globals.h

piece.o: ../include/piece.h ../src/piece.cpp ../include/chessboard.h ../include/globals.h
	@echo "\npiece.o needs updating"
	g++ -g -c $< ../src/piece.cpp ../include/globals.h

pawn.o: ../include/pawn.h ../src/pawn.cpp ../include/piece.h
	@echo "\npawn.o needs updating"
	g++ -g -c $< ../src/pawn.cpp ../include/piece.h

clean:
	rm $(OBJECTS) $(EXECUTABLES)
