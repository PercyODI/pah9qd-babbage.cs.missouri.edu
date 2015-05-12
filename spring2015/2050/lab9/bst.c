/* Pearse Hutson
 * Pawprint: pah9qd
 * Student ID: 14040826
 * Lab E
 * Lab9
 *   ->bst.c
 *	 ->bst.h
 *   ->runner.c
 * Date: 4/6/15
 * Lab Code: One Drive
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include "bst.h"
/*****************************************************************
							insert
Parameters:
	tree: A pointer to the root of a BST
	data: An int to be inserted into the BST

Return:
	The head of the BST

Description:
	This function will insert a given data value into the BST in 
the appropriate place.
****************************************************************/
BST* insert(BST *tree, int data)
{
	BST *newNode = malloc(sizeof(BST));
	BST *travTree = tree;
	int placed = 0;
	
	if(newNode != NULL) //Check if memory was allocated
	{
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
	}
	else
	{
		printf("%d not inserted. No memory available. \n", data);
		return tree;
	}
	
	if(tree == NULL) //First element in tree
	{
		return newNode;
	}
	
	while(placed != 1) //Run until the node is placed somewhere
	{
		if(data > travTree->data && travTree->right != NULL)
		{
			travTree = travTree->right;
		}
		else if(data < travTree->data && travTree->left != NULL)
		{
			travTree = travTree->left;
		}
		else if(data > travTree->data && travTree->right == NULL)
		{
			travTree->right = newNode;
			placed = 1;
		}
		else if(data < travTree->data && travTree->left == NULL)
		{
			travTree->left = newNode;
			placed = 1;
		}
		else if(data == travTree->data) //Discard duplicate entries
		{
			free(newNode);
			placed = 1;
		}
			
	}
	
	return tree;
}

/*****************************************************************
							find
Parameters:
	tree: A pointer to the root of a BST
	data: An int to be found in the BST

Return:
	A pointer to the node with the specified data or 
	NULL if the data was not found

Description:
	This function will find a user specified value within the 
BST. If the value is not found, NULL is returned instead.
****************************************************************/
BST* find(BST *tree, int data)
{
	BST *foundNode = NULL;
	
	if(tree == NULL)
	{
		return NULL;
	}
	
	if(tree->data == data)
	{
		return tree;
	}
	else if(tree->data > data)
	{
		foundNode = find(tree->left, data);
	}
	else// if(tree->data < data)
	{
		foundNode = find(tree->right, data);
	}
		
	
	return foundNode;
}

/*****************************************************************
							inorder
Parameters:
	tree: A pointer to the root of a BST

Return:
	None

Description:
	This function will print out the value of each node in order.
****************************************************************/
void inorder(BST *tree) 
{
	if(tree == NULL)
	{
		return;
	}
	
	inorder(tree->left);
	
	printf("%d ", tree->data);
	
	inorder(tree->right);
	
	return;
}

/*****************************************************************
							destroy
Parameters:
	tree: A pointer to the root of a BST

Return:

Description:
	This function will free each node in the BST
****************************************************************/
void destroy(BST* tree)
{
	if(tree == NULL)
	{
		return;
	}
	
	destroy(tree->left);
	destroy(tree->right);
	free(tree);
}

/*****************************************************************
							insert
Parameters:
	tree: A pointer to the root of a BST
	data: An int to be found in the BST

Return:
	The head of the BST

Description:
	This function will find the closest number to the user 
specified data value. 
****************************************************************/
BST* nearest(BST *tree, int data)
{
	BST *foundNode = NULL;
	
	if(tree == NULL)
	{
		return NULL;
	}
	
	if(tree->data == data)
	{
		return tree;
	}
	else if(tree->data > data)
	{
		foundNode = nearest(tree->left, data);
	}
	else// if(tree->data < data)
	{
		foundNode = nearest(tree->right, data);
	}
	
	if(foundNode == NULL)
	{
		foundNode = tree;
	}
	else if( abs((foundNode->data - data)) > abs((tree->data - data)) )
	{
		foundNode = tree;
	}
	
	
	return foundNode;
}



























