/* Pre-Lab 8
 * 2D Arrays
 * using random values
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

//Function Prototypes
int check_error(int size);
void initialize_2Darray(int array[][MAX], int size);
int smallest_number(int array[][MAX], int size);
void print_2Darray(int array[][MAX], int size);
int check_indent(int index, int size);
int find_columnmax(int array[][MAX], int c, int size);
float calculate_columnaverage(int array[][MAX], int c, int size);
int find_rowmin(int array[][MAX], int r, int size);

//Program begin
int main(void)
{
	//Set seed for rand()
	srand(time(NULL));
	//Local Variables
	int userSize; 
	int array[MAX][MAX];

	printf("\n"
			"Enter the size of the array: ");
	scanf("%d", &userSize);
	while(check_error(userSize) != 1)
	{
		printf("Invalid input enter the size of the array again: ");
		scanf("%d", &userSize);
	}
	
	initialize_2Darray(array, userSize);

	printf("\n"
			"Input Array\n");
	print_2Darray(array, userSize);

	printf("\n"
			"The smallest number in the array is %d\n\n", 
			smallest_number(array, userSize));

	return 0;
}

//Functions
int check_error(int size)
{
	if(size > 0 && size < 100)
		return 1;
	else
		return 0;
}

void initialize_2Darray(int array[][MAX], int size)
{
	int i, j;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			array[i][j] = (rand() % 100);
		}
	}
}

int smallest_number(int array[][MAX], int size)
{
	int i, j;
	int smallest_number = array[0][0];

	for(i = 0; i < size; i++)
	{
		for(j = 0; j< size; j++)
		{
			if(array[i][j] < smallest_number)
				smallest_number = array[i][j];
		}
	}

	return smallest_number;
}

void print_2Darray(int array[][MAX], int size)
{
	int i, j;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			printf("%5d", array[i][j]);
		}
		printf("\n");
	}
}

int check_indent(int index, int size)
{

}

int find_columnmax(int array[][MAX], int c, int size)
{

}

float calculate_columnaverage(int array[][MAX], int c, int size)
{

}

int find_rowmin(int array[][MAX], int r, int size)
{

}


