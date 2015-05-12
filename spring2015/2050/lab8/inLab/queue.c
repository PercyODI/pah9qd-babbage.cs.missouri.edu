/* Pearse Hutson
 * ID: 14040826
 * Pawprint: pah9qd
 * Date: 3/30/2015
 * Lab Code: Queue 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

/*
int main(void)
{
	char str1[50] = "Name Uno";
	char str2[50] = "Name Dos";
	queue *fake = NULL;
	
	enqueue(&fake, str1);
	enqueue(&fake, str2);
	
	int i;
	for(i = 0; i < 2; i++)
	{
		printf("%s\n", dequeue(&fake));
	}
	return 0;
}
*/

/***************************************************************
						enqueue
Parameters:
	head: A double pointer to the head of a queue
	name: A string to be enqueued
	
Return:
	None
	
Description:
	Enqueues the given value into the queue
***************************************************************/
void enqueue(queue **head, char *name)
{
	queue *node = malloc(sizeof(queue));
	queue *curr = *head;
	
	node->name = malloc(sizeof(char) * 50);
	strcpy(node->name, name);
	node->next = NULL;
	
	if(*head == NULL)
	{
		*head = node;
		return;
	}

	while(curr->next != NULL)
	{
		curr = curr->next;
	}
	
	curr->next = node;
	
	//(*head)->next = malloc(sizeof(queue));
	//*head = (*head)->next;
	
	//(*head)->next = malloc(sizeof(char) * 50);
	//strcpy((*head)->name, name);

	return;
}

/***************************************************************
						dequeue
Parameters:
	head: A double pointer to the head of a queue
	
Return:
	The string dequeued
	
Description:
	This function will dequeue and free the next node in the 
queue and return its stored value.
***************************************************************/
char* dequeue(queue **head)
{
	char *name = malloc(sizeof(char) * 50);
	queue *old_head = *head;
	strcpy(name, (*head)->name);
	
	*head = old_head->next;
	free(old_head->name);
	free(old_head);

	//name is freed in potato.c
	return name;
}

/***************************************************************
						free_queue
Parameters:
	head: A double pointer to the head of a queue
	
Return:
	None
	
Description:
	This function frees all the nodes in the queue
***************************************************************/
void free_queue(queue *head)
{
	queue *curr_head = head;
	queue *next_head = head->next;
	
	while(curr_head != NULL)
	{
		next_head = curr_head->next;
		free(curr_head->name);
		free(curr_head);
		curr_head = next_head;
	}
	
	return;
}