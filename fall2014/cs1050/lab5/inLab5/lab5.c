/* Pearse Hutson
 * pah9qd
 * Lab5
 * Submission Code: trickyprintresult
 * 10.16.14
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function Prototypes
int generateNumber(void);
int errorCheck(int option);
int checkGuess(int guess, int answer);
void printResult(int result, int answer);
void printFinalResult(int numCorrect, int numTries);
void displayMenu(void);

//Global Variables

//Main Function
int main(void)
{
	//Local Variables
	int userChoice, answer, result, playAgain, numCorrect, numTries;

	//Initialize random seed
	srand(time(NULL));

	while (playAgain != 0)
	{
		//Display menu
		displayMenu();
		printf("\n\nEnter your guess: ");
		scanf("%d", &userChoice);
		while(errorCheck(userChoice) == 0)
		{
			printf("Invalid guess, enter your choice again: ");
			scanf("%d", &userChoice);
		}

		//Create coin flip based on rand()
		answer = generateNumber();
		result = checkGuess(userChoice, answer);
		
		//Increase counters for final results
		if(result == 1)
		{
			++numCorrect;
			++numTries;
		}
		else
		{
			++numTries;
		}

		printResult(result, answer);
		
		//Play Again Menu
		do
		{
			printf("Do you want to play again? (1 yes, 0 no) ");
			scanf("%d", &playAgain);
		} while(errorCheck(playAgain) == 0);
	}

	printFinalResult(numCorrect, numTries);

	return 0;
}

//Functions
int generateNumber(void)
{
	//Randomly returns either 0 or 1
	return rand() % 2;
}

void displayMenu(void)
{
	//Shows the user the menu choices
	printf("\nPlease Take a guess");
	printf("\n0 : Heads");
	printf("\n1 : Tails");
}

int errorCheck(int option)
{
	//Checks menu options to user's choice. 
	if(option == 1 || option == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int checkGuess(int guess, int answer)
{
	//Determines if the user was correct (1) or incorrect (0)
	if(guess == answer) //User was correct
	{
		return 1;
	}
	else //User was incorrect
	{
		return 0;
	}
}

void printResult(int result, int answer)
{
	//Chooses correct response to show user
	if(result == 1 && answer == 0)
	{
		printf("\nYour choice was heads and it is a correct guess!\n");
	}
	else if(result == 1 && answer == 1)
	{
		printf("\nYour choice was tails and it is a correct guess!\n");
	}
	else if(result == 0 && answer == 0)
	{
		printf("\nYour choice was tails and it is an incorrect guess.\n");
	}
	else if(result == 0 && answer == 1)
	{
		printf("\nYour choice was heads and it is an incorrect guess.\n");
	}
	else
	{
		printf("\n\n\nError in printResult()\n\n\n");
	}
}

void printFinalResult(int numCorrect, int numTries)
{
	//Calculates the player's percentage
	float percentScore;
	percentScore = ((float)numCorrect / numTries) * 100;

	//Shows user their totals for the entire game
	printf("\nYou have made %d correct guesses in %d tries.", numCorrect, numTries);
	printf("\nYour winning percentage is %.2f%%\n\n", percentScore);
}
