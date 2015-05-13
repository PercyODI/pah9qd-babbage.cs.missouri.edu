/* Pearse Hutson
 * Pawprint: pah9qd
 * Lab: D
 * Submission Code: notjustabreedofdog
 * Date: 11.3.2014
 */

//Included Libraries
#include <stdio.h>

//Function Prototypes
int length(char *s);
int replace(char *s, int i);
void copy(char *s, char *s2);
void merge(char *s, char *s1, char *s2);
void reverse(char *s, char *s2);
int prefix(char *s, char *s2);
int palindrome(char *s, char *revStr);

//Program begins
int main(void)
{
	//Local variables
	char firstString[50];
	char secondString[50];
	char prefixString[50];
	char changingString[50];
	char reverseString[50];
	int replacePosition;
	int replaceReturnCode;
	int prefixReturnCode;
	int palindromeReturnCode;

	//Ask for firstString and print firstString and length of firstString
	printf("\nEnter the first string: ");
	scanf("%s", firstString);
	printf("\nFirst string is %s\n", firstString);
	printf("Length of the string is %d\n", length(firstString));
	
	//Call copy function and copy to changingString
	copy(firstString, changingString);
	printf("Copy of the first string is %s\n\n", changingString);

	//Replaces one value in the string to #
	printf("Enter a position for the replacement operation (1-6): ");
	scanf("%d", &replacePosition);
	replaceReturnCode = replace(firstString, replacePosition);
	if(replaceReturnCode == 0) //Invalid position (less than 0 or greater than length of array)
		printf("Invalid position\n\n");
	else //Valid position
		printf("String after replacement operation is %s\n\n", firstString);

	//Ask for secondString and apply merge to firstString and secondString
	printf("Enter second string: ");
	scanf("%s", secondString);
	printf("\nSecond string is %s\n", secondString);
	merge(firstString, secondString, changingString);
	printf("Merged string is %s\n", changingString);
	
	//Applies reverse function to firstString
	reverse(firstString, reverseString);
	printf("Reverse of the string %s is %s\n\n", firstString, reverseString);
	
	//Performs prefix function
	printf("Enter a string for the prefix operation: ");
	scanf("%s", prefixString);
	printf("Enter a string to check for prefix: ");
	scanf("%s", changingString);
	prefixReturnCode = prefix(prefixString, changingString);
	if(prefixReturnCode == 1)
		printf("%s is a prefix of the string %s\n\n", changingString, prefixString);
	else
		printf("%s is not a prefix of the string %s\n\n", changingString, prefixString);

	//Bonus Part
	printf("Bonus Part\n\n");

	//Ask for string to check
	printf("Enter a string for the palindrome operation: ");
	scanf("%s", changingString);

	//Creates a reversed copy of user's string
	reverse(changingString, reverseString);

	//Checks if user's copy is equal to reversed copy (palindrome)
	palindromeReturnCode = palindrome(changingString, reverseString);
	if(palindromeReturnCode == 1)
		printf("%s is a palindrome\n\n", changingString);
	else
		printf("%s is not a palindrome\n\n", changingString);
	
	return 0;
		
}

//Functions
int length(char *s)
{
	//Returns the length of the string.
	//Determines length by counting elements
	//until the null terminator is reached

	int stringLength = 0;

	while(*s != '\0')
	{
		stringLength++;
		s++;
	}

	return stringLength;
}

int replace(char *s, int i)
{
	//Replaces one element of the user's choice
	//in the array with '#'

	i = i - 1; //Converts i to array notation

	if(i < 0 || i > (length(s) - 1))
		return 0; //Invalid position. Do not perform function

	s += i; //Sets memory location to user choice
	*s = '#';

	return 1;
}
	
void copy(char *s, char *s2)
{
	//Copies the user string into another string
	//Will only produce exact copy until null
	//terminator is reached
	
	while(*s != '\0')
	{
		*s2 = *s;
		s2++;
		s++;
	}

	*s2 = '\0';
}

void merge(char *s, char *s1, char *s2)
{
	//Merges two strings together as a new string.
	//Will only change s2
	
	//Copies contents of s to s2
	while(*s != '\0')
	{
		*s2 = *s;
		s2++;
		s++;
	}
	//Copies contents of s1 to next part of s2 (does not overwrite s)
	while(*s1 != '\0')
	{
		*s2 = *s1;
		s2++;
		s1++;
	}

	//Add null terminator to end of string
	*s2 = '\0';
}
void reverse(char *s, char *s2)
{
	//Reverses given string into a new string
	
	//Local variables
	int counter = 0;

	//Find null terminator in s
	while(*s != '\0')
	{
		s++;
		counter++;
	}

	//Set s back one space to the last character
	s--;

	//Put characters in s2 from s in reverse order
	while(counter > 0)
	{
		*s2 = *s;
		s2++;
		s--;
		counter--;
	}

	*s2 = '\0';
}

int prefix(char *s, char *s2)
{
	//Checks s to see if s2 is found as a prefix
	
	//Perfoms while until either array hits 
	//the null terminator
	while(*s2 != '\0' && *s != '\0')
	{
		if(*s2 != *s)
			return 0; //s2 is not a prefix of s
		s2++;
		s++;
	}
	
	return 1; //Only returns 1 if s2 is a prefix of s
}

int palindrome(char *s, char *revStr)
{
	//Checks s to see if it is a palindrome 
	//by comparing it to revStr.
	while(*s != '\0')
	{
		if(*s != *revStr)
			return 0; //s is not a palindrome
		
		s++;
		revStr++;
	}

	return 1; //Only returns 1 if s is a palindrome
}
