
#include <stdio.h>

//Function Prototypes
unsigned long long int fibonacci(unsigned int n);

//Function main begins program execution
int main(void)
{
	unsigned long long int result; //fibonacci value
	unsigned int number, i; //number input by user

	//Obtain integer from user
	printf("%s", "Enter an integer: ");
	scanf("%u", &number);
		
	//Calculate fibonacci value for number input by user
	//result = fibonacci(number);
	//display result
	for(i = 1; i <= number; i++)
	{
		result = fibonacci(i);
		printf("Fibonacii(%u) is %llu\n", i, result);
	}
	//printf("Fibonacci(%u) = %llu\n", number, result);
}

//Recursive definition of function fibonacci
unsigned long long int fibonacci(unsigned int n)
{
	//Base Case
	if(n == 1 || n == 0)
	{
		return n;
	}
	else
	{
		return fibonacci(n-1) + fibonacci(n-2);
	}	
}	
