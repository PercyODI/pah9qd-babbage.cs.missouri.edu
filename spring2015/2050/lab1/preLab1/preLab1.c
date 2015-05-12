/* Pearse Hutson
 * Other various header items go here
 * But it's a prelab, so there
 */

//Included Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function Prototypes
int load_array(char *, int *);
void print_array(int *);

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("\nError: No file inlcuded.\n");
		return 0;
	}

	char *arrayFile = argv[1];
	int *intArray;
	int loadArrayErrCode;
	
	intArray = malloc(sizeof(int) * 5);

	loadArrayErrCode = load_array(arrayFile, intArray);
	if(loadArrayErrCode == 0)
	{
		printf("\nError: Invalid File Selected\n");
		return 0;
	}

	print_array(intArray);

	free(intArray);
	return 0;
}

int load_array(char *arrayFile, int *intArray)
{
	int i = 0;

	FILE *file = fopen(arrayFile, "r");

	if(file == NULL)
	{
		return 0;
	}

	for(i = 0; i < 5; i++)
	{
		fscanf(file, "%d", intArray + i);
	}
	
	return 1;
}

void print_array(int *intArray)
{
	int i = 0;

	printf("\n");
	printf("Printout of Arrays from arrayFile\n");
	for(i = 0; i < 5; i++)
	{
		printf("%d\n", *(intArray + i));
	}

	return;
}
	




