/*
 * Name: Pearse Hutson
 * Pawprint: pah9qd
 * ID: 14040826
 * Lab: E
 * Homework 3
 * 4/9/2015
 */
// Submission Guidelines for lab 9
// tar -czvf lab9.tar.gz runner.c bst.c bst.h Makefile
// cs_submit CS2050_E LAB9 lab9.tar.gz

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"
#include "calculator.h"

#define MAX_EQU_LEN 100
#define DELIMITER ' ' //Can only be one char long

static int prec(char operator);
static int isNumeric(char *num);

/**********************************************************
 *                          prec
 * Parameters:
 *     operator: A character to be evaluated
 * Return:
 *     An int indicated the character's precedence
 * Description: 
 *     Returns a number corresponding the the preccedence
 * of different arithmetic operators. * has a higher
 * precedence that / which is greater than %, +, -
 * in that order. Higher precedence should return a higher
 * number so say 5 for * 1 for - and 0 for a non operator
 **********************************************************/
static int prec(char operator)
{
    if(operator == '*')
        return 5;
    else if(operator == '/')
        return 4;
    else if(operator == '%')
        return 3;
    else if(operator == '+')
        return 2;
    else if(operator == '-')
        return 1;
    else
        return 0;
}

/**********************************************************
 *                  isNumeric
 * Parameters:
 *     num: A pointer to a string to be evaluated
 * Return:
 *     An int with evaluation result
 * Description:
 *     Returns 1 if the string passed is an integer
 * 0 otherwise. This function is able to process any number
 * of digits (chars). 
 **********************************************************/
static int isNumeric(char *num)
{
    int i, num_len;

    num_len = strlen(num);

    for(i = 0; i < num_len; i++)
    {
        if(isdigit(*(num + i)) == 0)
            return 0;
    }

    return 1;
}

/**********************************************************
 *                  infix_to_postfix
 * Parameters: 
 *     infix: A pointer to a string containing an equation
 *            in infix form
 * Return:
 *     A pointer to a string containing the same equation
 *     in postfix form
 * Description:
 *     Converts a valid infix expression into postfix
 *
 * Psuedocode:
 * for each token in the string
 *     if the next token is a number
 *         append it to the postfix string
 *     else if the next token is a left paren
 *          push it onto the stack
 *     else if the next token is a right paren
 *          while the stack is not empty and the left paren 
 *			 is not at the top of the stack
 *              pop the next operator off of the stack
 *              append it to the postfix string
 *          pop the left paren off of the stack and discard it
 *     else if the next token is an operator (+, -, *, /)
 *         while the stack is not empty and the operator at 
 *		    the top of the stack has a higher precedence than 
 *		    the token
 *              pop the top element off of the stack and 
 *				append it to the postfix string
 *         push the current token onto the stack
 *
 * while there are elements remaining on the stack
 *     pop the top element off of the stack and append it 
 *	    to the postfix string
 **********************************************************/
char* infix_to_postfix(char* infix)
{
	char  *postfixStr = calloc(MAX_EQU_LEN, sizeof(char)),
          *currChar= calloc(2, sizeof(char));
    int   i = 0,
          equLen = strlen(infix),
          postfixIndex = 0,
          precVal = 0;
    stack *runningStack = create_stack();

    for(i = 0; i < equLen; i++)
    {
        currChar[0] = infix[i];
		// Prevents access to invalid memory 
		// (Shouldn't happen because of buffer in frontend.c)
        if(postfixIndex > (MAX_EQU_LEN - 2)) 
            break;

        if(isNumeric(currChar))
            postfixStr[postfixIndex++] = infix[i];
        else if(currChar[0] == '(')
        {
            push(runningStack, '(');
            if(postfixIndex != 0 && postfixStr[postfixIndex - 1] != DELIMITER)
                postfixStr[postfixIndex++] = DELIMITER;
        }
        else if(currChar[0] == ')')
        {
            while(isEmpty(runningStack) == 0 && top(runningStack) != '(')
            {
                if(postfixIndex != 0 && postfixStr[postfixIndex - 1] != DELIMITER)
                    postfixStr[postfixIndex++] = DELIMITER;
                postfixStr[postfixIndex++] = top(runningStack);
                pop(runningStack);
            }
            pop(runningStack); //pops left paren and discards
        }
        else if(currChar[0] == ' ')//next char is a whitespace
        {
            if(postfixIndex != 0 && postfixStr[postfixIndex - 1] != DELIMITER)
                postfixStr[postfixIndex++] = DELIMITER;
        }
        else if(currChar[0] == '\n')//ends equation if next char is a newline
        {
            break;
        }
        else if(prec(currChar[0]) > 0)//next char is an operator
        {
            precVal = prec(currChar[0]);

            if(postfixIndex != 0 && postfixStr[postfixIndex - 1] != DELIMITER)
                postfixStr[postfixIndex++] = DELIMITER;

            while(isEmpty(runningStack) == 0 && prec(top(runningStack)) > precVal)
            {
                postfixStr[postfixIndex++] = top(runningStack);
                pop(runningStack);
            }

            push(runningStack, infix[i]);
        }
        //If next char is invalid, it is skipped and the next char is read
    }

    while(isEmpty(runningStack) == 0 && postfixIndex < (MAX_EQU_LEN - 2)) //Add remaining operators from stack to equation
    {
        postfixStr[postfixIndex++] = DELIMITER;
        postfixStr[postfixIndex++] = top(runningStack);
        pop(runningStack);
    }

    // postfixStr[postfixIndex] = '\0'; //Unnecessary due to use of calloc

    free(currChar);
    free(runningStack);
    return postfixStr;
}

/**********************************************************
 *                evaluate_postfix
 * Parameters:
 *     postfix: A pointer to a valid postfix string to be evaluated
 * Return:
 *     The integer result of the equation
 * Description:
 *     This function takes in a valid postfix expression
 * and evaluate it to an integer
 *
 * Pseudocode:
 * for each token in the string
 *      if the token is numeric
 *          convert it to an integer
 *          push it onto the stack
 *      else
 *          pop the top 2 element off of the stack
 *          the first goes into the right variable
 *          the second goes into the left variable
 *          apply the operation:
 *              result = left op right
 *              ex result = left + right
 *
 *          push the result onto the stack
 *
 * return the result from the stack
 */
int evaluate_postfix(char* postfix)
{
    char  *token = NULL,
          *delimEquation = malloc(sizeof(char) * (strlen(postfix)+ 1)),
          delim[2] = {DELIMITER};
    int   leftVar = 0,
          rightVar = 0,
          result = 0;
    stack *runningStack = create_stack();

    strcpy(delimEquation, postfix);
    
    token = strtok(delimEquation, delim);
    
    while(token != NULL)
    {
        if(isNumeric(token))
        {
            push(runningStack, atoi(token));
        }
        else
        {
            rightVar = top(runningStack);
            pop(runningStack);
			leftVar = top(runningStack);
            pop(runningStack);

            if(strcmp(token, "+") == 0)
                push(runningStack, leftVar + rightVar);
            else if(strcmp(token, "-") == 0)
                push(runningStack, leftVar - rightVar);
            else if(strcmp(token, "*") == 0)
                push(runningStack, leftVar * rightVar);
            else if(strcmp(token, "/") == 0)
                push(runningStack, leftVar / rightVar);
            else if(strcmp(token, "%") == 0)
                push(runningStack, leftVar % rightVar);
            // If the operation is not listed above, it is ignored
        }

        token = strtok(NULL, delim);
    }
    result = top(runningStack);
    pop(runningStack);

    free(token);
    free(delimEquation);
    free(runningStack);
    return result;
}