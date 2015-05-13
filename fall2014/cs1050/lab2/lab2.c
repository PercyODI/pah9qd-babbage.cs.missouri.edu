/* Pearse Hutson
 * Pawprint: pah9qd
 * Lab1
 * Submission Code: DASHLM
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	int side1, side2, side3, shortSide, longSide;
	float p, area;
	
	//Ask user for Side 1 and verify it is a positive number
	printf("\nEnter the first side: ");
	scanf("%d", &side1);
	while(side1 <= 0)
	{
		printf("Invalid value enter the side again: ");
		scanf("%d", &side1);
	}

	//Ask user for Side 2 and verify it is a positive number
	printf("\nEnter the second side: ");
	scanf("%d", &side2);
	while(side2 <= 0)
	{
		printf("Invalid value enter the side again: ");
		scanf("%d", &side2);
	}
	
	//Ask user for Side 3 and verify it is ia positive number
	printf("\nEnter the third side: ");
	scanf("%d", &side3);
	while(side3 <= 0)
	{
		printf("Invalid value enter the side again: ");
		scanf("%d", &side3);
	}
	
	//Perform Area Calculation
	p = (((float)side1 + side2 + side3) / 2);
	area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
	
	//Output the Calculation Information
	printf("\nArea of the triangle is %f\n", area);

	printf("\nBonus Part\n");
	
	//Ask user for Side 1 and verify it is a positive number
	printf("\nEnter the first side: ");
	scanf("%d", &side1);
	while(side1 <= 0)
	{
		printf("Invalid value enter the side again: ");
		scanf("%d", &side1);
	}

	//Ask user for Side 2 and verify it is a positive number
	printf("Enter the second side: ");
	scanf("%d", &side2);
	while(side2 <= 0)
	{
		printf("Invalid value enter the side again: ");
		scanf("%d", &side2);
	}
	
	//Ask user for Side 3 and verify it is ia positive number
	printf("Enter the third side: ");
	scanf("%d", &side3);
	while(side3 <= 0)
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

		//Determine Triangle Type
		if(side1 == side2 && side1 == side3)
		{
			printf("Triangle is an equilateral triangle\n");
		}
		else if(side1 != side2 && side1 != side3 && side2 != side3)
		{
			printf("Triangle is a scalene triangle\n");
		}
		else
		{
			printf("Traingle is a isosceles triangle\n");
		}

		//Compute and print the longest side
		longSide = side1;
		if(longSide < side2)
		{
			longSide = side2;
		}
		if(longSide < side3)
		{
			longSide = side3;
		}
		printf("Length of the longest side of triangle is %d\n", longSide);

		//Compute and print the shortest side
		shortSide = side1;
		if(shortSide > side2)
		{
			shortSide = side2;
		}
		if(shortSide > side3)
		{
			shortSide = side3;
		}
		printf("Length of the shortest side of triangle is %d\n", shortSide);
	}
	//If the three sides do not satisfy triangle inequality,
	//do not complete calculations and print this instead
	else
	{
		printf("\nThree sides do not form a triangle\n");
	}

	//Add a blank line before command line returns
	printf("\n");
	return 0;
}
