/*
 * Pearse Hutson
 * pah9qd
 * 9.7.14
 * Lab Code: 
 */

#include <stdio.h>

int main( void )
{
	int num1, num2;
	
	//Ask user for first number
	printf("Enter a Number: ");
	scanf("%d", &num1);

	//Check to see if the first number is positive
	if(num1 <= 0){
		printf("Invalid number enter the number again: ");
		scanf("%d", &num1);
	}
	
	//Ask user for second number
	printf("\nEnter a second number: ");
	scanf("%d", &num2);

	//Check to see if the second number is positive
	if(num2 <= 0){
		printf("Invalid number enter the number again: ");
		scanf("%d", &num2);
	}
	
	//Show user the product and addition of their two numbers
	printf("\nProduct of %d and %d is %d\n", num1, num2, num1 * num2);
	printf("Addition of %d and %d is %d\n", num1, num2, num1 + num2);

	//End Program
	return 0;
}
