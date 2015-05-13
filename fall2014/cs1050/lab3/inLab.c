#include <stdio.h>


int main(void)
{
	int i = 1;

	while(i != 0)
	{
		printf("Please enter zero: ");
		scanf("%d", &i);

		if(i != 0)
		{
			printf("Lex Luthor says WRONG!\n");
		}
	}

	printf("Yay! You did it!");

	return 0;
}
