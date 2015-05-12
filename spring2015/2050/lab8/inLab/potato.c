/* Pearse Hutson
 * ID: 14040826
 * Pawprint: pah9qd
 * Date: 3/30/2015
 * Lab Code: Queue 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//Function Prototypes
queue* load_queue(char* input);
queue* play_game(int passes, queue* head);

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Incorrect number of command line arguments\n");
		printf("Usage: ./lab8 <input>\n\n");
		return 0;
	}
	queue *current_head = NULL;
	int potato_passes;
	
	current_head = load_queue(argv[1]);
	
	printf("Enter the number of passes or -1 to quit\n");
	scanf("%d", &potato_passes);
	
	while(potato_passes != -1)
	{
		current_head = play_game(potato_passes, current_head);
		
		printf("Enter the number of passes or -1 to quit\n");
		scanf("%d", &potato_passes);
	}
	
	free_queue(current_head);
	
	return 0;
}

/***************************************************************
						load_queue
Parameters:
	input: The name of an input file
	
Return:
	The new head of a queue
	
Description:
	This function will read in each name from the file and 
enqueue them into a new queue.
***************************************************************/
queue* load_queue(char* input)
{
	FILE *fp = fopen(input, "r");
	queue *head = NULL;
	char curr_name[50];
	while(fscanf(fp, "%s", curr_name) != EOF)
	{
		enqueue(&head, curr_name);
	}
	
	fclose(fp);
	return head;
}

/***************************************************************
						play_game
Parameters:
	passes: The number of times the potato is passed
	head: The head of a queue
	
Return:
	The new head of a queue
	
Description:
	This function will simulate a game of hot potato. For each 
turn a player will be dequeued, they are the player that 
currently has the potato. When they pass the potato they should 
be re enqueued so they can play again. The player who has the 
potato when the game is over loses.
***************************************************************/
queue* play_game(int passes, queue* head)
{	
	char *name = NULL;
	while(passes > 1)
	{
		enqueue(&head, head->name);
		name = dequeue(&head);
		printf("%s got the potato and passed to\n", name);
		passes--;
		free(name);
	}
	
	enqueue(&head, head->name);
	name = dequeue(&head);
	printf("%s got the potato and lost\n", name);
	free(name);
	
	
	return head;
}		
		
		

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		