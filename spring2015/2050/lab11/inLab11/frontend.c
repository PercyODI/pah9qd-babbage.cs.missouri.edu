/* Name: Pearse Hutson
 * PawPrint: pah9qd
 * Student ID: 14040826
 * Lab: E
 * Labcode: The End
 * Date: 4/27/2015
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "parser.h"

int main(int argc, char *argv[])
{
	//Verify command line arguments
	if(argc != 2)
	{
		printf("Invalid command arguments\n");
		printf("Expected: %s <input file>\n", argv[0]);
		return 0;
	}
	
	char buffer[MAX_LINE],
		 *lookLikeNameFlag = NULL,
		 *tokenizedStr = malloc(sizeof(char) * MAX_LINE),
		 *token = NULL,
		 delimiters[] = " ,!?\r\n\t";
	int wordCounter = 0;
		
	//Open user-specified file
	FILE *fp = fopen(argv[1], "r");
	
	//Verify file
	if(fp == NULL)
	{
		printf("Invalid file. Aborting.\n");
		return 0;
	}
	
	//Takes the first line (or first 250 words, whichever
	//comes first) into the buffer and parses the buffer.
	//Will run until the end of the file is reached
	while(fgets(buffer, MAX_LINE, fp) != NULL)
	{
		//Removes trailing newline characters
		if(buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';
		
		//Copies the buffer into tokenizedStr
		//to preserve buffer
		strcpy(tokenizedStr, buffer);
	
		//Initializes first token in current buffer
		token = strtok(tokenizedStr, delimiters);
		
		//Evaluates all tokens available in the current buffer.
		//Will run until there are no more tokens available.
		while(token != NULL)
		{
			wordCounter++;
			
			//Remove trailing '.' Leaves '.' in the middle of string (like email)
			if(token[strlen(token) - 1] == '.')
				token[strlen(token) - 1] = '\0';
			
			//Check if token is a phone number
			if(is_phone_number(token) == 1)
				printf("Phone Number: %s\n", token);
			
			//check if token is a date
			if(is_date(token) == 1)
				printf("Date: %s\n", token);
			
			//Check if token looks like a name.
			//Won't print unless two names in a row appear
			if(looks_like_name(token) == 1)
			{
				if(lookLikeNameFlag != NULL)
				{
					printf("Name: %s %s\n", lookLikeNameFlag, token);
					lookLikeNameFlag = NULL;
				}
				else
					lookLikeNameFlag = token;
			}
			else
				lookLikeNameFlag = NULL;
			
			//Check if token is an email address
			if(is_email(token) == 1)
				printf("Email: %s\n", token);
			
			//Move to next token in buffer
			token = strtok(NULL, delimiters);
		}
		
		//Reset flag between buffer calls
		lookLikeNameFlag = NULL;
	}
	
	//Output number of words in file, as calculated by wordCounter
	printf("There are %d words in the file\n", wordCounter);
	
	//Free open pointers
	free(tokenizedStr);
	fclose(fp);
	return 0;
}