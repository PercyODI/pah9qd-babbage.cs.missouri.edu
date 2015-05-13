#include <stdio.h>
#include <stdlib.h>

int length(char *s);
char* copy(char *s);
char* reverse(char *s);
void clear(char *s);

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("\nNot enough parameters\n");
		return 0;
	}

	char *x = argv[1];
	char *y = copy(x);
	int len = length(x);

	printf("\nInput string is %s", x);
	printf("\nLength of the string is %d", len);
	printf("\nCopy of the string is %s", y);

	char *rev = reverse(x);
	printf("\nReverse of the string %s is %s\n", x, rev);

	//clear(y);
	//clear(rev);

	return 0;
}

int length(char *s)
{
	int myLength = 0;

	while(*s != '\0')
	{
		myLength++;
		s++;
	}
	return myLength;
}

char* copy(char *s)
{
	char *copiedStringPtr;
	char *copiedStringInitPtr;
	copiedStringPtr = malloc(sizeof(char) * (length(s) + 1));
	copiedStringInitPtr = copiedStringPtr;

	while(*s != '\0')
	{
		*copiedStringPtr = *s;
		copiedStringPtr++;
		s++;
	}
	*copiedStringPtr = '\0';

	return copiedStringInitPtr;
}

char* reverse(char *s)
{
	char *revStrPtr;
	char *revStrInitPtr;
	int sLength = 0;
	int i;
	sLength = length(s);
	revStrPtr = malloc(sizeof(char) * (sLength + 1));
	revStrInitPtr = revStrPtr;

	//Set revStrPtr to the end of it's contained string
	s += sLength - 1;
	for(i = 0; i <= sLength; i++)
	{
		*revStrPtr = *s;
		revStrPtr++;
		s--;
	}

	*revStrPtr = '\0'; 

	return revStrInitPtr;
}

void clear(char *s)
{
	free(s);
}
