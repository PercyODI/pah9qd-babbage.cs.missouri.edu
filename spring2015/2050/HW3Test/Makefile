BIN = HW3
CC = gcc
CFLAGS = -g -Wall

$(BIN): calculator.o stack.o frontend.o
	$(CC) $(CFLAGS) calculator.o stack.o frontend.o -o $(BIN)

calculator.o: calculator.c calculator.h stack.h
	$(CC) $(CFLAGS) -c calculator.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

frontend.o: frontend.c calculator.h
	$(CC) $(CFLAGS) -c frontend.c

clean:
	rm *.o $(BIN)
