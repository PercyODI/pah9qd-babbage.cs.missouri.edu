/* Pearse Hutson
 * Pawprint: pah9qd
 * Lab Code: D
 * Date: 12.5.2014
 * Homework 4
 */

#include<stdio.h>
#include<stdlib.h>

int load_data(char *, int *, float *);
void print_data(int, int *, float *);
int update_data(char *, int *, float *, int);
int highest_amount(float *, int);
int lowest_amount(float *, int);
float average_amount(float *, int);
void write_data(char *, int *, float *, int, int, int, float);

int main(int argc, char **argv)
{
	//Expected argument order: a.out input.txt 8 update.txt output.txt
	if(argc != 5)
	{
		printf("\nInsufficient arguments\n");
		return 0;
	}

	//Number of accounts from command line
	int n = atoi(argv[2]);

	if(n == 0)
	{
		printf("\nInvalid number of entries\n");
		return 0;
	}

	//Initial variables
	int *acnPtr;
	float *amtPtr;
	int size, updateRtn;
	int highestIndex, lowestIndex;
	float averageAmt;

	//Allocate memory using information from command line
	acnPtr = malloc(sizeof(int) * n);
	amtPtr = malloc(sizeof(float) * n);

	//Number of accounts from file
	size = load_data(argv[1], acnPtr, amtPtr);

	if(size == 0)
	{
		printf("\nUnable to open the input file\n");
		return 0;
	}

	//Return error for inconsistant numbers
	if(size != n)
	{
		printf("\nCommand Line and File numbers do not match");
		return 0;
	}

	print_data(size, acnPtr, amtPtr);

	//Updates account information from argv[3] (update.txt)
	printf("\nUpdated account information\n");
	updateRtn = update_data(argv[3], acnPtr, amtPtr, size);
	if(updateRtn == 0)
	{
		printf("\nUnable to open the update file\n");
		return 0;
	}
	print_data(size, acnPtr, amtPtr);

	//Prints off account statistics
	printf("\n");
	highestIndex = highest_amount(amtPtr, size);
	lowestIndex = lowest_amount(amtPtr, size);
	averageAmt = average_amount(amtPtr, size);
	printf("The highest amount is $%.2f in the account number %d\n",
			*(amtPtr + highestIndex), *(acnPtr + highestIndex));
	printf("The lowest amount is $%.2f in the account number %d\n",
			*(amtPtr + lowestIndex), *(acnPtr + lowestIndex));
	printf("The average amount is $%.2f\n", averageAmt);

	//Writes data to file from argv[4] (output.txt)
	write_data(argv[4], acnPtr, amtPtr, size, highestIndex, lowestIndex, averageAmt);

	//Free malloc'ed memory in acnPtr and amtPtr
	free(acnPtr);
	free(amtPtr);

	return 0;
}

int load_data(char *filename, int *x, float *y)
{

	//Loads data from argv[1] (input.txt) and
	//fills in amtPtr and acnPtr with the data.
	//Returns the number of accounts.
	int i = 0;
	int size;

	FILE *file = fopen(filename, "r");

	if(file == NULL)
	{
		return 0;
	}

	//Scans in the number of accounts
	fscanf(file, "%d", &size);

	//Scans in the accounts and amounts one line at a time
	for(i = 0; i < size;  i++)
	{
		fscanf(file, "%d %f", x, y);
		x++;
		y++;
	}

	//Close the file
	fclose(file);
	return size;
}

void print_data(int size, int *x, float *y)
{
	//Prints the data to the screen one line at a time
	//with headers. Does not return anything
	int i;

	printf("\n");
	printf("%-12s%-10s\n", "Account No.", "Amount");

	for(i = 0; i < size; i++)
	{
		printf("%-8d%-10.2f\n", *x, *y);
		x++;
		y++;
	}
}

int update_data(char *filename, int *acnPtr, float *amtPtr, int numOfAccounts)
{
	//Updates the information in acnPtr and amtPtr with the data in
	//argv[3] (update.txt)
	//Returns a error code for complete or incomplete update
	FILE *file = fopen(filename, "r");

	if(file == NULL)
	{
		return 0;
	}

	int numRuns;
	int i, j;
	int *acnPtrStart = acnPtr;
	float *amtPtrStart = amtPtr;
	int updAcn;
	float updAmt;

	fscanf(file, "%d", &numRuns);

	for(i = 0; i < numRuns; i++)
	{
		fscanf(file, "%d %f", &updAcn, &updAmt);
		acnPtr = acnPtrStart; //Reset acnPtr pointer
		amtPtr = amtPtrStart; //Reset amtPtr pointer

		for(j = 0; j < numOfAccounts; j++)
		{
			if(*acnPtr == updAcn)
			{
				*amtPtr += updAmt;
				j = numOfAccounts; // Break out of for loop
			}
			else
			{
				acnPtr++;
				amtPtr++;
			}
		}
	}

	fclose(file);
	return 1;
}

int highest_amount(float *amtPtr, int numOfAccounts)
{
	//Searches the data for the highest value in
	//amtPtr and returns the index of that value
	int i;
	float highestAmt = *amtPtr;
	int highestIndex = 0;

	for(i = 0; i < numOfAccounts; i++)
	{
		if(*amtPtr > highestAmt)
		{
			highestAmt = *amtPtr;
			highestIndex = i;
		}
		amtPtr++;
	}

	return highestIndex;
}

int lowest_amount(float *amtPtr, int numOfAccounts)
{
	//Searches the data for the lowest value in
	//amtPtr and returns the index of that value
	int i;
	float lowestAmt = *amtPtr;
	int lowestIndex = 0;

	for(i = 0; i < numOfAccounts; i++)
	{
		if(*amtPtr < lowestAmt)
		{
			lowestAmt = *amtPtr;
			lowestIndex = i;
		}
		amtPtr++;
	}

	return lowestIndex;
}

float average_amount(float *amtPtr, int numOfAccounts)
{
	//Finds the average amount of the values in amtPtr
	//and returns that amount
	int i;
	float totalAmt = 0;

	for(i = 0; i < numOfAccounts; i++)
	{
		totalAmt += *amtPtr;
		amtPtr++;
	}

	return totalAmt / numOfAccounts;
}

void write_data(char *filename, int *acnPtrPtr, float *amtPtr, int numOfAccounts, int highestIndex, int lowestIndex, float averageAmt)
{
	//Writes data to argv[4] (output.txt)
	//Includes headers
	//Doesn't not return anything
	FILE *file = fopen(filename, "w");

	int i;
	int *acnPtrStartPtr = acnPtrPtr;
	float *amtPtrStartPtr = amtPtr;

	fprintf(file, "Account No. Amount\r\n");

	for(i = 0; i < numOfAccounts; i++)
	{
		fprintf(file, "%d %.2f\r\n", *acnPtrPtr, *amtPtr);
		acnPtrPtr++;
		amtPtr++;
	}

	fprintf(file, "\n");
	fprintf(file, "The highest amount is $%.2f in the account number %d\r\n",
			*(amtPtrStartPtr + highestIndex), *(acnPtrStartPtr + highestIndex));
	fprintf(file, "The lowest amount is $%.2f in the account number %d\r\n",
			*(amtPtrStartPtr + lowestIndex), *(acnPtrStartPtr + lowestIndex));
	fprintf(file, "The average amount is $%.2f", averageAmt);

	fclose(file);
}
