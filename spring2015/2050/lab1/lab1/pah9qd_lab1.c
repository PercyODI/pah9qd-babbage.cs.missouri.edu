/* Lab Code: First Day
 * Student Name: Pearse Hutson
 * Student ID: 14040826
 * Pawprint: pah9qd
 * Lab: Lab E
 * Date: 1/26/2015
 * Lab 1
 */

//Included Libraries
#include <stdio.h>
#include <stdlib.h>

//Function Prototypes
int* readFile(char *inputfile);
int  findMin(int *array);
int  findMax(int *array);
int  findAvg(int *array);
void writeOut(char *outFile, int min, int max, int avg, int median);
int  findMedian(int *array);

//Program Begin
int main(int argc, char **argv)
{
	//Verify the correct number of arguments
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return 0;
	}
	
	int *numArray;
	int minNum, maxNum, avgNum, medianNum;
	
	//Set numArray to the numbers from input file
	numArray = readFile(argv[1]);
	
	//Checks validity of file. If file doesn't exsist, 
	//return error and exit program
	if(numArray == NULL)
	{
		printf("Invalid input file\n");
		return 0;
	}

	//Find the minimum, maximum, average, and median numbers
	//in numArray
	minNum = findMin(numArray);
	maxNum = findMax(numArray);
	avgNum = findAvg(numArray);
	medianNum = findMedian(numArray);

	//Write data to output file.
	writeOut(argv[2], minNum, maxNum, avgNum, medianNum);

	//Free array memory
	free(numArray);

	//End program
	return 0;
}

int* readFile(char *inputFile)
{
	/* Parameter: inputFile - The name of a file containint 10 ints
	 * Return: A pointer to an array containing the numbers from the 
	 * 		   input file
	 *
	 * This function dynamically creates an array to hold 10 integers
	 * and reads the contents of the input file into it
	 */

	int i, *numArray;

	//Dynamically allocates memory for an array of 10 integers
	numArray = malloc(sizeof(int) * 10);
	
	FILE *file = fopen(inputFile, "r");

	//Check that the inputFile exsists. Return NULL if false
	if(file == NULL)
	{
		return NULL;
	}

	for(i = 0; i < 10; i++)
	{
		fscanf(file, "%d", (numArray + i));
	}

	fclose(file);
	return numArray;
}

int findMin(int *array)
{
	/* Parameter: array - An array of 10 integers
	 * Return: The smallest value in the array
	 *
	 * This function searches the array for the smallest value
	 * and returns that number
	 */
	int minNum, i;

	//Set initial min number to first number in the array
	minNum = *array;

	for(i = 0; i < 10; i++)
	{
		if(*(array + i) < minNum)
		{
			minNum = *(array + i);
		}
	}

	return minNum;
}

int findMax(int *array)
{
	/* Parameter: array - An array of 10 integers
	 * Return: The small value in the array
	 *
	 * This function searches the array for the smallest value
	 * and returns that number
	 */

	int maxNum, i;

	//Set initial max number to first number in the array
	maxNum = *array;

	for(i = 0; i < 10; i++)
	{
		if(*(array + i) > maxNum)
		{
			maxNum = *(array + i);
		}
	}

	return maxNum;
}

int findAvg(int *array)
{
	/* Parameter: array - An array of 10 integers
	 * Return: The average of all the numbers in the array
	 * 
	 * This function sums all of the numbers in the array and
	 * divides them by the number of values in the array (10)
	 * to return the average of the numbers	
	 *
	 * Caution: Calculations produce a floating point number
	 * that is converted to an integer
	 */
	int sumOfArray = 0;
	int i;
	
	for(i = 0; i < 10; i++)
	{
		sumOfArray += *(array + i);
	}

	return (sumOfArray / 10);
}


void writeOut(char *outFile, int min, int max, int avg, int median)
{
	/* Parameters: outFile - The name of the output file to write to
	 * 			   min - The smallest number in the array
	 * 			   max - The largest number in the array
	 * 			   avg - The average of all the numbers in the array
	 * 			   median - The median number of the array
	 * Return: None
	 *
	 * This function writes out the computed values into the
	 * output file.
	 */
	FILE *file = fopen(outFile, "w");

	fprintf(file, "min: %d\n", min);
	fprintf(file, "max: %d\n", max);
	fprintf(file, "avg: %d\n", avg);
	fprintf(file, "median: %d", median);

	fclose(file);
	return;
}

int findMedian(int *array)
{
	/* Parameter: array - An array of 10 integers
	 * Return: The median number of the array
	 *
	 * This function sorts the array numerically and finds the median
	 * number of the array. Because the array size is 10, there are
	 * two "middle" numbers which must be averaged for the median num
	 *
	 * Caution: Calculations produce a floating point number
	 * that is converted to an integer
	 */
	int i, j, holdingNum, medianNum;

	//Bubblesort array to put in numeric order
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(*(array + j) > *(array + j + 1))
			{
				holdingNum = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = holdingNum;
			}
		}
	}

	//Finds the average of the two middle numbers for the median num
	medianNum = (*(array + 4) + *(array + 5)) / 2;
	
	return medianNum;
} 
