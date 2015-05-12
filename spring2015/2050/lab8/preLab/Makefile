BIN = preLab8
CC = gcc
CFLAGS = -g -Wall

$(BIN): main.o prelab8.o
	$(CC) $(CFLAGS) main.o prelab8.o -o preLab8

main.o: main.c prelab8.h
	$(CC) $(CFLAGS) -c main.c

prelab8.o: prelab8.c
	$(CC) $(CFLAGS) -c prelab8.c

clean:
	rm *.o $(BIN)