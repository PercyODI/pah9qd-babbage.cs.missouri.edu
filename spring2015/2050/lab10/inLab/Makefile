BIN = bst
CC = gcc
CFLAGS = -g -Wall

$(BIN): runner.o bst.o
	$(CC) $(CFLAGS) runner.o bst.o -o $(BIN)

runner.o: runner.c bst.h
	$(CC) $(CFLAGS) -c runner.c

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) -c bst.c

clean:
	rm *.o $(BIN)