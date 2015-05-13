/* Fig. 2.13: fig02_13.c
 * Using if statements, relational
 * operators, and equality operators.
 */

#include <stdio.h>

//funtion main begins program execution
int main( void )
{
	int num1, num2;

	printf( "Enter two integers, and I will tell you\n" );
	printf( "the relationship they satisfy: " );
	scanf( "%d%d", &num1, &num2 );

	if ( num1 == num2 ) {
		printf( "%d is equal to %d\n", num1, num2 );
	}

	if ( num1 != num2 ) {
		printf( "%d is not equal to %d\n", num1, num2 );
	}
	if ( num1 < num2 ) {
		printf( "%d is less than %d\n", num1, num2 );
	}
	if ( num1 > num2 ) {
		printf( "%d is more than %d\n", num1, num2 );
	}
	if ( num1 <= num2 ) {
		printf( "%d is less than or equal to %d\n", num1, num2 );
	}
	if ( num1 >= num2 ) {
		printf( "%d is greater than or equal to %d\n", num1, num2 );
	}
}
