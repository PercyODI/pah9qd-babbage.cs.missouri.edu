#include <stdio.h>

int main( void )
{
	int int1, int2, int3, sum, average, product, smallest, largest;	

	printf( "Enter three different integers: " );
	scanf( "%d%d%d", &int1, &int2, &int3 );

	sum = int1 + int2 + int3;

	average = sum / 3;

	product = int1 * int2 * int3;

	//Find Smallest Integer
	smallest = int1;
	if (int2 < smallest ) {
		smallest = int2;
	}
	if (int3 < smallest ) {
		smallest = int3;
	}
	
	//Find Largest Integer
	largest = int1;
	if ( int2 > largest ) {
		largest = int2;
	}
	if ( int3 > largest ) {
		largest = int3;
	}

	//Print Results
	printf( "Sum is %d\n", sum );
	printf( "Average is %d\n", average );
	printf( "Product is %d\n", product );
	printf( "Smallest is %d\n", smallest );
	printf( "Largests is %d\n", largest );
}
