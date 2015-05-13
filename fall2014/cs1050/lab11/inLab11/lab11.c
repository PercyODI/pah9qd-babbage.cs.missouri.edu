/* Pearse Hutson
 * Pawprint: pah9qd
 * Lab D
 * lab11.c
 * Labcode: formatthatoutput
 * Date: 12.1.2014
 */

#include<stdio.h>
#include<stdlib.h>

int load_data(char *, int *, float *);
void print_data(int size, int *x, float *y);
int search_account(int *, int, int);
int highest_amount(float *, int);
void write_data(char *, int *, float *, int);
void sort_data(int *acnPtr, float *amtPtr, int numOfAccounts);

int main(int argc, char** argv)
{
	//Check for correct number of arguments
	//Expected argument order: a.out input.txt 8 output.txt
	if(argc != 4)
	{
		//Print error and exit if incorrect number of arguments
		printf("\nInsufficient arguments\n\n");
		return 0;
	}

	int n = atoi(argv[2]);
	int *acnPtr;
	float *amtPtr;
	int numOfAccounts, searchForAcn, searchResult, highestIndex;

	//Allocate memory based on number of accounts
	//given by n (from argv[2])
	acnPtr = malloc(sizeof(int) * n);
	amtPtr = malloc(sizeof(float) * n);

	//Loads the input.txt file, acnPtr and amtPtr values are updated
	//to input.txt data. Returns the number of accounts into numOfAccounts
	//from the first int found at beginning of file
	numOfAccounts = load_data(argv[1], acnPtr, amtPtr);
	
	//If there are no accounts, or the file doesn't exsist
	//print error and exit
	if(numOfAccounts == 0)
	{
		printf("\nUnable to open the input file\n\n");
		return 0;
	}

	//Prints the data from input.txt
	print_data(numOfAccounts, acnPtr, amtPtr);

	//Begin search function by scanning for account number
	//to search for
	printf("\nEnter the account number you want to search: ");
	scanf("%d", &searchForAcn);
	
	searchResult = search_account(acnPtr, searchForAcn, numOfAccounts);
	if(searchResult == -1) //If the account isn't present
	{
		printf("\nAccount number %d is not present.\n", searchForAcn);
	}
	else //Account was found
	{
		printf("\nAccount number %d has $%.2f in it.\n", 
				searchForAcn, *(amtPtr + searchResult));
	}

	//Highest Amount function and print results
	highestIndex = highest_amount(amtPtr, numOfAccounts);
	printf("\nThe highest amount is $%.2f in the account number %d.\n",
			*(amtPtr + highestIndex), *(acnPtr + highestIndex));

	

	//Bonus Part
	
	//Sort the data
	sort_data(acnPtr, amtPtr, numOfAccounts);

	//Print results
	printf("\nBonus Part\n");
	printf("\nAfter Sorting\n");
	print_data(numOfAccounts, acnPtr, amtPtr);
	printf("\n");

	//Write sorted data to output.txt
	write_data(argv[3], acnPtr, amtPtr, numOfAccounts);

	//Free the allocated memory
	free(acnPtr);
	free(amtPtr);

	return 0;
}

int load_data(char *filename, int *x, float *y)
{
	//Loads the data from input.txt (argv[1])
	//into acnPtr (x) and amtPtr (y) amd returns
	//the number of accounts according to the file
	int i = 0;
	int numOfAccounts;

	//Opens input.txt in read-only mode
	FILE *file = fopen(filename, "r");

	//If file doesn't exsist, return 0
	if(file == NULL)
	{
		return 0;
	}

	//Scan for the number of accounts, given as the first int value
	fscanf(file, "%d", &numOfAccounts);

	//Loads each data one line at a time
	for(i = 0; i < numOfAccounts;  i++)
	{
		fscanf(file, "%d %f", x, y);
		x++;
		y++;
	}

	//Close input.txt
	fclose(file);

	return numOfAccounts;
}

void print_data(int numOfAccounts, int *x, float *y)
{
	//Prints the data with headings and one line per entry
	//Does not return anything
	int i;

	//Print headings
	printf("\n%-12s%-10s\n", "Account No.", "Amount");

	//Print one line per entry
	for(i = 0; i < numOfAccounts; i++)
	{
		printf("%-8d%-10.2f\n", *x, *y);
		x++;
		y++;
	}
}

int search_account(int *acnPtr, int searchForAcn, int numOfAccounts)
{
	//Searches for a user specified account number.
	//Returns the index of the account number
	int i;

	for(i = 0; i < numOfAccounts; i++)
	{
		if(*(acnPtr + i) == searchForAcn)
		{
			return i; // i is the Index Num of the match
		}
	}

	return -1; //Returns -1 if no account match is found
}

int highest_amount(float *amtPtr, int numOfAccounts)
{
	//Searches for the index of the highest amount.
	//Returns the index of the highest amount
	int i;
	int highestIndex = 0;
	float highestAmt = *amtPtr;

	for(i = 0; i < numOfAccounts; i++)
	{
		if(*(amtPtr + i) > highestAmt)
		{
			highestAmt = *(amtPtr + i);
			highestIndex = i;
		}
	}

	return highestIndex;
}

void write_data(char *filename, int *acnPtr, float *amtPtr, int numOfAccounts)
{
	//Writes the data to output.txt (argv[3])
	//Does not return anything
	int i;

	//Opens (or creates) output.txt in write mode
	FILE *file = fopen(filename, "w");
	
	//Writes headings
	fprintf(file, "%s %s\r\n", "Account No.", "Amount");

	//Writes one line per entry
	//uses \r\n for proper formatting (in Windows Notepad)
	for(i = 0; i < numOfAccounts; i++)
	{
		fprintf(file, "%d %.2f\r\n", *acnPtr, *amtPtr);
		acnPtr++;
		amtPtr++;
	}

	//Close output.txt
	fclose(file);

}	

void sort_data(int *acnPtr, float *amtPtr, int numOfAccounts)
{
	//Sorts the data by Account Number in Ascending Order
	//using Bubble Sort
	//Does not return anything
	int i, j, noChange;
	int holdAcn; 
	float holdAmt;

	for(i = 0; i < numOfAccounts; i++)
	{
		//Guarantees a number of passes equal to the number of accounts
		noChange = 1;
		for(j = 0; j < (numOfAccounts - 1); j++)
		{
			//Switches values if second value is
			//larger than the first value
			if(*(acnPtr + j) > *(acnPtr + j + 1))
			{
				//Hold the data of the first value
				holdAcn = *(acnPtr + j);
				holdAmt = *(amtPtr + j);
				//Set the data of the second value into the 
				//first data location
				*(acnPtr + j) = *(acnPtr + j + 1);
				*(amtPtr + j) = *(amtPtr + j + 1);
				//Set the data of the first value into the
				//second data location
				*(acnPtr + j + 1) = holdAcn;
				*(amtPtr + j + 1) = holdAmt;
				//Set noChange to 0 to continue looping
				noChange = 0;
			}
		}

		//Break if there is no changes (list sorted)
		if(noChange == 1)
		{
			return;
		}
	}
}
