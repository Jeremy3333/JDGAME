# *****************************************************
# Variables

CC = g++
CFLAGS = -Wall
WINDOWFLAG = -lmingw32
SDLLIB = -L lib
SDLDLL = -L bin
SDLFLAGS = -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf
INCLUDES = -Iinclude  -I C:\SDL2-w64\include
TARGET = bin/program.exe

# *****************************************************
# Targets

all: $(TARGET)

$(TARGET): obj/main.o obj/displaySDL.o obj/general.o obj/math.o obj/player.o obj/world.o
	$(CC) $(CFLAGS) $(WINDOWFLAG) $(SDLDLL) $(SDLLIB) $(SDLFLAGS) $(INCLUDES) obj/main.o obj/displaySDL.o obj/general.o obj/math.o obj/player.o obj/world.o -o $(TARGET)

# *****************************************************
#main

obj/main.o: src/main.cpp include/SDL/DisplaySDL.hpp
	$(CC) $(CFLAGS) $(WINDOWFLAG) $(INCLUDES) -c src/main.cpp -o obj/main.o

# *****************************************************
#SDL

obj/displaySDL.o: src/SDL/displaySDL.cpp include/SDL/DisplaySDL.hpp include/STATE/General.hpp include/UTILS/Utils.hpp
	$(CC) $(CFLAGS) $(WINDOWFLAG) $(SDLDLL) $(SDLFLAGS) $(INCLUDES) -c src/SDL/displaySDL.cpp -o obj/displaySDL.o

# *****************************************************
#STATE

obj/general.o: src/STATE/general.cpp include/STATE/General.hpp include/STATE/World.hpp include/UTILS/Utils.hpp
	$(CC) $(CFLAGS) $(WINDOWFLAG) $(INCLUDES) -c src/STATE/general.cpp -o obj/general.o

obj/world.o: src/STATE/world.cpp include/STATE/World.hpp include/GAME/Player.hpp
	$(CC) $(CFLAGS) $(WINDOWFLAG) $(INCLUDES) -c src/STATE/world.cpp -o obj/world.o

# *****************************************************
#UTILS

obj/math.o: src/UTILS/math.cpp include/UTILS/Math.hpp
	$(CC) $(CFLAGS) $(WINDOWFLAG) $(INCLUDES) -c src/UTILS/math.cpp -o obj/math.o

# *****************************************************
#GAME

obj/player.o: src/GAME/player.cpp include/GAME/Player.hpp include/UTILS/Math.hpp
	$(CC) $(CFLAGS) $(WINDOWFLAG) $(INCLUDES) -c src/GAME/player.cpp -o obj/player.o

# *****************************************************
# Other stuff

clean:
	rm -f obj/*.o $(TARGET)