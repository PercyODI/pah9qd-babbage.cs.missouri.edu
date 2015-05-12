/* Pearse Hutson
 * Prelab 3
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int accountId;
	char *name;
	double amount;
} Account;

Account* readFile(char *inputFile, int *size);
void printAccounts(Account *accountArray, int size);
//void writeAccounts(*Account accountArray, int size);

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Error: Invalid number of arguments\n");
		return 0;
	}

	int size, i;
	Account *accountArray;

	accountArray = readFile(argv[1], &size);

	printAccounts(accountArray, size);

	for(i = 0; i < size; i++)
	{
		free((accountArray + i)->name);
	}
	free(accountArray);
	return 0;
}

Account* readFile(char *inputFile, int *size)
{
	int i;
	Account *accountArray;
	FILE *file = fopen(inputFile, "r");
	fscanf(file, "%d", size);

	accountArray = malloc(sizeof(Account) * *size);
	for(i = 0; i < *size; i++)
	{
		accountArray[i].name = malloc(sizeof(char)*50);
	}

	//char name[50];

	for(i = 0; i < *size; i++)
	{
		fscanf( file, "%d %s %lf", 
				&accountArray[i].accountId, 
				accountArray[i].name, 
				&accountArray[i].amount);


		//accountArray[i].name = name;
	}

	fclose(file);

	return accountArray;
}


void printAccounts(Account *accountArray, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		printf("%d %s %.2f\n", 
				accountArray[i].accountId, 
				accountArray[i].name, 
				accountArray[i].amount);;
	}

}

