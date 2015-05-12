/* Name: Pearse Hutson
 * ID: 14040826
 * PawPrint: pah9qd
 * Lab: Pre Lab 7
 * Lab Code: List
 * Date: 3/16/15
 */

 #include <stdio.h>
 #include <stdlib.h>

 typedef struct node_{
	int val;
	struct node_ *next;
} node;

node* insert_at_head(node *head, int val);
node* create_list(char *file);
void print_list(node *head);
node *delete_even(node *head);
void delete(node *head);
node* reverse_list(node *head);

int main(int argc, char *argv[])
{
	node *currentHead = NULL;
	
	if(argc != 2)
	{
		printf("Error: Invalid command arguments.\n");
		printf("Expected input: ./a.out <input file>\n");
		return 0;
	}

	//Create new linked list from file
	currentHead = create_list(argv[1]);
	if(currentHead == NULL)
	{
		printf("%s is an invalid input file. Execution aborted\n", argv[1]);
		return 0;
	}
	
	//Print initial link list from file
	print_list(currentHead);
	
	//Delete all even values from link list
	currentHead = delete_even(currentHead);
	
	//Reprint link list without even values
	print_list(currentHead);
	
	//Reverse link list order
	currentHead = reverse_list(currentHead);
	
	//Reprint link list in reverse_list
	printf("Bonus\n");
	print_list(currentHead);
	
	//Delete the link list
	delete(currentHead);
	currentHead = NULL;

	return 0;
}

/*******************************************************************************
								insert_at_head

Parameters:
	head - The head of a valid linked list
	val - An integer to be isnerted into the list

Return:
	The new head of the linked list
	
	This function will take in a pointer to the head of a linked listed and a 
number, put the number into a node, and make that node the new head of the 
linked list.
*******************************************************************************/
node* insert_at_head(node *head, int val)
{
	node *newNode = malloc(sizeof(node));

	newNode->val = val;
	newNode->next = head;
	return newNode;
}

/*******************************************************************************
								create_list

Parameters:
	file - The name of a file of integers

Return:
	The head of the created linked list
	
	This function will insert each number in the user specified file into the 
head of a linked ilst. The length of the file is not given.
*******************************************************************************/
node* create_list(char *file)
{
	int newVal = 0;
	node *currentHead = NULL;
	FILE *fp = fopen(file, "r");
	
	if(fp == NULL)
		return NULL;
	
	while(fscanf(fp, "%d", &newVal) != EOF)
	{
		currentHead = insert_at_head(currentHead, newVal);
	}
	
	fclose(fp);
	return currentHead;
}

/*******************************************************************************
									print_list

Parameters:
	head - The head of a valid linked list

Return:
	None
	
	This function will print out each number of the linked list with one space 
in between. At the end of the list a newline will be printed.
*******************************************************************************/
void print_list(node *head)
{
	if(head == NULL)
	{
		printf("Empty List.\n");
		return;
	}
	
	while(head != NULL)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

/*******************************************************************************
									delete_even

Parameters:
	head - The head of a valid linked list

Return:
	The new head of the linked list
	
	This function will delete each node from the linked list that contains an 
even value.
*******************************************************************************/
node *delete_even(node *head)
{
	node *nextNode = NULL,
		 *previousNode = NULL,
		 *returnHead = head;
		 
	if(head == NULL)
		return head;
		
	while(head != NULL)
	{
		nextNode = head->next;
		if((head->val % 2) == 0)
		{
			if(head == returnHead)
			{
				returnHead = head->next;
			}
			else if(head->next == NULL)
			{
				previousNode->next = NULL;
			}
			else
			{
				previousNode->next = nextNode->next;
			}
			free(head);
		}
		previousNode = head;
		head = nextNode;
	}
	
	return returnHead;
}

/*******************************************************************************
									delete

Parameters:
	head - The head of a valid linked list

Return:
	None
	
	This function will delete each node from the linked list. 
*******************************************************************************/
void delete(node *head)
{
	node *nextNode = NULL;
	
	while(head != NULL)
	{
		nextNode = head->next;
		free(head);			
		head = nextNode;
	}
}

/*******************************************************************************
								reverse_list

Parameters:
	head - The head of a valid linked list

Return:
	The new head of the linked list
	
	This function will reverse the order of a linked list. This function 
recursively calls itself while setting the penultimate node to NULL. When it 
reaches a list of one node, it starts returning up the stack appending the 
previous result to the new head. It then returns that head.
*******************************************************************************/
node* reverse_list(node *head)
{
	node *previousNode = NULL;
	node *endNode = head;
	
	//Error Handling a null Head
	if(head == NULL)
		return NULL;
	
	//Base case. Linked List is only one element
	if(head->next == NULL)
		return head;
		
	//Find last
	while(endNode->next != NULL)
	{
		previousNode = endNode;
		endNode = endNode->next;
	}
	
	previousNode->next = NULL;		
	endNode->next = reverse_list(head);
	
	return endNode;
}