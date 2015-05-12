/* Name: Pearse Hutson
 * Pawprint: pah9qd
 * Student ID: 14040826
 * Lab: E
 * Labcode: Sorting
 * Date: 3/9/2015
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

typedef struct {
	unsigned long int comparisons;
	unsigned long int swaps;
	long double duration;
}SortStat;

typedef struct {
	int *first;
	int *second;
	int *third;
}Arrays;

Arrays generate_arrays(int len);
SortStat bubble_sort(int array[], int len);
SortStat selection_sort(int array[], int len);
SortStat insertion_sort(int array[], int len);
unsigned long int linear_search(int array[], int len, int key);
unsigned long int binary_search(int array[], int low, int high, int key);

int main(void)
{
	srand(time(NULL));
	Arrays threeArrays;
	int i, len;
	SortStat bubbleStats, selectionStats, insertionStats;

	len = 10;
	for(i = 0; i < 4; i++)
	{
		threeArrays = generate_arrays(len);
		bubbleStats = bubble_sort(threeArrays.first, len);
		selectionStats = selection_sort(threeArrays.second, len);
		insertionStats = insertion_sort(threeArrays.third, len);

		printf("For arrays of size %d\n", len);
		printf("\tBubble sort makes %lu comparisons, %lu swaps and took %Le milliseconds\n", 
				bubbleStats.comparisons, bubbleStats.swaps, 
				bubbleStats.duration);
		printf("\tSelection sort makes %lu comparisons, %lu swaps and took %Le milliseconds\n", 
				selectionStats.comparisons, selectionStats.swaps, 
				selectionStats.duration);
		printf("\tInsertion sort makes %lu comparisons, %lu swaps and took %Le milliseconds\n", 
				insertionStats.comparisons, insertionStats.swaps, 
				insertionStats.duration);
		printf("\tLinear search made %lu comparisons\n", linear_search(threeArrays.first, len, len + 1));
		printf("\tBinary search made %lu comparisons\n", binary_search(threeArrays.second, 0, len, len + 1));
		len *= 10;
		
		free(threeArrays.first);
		free(threeArrays.second);
		free(threeArrays.third);
	}

	printf("The binary search made so many fewer comparisons than the linear\n\
search because it removes half of the possible set (between low\n\
and high) in every set. The linear search has to check every \n\
element in the array, while the binary search only checks the \n\
middle of it's set before removing half and trying again.\n");

	return 0;
}
/**********************************************************
					generate_arrays
Parameters:
	len - The length of the array to generate_arrays
Return:
	An Arrays struct

	This function will create three identical int arrays and 
store them in an Arrays struct. They will contain random 
numbers in the range [0, len].
**********************************************************/
Arrays generate_arrays(int len)
{
	int i, randNum;
	Arrays threeArrays;

	threeArrays.first = malloc(sizeof(int) * len);
	threeArrays.second = malloc(sizeof(int) * len);
	threeArrays.third = malloc(sizeof(int) * len);
	for(i = 0; i < len; i++)
	{
		randNum = rand() % len + 1;
		threeArrays.first[i] = randNum;
		threeArrays.second[i] = randNum;
		threeArrays.third[i] = randNum;
	}

	return threeArrays;
}

/**********************************************************
					bubble_sort
Parameters:
	array - An array of integers
	len - The length of the array
Return:
	A SortStat struct containing statistics about bubble sort

	This function will sort the array using bubble sort and 
track three statistics about it; the number of comparisons, 
the number of swaps, and the duration of the swap in 
milliseconds.
**********************************************************/
SortStat bubble_sort(int array[], int len)
{
	int i, j, tempHold, madeChange;
	struct timeval tv;
	double t1, t2;
	SortStat Stats = {0, 0, 0.0};
	
	gettimeofday(&tv, NULL);
	t1 = tv.tv_sec+(tv.tv_usec/1000000.0);

	for(i = 0; i < len; i++)
	{
		madeChange = 0;
		for(j = 0; j < (len - 1); j++)
		{
			Stats.comparisons++;
			if(array[j] > array[j+1])
			{
				Stats.swaps++;
				madeChange = 1;
				tempHold = array[j];
				array[j] = array[j+1];
				array[j+1] = tempHold;
			}
		}
		if(madeChange == 0)
			break;
	}
	
	gettimeofday(&tv, NULL);
	t2 = tv.tv_sec+(tv.tv_usec/1000000.0);
	Stats.duration = (t2 - t1) * 1000;
	
	return Stats;
}

