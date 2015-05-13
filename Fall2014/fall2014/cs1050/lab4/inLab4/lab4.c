/* Pearse Hutson
 * Pawprint: pah9qd
 * Lab 4
 * Submission Code: exponents 
 */

#include <stdio.h>

//Function Prototypes
float interestRateMenu(void);
int interestCalculations(float interestRate, int yearChoice, float amount);
float compute_power(float x, int y);

int main(void)
{
	//Local Variables
	int yearChoice = 0, exponent;
	float interestRate, amount, numToRaise;

	//Determine the interest rate to use
	interestRate = interestRateMenu();

	//Determine number of years to use
	while (yearChoice < 1 || yearChoice > 10)
	{
		printf("\n");
		printf("Enter a year: ");
		scanf("%d", &yearChoice);

		if (yearChoice < 1 || yearChoice > 10)
		{
			printf("In correct value year should be between 1-10\n");
		}
	}
	
	//Determine the starting amount
	printf("\n");
	printf("Enter the amount: ");
	scanf("%f", &amount);

	while (amount <= 0)
	{
		printf("Incorrect value enter the amount again: ");
		scanf("%f", &amount);
	}

	interestCalculations(interestRate, yearChoice, amount);

	//Bonus Part
	
	printf("\n");
	printf("Bonus part\n\n");
	//Ask user for a number to raise to a specified power
	printf("Enter a number: ");
	scanf("%f", &numToRaise);
	printf("\n");
	//Ask user for an exponent to raise the number to
	printf("Enter an exponent: ");
	scanf("%d", &exponent);
	printf("\n");
	if (exponent < 0)//If the number is negative, use more decimal precision
	{
		printf("pow(%.2f, %d)=%.5f", numToRaise, exponent, compute_power(numToRaise, exponent));
	}
	else//If the number is 0 or positive, use less decimal presision
	{		
		printf("pow(%.2f, %d)=%.2f", numToRaise, exponent, compute_power(numToRaise, exponent));
	}

	printf("\n\n");
	return 0;
}

float interestRateMenu(void)
{
	int menuChoice;

	//Display menu options and ask user for their choice until a correct
	//choice is selected
	while (menuChoice < 1 || menuChoice > 3)
	{
		printf("\n");
		printf("Bank account type\n");
		printf("\n");
		printf("(1) Checking\n");
		printf("(2) Saving\n");
		printf("(3) Fixed Deposit\n");
		printf("Please make a selection: ");
		scanf("%d", &menuChoice);

		if (menuChoice < 1 || menuChoice > 3)
		{
			printf("Incorrect a choice\n");
		}
	}

	//Determines Account Type and returns interest rate to main
	switch(menuChoice)
	{
		case 1://Checking Account at 1% interest
			return 0.01;
			break;

		case 2://Saving Account at 3% interest
			return 0.03;
			break;

		case 3://Fixed Deposit Account at 7% interest
			return 0.07;
			break;

		default:
			printf("Error in Switch Statement");
	}


}

int interestCalculations(float interestRate, int yearChoice, float amount)
{
	float amountWithInterest, interestEarned;

	//Compute the total amount with interest in the accout after a specified number
	//of years
	amountWithInterest = amount * compute_power(1 + (interestRate), yearChoice);
	interestEarned = amountWithInterest - amount;
	
	//Print the results of the calculations
	printf("\n");
	printf("Total amount after %d years is $%.2f\n", yearChoice, amountWithInterest);
	printf("Total interest earned on the amount $%.2f is $%.2f\n", amount, interestEarned);

}

float compute_power(float x, int n)
{
	int i;
	float origx = x;	

	if (n == 0)//Return 1 if raised to the 0th power
	{
		x = 1;
		return x;
	}
	else if (n > 0)//Return results for positve powers
	{
		for (i = 1; i < n; ++i)
		{
			x = x * origx;
		}
		return x;
	}
	else if (n < 0)//Return results for negative powers
	{
		x = 1 / x;
		for (i = -1; i > n; --i)
		{
			x = x / origx;
		}
		return x;
	}	
}
		
