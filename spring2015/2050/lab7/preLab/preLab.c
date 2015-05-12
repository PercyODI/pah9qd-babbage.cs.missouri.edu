/* Name: Pearse Hutson
 * Lab: Pre Lab 7
 */

 #include <stdio.h>
 #include <stdlib.h>

 typedef struct node_{
	int val;
	struct node_ *next;
} node;

node* insert_at_head(node *head, int val);

int main(void)
{
	//Create first value in linked list
	//node firstHead = {0, NULL};
	//node newNode = {0, NULL};
	node *movingNode = NULL;
	node *currentHead = NULL;
	int userValue, counter;

	printf("Enter new node value to insert into list: ");
	scanf("%d", &userValue);
	do
	{
		currentHead = insert_at_head(currentHead, userValue);
		printf("Enter new node value to insert into list(-1 to exit): ");
		scanf("%d", &userValue);
	} while(userValue != -1);

	//print entire link list
	movingNode = currentHead;
	counter = 1;
	while(movingNode != NULL)
	{
		printf("Node %d at %p: %d\tNext Address: %p\n", counter, movingNode, movingNode->val, movingNode->next);
		movingNode = movingNode->next;
		counter++;
	}
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