/**********************************************************
					selection_sort
Parameters:
	array - An array of integers
	len - The length of the array
Return:
	A SortStat struct containing statistics about 
selection sort

	This function will sort the array using selection sort 
and track three statistics about it; the number of 
comparisons, the number of swaps, and the duration of 
the swap in milliseconds.
**********************************************************/	
SortStat selection_sort(int array[], int len)
{
	int i, j, tempHold, currentSmallestIndex;
	struct timeval tv;
	double t1, t2;
	SortStat Stats = {0, 0, 0.0};
	
	gettimeofday(&tv, NULL);
	t1 = tv.tv_sec+(tv.tv_usec/1000000.0);
	
	for(i = 0; i < len; i++)
	{
		tempHold = array[i];
		currentSmallestIndex = i;
		
		for(j = i; j < len; j++)
		{
			Stats.comparisons++;
			if(array[j] < array[currentSmallestIndex])
			{
				currentSmallestIndex = j;
			}
		}
		if(currentSmallestIndex != i)
		{
			Stats.swaps++;
			array[i] = array[currentSmallestIndex];
			array[currentSmallestIndex] = tempHold;
		}
	}
	
	gettimeofday(&tv, NULL);
	t2 = tv.tv_sec+(tv.tv_usec/1000000.0);
	Stats.duration = (t2 - t1) * 1000;
	
	return Stats;
}

/**********************************************************
					insertion_sort
Parameters:
	array - An array of integers
	len - The length of the array
Return:
	A SortStat struct containing statistics about 
insertion sort

	This function will sort the array using insertion sort 
and track three statistics about it; the number of 
comparisons, the number of swaps, and the duration of 
the swap in milliseconds.
**********************************************************/	
SortStat insertion_sort(int array[], int len)
{
	int i, moveItem, insert;
	struct timeval tv;
	double t1, t2;
	SortStat Stats = {0, 0, 0.0};
	
	gettimeofday(&tv, NULL);
	t1 = tv.tv_sec+(tv.tv_usec/1000000.0);
	
	for(i = 1; i < len; i++)
	{
		moveItem = i;
		insert = array[i];
		Stats.comparisons++;
		while(moveItem > 0 && array[moveItem - 1] > insert)
		{
			Stats.swaps++;
			array[moveItem] = array[moveItem - 1];
			moveItem--;
		}

		array[moveItem] = insert;
	}
	
	gettimeofday(&tv, NULL);
	t2 = tv.tv_sec+(tv.tv_usec/1000000.0);
	Stats.duration = (t2 - t1) * 1000;
	
	return Stats;
}

/**********************************************************
					linear_search
Parameters:
	array - An array of integers
	len - The length of the array
	key - The int we are searching for
Return:
	An unsigned long int containing the number of comparisons

	This function will search a sorted array for a specific 
key. It then returns the number of comparisons it took to 
find the key.
**********************************************************/	
unsigned long int linear_search(int array[], int len, int key)
{
	int i;
	unsigned long int comparisons = 0;
	
	for(i = 0; i < len; i++)
	{
		comparisons++;
		if(array[i] == key)
		{
			return comparisons;
		}
	}
	
	return comparisons;
}

/**********************************************************
					binary_search
Parameters:
	array - An array of integers
	low - The lowest index to search for
	high - The highest index to search for
	key - The int we are searching for
Return:
	An unsigned long int containing the number of comparisons

	This function will search a sorted array for a specific 
key. It then returns the number of comparisons it took to 
find the key. This function works recursively
**********************************************************/	
unsigned long int binary_search(int array[], int low, int high, int key)
{
	unsigned long int comparisons = 1;
	int middleIndex;
	
	middleIndex = (low + high) / 2;
	if(array[middleIndex] == key)
		return comparisons;
	else if(high == low)
		return comparisons;
	else if(array[middleIndex] > key)
		return comparisons + binary_search(array, low, middleIndex - 1, key);
	else if(array[middleIndex] < key)
		return comparisons + binary_search(array, middleIndex + 1, high, key);
	else
	{
		printf("\n\nError: Binary Search Malfunction\n\n");
		return 0;
	}
}
