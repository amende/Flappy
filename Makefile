CC=gcc
CFLAGS=-Wall
LDFLAGS=
EXEC=executable

all: $(EXEC)

executable: main.o lancer.o
	$(CC) -o executable main.o lancer.o $(LDFLAGS)

lancer.o: lancer.c lancer.h
	$(CC) -o lancer.o -c lancer.c $(CFLAGS)

main.o: lancer.h main.c
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -f *.o core
