/* -----------------------------------------------
Student: 		  Pearse Hutson
Student ID: 	  14040826
Student Pawpring: pah9qd
Lab Code: 		  Protein
Assignment: Lab3
	lab3.c - Implement a program that reads a list
of points from a file and performs some operations
on them.
----------------------------------------------- */

// Included Libraries
#include <stdio.h>
#include <stdlib.h>

//Constant Definitions
#define MAX_STRING_LEN 20

// Define Structs
typedef struct {
	int accountId;
	char *name;
	double amount;
} account;

//Function Prototypes
account* load_accounts(char *inputFile, int *size);
account* find_account(account *accounts, int size, int accountId);
void update_accounts(char *updateFile, account *accounts, int size);
void write_accounts(char *outputFile, account *accounts, int size);
void free_accounts(account *accounts, int size);
void sort(account *accounts, int size);

/* ===============================================
Function: main 
	main will take the names of three files as 
command line arguments 	and calls other functions
to be performed
=============================================== */
int main(int argc, char **argv)
{
	if(argc != 4)
	{
		printf("Error: Invalid command line arguments\n");
		printf("Example: ./a.out input.txt update.txt output.txt\n");
		return 0;
	}

	int size;
	account *accountsArray;

	//Call load_accounts. Loads the inputfile into an array of 
	//account structs
	accountsArray = load_accounts(argv[1], &size);

	//Call update_accounts. Updates the data in the array of account
	//structs with the data in the update file
	update_accounts(argv[2], accountsArray, size);

	//Selection sorts the array of account structs by amount 
	//(NOT by account number)
	sort(accountsArray, size);
	
	//Writes the array of account structs to the output file
	write_accounts(argv[3], accountsArray, size);

	//Frees all of the malloc'ed data found in the array of
	//account structs
	free_accounts(accountsArray, size);

	return 0;
}

/* ===============================================
Function: load_accounts 
	Parameters: inputFile - The name of a file containing account 
							information
		 			 size - A pointer to the int where the number of
					 		accounts will be stored
	Return: A pointer to an array of accounts

		 
	This function will dynamically create an array to hold the accounts 
and read the contents of the input file into it.	
=============================================== */
account* load_accounts(char *inputFile, int *size)
{
	FILE *file = fopen(inputFile, "r");
	int i;
	account *accountsArray;

	fscanf(file, "%d", size);

	accountsArray = malloc(sizeof(account) * *size);

	for(i = 0; i < *size; i++)
	{
		accountsArray[i].name  = malloc(sizeof(char) * MAX_STRING_LEN);

		fscanf(file, "%d", &accountsArray[i].accountId);
		fscanf(file, "%s", accountsArray[i].name);
		fscanf(file, "%lf", &accountsArray[i].amount);
	}

	fclose(file);
	return accountsArray;
}

/* ===============================================
Function: find_accounts 
	Parameters: accounts - An array of accounts
				size - The length of the array
				accountId - The account to be searched for
	Return: A pointer to an account with the given id, 
			NULL if not found

	This function will search for the account with the specified
accountId and return a pointer to it. If the account does not
exsist it will return NULL
=============================================== */
account* find_account(account *accounts, int size, int accountId)
{
	int i;

	for(i = 0; i < size; i++)
	{
		if(accounts[i].accountId == accountId)
		{
			return &accounts[i];
		}
	}

	//Only runs if accountId is not found
	return NULL;
}

/* ===============================================
Function: update_accounts 
	Parameters: updateFile - A file containing transaction to update 
							 the accounts
				accounts - An array of accounts
				size - The length of the array
	Return: None

	This function will read from the file specified by the updateFile 
parameter and on each line read in an accountId and transaction 
(either positive or negative). It will use find_account to find the 
specified account and then if found update the amount accordingly.
=============================================== */
void update_accounts(char *updateFile, account *accounts, int size)
{
	FILE *file = fopen(updateFile, "r");
	int i, transNum, searchId;
	double transAmt;
	account *matchingAcct;

	fscanf(file, "%d", &transNum);

	for(i = 0; i < transNum; i++)
	{
		fscanf(file, "%d %lf", &searchId, &transAmt);
		matchingAcct = find_account(accounts, size, searchId);
		if(matchingAcct != NULL)
		{
			matchingAcct->amount += transAmt;
		}
	}

	fclose(file);
	return;
}

/* ===============================================
Function: write_accounts 
	Parameters: outputFile - The name of the file to write to
				accounts - An array of accounts
				size - The length of the array
	Return: None

	This function will write the new accounts to the given output file.
=============================================== */
void write_accounts(char *outputFile, account *accounts, int size)
{
	FILE *file = fopen(outputFile, "w");
	int i;

	for(i = 0; i < size; i++)
	{
		fprintf(file, "%d %s %lf\n", 
				accounts[i].accountId, 
				accounts[i].name, 
				accounts[i].amount);
	}

	fclose(file);
	return;
}

/* ===============================================
Function: free_accounts 
	Parameters: accounts - An array of accounts
				size - The length of the array
	Return: None

	This function will free all malloced memory
=============================================== */
void free_accounts(account *accounts, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		free(accounts[i].name);
	}

	free(accounts);

	return;
}

/* ===============================================
Function: sort 
	Parameters: accounts - An array of accounts
				size - The length of the array
	Return: None

	This function will sort the accounts based on 
amount before writing to the file using selection sort. 
=============================================== */
void sort(account *accounts, int size)
{
	int i, j;
	int minIndex;
	account holdAcct;

	for(i = 0; i < (size - 1); i++)
	{
		minIndex = i;

		for(j = (i + 1); j < (size - 1); j++)
		{
			if(accounts[j].amount < accounts[minIndex].amount)
			{
				minIndex = j;
			}
		}
		if(minIndex != i)
		{
			holdAcct = accounts[i];
			accounts[i] = accounts[minIndex];
			accounts[minIndex] = holdAcct;
		}
	}

	return;
}
							

