#include <stdio.h>
#include "prelab8.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Incorrect number of command line arguments\n" 
						"Usage: %s <your name>\n", argv[0]);
		return 0;
	}
	
	say_hello(argv[1]);
	
	return 0;
}