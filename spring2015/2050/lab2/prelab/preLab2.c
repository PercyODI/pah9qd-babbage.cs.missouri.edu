/* Pearse Hutson
 * Important Info Here
 * Implementation of Structs
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
} Pair;

int  readFile(char *filename, Pair *pairArray);
void printSum(Pair *pairArray);

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Error: Missing input file\n");
		return 0;
	}

	Pair *pairArray;
	int fileErrorCode;

	pairArray = malloc(sizeof(Pair) * 3);

	fileErrorCode = readFile(argv[1], pairArray);
	if(fileErrorCode == -1)
	{
		printf("Error: Invalid or Missing File\n");
		return 0;
	}

	printSum(pairArray);

	free(pairArray);

	return 0;
}

int readFile(char *filename, Pair *pairArray)
{

	FILE *file = fopen(filename, "r");
	int i;

	if(file == NULL)
	{
		return -1;
	}

	for(i = 0; i < 3; i++)
	{
		fscanf(file, "%d %d", &((pairArray + i)->x), &((pairArray + i)->y));
	}

	fclose(file);	
	
	return 0;
}

void printSum(Pair *pairArray)
{
	int i;

	for(i = 0; i < 3; i++)
	{
		printf("%d\n", (pairArray + i)->x + (pairArray + i)->y);
	}
}


