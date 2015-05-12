BIN = lab8
CC = gcc
CFLAGS = -g -Wall

$(BIN): queue.o potato.o
	$(CC) $(CFLAGS) queue.o potato.o -o $(BIN)

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

potato.o: potato.c queue.h
	$(CC) $(CFLAGS) -c potato.c

clean:
	rm *.o $(BIN)