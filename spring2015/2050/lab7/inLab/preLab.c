/* Name: Pearse Hutson
 * Lab: Pre Lab 7
 * Lab Code: List
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

int main(int argc, char *argv[])
{
	//Create first value in linked list
	//node firstHead = {0, NULL};
	//node newNode = {0, NULL};
	node *movingNode = NULL;
	node *currentHead = NULL;
	int userValue, counter;
	
	if(argc != 2)
	{
		printf("Error: Invalid command arguments.\n");
		printf("Expected input: ./a.out <input file>");
		return 0;
	}

	//Create new linked list from file
	currentHead = create_list(argv[1]);
	if(currentHead == NULL)
	{
		printf("%s is an invalid input file. Execution aborted", argv[1]);
		return 0;
	}
	
	printf("\nCurrent head @ %p\n", currentHead);
	print_list(currentHead);
	printf("\nCurrent head @ %p\n", currentHead);
	
	return 0;
}

/************************************************
This function will take in a pointer to the head
of a linked listed and a number, put the number
into a node, and make that node the new head of the
linked list.
************************************************/
node* insert_at_head(node *head, int val)
{
	node *newNode = malloc(sizeof(node));

	newNode->val = val;
	newNode->next = head;
	return newNode;
}

node* create_list(char *file)
{
	int newVal = 0;
	node *currentHead == NULL;
	FILE *fp = fopen(file, "r");
	
	if(fp == NULL)
		return -1;
	
	while(!feof(fp))
	{
		fscanf("%d", &newVal);
		currentHead = insert_at_head(currentHead, newVal);
	}
	
	return currentHead;
}

void print_list(node *head)
{
	while(head != NULL)
	{
		printf("%d ", head->val);
		head = head->next;
	}
}
node *delete_even(node *head);
void delete(node *head);
























