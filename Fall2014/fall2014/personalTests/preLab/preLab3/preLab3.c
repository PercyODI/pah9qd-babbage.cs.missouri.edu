#include <stdio.h>

int main(void)
{
	int num1 = -1, num2 = 0;
	
	system("clear");

	printf("\nEnter a positive number: ");
	scanf("%d", &num1);
	
	while(num1 <= 0)
	{
		printf("Number should be positive enter the number again: ");
		scanf("%d", &num1);
	}

	printf("\nThe positive number entered is %d\n", num1);
	
	printf("\nSentinel controlled loop\n");

	while(num2 != -1)
	{
		printf("\nEnter a number (-1 to exit): ");
		scanf("%d", &num2);

		printf("The number entered is %d\n", num2);
	}
	
	printf("\nExiting the program\n\n");
	return 0;
}
