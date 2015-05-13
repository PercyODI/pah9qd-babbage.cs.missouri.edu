/* Pearse Hutson
 * pah9qd
 * Homework 2
 * 10.17.14
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function Prototypes
void display_menu(void);
int errorCheck(int option);
int throw_dice(void);
int even_odd(int x, int option);
int lucky_seven(int x, int option);
int guess_number(int x, int guess);

//Start Program
int main(void)
{
	//Set Rand Seed
	srand(time(NULL));

	//Local Variables
	int gameChoice = 0;
	int gameOption, betAmount,  diceSum;
	int userMoney = 100;

	while(gameChoice != 4 && userMoney > 0)
	{
		//Display Menu
		do
		{
			display_menu();
			scanf("%d", &gameChoice);
			
			if (errorCheck(gameChoice) == 0)
			{
				printf("\nInvalid choice");
			}
		} while(errorCheck(gameChoice) == 0);

		//Determine which game to call
		switch(gameChoice)
		{
			case 1: //Even Odd Game
				printf("\n");
				printf("Take a guess (1)Even (2)Odd: ");
				scanf("%d", &gameOption);
				printf("\n");
				printf("You have $%d to bet.\n", userMoney);
				printf("How much do you want to bet: $");
				scanf("%d", &betAmount);
				printf("\n\n");
				diceSum = throw_dice();
				if (even_odd(diceSum, gameOption) == 1)
				{
					printf("You win! Your guess is correct. The sum of the dice is %d\n", diceSum);
					userMoney += betAmount * 2;
				}
				else
				{
					printf("You lost! Your guess is incorrect. The sum of the dice is %d\n", diceSum);
					userMoney -= betAmount;
				}
				break;
			
			case 2: //Lucky Seven Game
				printf("\n");
				printf("Enter your guess (1) Lucky 7 (2) above 7 (3) below 7: ");
				scanf("%d", &gameOption);
				printf("\n");
				printf("You have $%d to bet.\n", userMoney);
				printf("How much do you want to bet: $");
				scanf("%d", &betAmount);
				printf("\n\n");
				diceSum = throw_dice();
				if (lucky_seven(diceSum, gameOption) == 1)
				{
					printf("You win! Your guess is correct. The sum of the dice is %d\n", diceSum);
					if (gameOption == 1)
					{
						userMoney += betAmount * 7;
					}
					else
					{
						userMoney += betAmount * 2;
					}
				}
				else
				{
					printf("You lost! Your guess is incorrect. The sum of the dice is %d\n", diceSum);
					userMoney -= betAmount;
				}
				break;

			case 3: //Guess the Number game
				printf("\n");
				printf("Guess a number: ");
				scanf("%d", &gameOption);
				printf("\n");
				printf("You have $%d to bet.\n", userMoney);
				printf("How much do you want to bet: $");
				scanf("%d", &betAmount);
				printf("\n\n");
				diceSum = throw_dice();
				if (guess_number(diceSum, gameOption) == 1)
				{
					printf("You win! Your guess is %d correct. The sum of the dice is %d\n", gameOption, diceSum);
					userMoney += betAmount * 2;
				}
				else
				{
					printf("You lost! Your guess %d is incorrect. The sum of the dice is %d\n", gameOption, diceSum);
					userMoney -= betAmount;
				}
				break;

			default: //Exit the game
				break;
		}
	}//end of while loop		

	if (userMoney <= 0)
	{
		printf("You lost all of your money!");
	}

	printf("\n");
	printf("Total money after gambling is $%d\n", userMoney);

	return 0;
}

//Functions
void display_menu(void)
{
	printf("\n");
	printf("Welcome to the casino!\n");
	printf("Games you can play\n");
	printf("1: Even/Odd\n");
	printf("2: Lucky seven\n");
	printf("3: Guess the number\n");
	printf("4: Exit\n");
	printf("Please select an option: ");

	return;
}

int errorCheck(int option)
{
	if (option >= 1 && option <= 4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int throw_dice(void)
{
	int x, y;
	x = (rand() % 6) + 1;
	y = (rand() % 6) + 1;
	return x + y;
}

int even_odd(int x, int option)
{
	//Convert dice sum to 1 for evens and 2 for odds
	x = (x % 2) + 1;

	if (x == option)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int lucky_seven(int x, int option)
{
	if (option == 1 && x == 7) //Equal to 7 (Lucky 7!)
	{
		return 1;	
	}
	else if (option == 2 && x > 7) //Above 7
	{
		return 1;
	}
	else if (option == 3 && x < 7) //Below 7
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int guess_number(int x, int guess)
{
	if (x == guess)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
