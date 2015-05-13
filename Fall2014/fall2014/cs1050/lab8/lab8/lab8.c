/* Pearse Hutson
 * lab8.c
 * Pawprint: pah9qd
 * Lab D
 * Lab Code: rowsandcolumns
 * Date: 10.27.14
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

//Function Prototypes
int check_error(int size);
void initialize_2Darray(int array[][MAX], int size);
void print_2Darray(int array[][MAX], int size);
int check_index(int index, int size);
int find_columnmax(int array[][MAX], int c, int size);
float calculate_columnaverage(int array[][MAX], int c, int size);
int find_rowmin(int array[][MAX], int r, int size);
void sort_2Darray(int array[][MAX], int size);

//Program begin
int main(void)
{
	//Set seed for rand()
	srand(time(NULL));

	//Local Variables
	int userSize, columnIndex; 
	int i;
	int array[MAX][MAX];

	//Ask for the size of the array and error check to ensure the
	//user input is between 0 and MAX (100)
	printf("\nEnter the size of the array: ");
	scanf("%d", &userSize);
	while(check_error(userSize) == 0)
	{
		printf("Invalid input enter the size of the array again: ");
		scanf("%d", &userSize);
	}
	
	//Insert random numbers between 0 and 99 into every element within the user-given size in the array
	initialize_2Darray(array, userSize);
	
	//Display the initial 2D Array
	printf("\n2D arrays\n");
	print_2Darray(array, userSize);

	//Recieve a column index from user
	printf("\nEnter the column(1-%d): ", userSize);
	scanf("%d", &columnIndex);
	while(check_index(columnIndex, userSize) == 0)
	{
		printf("Invalid coumn index enter the column again: ");
		scanf("%d", &columnIndex);
	}

	//Display information about column
	printf("\nThe largest number present in the column %d is %d\n", 
			columnIndex, find_columnmax(array, columnIndex - 1, userSize)); 
			//columnIndex must be reduced by 1 for proper indexing
	printf("The average of numbers present in the column %d is %.2f\n\n", 
			columnIndex, calculate_columnaverage(array, columnIndex - 1, userSize)); 
			//columnIndex must be reduced by 1 for proper indexing

	//Display smallest number in each row. Will print one line per userSize
	for(i = 0; i < userSize; i++)
	{
		printf("Minimum number present in row %d is %d\n", 
				(i + 1), find_rowmin(array, i, userSize));
	}

	//Bonus Part! Display the header and the unsorted array
	printf("\nBonus Part\n\n");
	printf("Array before sorting\n");
	print_2Darray(array, userSize);

	//Sort the array by row and redisplay the array
	sort_2Darray(array, userSize);
	printf("\nArray after sorting\n");
	print_2Darray(array, userSize);

	//End Program
	printf("\n");
	return 0;
}

int check_error(int size)
{
	//Check the user input to ensure it is greater than 0
	//and less than MAX (100)
	
	if(size > 0 && size < MAX)
		return 1;
	else
		return 0;
}

void initialize_2Darray(int array[][MAX], int size)
{
	//For each element within the user-given size, 
	//insert a random number between 0 and 100
	
	int i, j;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			array[i][j] = (rand() % 100);
		}
	}
}

void print_2Darray(int array[][MAX], int size)
{
	//Prints the 2D array. Does not include header
	//information. Leaves a space between each element
	//for readability

	int i, j;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			printf("%3d", array[i][j]);
		}
		printf("\n");
	}
}

int check_index(int index, int size)
{
	//Check the user input to ensure that the index
	//given is in the array dimensions
	
	if(index >= 1 && index <= size)
		return 1;
	else
		return 0;
}

int find_columnmax(int array[][MAX], int c, int size)
{
	//Checks every element in the user array and the
	//column specified by the user and returns the 
	//largest value found
	
	int i, columnMax;

	columnMax = array[0][c];
	for(i = 1; i < size; i++)
	{
		if(array[i][c] > columnMax)
			columnMax = array[i][c];
	}

	return columnMax;
}

float calculate_columnaverage(int array[][MAX], int c, int size)
{
	//Finds the sum of all of the values in the 
	//user specified column and returns the average by
	//dividing by the user size (number of elements
	//in each column equals the user size)
	
	int i; 
	int columnSum = 0;

	for(i = 0; i < size; i++)
	{
		columnSum += array[i][c];
	}

	return (float)columnSum / size;

}

int find_rowmin(int array[][MAX], int r, int size)
{
	//Checks every element in the user array and the
	//row specified by for-loop and returns the 
	//smallest value found. 
	//This function will only run through one row
	//at a time. Mulitple rows must be specified or 
	//looped through in main()
	
	int i;
	int rowMin = array[r][0];

	for(i = 0; i < size; i++)
	{
		if(array[r][i] < rowMin)
			rowMin = array[r][i];
	}

	return rowMin;
}

void sort_2Darray(int array[][MAX], int size)
{
	//Bubble sorts each row in ascending order. This function will sort
	//every row in the user given array. Will not sort columns.
	//This function will not print the sorted array. Use 
	//print_2Darray() to print the array.

	int row, column, passes, holdValue;

 	//Performs bubble sort for each row in the user given array
	for(row = 0; row < size; row++)
	{
		// Must run "size" number of times to ensure proper sorting
		for(passes = 0; passes < size; passes++) 
		{
			//column + 1 is used to prevent accessing an element outside the array
			for(column = 0; column + 1 < size; column++)
			{
				//If an element is larger than the element to its right, exchange values
				if(array[row][column] > array[row][column + 1]) 
				{
					holdValue = array[row][column];
					array[row][column] = array[row][column + 1];
					array[row][column + 1] = holdValue;
				}
			}
		}
	}
}
