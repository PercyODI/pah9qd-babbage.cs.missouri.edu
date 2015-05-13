/* Pearse Hutson
 * Pawprint: pah9qd
 * Submission Code: awfulhistograms
 * Lab: D
 * Date: 10.20.14
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function Prototypes
int check_error(int size);
void initialize_array(int inputArray[], int size);
void print_array(int inputArray[], int size);
int count_numbers(int[], int, int);
void frequency(int[], int[], int);
int mode(int secondArray[]);
void print_histogram(int secondArray[]);
float median(int inputArray[], int size);

//Main
int main(void)
{
	//Initialize Random Seed and Local Variables
	srand(time(NULL));
	int userSize;
	int userArray[100] = {0};
	int frequencyArray[10] = {0};

	//Display user input line and check for errors
	printf("\n");
	printf("Enter the size of the input: ");
	scanf("%d", &userSize);
	while(check_error(userSize) == 0)
	{
		printf("Invalid input enter the size of the input again: ");
		scanf("%d", &userSize);
	}
	
	//Perform array functions
	initialize_array(userArray, userSize);
	frequency(userArray, frequencyArray, userSize);
	
	//Print the Input Array
	printf("\n\n");
	printf("Input array\n");
	print_array(userArray, userSize);

	//Print the mode of the array
	printf("\n\n");
	printf("Mode for the array is number %d\n\n", mode(frequencyArray));

	//Print the histogram of the array
	printf("Printing Histogram\n\n");
	print_histogram(frequencyArray);
		
	//Bonus Part
	printf("\n");
	printf("Bonus part\n\n");
	printf("Input array\n");
	print_array(userArray, userSize);
	printf("\n");
	printf("Median value is %.2f", median(userArray, userSize));

	//End Program
	printf("\n\n");
	return 0;	

}

int check_error(int size)
{
	//If the user inputs a number between 1 and 100, check_error will return 1
	//otherwise check_error will return 0 for a bad input
	if(size > 0 && size <= 100)
		return 1;
	else
		return 0;
}

void initialize_array(int inputArray[], int size)
{
	//Sets all values in the array to a random number between 0 and 9
	int i;
	for(i = 0; i < size; i++)
		inputArray[i] = rand() % 10;
}

void print_array(int inputArray[], int size)
{
	//Prints all of the values in the array with one space between each value.
	//Does not print heading information.
	int i;

	for(i = 0; i < size; i++)
		printf("%d ", inputArray[i]);
}

int count_numbers(int inputArray[], int size, int numToBeSearched)
{
	//Returns the number of times a certain number appears in an array
	//This function must be run once for every number possibility
	int numberTotal = 0;
	int i;
	for(i = 0; i < size; i++)
	{
		if (inputArray[i] == numToBeSearched)
			numberTotal++;
	}
	
	return numberTotal;
}

void frequency(int inputArray[], int secondArray[], int size)
{
	//Modifies the second array so that each element corresponds to the number
	//of times a value appears in the inputArray
	int i;

	for(i = 0; i < 10; i++)
		secondArray[i] = count_numbers(inputArray, size, i);
}

int mode(int secondArray[])
{
	//Searches the array for the element that has the largest value 
	//and returns the element number corresponding to that largest value
	int i, modeElement, modeFrequency;
	
	modeFrequency = 0;
	modeElement = 0; 

	for(i = 0; i < 10; i++)
	{
		if(secondArray[i] > modeFrequency)
		{
			modeFrequency = secondArray[i];
			modeElement = i;
		}
	}
	
	//Returns the element number with the largest value
	//NOT the largest value itself
	return modeElement;
}

void print_histogram(int secondArray[])
{
	//Prints each number and one * for every instance of a value found in the array
	//Does not print any header information
	int i, j;

	for(i = 0; i < 10; i++)
	{
		//Starts each line with the number being evaluated
		printf("%d:", i);

		//Prints one * for the number in each element
		for(j = 1; j <= secondArray[i]; j++)
			printf("*");
		
		//Starts a new line for the next number to be evaluated
		printf("\n");
	}
}

float median(int inputArray[], int size)
{
	//Returns the median of the array. Array is not sorted
	float evenMedian;

	//Determine if the array is even or odd, then perform calculations
	if(size % 2 == 0) //Even
	{
		//Finds sum of two middle numbers and calculates average
		evenMedian = ((float)inputArray[size / 2] + inputArray[(size - 2) / 2]) / 2;
		return evenMedian;
	}
	else //Odd
	{
		//(size - 1) / 2 gives the value of the middle element in the set
		return inputArray[(size - 1) / 2];
	}
}
