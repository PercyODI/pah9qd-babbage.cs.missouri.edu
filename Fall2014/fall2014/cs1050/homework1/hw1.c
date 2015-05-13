/* Pearse Hutson
 * Pawprint: pah9qd
 * Homework1
 */

#include <stdio.h>

//Global Variable
int filingStatus;

//Function Prototypes
int taxCalculations(void);
int menu(void);

int main(void)
{
	//Prime the pump with the menu	
	menu();
	
	while(filingStatus != 0)
	{
		//Perform tax calculations and print the results
		taxCalculations();

		//Show the menu again
		menu();
	}

	printf("\n");
	printf("Exiting the tax calculator\n");
	return 0;
}

int menu(void)
{
	printf("\n");
	printf("Filing Status\n");
	printf("(1) Single\n");
	printf("(2) Married\n");
	printf("(3) Head of Household\n");
	printf("(0) Quit Program\n");
	printf("Please make selection: ");
	scanf("%d", &filingStatus);
	while(filingStatus < 0 || filingStatus > 3)
	{
		printf("Invalid choice, make a selection again: ");
		scanf("%d", &filingStatus);
		
		//Extra line to conform to expected output layout
		if(filingStatus >= 0 && filingStatus <= 3)
		{
			printf("\n");
		}
	}
	
	return filingStatus;
}

int taxCalculations(void)
{
	int annualIncome;
	float taxRate, taxes, netIncome;

	printf("Enter the annual income: ");
	scanf("%d", &annualIncome);
	while(annualIncome <= 0)
	{
		printf("Invalid income, enter the income again: ");
		scanf("%d", &annualIncome);
	}
	//Determine tax rate by menu choice
	switch(filingStatus)
	{
		case 1:
			if (annualIncome < 20000)
			{
				taxRate = 0.1;
			}
			else if(annualIncome >= 20000 && annualIncome < 50000)
			{
				taxRate = 0.2;
			}
			else if(annualIncome >= 50000 && annualIncome < 100000)
			{
				taxRate = 0.3;
			}
			else if(annualIncome >= 100000 && annualIncome < 250000)
			{
				taxRate = 0.35;
			}
			else //annualIncome > 250000
			{
				taxRate = 0.4;
			}
			break;
	
		case 2:
			if(annualIncome < 30000)
			{
				taxRate = 0.1;
			}
			else if(annualIncome >= 30000 && annualIncome < 60000)
			{
				taxRate = 0.2;
			}
			else if(annualIncome >= 60000 && annualIncome < 125000)
			{
				taxRate = 0.3;
			}
			else if(annualIncome >= 125000 && annualIncome < 300000)
			{
				taxRate = 0.35;
			}
			else //annualIncome >= 300000
			{
				taxRate = 0.4;
			}
			break;

		case 3:
			if(annualIncome < 50000)
			{
				taxRate = 0.1;
			}
			else if(annualIncome >= 50000 && annualIncome < 100000)
			{
				taxRate = 0.2;
			}
			else if(annualIncome >= 100000 && annualIncome < 250000)
			{
				taxRate = 0.3;
			}
			else if(annualIncome >= 250000 && annualIncome < 500000)
			{
				taxRate = 0.35;
			}
			else //annualIncome >= 500000
			{
				taxRate = 0.4;
			}
			break;

		default:
			printf("Error in Filing Status. Please Try Again!");
			break;
	}

	//Tax Calculations
	taxes = annualIncome * taxRate;
	netIncome = annualIncome - taxes;

	//Print results of Calculations
	printf("\n");
	printf("Your tax rate is: %.0f%%\n", taxRate * 100);
	printf("You pay $%.2f in taxes\n", taxes);
	printf("After taxes your net income is: $%.2f\n", netIncome);
}
