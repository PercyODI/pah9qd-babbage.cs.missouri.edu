/* Name: Pearse Hutson
 * Pawprint: pah9qd
 * Id: 14040826
 * Date: 3/2/2015
 * Lab: 5
 * Labcode: Snowman
 */

//Included Libraries
#include <stdio.h>
#include <stdlib.h>

//Function Prototypes
int* load_array(char *file, int *length);
void insertion_sort(int array[], int length);
int binary_search(int array[], int low, int high, int key);
int fib(int n, int);
int range(int array[], int length, int low, int high);

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Usage: ./a.out <input file>");
		return 0;
	}
	
	int length, i, searchKey, foundIndex;
	int rangeResult, rangeLow, rangeHigh;
	int *inputArray;

	inputArray = load_array(argv[1], &length);
	if(load_array == NULL)
	{
		printf("Invalid Input File");
		return 0;
	}

	insertion_sort(inputArray, length);

	for(i = 0; i < length; i++)
	{
		inputArray[i] = fib(inputArray[i], 0);
	}

	for(i = 0; i < length; i++)
	{
		printf("%d\n", inputArray[i]);
	}

	printf("Enter a number to search for:\n");
	scanf("%d", &searchKey);	
	foundIndex = binary_search(inputArray, 0, length - 1, searchKey);
	if(foundIndex == -1)
		printf("%d was not found in the array", searchKey);
	else
		printf("%d was found at index %d", searchKey, foundIndex);

	printf("\nBonus: Enter a range to search for\n");
	scanf("%d %d", &rangeLow, &rangeHigh);
	rangeResult = range(inputArray, length, rangeLow, rangeHigh);
	printf("There are %d numbers between %d and %d inclusively\n",
			rangeResult, rangeLow, rangeHigh);

	free(inputArray);
	
	return 0;
}

/*************************************************
					load_array
Parameters
	file: The name of an input file
	length: A pointer to the variable where the length
   			of the array is to be stored
Return
	A pointer to the head of the array

Description
	This function opens the file specified by file and 
	reads its contents into the accounts array. The 
	first line is the length of the file followed by 
	that many numbers.
*************************************************/
int* load_array(char *file, int *length)
{
	FILE *fp = fopen(file, "r");
	
	if(fp == NULL)
		return NULL;

	int *arrayFromFile;
	int i;

	fscanf(fp, "%d", length);
	arrayFromFile = malloc(sizeof(int) * *length);

	for(i = 0; i < *length; i++)
	{
		fscanf(fp, "%d", &arrayFromFile[i]);
	}

	fclose(fp);
	return arrayFromFile;	
}
/*************************************************
					insertion_sort
Parameters
	array: An array of integers
	length: the number of elements in the array

Return 
	None

Description
	This function sorts the array using 
	insertion sort
*************************************************/
void insertion_sort(int array[], int length)
{
	int insert;
	int moveItem;
	int i;
	
	for(i = 1; i < length; i++)
	{
		moveItem = i;
		insert = array[i];

		while(moveItem > 0 && array[moveItem - 1] > insert)
		{
			array[moveItem] = array[moveItem - 1];
			moveItem--;
		}

		array[moveItem] = insert;
	}

}


/*************************************************
					fib
Parameters
	n: A number

Return
	The nth Fibonacci number

Description
	This function finds the nth fibonacci number
	when given a number n. This function is
	recursively implemented.
*************************************************/
int fib(int n, int callNum)
{
	printf("Execute Fib callNum %d\n", callNum);
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return (fib(n - 1, callNum++) + fib(n - 2, callNum++));
}

/*************************************************
				binary_search
Parameters
	array: An array of ints
	low: The index of the first element to be searched
	high: The index of the last element to be searched
	key: The value to be searched for

Return
	The index of the array with the specified value

Description
	This function searches the sorted array with
	binary search. This function is recursively 
	implemented.
*************************************************/
int binary_search(int array[], int low, int high, int key)
{
	int middle = (high + low) / 2;

	if(key == array[middle])
	{
		return middle;
	}
	else if(high == low || high < low)
	{
		return -1;
	}
	else if(key > array[middle])
	{
		return binary_search(array, middle + 1, high, key);
	}
	else if(key < array[middle])
	{
		return binary_search(array, low, middle - 1, key);
	}
	else
	{
		return -1;
	}
}

/*************************************************
					range
Parameters
	array: An array of ints
	length: The length of the array
   	low: The low end of the range to search for
	high: The high end of the range to search for

Return
	The number of elements that exist within 
	the specified range

Description
	This function sequentially checks an array
	and counts the number of elements in the array
	that fit within a user specified range.
*************************************************/
int range(int array[], int length, int low, int high)
{
	int counter = 0;
	int i, switchHold;

	if(low > high)
	{
		switchHold = low;
		low = high;
		high = switchHold;
	}

	for(i = 0; i < length; i++)
	{
		if(array[i] >= low && array[i] <= high)
			counter++;
		if(array[i] >= high)
			break;
	}
	
	return counter;
}
	
	
