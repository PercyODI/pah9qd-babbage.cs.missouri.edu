/*
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

typedef struct {
	int *first;
	int *second;
	int *third;
} Arrays;

Arrays generate_arrays(int len);

int main(void)
{
	Arrays threeArrays;
	int len;
	struct timeval tv;
	double t1, t2, duration;
	
	srand(time(NULL));

	FILE *fp = fopen("output.txt", "w");

	len = 0;
	do
	{

	//printf("What to use for len? ");
	//scanf("%d", &len);
	if(len < 10)
		len++;
	else if(len < 100)
		len += 10;
	else if(len < 1000)
		len += 100;
	else if(len < 10000)
		len += 1000;
	else if(len < 100000)
		len += 10000;
	else if(len < 1000000)
		len += 100000;
	else if(len < 10000000)
		len += 1000000;
	else if(len < 100000000)
		len += 10000000;
	else
		len = -1;

	gettimeofday(&tv, NULL);
	t1 = tv.tv_sec+(tv.tv_usec/1000000.0);

	threeArrays = generate_arrays(len);

	gettimeofday(&tv, NULL);
	t2 = tv.tv_sec+(tv.tv_usec/1000000.0);
	duration = (t2 - t1) * 1000;
	/*
	printf("\nFirst: \n");
	for(i = 0; i < len; i++)
	{
		printf("%3d ", threeArrays.first[i]);
	}
	printf("\nSecond: \n");
	for(i = 0; i < len; i++)
	{
		printf("%3d ", threeArrays.second[i]);
	}
	printf("\nThird: \n");
	for(i = 0; i < len; i++)
	{
		printf("%3d ", threeArrays.third[i]);
	}
	
	printf("\n");
	*/
	printf("\nThe gererate_array function took %f milliseconds to complete\n\n", duration);

	fprintf(fp, "%d, %f,\n", len, duration);

	free(threeArrays.first);
	free(threeArrays.second);
	free(threeArrays.third);
	} while(len > 0);
	fclose(fp);
	return 0;
	
}

Arrays generate_arrays(int len)
{
	int i;
	Arrays threeArrays;

	/*	
	for(i = 0; i < 3; i++)
	{
		if(i == 0)
		{
			threeArrays.first = malloc(sizeof(int) * len);
			for(j = 0; j < len; j++)
			{	
				threeArrays.first[j] = rand() % len + 1;
			}
		}
		else if(i == 1)
		{
			threeArrays.second = malloc(sizeof(int) * len);
			for(j = 0; j < len; j++)
			{	
				threeArrays.second[j] = rand() % len + 1;
			}
		}
		else
		{
			threeArrays.third = malloc(sizeof(int) * len);
			for(j = 0; j < len; j++)
			{	
				threeArrays.third[j] = rand() % len + 1;
			}
		}
	}
	*/
	
	threeArrays.first = malloc(sizeof(int) * len);
	threeArrays.second = malloc(sizeof(int) * len);
	threeArrays.third = malloc(sizeof(int) * len);

	for(i = 0; i < len; i++)
	{
		threeArrays.first[i] = rand() % len + 1;
		threeArrays.second[i] = rand() % len + 1;
		threeArrays.third[i] = rand() % len + 1;
	}

	return threeArrays;
}
