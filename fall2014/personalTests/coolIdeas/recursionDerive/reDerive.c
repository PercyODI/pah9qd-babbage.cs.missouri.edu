#include <stdio.h>
#include <string.h>

int main(void)
{
	//This program should be able to recursively determine several 
	//derivitives. 
	
	int coeff, n;

	printf("Enter your simple formula:\n");
	scanf("%d", &coeff);
	printf("x^");
	scanf("%d", &n);

	deriveFunction(coeff, n);
	
	return 0;
}	

deriveFunction(int coeff, int n, const char * argv[])
{
	int i;
	int constantn = n;
	char deriveNum[20] = "'";
	char deriveNum1[20] = "";

	for(i = 1; i < constantn; ++i)
	{
		coeff = coeff * n;
		n = n - 1;
		strcat("'", deriveNum);
		printf("f%s = %dx^%d\n", deriveNum, coeff, n);
	}
}

