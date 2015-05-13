#include<stdio.h>
#include<stdlib.h>

int load_data(char*, int *, float *);
void print_data(int size, int *x, float *y);
//void clear(void *);

int main(int argc, char** argv)
{
	if(argc != 3)
	{
		printf("\nInsufficient arguments\n");
		return 0;
	}

	int n = atoi(argv[2]);

	int *acn;
	float *amt;
	int size;

	acn = malloc(sizeof(int) * n);
	amt = malloc(sizeof(float) * n);

	size = load_data(argv[1], acn, amt);
	
	if(size == 0)
	{
		printf("\nUnable to open the input file\n");
		return 0;
	}

	print_data(size, acn, amt);

	free(acn);
	free(amt);

	return 0;
}

int load_data(char* filename, int *x, float *y)
{
	int i = 0;

	FILE *file = fopen(filename, "r");

	if(file == NULL)
	{
		return 0;
	}

	int size;

	fscanf(file, "%d", &size);

	for(i = 0; i < size;  i++)
	{
		fscanf(file, "%d %f", x, y);
		x++;
		y++;
	}

	fclose(file);
	return size;
}

void print_data(int size, int *x, float *y)
{
	int i;

	printf("%-10s%-10s\n", "Account", "Balance");

	for(i = 0; i < size; i++)
	{
		printf("%-10d%-10.2f\n", *x, *y);
		x++;
		y++;
	}
}

//clear(void *x)
//{
//	free(x);
//}
