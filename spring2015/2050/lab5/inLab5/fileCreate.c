#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	srand(time(NULL));
	int numOfNums, i;

	FILE *fp = fopen("coolInput.txt", "w");
	printf("How many random numbers do you want? ");
	scanf("%d", &numOfNums);

	fprintf(fp, "%d", numOfNums);
	for(i = 0; i < numOfNums; i++)
	{
		fprintf(fp, "\n%d", (rand() % 30));
	}

	printf("Output Finished as coolInput.txt\n");

	return 0;
}


