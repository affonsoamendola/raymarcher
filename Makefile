GAMENAME = raymarcher
CC = g++
RM = rm -rf
INCLUDE = /usr/include/SDL

all: build
	
build:
	$(CC)  *.cpp -g -o $(GAMENAME) -I$(INCLUDE) -lSDL2 -lm

run:
	./$(GAMENAME)

clean:
	$(RM) ./$(GAMENAME) *.o