/* Pearse Hutson
 * pah9qd
 * 10.13.14
 * Lab 6
 * lotsofbuckets
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Global Variables
int globalArray[100];

//Function Prototypes
int check_input(int);
void initialize_array(int);
void print_array(int);
int max(int);
int min(int);
float average(int);
void compute_stats(int);
int search(int, int);
int count_numbers(int, int);
void sort(int);

int main(void)
{
	//Initialize Random Seed
	srand(time(NULL));
	//Local Variables
	int size, searchNum, searchResult, countResult;

	printf("\n");
	printf("Enter the size of the input: ");
	scanf("%d", &size);
	while(check_input(size) == 0)
	{
		printf("Invalid input enter the size of the input again: ");
		scanf("%d", &size);
	}
	
	//Insert initial values into globalArray
	initialize_array(size);

	//Display initial values of globalArray
	printf("\n");
	printf("Input Array\n");
	print_array(size);

	//Display statistics of globalArray
	compute_stats(size);

	//Search for number function
	printf("Enter the number you want to search: ");
	scanf("%d", &searchNum);

	searchResult = search(searchNum, size);
	if(searchResult !=  -1)
	{
		printf("\n");
		printf("The number %d is present at index %d\n", searchNum, searchResult);
	}
	else
	{
		printf("\n");
		printf("The number %d is not present in the array\n", searchNum);
	}

	//Count the number of times a number appears in an array
	countResult = count_numbers(searchNum, size);
	if(countResult != -1)
	{
		printf("The number %d is present %d times in the array\n", searchNum, countResult);
	}
	else
	{
		printf("The number %d is not present in the array\n", searchNum);
	}

	//Bonus Part
	printf("\n");
	printf("Bonus part\n");
	printf("Array before sorting\n");
	print_array(size);
	printf("\n");
	printf("Array after sorting\n");
	sort(size);
	print_array(size);
	printf("\n\n");

	return 0;
}

//Checks if the user's specified size 
//is between 0 and 100
int check_input(int size)
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

//Sets all elements to user specified size
//to a random number
void initialize_array(int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		globalArray[i] = rand() % 10;
	}
	
	return;
}

//Prints the array for the user specified
//number of elements
void print_array(int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		printf("%d ", globalArray[i]);
	}

	return;
}

//Returns the largest number in the array
int max(int size)
{
	int i, maxNum = 0;

	for(i = 0; i < size; i++)
	{
		if(globalArray[i] > maxNum)
		{
			maxNum = globalArray[i];
		}
	}

	return maxNum;
}

//Returns the smallest number in the array
int min(int size)
{
	int i, minNum = globalArray[0];

	for(i = 0; i < size; i++)
	{
		if(globalArray[i] < minNum)
		{
			minNum = globalArray[i];
		}
	}

	return minNum;
}

//Returns the average of all of the numbers in the array
float average(int size)
{
	int i;
    int	totalSum = 0; 
	int totalCount = 0;
	float avgNum = 0.0;

	for(i = 0; i < size; i++)
	{
		totalSum += globalArray[i];
		totalCount++;
	}
	
	avgNum = (float)totalSum / totalCount;
	return avgNum;
}

//Calls the previous three functions and displays
//the result
void compute_stats(int size)
{
	printf("\n\n");
	printf("Largest number is %d\n", max(size));
	printf("Smallest number is %d\n", min(size));
	printf("Average of numbers is %.3f\n\n", average(size));

	return;
}

//Takes a user search request and returns the first
//index of the array that contains that request
int search(int searchNum, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		if(globalArray[i] == searchNum)
		{
			return i;
		}
	}

	//return -1 if no value matches search
	return -1;
}

//Takes a user search request and returns the total
//number of times in the array that the request
//appears
int count_numbers(int searchNum, int size)
{
	int i, totalCount = 0;

	for(i = 0; i < size; i++)
	{
		if(globalArray[i] == searchNum)
		{
			totalCount++;
		}
	}
	
	//Return code -1 if the number is not present in the array
	if(totalCount == 0)
	{
		return -1;
	}
	else
	{
		return totalCount;
	}
}

//Sorts the array by moving left to right
//in the array and finding the next smallest
//number and switches those numbers
void sort(int size)
{
	
	int i, smallest, makeChange;
	int replacingIndex = 0;
	int timesRun = 0;

	while(timesRun < size)
	{
		//makeChange can only be set to 1
		//when a change needs to be made
		makeChange = 0;
		smallest = globalArray[timesRun];
		for(i = timesRun; i < size; i++)
		{
			if(globalArray[i] < smallest)
			{
				smallest = globalArray[i];
				replacingIndex = i; 
				makeChange = 1;//Will cause the switching of numbers
			}
		}

		//If no number is smaller than the current number, do not make 
		//any switches.
		//If a number is smaller than the current number, do make
		//the switch.
		if(makeChange == 1)
		{
			globalArray[replacingIndex] = globalArray[timesRun]; 
			globalArray[timesRun] = smallest;
		}

		timesRun++;
	}
}
