
LINKER_FLAGS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image

LIBRARY_PATHS+=-Lsrc\SDL2_image-2.6.2\i686-w64-mingw32\lib
LIBRARY_PATHS+=-Lsrc\lib

INCLUDE_PATHS+=-Isrc\SDL2_image-2.6.2\i686-w64-mingw32\include\SDL2
INCLUDE_PATHS+=-Isrc\include

OPTIONS=-Wall -Wextra

all: main

main: main.o GameState.o 
	@echo "Building executable file"
	g++ $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(OPTIONS) $^ -o $@ $(LINKER_FLAGS)

main.o: main.cpp Gamestate.cpp
	@echo "buiding main object"
	g++ -c $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(OPTIONS) $< -o $@ $(LINKER_FLAGS)

GameState.o: GameState.cpp globals.h
	@echo "Building gamestate object"
	g++ -c $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(OPTIONS) $< -o $@ $(LINKER_FLAGS)

clean:
	del *.o *.exe
   
