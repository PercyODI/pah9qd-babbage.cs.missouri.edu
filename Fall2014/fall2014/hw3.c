/* Pearse Hutson
 * Pawprint: pah9qd
 * Homework 3
 */

//Included libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Global Definitions
#define MAX 100

//Function Prototypes
void display_menu();
int check_option(int option);
int check_size(int size);
void initialize_2Darray(int x[][MAX], int size);
void print_2Darray(int x[][MAX], int size);
void initialize_1Darray(int y[], int size);
void print_1Darray(int y[], int size);
int search_min(int x[][MAX], int r, int c, int size);
int count_match(int x[][MAX], int y[], int size, int r);
int closest_row(int x[][MAX], int y[], int size);
void sort_1Darray(int y[], int size);
void sort_2Darray(int x[][MAX], int size);

//Program Begin
int main(void)
{
	//Local Variables
	int mainSize, mainOption;

	//Receive and check user-selected size
	printf("\nEnter the size: ");
	scanf("%d", &mainSize);
	while(check_size(mainSize) == 0)
	{
		printf("Invalid input enter the size of the array again: ");
		scanf("%d", &mainSize);
	}
	
	//Display menu, take and check user option
	display_menu();
	scanf("%d", &mainOption);
	while(check_option(mainOption) == 0)
	{
		printf("Invalid input: Enter the operation you want to perform: ");
		scanf("%d", &mainOption);
	}

	//Perform function based on user choice
	switch(mainOption)
	{
		case 1: 
			// Perform Search Min Function

			break;
		case 2:
			// Perform Count Matches Function

			break;
		case 3:
			// Perform Closest Row Function
			
			break;
		case 4:
			// Perform Sort 1D Array Function

			break;
		case 5:
			// Perform Sort 2D Array Function

			break;
		case 6:
			// Exit Program
			
			break;
		case default:
			// Invalid input - Error
			printf( "\n"
					"*********************************\n\n"
					" Error: Invalid Switch Condition \n\n"
					"*********************************\n");


	return 0;
}

void display_menu()
{

}

int check_option(int option)
{

}

int check_size(int size)
{

}

void initialize_2Darray(int x[][MAX], int size)
{

}

void print_2Darray(int x[][MAX], int size)
{

}

void initialize_1Darray(int y[], int size)
{

}

void print_1Darray(int y[], int size)
{

}

int search_min(int x[][MAX], int r, int c, int size)
{

}

int count_match(int x[][MAX], int y[], int size, int r)
{

}

int closest_row(int x[][MAX], int y[], int size)
{

}

void sort_1Darray(int y[], int size)
{

}

void sort_2Darray(int x[][MAX], int size)
{

}
