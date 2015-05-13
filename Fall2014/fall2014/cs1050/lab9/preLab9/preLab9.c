/* Pearse Hutson
 *
 */

//Header Files
#include <stdio.h>
#include <stdlib.h>

//Definitions
#define MAX 100

//Function Prototypes
int length(char *s);
int replace(char *s, int i);
void copy(char *s, char *s2);

//Program Begins
int main(void)
{
	//Local Variables
	char string1[MAX], string2[MAX];
	int userPosition;

	printf("\n\n");
	printf("Enter a String : ");
	scanf("%s", &string1);
	printf("\n");
	printf("Input string is %s\n", string1);
	printf("Length of the string is %d\n", length(string1));

	copy(string1, string2);
	printf("Copy of input string is %s\n\n", string2);

	printf("Enter a position for the replacement operation(1-6): ");
	scanf("%d", &userPosition);

	replace(string1, userPosition);
	printf("\nString after replacement operation is %s\n\n", string1);

	return 0;
}

int length(char *s)
{
	int i;
	int strLength = 0;
	
	for(i = 0; *s != '\0'; i++)
	{
		strLength++;
		s++;
	}

	return strLength;
}


void copy(char *s, char *s2)
{
	int i;
	for(i = 0; *s != '\0'; i++)
	{
		*s2 = *s;
		s++;
		s2++;
	}
	*s2 = '\0'; //Sets the last character as the null terminator
}

int replace(char *s, int i)
{
	i = i - 1; //set to array notation
	int j;
	for(j = 0; j < i; j++)
	{
		s++;
	}

	*s = '#';
	return 1;
}

