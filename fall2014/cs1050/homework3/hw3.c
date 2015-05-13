/* Pearse Hutson
 * Pawprint: pah9qd
 * Lab D
 * Homework 3
 * Date: 11.2.14
 */

//Included libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Global Definitions
#define MAX 100

//Function Prototypes
void display_menu();
int check_option(int option);
int check_size(int size);
void initialize_2Darray(int x[][MAX], int size);
void print_2Darray(int x[][MAX], int size);
void initialize_1Darray(int y[], int size);
void print_1Darray(int y[], int size);
int search_min(int x[][MAX], int r, int c, int size);
int count_match(int x[][MAX], int y[], int size, int r);
int closest_row(int x[][MAX], int y[], int size);
void sort_1Darray(int y[], int size);
void sort_2Darray(int x[][MAX], int size);

//Program Begin
int main(void)
{
	//Seed Random Generator
	srand(time(NULL));

	//Local Variables
	int mainSize, mainOption;
	int userRow, userColumn;
	int countMatchResult;
	int main2Darray[MAX][MAX];
	int main1Darray[MAX];

	//Receive and check user-selected size
	printf("\nEnter the size: ");
	scanf("%d", &mainSize);
	while(check_size(mainSize) == 0)
	{
		printf("Invalid input enter the size of the array again: ");
		scanf("%d", &mainSize);
	}

	do //Perform functions until user selects 6 (exit)
	{
		//Display menu, take and check user option
		display_menu();
		scanf("%d", &mainOption);
		while(check_option(mainOption) == 0)
		{
			printf("Invalid input: Enter the operation you want to perform: ");
			scanf("%d", &mainOption);
		}

		//Perform function based on user choice
		switch(mainOption)
		{
			case 1:
				// Perform Search Min Function
				initialize_2Darray(main2Darray, mainSize);

				//Display Arrays
				printf("\nSearch Min Operation\n\n");
				printf("2D array\n");
				print_2Darray(main2Darray, mainSize);

				//Get user row and column choice
				printf("\nEnter the row: ");
				scanf("%d", &userRow);
				printf("Enter the col: ");
				scanf("%d", &userColumn);

				//Perform function and display result
				printf( "\n\nThe smallest number present in the "
						"row %d and col %d is ", userRow, userColumn);
				printf("%d", search_min(main2Darray, userRow, userColumn, mainSize));

				break;

			case 2:
				// Perform Count Matches Function
				initialize_2Darray(main2Darray, mainSize);
				initialize_1Darray(main1Darray, mainSize);

				//Display initialized arrays
				printf("\nCount Match Operation\n\n");
				printf("2D array\n");
				print_2Darray(main2Darray, mainSize);
				printf("\n1D array\n");
				print_1Darray(main1Darray, mainSize);

				//Get user row choice
				printf("\n\nEnter the row: ");
				scanf("%d", &userRow);

				//Perform function and display result
				countMatchResult = count_match(main2Darray, main1Darray, mainSize, userRow);
				if(countMatchResult == 0)
					printf("\nThere are no numbers from 1D array present in the 2D array");
				else
				{
					printf( "\nThere are %d numbers from the 1D array present in the 2D array",
							countMatchResult);
				}

				break;

			case 3:
				// Perform Closest Row Function
				initialize_2Darray(main2Darray, mainSize);
				initialize_1Darray(main1Darray, mainSize);

				//Display initialized arrays
				printf("\nClosest Row Operation\n\n");
				printf("2D array\n");
				print_2Darray(main2Darray, mainSize);
				printf("\n1D array\n");
				print_1Darray(main1Darray, mainSize);

				//Perform function and display result
				printf( "\n\nRow closest to the 1D array is row %d",
						closest_row(main2Darray, main1Darray, mainSize));
				break;

			case 4:
				// Perform Sort 1D Array Function
				initialize_1Darray(main1Darray, mainSize);

				//Display initialized array
				printf("\nSort 1D Array Operation\n\n");
				printf("1D Array before sorting\n");
				print_1Darray(main1Darray, mainSize);

				//Display sorted array
				printf("\n1D Array after sorting\n");
				sort_1Darray(main1Darray, mainSize);
				print_1Darray(main1Darray, mainSize);

				break;

			case 5:
				// Perform Sort 2D Array Function
				initialize_2Darray(main2Darray, mainSize);

				//Display initialized array
				printf("\nSort 2D Array Operation\n\n");
				printf("2D Array before sorting\n");
				print_2Darray(main2Darray, mainSize);

				//Display sorted array
				printf("\n2D Array after sorting\n");
				sort_2Darray(main2Darray, mainSize);
				print_2Darray(main2Darray, mainSize);

				break;

			case 6:
				// Exit Program

				break;

			default:
				// Invalid input - Error
				printf( "\n"
						"*********************************\n\n"
						" Error: Invalid Switch Condition \n\n"
						"*********************************\n");
		}

	} while(mainOption != 6);

	return 0;
}

void display_menu()
{
	//Displays menu choices.
	//Does not allow user selection of choices or error checks their choice
	printf( "\n\n"
			"Array operations, your options are:\n"
			"\n"
			"1: Search Min\n"
			"2: Count Matches\n"
			"3: Closest Row\n"
			"4: Sort 1D Array\n"
			"5: Sort 2D Array\n"
			"6: Exit\n"
			"Enter the operation you want to perform: ");

	return;
}

