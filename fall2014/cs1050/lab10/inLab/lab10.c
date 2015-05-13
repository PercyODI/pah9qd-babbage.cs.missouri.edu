/* Pearse Hutson
 * Pawprint: pah9qd
 * Lab: D
 * Submission Code: argvissimple
 * Date: 11.17.14
 */

#include <stdio.h>
#include <stdlib.h>

//Function Prototypes
int length(char *s);
char* copy(char *s);
char* reverse(char *s);
void clear(char *s);
int search(char *s, char c);
char* merge(char *s, char *s1);
char* new_merge(char *s1, char *s2);

int main(int argc, char **argv)
{
	//Check for correct number of arguments (2)
	if(argc < 2)
	{
		printf("\nNot enough parameters\n\n");
		return 0;
	}

	//Initial variables
	char *x = argv[1]; //Set x to address of argv[1]
	char *y = copy(x); //Set y to address of copy of argv[1]
	int len = length(x); //Set len to the length of x
	char searchChar;
	int searchResult;
	char mergingStr[100];
	char *mergedStrPtr;

	//Display inital values
	printf("\nFirst string is %s", x);
	printf("\nLength of the string is %d", len);
	printf("\nCopy of the first string is %s", y);

	//Perform reverse function
	char *rev = reverse(x);
	printf("\nReverse of the string %s is %s\n", x, rev);

	//Search Function
	printf("\nEnter a character for the search operation: ");
	scanf("%c", &searchChar);
	searchResult = search(x, searchChar);
	if(searchResult == -1)
	{
		printf("Character %c is not present in the string %s", searchChar, x);
	}
	else
	{
		printf("Character %c is present at index %d in the string %s", 
				searchChar, searchResult, x);
	}
	
	//Merge Function
	printf("\n\nEnter a string for the merge operation: ");
	scanf("%s", mergingStr);
	mergedStrPtr = merge(x, mergingStr);
	printf("Merged string is %s\n", mergedStrPtr);

	//Bonus Merge Function
	//Recylces merdStrPtr and mergingStr from previous block
	printf("\nBonus Part");
	mergedStrPtr = new_merge(x, mergingStr);
	printf("\nNew merged string is %s\n\n", mergedStrPtr);

	//Free malloc'd memory
	clear(y);
	clear(rev);
	clear(mergedStrPtr);

	return 0;
}

int length(char *s)
{
	//Finds the length of string s
	//Does not include null terminator
	int myLength = 0;

	while(*s != '\0')
	{
		myLength++;
		s++;
	}
	return myLength;
}

char* copy(char *s)
{
	//Copies string s into a new string and returns address of new string
	char *copiedStringPtr;
	char *copiedStringInitPtr;

	//Creates two pointers:
	//copiedStringPtr to move around within memory
	//copiedStringInitPtr to hold beginning address
	//+1 needed to include the null terminator
	copiedStringPtr = malloc(sizeof(char) * (length(s) + 1));
	copiedStringInitPtr = copiedStringPtr;

	while(*s != '\0')
	{
		*copiedStringPtr = *s;
		copiedStringPtr++;
		s++;
	}

	//Add null terminator to end of copiedStringPtr
	*copiedStringPtr = '\0';

	return copiedStringInitPtr;
}

char* reverse(char *s)
{
	//Creates a new string that is the reverse of string s
	//and returns the address of the new string
	char *revStrPtr;
	char *revStrInitPtr;
	int sLength = 0;
	int i;
	sLength = length(s);

	//Creates two pointers:
	//revStrPtr to move around within memory
	//revStrInitPtr to hold beginning address
	//+1 needed to include the null terminator
	revStrPtr = malloc(sizeof(char) * (sLength + 1));
	revStrInitPtr = revStrPtr;

	//Set revStrPtr to the end of it's contained string
	s += sLength - 1;
	for(i = 0; i <= sLength; i++)
	{
		*revStrPtr = *s;
		revStrPtr++;
		s--;
	}

	//Add null terminator to end of revStrPtr
	*revStrPtr = '\0'; 

	return revStrInitPtr;
}

void clear(char *s)
{
	//Frees the malloc'd data s
	free(s);
}

int search(char *s, char c)
{
	//Searches string s for a user specified character c
	//Returns -1 if no match is found
	//Returns the indexNum of the match
	int i;
	int indexNum = 0;
	int sLength = length(s);
	for(i = 0; i < sLength; i++)
	{
		if(*s == c) //Return indexNum: match found		
			return indexNum;
		else //match not found, continue looking
		{
			s++;
			indexNum++;
		}
	}

	//Return -1: no match found
	return -1;
}

char* merge(char *s, char *s1)
{
	//Merges two strings s and s1 into a new string
	//and returns the address of the new string
	
	//Creates two pointers:
	//mergeStrPtr to move around within memory
	//mergeStrInitPtr to hold beginning address
	//+1 needed to include the null terminator
	char *mergeStrPtr = malloc(sizeof(char)*(length(s) + length(s1) + 1));
	char *mergeStrInitPtr = mergeStrPtr;

	//Adds the characters of the first string to the beginning
	//of the new string
	while(*s != '\0')
	{
		*mergeStrPtr = *s;
		mergeStrPtr++;
		s++;
	}

	//Adds the characters of the second string to the end of
	//the new string
	while(*s1 != '\0')
	{
		*mergeStrPtr = *s1;
		mergeStrPtr++;
		s1++;
	}

	//Adds null terminator to end of the string
	*mergeStrPtr = '\0';

	return mergeStrInitPtr;
}

char* new_merge(char *s1, char *s2)
{
	//Merges two string s1 and s2 into a new string in an alternating fashion
	//and returns the address of the new string

	//Creates two pointers:
	//mergeStrPtr to move around within memory
	//mergeStrInitPtr to hold beginning address
	//+1 needed to include the null terminator
	char *mergeStrPtr = malloc(sizeof(char)*(length(s1) + length(s2) + 1));
	char *mergeStrInitPtr = mergeStrPtr;
	
	//Continues until both null terminators reached
	while(*s1 != '\0' || *s2 != '\0') 
	{
		if(*s1 != '\0')
		{
			*mergeStrPtr = *s1;
			mergeStrPtr++;
			s1++;
		}
		if(*s2 != '\0')
		{
			*mergeStrPtr = *s2;
			mergeStrPtr++;
			s2++;
		}
	}

	//Adds null terminator to end of the string
	*mergeStrPtr = '\0';

	return mergeStrInitPtr;
}

