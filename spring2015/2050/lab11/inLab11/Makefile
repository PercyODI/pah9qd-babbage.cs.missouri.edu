BIN = lab11
CC = gcc
CFLAGS = -g -Wall

$(BIN): parser.o frontend.o
	$(CC) $(CFLAGS) frontend.o parser.o -o $(BIN)

frontend.o: frontend.c parser.h
	$(CC) $(CFLAGS) -c frontend.c

parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c

clean:
	rm *.o $(BIN)