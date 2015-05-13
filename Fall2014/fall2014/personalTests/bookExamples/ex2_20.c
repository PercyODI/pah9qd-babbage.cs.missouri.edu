/*
 * Example 2.20
 * Page 67
*/

#include <stdio.h>

int main( void )
{

	float radius, area;
	
	printf("Enter radius of the circle: ");
	scanf("%f", &radius);

	printf("Diameter: %f\n", radius * 2);
	printf("Circumference: %f\n", 2 * 3.14159 * radius);
	printf("Area: %f\n", 3.14159 * (radius * radius));

	return 0;
}
