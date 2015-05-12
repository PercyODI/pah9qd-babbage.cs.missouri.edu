#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

/**
 * Param string: a string
 *
 * Return: 1 if the string is a phone number, 0 otherwise
 *
 * A phone number takes the form (xxx)-xxx-xxxx where the 
 * x's are digits 0-9.
 */
int is_phone(char* string);
int is_email(char *string);
int is_name(char *string);

int main(void) {

    assert(is_phone("(123)-456-7890") == 1);
    assert(is_phone("(123) 456-7890") == 0);
    assert(is_phone("123-456-7890") == 0);
    assert(is_phone("(123)-45e-7890") == 0);
    assert(is_phone("(123)-456-789") == 0);
	
	assert(is_phone("(123)-456-7890i") == 0);
	
	assert(is_email("pearse2008@gmail.com") == 1);
	assert(is_email("pearse2008@gmail.comizzle") == 0);
	assert(is_email("pearse@2008@gmail.com") == 0);
	assert(is_email("pearse.2008@gmail.com ") == 0);
	
	assert(is_name("Pearse") == 1);

    printf("Yay!!\n");

    return 0;
}

int is_phone(char *string)
{
	int one, two, three;
	char errorCatch;
	if(sscanf(string, "(%3d)-%3d-%4d%c", &one, &two, &three, &errorCatch) == 3)
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

int is_email(char *string)
{
	char one[255], two[255], three[3], errorCatch;
	if(sscanf(string, "%[^@/\\]@%[^.@/\\].%c%c%c%c", 
			  one, two, &three[0], &three[1], &three[2], &errorCatch) == 5)
		return 1;
	else
		return 0;
}

int is_name(char *string)
{
	char name[255];
	if(sscanf(string, "%c%s", &name[0], &name[1]) == 2)
	{
		if(isupper(name[0]) != 0)
			return 1;
		else
			return 0;
	}
	return 0;
}

// int is_phone(char* string)
// {    
//     if(strlen(string) != 14)
//         return 0;
//	   if(string[0] != '(')
//         return 0;
//     if(isdigit(string[1]) == 0)
//         return 0;
//     if(isdigit(string[2]) == 0)
//         return 0;
//     if(isdigit(string[3]) == 0)
//         return 0;
//     if(string[4] != ')')
//         return 0;
//     if(string[5] != '-')
//         return 0;
//     if(isdigit(string[6]) == 0)
//         return 0;
//     if(isdigit(string[7]) == 0)
//         return 0;
//     if(isdigit(string[8]) == 0)
//         return 0;
//     if(string[9] != '-')
//         return 0;
//     if(isdigit(string[10]) == 0)
//         return 0;
//     if(isdigit(string[11]) == 0)
//         return 0;
//     if(isdigit(string[12]) == 0)
//         return 0;
//     if(isdigit(string[13]) == 0)
//         return 0;
// 
//     return 1;
// }