int check_option(int option)
{
	//Checks if user menu choice is within range (1 - 6)
	if(option >= 1 && option <= 6)
		return 1;
	else
		return 0;
}

int check_size(int size)
{
	//Checks if user size choice is within range (1 - MAX)
	if(size >= 1 && size <= MAX)
		return 1;
	else
		return 0;
}

void initialize_2Darray(int x[][MAX], int size)
{
	//Initializes every element in user specified size array to
	//a random number between 0 and 9

	//for loop variables
	int row, column;

	for(row = 0; row < size; row++)
	{
		for(column = 0; column < size; column++)
		{
			x[row][column] = rand() % 10;
		}
	}
}

void print_2Darray(int x[][MAX], int size)
{
	//Prints each element in the user specified size array
	//with one space between

	//for loop variables
	int row, column;

	for(row = 0; row < size; row++)
	{
		for(column = 0; column < size; column++)
		{
			printf("%d ", x[row][column]);
		}

		printf("\n");
	}
}

void initialize_1Darray(int y[], int size)
{
	//Initializes every element in user specified size array to
	//a random number between 0 and 9

	//for loop variables
	int i;

	for(i = 0; i < size; i++)
	{
		y[i] = rand() % 10;
	}
}

void print_1Darray(int y[], int size)
{
	//Prints each element in the user specified size array
	//with one space between

	//for loop variables
	int i;

	for(i = 0; i < size; i++)
	{
		printf("%d ", y[i]);
	}

	printf("\n");
}

int search_min(int x[][MAX], int r, int c, int size)
{
	//Find the smallest number in both the user selected row and column
	//and returns the value of the smallest number

	int realUserRow = r - 1; //corrects user row choice
	int realUserColumn = c - 1; //corrects user column choice
	int minNum = 10; //initial smallest number (max number possible is 10)
	int row, column;

	//Check all elements in specified column
	for(row = 0; row < size; row++)
	{
		if(minNum > x[row][realUserColumn])
			minNum = x[row][realUserColumn];
	}

	//Check all elements in the specified row
	for(column = 0; column < size; column++)
	{
		if(minNum > x[realUserRow][column])
			minNum = x[realUserRow][column];
	}

	return minNum;
}

int count_match(int x[][MAX], int y[], int size, int r)
{
	//Finds the number of matches from the 1D array found in the
	//user selected row of the 2D array

	int realUserRow = r - 1;
	int counter1Delement;
	int counter2Dcolumn;
	int matchCount = 0;

	for(counter1Delement = 0; counter1Delement < size; counter1Delement++)
	{
		for(counter2Dcolumn = 0; counter2Dcolumn < size; counter2Dcolumn++)
		{
			if(y[counter1Delement] == x[realUserRow][counter2Dcolumn])
			{
				matchCount++;
				counter2Dcolumn = size; //break out of for loop
			}
		}
	}

	return matchCount;
}

int closest_row(int x[][MAX], int y[], int size)
{
	//Finds the row in the 2D array that is the closest to the
	//values of the 1D array

	int counter1Delement;
	int counter2Drow;
	int closestRow = 0;
	int closestRowValue;
	int forSum = 0;
	int firstPass = 1;

	for(counter2Drow = 0; counter2Drow < size; counter2Drow++)
	{
		//Finds the value of each row in terms of it's closeness to the 1D
		//array. If it is smaller that the previous smaller value it becomes
		//the current smallest value until every row has been checked
		for(counter1Delement = 0; counter1Delement < size; counter1Delement++)
		{
			forSum += abs(x[counter2Drow][counter1Delement] - y[counter1Delement]);
		}

		//Sets the first row as the beginning closest row
		if(firstPass == 1)
		{
			closestRow = counter2Drow;
			closestRowValue = forSum;
			firstPass = 0;
		}
		//All other rows checked against the current closest row
		else if(forSum < closestRowValue)
		{
			closestRow = counter2Drow;
			closestRowValue = forSum;
		}

		//Reset forSum for next row
		forSum = 0;
	}

	return closestRow + 1; //+1 added for user readability

}

void sort_1Darray(int y[], int size)
{
	//Bubble sorts the 1D array in ascending order

	int array1Delement;
	int holdValue, passes;

	for(passes = 0; passes < size; passes++)
	{
		for(array1Delement = 0; array1Delement < (size - 1); array1Delement++)
		{
			if(y[array1Delement] > y[array1Delement + 1])
			{
				holdValue = y[array1Delement];
				y[array1Delement] = y[array1Delement + 1];
				y[array1Delement + 1] = holdValue;
			}
		}
	}

	return;
}

void sort_2Darray(int x[][MAX], int size)
{
	//Bubble sorts each row of the 2D array in ascending order

	int array2Dcolumn, array2Drow;
	int holdValue, passes;
	for(array2Drow = 0; array2Drow < size; array2Drow++)
	{
		for(passes = 0; passes < size; passes++)
		{
			for(array2Dcolumn = 0; array2Dcolumn < (size - 1); array2Dcolumn++)
			{
				if(x[array2Drow][array2Dcolumn] > x[array2Drow][array2Dcolumn + 1])
				{
					holdValue = x[array2Drow][array2Dcolumn];
					x[array2Drow][array2Dcolumn] = x[array2Drow][array2Dcolumn + 1];
					x[array2Drow][array2Dcolumn + 1] = holdValue;
				}
			}
		}
	}

	return;
}
