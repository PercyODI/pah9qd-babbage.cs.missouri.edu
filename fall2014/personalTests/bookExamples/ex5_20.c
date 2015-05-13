
#include <stdio.h>

int main(void)
{
	//Local Variables
	int side, x, y;
	char fillCharacter;

	//Ask user for side length and charater choice
	printf("\nEnter a value for side length: ");
	scanf("%d", &side);	
	printf("Enter a character to use: ");
	getchar();
	fillCharacter = getchar();
	printf("\n\n\n");

	//Print square based on user entries
	for(x = 1; x <= side; x++)
	{
		for(y = 1; y <= side; y++)
		{	
			printf("%c", fillCharacter);
		}
		printf("\n");
	}

}
