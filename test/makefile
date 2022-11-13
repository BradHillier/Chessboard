EXECUTABLES = main                                                                 
OBJECTS = piece.o chessboard.o pawn.o                                              
                                                                                   
PIECE_HEADERS = ../include/piece.h ../include/pawn.h                               
                                                                                   
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
                                                                                   
clean:                                                                             
   rm $(OBJECTS) $(EXECUTABLES) 
