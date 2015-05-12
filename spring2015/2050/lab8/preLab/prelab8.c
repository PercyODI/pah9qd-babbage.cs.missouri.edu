#include <stdio.h>
#include "prelab8.h"

static void print_new_line();

void say_hello(char* name) {
	printf("Hello %s!", name);
	print_new_line();
}

void print_new_line() {
	printf("\n");
}