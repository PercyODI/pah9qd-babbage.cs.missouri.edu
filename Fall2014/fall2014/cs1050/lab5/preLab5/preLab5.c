/* Important information here!
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funciton Prototypes
void displayMenu(void);
int errorCheck(int);
int generateNumber(void);
int cube(int);
float division(int, int);

int main(void)
{
	//Local Variables
	int x, y, largestNum, smallestNum, menuChoice;

	//Generate random numbers
	srand(time(NULL));
	
	//Display Menu and Determine Calculations to do
	do
	{
		displayMenu();
		printf("Enter your choice: ");
		scanf("%d", &menuChoice);
	} while (errorCheck(menuChoice) == 0);
	
	switch(menuChoice)
	{
		case 1: //Perform Cube Calculations
			x = generateNumber();
			printf("\nCube of %d is %d\n\n", x, cube(x));
			break;
		case 2: //Perform Division Calculations
			x = generateNumber();
			y = generateNumber();
			if (x > y)
			{
				largestNum = x;
				smallestNum = y;
			}
			else // y < x OR y = x where it doesn't matter
			{
				largestNum = y;
				smallestNum = x;
			}
			printf("\nDiv(%d,%d)=%.2f\n\n", largestNum, smallestNum, division(largestNum, smallestNum));
			break;
	}
}

void displayMenu(void)
{
	printf("\nPlease select an operation\n");
	printf("1 : Cube\n");
	printf("2 : Division\n");
}

int errorCheck(int menuChoice)
{
	if(menuChoice == 1 || menuChoice == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int generateNumber(void)
{
	return rand()%10;
}

int cube(int x)
{
	return x * x * x;
}

float division(int largestNum, int smallestNum)
{
	if (smallestNum == 0)
	{
		return 0.00;
	}
	else
	{
	return (float)largestNum / smallestNum;
	}
}
