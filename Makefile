CC=gcc
CFLAGS=-Wall
LDFLAGS=
EXEC=executable

all: $(EXEC)

executable: main.o game.o
	$(CC) -o executable main.o game.o $(LDFLAGS)

game.o: game.cpp game.h bird.o
	$(CC) -o game.o -c game.cpp bird.o $(CFLAGS)

bird.o: bird.cpp bird.h wall.o
	$(CC) -o bird.o -c bird.cpp wall.o $(CFLAGS)

wall.o: wall.cpp wall.h
	$(CC) -o wall.o -c wall.cpp $(CFLAGS)

main.o: lancer.h main.c
	$(CC) -o main.o -c main.cpp $(CFLAGS)

clean:
	rm -f *.o core
