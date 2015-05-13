/*Pre Lab 4
 * Pearse Hutson
 * pah9qd
 */

#include <stdio.h>
#include <math.h>

int squareArea(int length);

int cubeArea(int length);

float circleArea(int radius);

int main(void)
{
	int menuChoice = 0, positiveNum = 0;

	while (menuChoice < 1 || menuChoice > 3)
	{
		printf("\n\n");//set initial spaces
		printf("Area Calculation\n");
		printf("(1) Square\n");
		printf("(2) Cube\n");
		printf("(3) Circle\n");
		printf("Please make a selection: ");
		scanf("%d", &menuChoice);

		if (menuChoice < 1 || menuChoice > 3)
		{
			printf("Incorrect choice");
		}
	}

	printf("\n");
	while (positiveNum < 1)
	{
		printf("Enter a positive number: ");
		scanf("%d", &positiveNum);
		
		if (positiveNum < 1)
		{
			printf("Number can't be negative or zero\n");
		}
	}

	printf("\n"); //Formatting

	switch (menuChoice) //Decide which function to call based on menu choice
	{
		case 1:
			squareArea(positiveNum);
			break;
		case 2:
			cubeArea(positiveNum);
			break;
		case 3:
			circleArea(positiveNum);
			break;
		default:
			printf("Error in Switch Detection. Goodbye.");
			break;
	}

	printf("\n\n"); //Formatting
	return 0;	
}

int squareArea(int length)
{
	printf("Length of the side of square is %d\n", length);
	printf("Area of square is %d", length * length);
}

int cubeArea(int length)
{
	printf("Length of the side of the cube is %d\n", length);
	printf("Area of cube is %d", 6 * length * length);
}

float circleArea(radius)
{
	printf("Radius of circle is %d\n", radius);
	printf("Area of circle is %.2f", 3.14159 * radius * radius);
}
