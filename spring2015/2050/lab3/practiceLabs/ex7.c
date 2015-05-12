#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//Creates two sample files for use with exercise 8
	
	char cont;

	printf("Warning: This program will overwrite any existing dat files.\n");
	printf("Do you want to continue?");
   	scanf("%c", &cont);

	if(cont != 'y' && cont != 'Y')
	{
		printf("Exiting Program without writing new files\n");
		return 0;
	}

	printf("Writing new files\n\n");
	FILE *masterFile = fopen("oldmast.dat", "w");
	FILE *transFile = fopen("trans.dat", "w");

	fprintf(masterFile, "100 Alan Jones 348.17\n300 Mary Smith 27.19\n500 Sam Sharp 0.00\n700 suzy Green -14.22");
	printf("oldmast.dat created\n");

	fprintf(transFile, "100 27.14\n300 62.11\n400 100.56\n900 82.17");
	printf("trans.dat created\n");

	fclose(masterFile);
	fclose(transFile);
	return 0;
}
