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

/************************************************
				is_phone_number
Parameters:
	word - A pointer to a string to be evaluated

Return:
	An integer containing evaluation result
	1 = True
	0 = False
	
Description:
	This function determines whether the word 
provided looks like a phone number. Phone 
numbers must have the format "(xxx)-xxx-xxxx".
************************************************/
int is_phone_number(char *word)
{
	int one, two, three;
	char errorCatch;
	if(sscanf(word, "(%3d)-%3d-%4d%c", &one, &two, &three, &errorCatch) == 3)
	{
		if( (one > 99 && one < 1000) && 
			(two > 99 && two < 1000) && 
			(three > 999 && three < 10000) )
			return 1;
		else
			return 0;
	}
	else
		return 0;
	 
}

/************************************************
					is_email
Parameters:
	word - A pointer to a string to be evaluated

Return:
	An integer containing evaluation result
	1 = True
	0 = False
	
Description:
	This function determines whether the word 
provided looks like an email. An email must be a 
string of letters and numbers, followed by  an 
'@', followed by another string of letters or 
numbers, followed by '.', followed by 
three-character top level domain
************************************************/
int is_email(char *word)
{
	char one[255], two[255], three[3], errorCatch;
	if(sscanf(word, "%[a-zA-Z0-9]@%[a-zA-Z0-9].%c%c%c%c", 
			  one, two, &three[0], &three[1], &three[2], &errorCatch) == 5)
		return 1;
	else
		return 0;
}

/************************************************
				looks_like_name
Parameters:
	word - A pointer to a string to be evaluated

Return:
	An integer containing evaluation result
	1 = True
	0 = False
	
Description:
	This function determines whether the word 
provided looks like a name. A name must start 
with a capital letter. All other characters in 
the word must be lowercase letters.
************************************************/
int looks_like_name(char *word)
{
	char name[MAX_LINE],
		 errorCatch[MAX_LINE];
	if(sscanf(word, "%c%[a-z]%[^a-z]", &name[0], &name[1], errorCatch) == 2)
	{
		if(isupper(name[0]) != 0)
			return 1;
		else
			return 0;
	}
	return 0;
}

/************************************************
					is_date
Parameters:
	word - A pointer to a string to be evaluated

Return:
	An integer containing evaluation result
	1 = True
	0 = False
	
Description:
	This function determines whether the word 
provided looks like a date. Dates must follow 
the MM/DD/YYYY format. This function will 
determine if a date is valid based on a 
12-month calendar.
************************************************/
int is_date(char *word)
{
	int month, day, year;
	int validDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char errorCatch;
	if(sscanf(word, "%d/%d/%d%c", &month, &day, &year, &errorCatch) == 3)
	{
		if(month < 1 || month > 12)
			return 0;
		if(day < 1 || day > validDays[month])
			return 0;
		return 1;
	}
	return 0;
}

// int is_phone_number(char* word)
// {    
//     if(strlen(word) != 14)
//         return 0;
//	   if(word[0] != '(')
//         return 0;
//     if(isdigit(word[1]) == 0)
//         return 0;
//     if(isdigit(word[2]) == 0)
//         return 0;
//     if(isdigit(word[3]) == 0)
//         return 0;
//     if(word[4] != ')')
//         return 0;
//     if(word[5] != '-')
//         return 0;
//     if(isdigit(word[6]) == 0)
//         return 0;
//     if(isdigit(word[7]) == 0)
//         return 0;
//     if(isdigit(word[8]) == 0)
//         return 0;
//     if(word[9] != '-')
//         return 0;
//     if(isdigit(word[10]) == 0)
//         return 0;
//     if(isdigit(word[11]) == 0)
//         return 0;
//     if(isdigit(word[12]) == 0)
//         return 0;
//     if(isdigit(word[13]) == 0)
//         return 0;
// 
//     return 1;
// }