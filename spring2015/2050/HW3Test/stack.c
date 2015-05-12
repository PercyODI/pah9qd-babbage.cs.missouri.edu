#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/**********************************************************
 *          create_stack
 * Parameters:
 *     None
 * Return:
 *     A pointer to a new and empty stack
 * Description:
 *     Creates an empty stack and sets
 * the size equal to 0
 **********************************************************/
stack* create_stack()
{
    stack *newStack = malloc(sizeof(stack));
	if(newStack != NULL)
	{
		newStack->size = 0;
		newStack->stack = NULL;
	}
	else
	{
		printf("\nStack not created. No memory available.\n");
		return NULL;
	}

    return newStack;
}

/**********************************************************
 *                          push
 * Parameters:
 *     s: A pointer to a specific stack instance
 *     val: An int value to put into the stack as a new node
 * Return:
 *     None:
 * Description:
 *     pushes the value into the top of the stack
 **********************************************************/
void push(stack *s, int val)
{
    node *newNode = malloc(sizeof(node));
	
	if(newNode == NULL)
	{
		printf("\n%d could not be pushed to stack. No memory available.\n", val);
		return;
	}
	
    newNode->data = val;
    newNode->next = s->stack;

    s->stack = newNode;
    s->size++;
}

/**********************************************************
 *                       pop
 * Parameters:
 *     s: A pointer to a specific stack instance
 * Return:
 *     None
 * Description
 *     pops the head of the stack the value is not returned
 **********************************************************/
void pop(stack *s)
{
    if(s->size == 0)
    {
        // printf("\n***\nInvalid Pop Action\n***\n"); //Used for debugging
        return;
    }

    node *oldHead = s->stack;
    node *newHead = oldHead->next;
    s->stack = newHead;
    s->size--;

    free(oldHead);
}


/**********************************************************
 *                       top
 * Parameters:
 *     s: A pointer to a specific stack instance
 * Return:
 *     An int containing the val in the top stack node
 * Description:
 *     returns the value at the top of the stack
 * the stack remains unchanged
 **********************************************************/
int top(stack *s)
{
    node *head = s->stack;

    if(s->size == 0)
    {
        // printf("\n***\nInvalid Top Action\n***\n"); //Used for debugging
        return 0;
    }

    return head->data;

}

/**********************************************************
 *                  isEmpty
 * Parameters:
 *     s: A pointer to a specific stack instance
 * Return:
 *     An int containing the result of whether the 
 *      stack is empty or not
 * Description:
 *     returns 1 if the stack is empty, 0 otherwise
 **********************************************************/
int isEmpty(stack *s)
{
    if(s->size == 0)
        return 1;
    else
        return 0;
}
