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

obj/main.o: src/main.cpp include/DisplaySDL.hpp
	$(CC) $(CFLAGS) $(WINDOWFLAG) $(INCLUDES) -c src/main.cpp -o obj/main.o

obj/displaySDL.o: src/displaySDL.cpp include/DisplaySDL.hpp include/General.hpp include/Utils.hpp
	$(CC) $(CFLAGS) $(WINDOWFLAG) $(SDLDLL) $(SDLFLAGS) $(INCLUDES) -c src/displaySDL.cpp -o obj/displaySDL.o

obj/general.o: src/general.cpp include/General.hpp include/World.hpp include/Utils.hpp
	$(CC) $(CFLAGS) $(WINDOWFLAG) $(INCLUDES) -c src/general.cpp -o obj/general.o

obj/math.o: src/math.cpp include/Math.hpp
	$(CC) $(CFLAGS) $(WINDOWFLAG) $(INCLUDES) -c src/math.cpp -o obj/math.o

obj/player.o: src/player.cpp include/Player.hpp include/Math.hpp
	$(CC) $(CFLAGS) $(WINDOWFLAG) $(INCLUDES) -c src/player.cpp -o obj/player.o

obj/world.o: src/world.cpp include/World.hpp include/Player.hpp
	$(CC) $(CFLAGS) $(WINDOWFLAG) $(INCLUDES) -c src/world.cpp -o obj/world.o

clean:
	rm -f obj/*.o $(TARGET)