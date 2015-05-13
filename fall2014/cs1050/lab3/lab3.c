/* Pearse Hutson
 * Pawprint: pah9qd
 * Lab3
 * Submission Code: LINKMATHAGAIN
 */

#include <stdio.h>
#include <math.h>

int error_check(int y);

int main(void)
{
	int side1, side2, side3, exitCheck;
	float p, area;
	
	exitCheck = 0;

	while(exitCheck != -1)
	{
		//Ask user for Side 1 and verify it is a positive number
		printf("\nEnter the first side: ");
		scanf("%d", &side1);
		while(error_check(side1) != 0)
		{
			printf("Invalid value enter the side again: ");
			scanf("%d", &side1);
		}

		//Ask user for Side 2 and verify it is a positive number
		printf("\nEnter the second side: ");
		scanf("%d", &side2);
		while(error_check(side2) != 0)
		{
			printf("Invalid value enter the side again: ");
			scanf("%d", &side2);
		}
	
		//Ask user for Side 3 and verify it is ia positive number
		printf("\nEnter the third side: ");
		scanf("%d", &side3);
		while(error_check(side3) != 0)
		{
			printf("Invalid value enter the side again: ");
			scanf("%d", &side3);
		}
	
		//Verify the sides form a triangle and output the area if true
		if(side1 < (side2 + side3) && side2 < (side1 + side3) && side3 < (side1 + side2))
		{
			//Perform Area Calculation and print the Area
			p = (((float)side1 + side2 + side3) / 2);
			area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
			printf("\nArea of the triangle is %f\n", area);
		}
		else //If the three sides do not satisfy triangle inequality display this text
		{
			printf("\nThree sides do not form a triangle\n\n");
		}
		
		//Check if user wants to exit the program
		printf("Do you want to continue (type -1 to exit): ");
		scanf("%d", &exitCheck);
	}

	return 0;
}

int error_check(int y)
{
	if(y <= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

