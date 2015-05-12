#include <stdio.h>
#include <stdlib.h>

typedef struct  {
	int acctNum;
	char *firstName;
	char *lastName;
	float balance;
} Account;

Account* readFile(char *filename, int *size);

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("Invalid arguments\n");
		printf("Example format: ./a.out oldmast.dat trans.dat\n");
		return 0;
	}
	
	int size, i;
	Account *accountsArray;

	//Read oldmast into the accountsArray
	accountsArray = readFile(argv[1], &size);

	for(i = 0; i < size; i++)
	{
		printf("%d %s %s %f\n", 
				accountsArray[i].acctNum,
				accountsArray[i].firstName,
				accountsArray[i].lastName,
				accountsArray[i].balance);
	}



	return 0;
}

Account* readFile(char *filename, int *size)
{
	FILE *file = fopen(filename, 'r');
	Account *accountsArray;
	int size = 0;
	char *fname, *lname;

	while(!feof(file))
	{
		accountsArray = realloc(sizeof(Account) * size);
		fname = malloc(sizeof(char) * 50);
		lname = malloc(sizeof(char) * 50);

		fscanf(file, "%d %s %s %f", 
				&accountsArray[size].acctNum, fname, lname, &accountsArray[size].balance);

		accountsArray[size].firstName = fname;
		accountsArray[size].lastName = lname;

		size++;
	}

	fclose(file);
	free(fname);
	free(lname);

	return accountsArray;
}
