#include <stdio.h>

int binary_search(int array[], int low, int high, int key);

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Invalid command prompt\n");
		return 0;
	}

	int startingArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int foundIndex;
	printf("Starting Binary Search of [1,2,3,4,5,6,7,8,9,10] searching for %d", atoi(argv[1]));
	foundIndex = binary_search(startingArray, 0, 9, atoi(argv[1]));
	if(foundIndex == -1)
		printf("\nNo Match!!\n");
	else
	{
		printf("\nfoundIndex = %d", foundIndex);
		printf("\nIndex Value = %d\n", startingArray[foundIndex]); 
	}
}

int binary_search(int array[], int low, int high, int key)
{
	int middle = (high + low) / 2;
	printf("\n\nMiddle = %d\nhigh = %d\nlow = %d", middle, high, low);

	if(key == array[middle])
	{
		printf("\nkey == array[middle]. Returning middle");
		return middle;
	}
	else if(high == low)
	{
		printf("\nNo Match. Returning -1");
		return -1;
	}
	else if(key > array[middle])
	{
		printf("\nkey > array[middle].");
		return binary_search(array, middle + 1, high, key);
	}
	else if(key < array[middle])
	{
		printf("\nkey < array[middle]");
		return binary_search(array, low, middle - 1, key);
	}
	else
	{
		printf("Error: Invalid Function Response");
		return -1;
	}
}


