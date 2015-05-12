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

//Begin program run
int main(int argc, char *argv[])
{
	//Check user supplied arguments
	if(argc < 3 || argc > 4)
	{
		printf("Usage: %s <input file> <number> [<bonus>]\n", argv[0]);
		return 0;
	}
	
	FILE *fp = fopen(argv[1], "r"); //open user specified file
	int numToAdd = 0; //variable used for inserting file values into tree
	BST *tree = NULL, //the root of the tree
		*foundDataPtr = NULL; //a reusable variable for results of search functions
	 
	
	if(fp == NULL) //checks if user specified file is available
	{
		printf("Invalid File. Aborting Program.\n");
		return 0;
	}
	
	while(fscanf(fp, "%d", &numToAdd) != EOF) //populates tree with values from fp
	{
		tree = insert(tree, numToAdd);
	}
	
	fclose(fp); //closes the file
	
	if(tree == NULL) //if no elements the tree is invalid
	{
		printf("No elements in tree. Aborting Program.\n");
		return 0;
	}
	
	inorder(tree);
	printf("\n");
	
	foundDataPtr = find(tree, atoi(argv[2])); //Find the value and returns the pointer
	if(foundDataPtr != NULL)
	{
		printf("%s was found\n", argv[2]);
	}
	else
	{
		printf("%s was not found\n", argv[2]);
	}
	
	if(argc == 4) //Bonus finds the value and returns the closest pointer
	{
		foundDataPtr = nearest(tree, atoi(argv[3]));
		printf("%d is the closest number to %s\n", foundDataPtr->data, argv[3]);
	}
	
	destroy(tree);
	
	return 0;
}