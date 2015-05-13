#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int check_size(int);
void initialiaze_array(int);
void print_array(int);
//int replace(int, int, int);

int array[100];

int main(void)
{
	srand(time(NULL));
	//Local Variables
	int size, index, newNum;

	printf("\n");
	printf("Enter the size of the input: ");
	scanf("%d", &size);
	while(check_size(size) == 0)
	{
		printf("Invalid input enter the size of the input again: ");
		scanf("%d", &size);
	}

	initialiaze_array(size);

	printf("\n");
	printf("Input Array\n");
	print_array(size);
	
	printf("\n\n");
	printf("Enter the index: ");
	scanf("%d", &index);
	printf("Enter the new number: ");
	scanf("%d", &newNum);
	
	if(replace(newNum, index, size) == -1)
	{
		printf("\n");
		printf("Invalid index! index should be smaller than the input size");
		printf("\n\n");
		return 0;
	}

	printf("\n");
	printf("Array after replacement operation\n");
	print_array(size);
	printf("\n");

	return 0;
}

int check_size(int size)
{
	if(size > 0 && size < 101)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void initialiaze_array(int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		array[i] = rand() % 10;
	}
}

void print_array(int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

int replace(int num, int i, int size)
{
	if(i >= size)
	{
		return -1;
	}

	array[i] = num;
}
