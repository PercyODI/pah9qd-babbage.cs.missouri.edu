/* Name: Pearse Hutson
 * Id: 14040826
 * PawPrint: pah9qd
 * Date: 4/20/15
 * Lab: E
 * Labcode: White
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
 
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Invalid input.\nExpected: %s <input file>\n", argv[0]);
		return 0;
	}
	
	int lenArray = 0,
		i = 0,
		userDelete = 0,
		*array = NULL;
	BST *tree = NULL;
	
	FILE *fp = fopen(argv[1], "r");
	
	fscanf(fp, "%d", &lenArray);
	array = malloc(sizeof(int) * lenArray);
	
	for(i = 0; i < lenArray; i++)
		fscanf(fp, "%d", &array[i]);
	
	tree = build_balanced_tree(array, 0, lenArray - 1);
	free(array);
	
	print(tree);
	
	printf("\nEnter a number to delete: ");
	scanf("%d", &userDelete);
	// if(userDelete == tree->data)
	// 	tree = NULL;
	
	delete_node(tree, userDelete);
	
	printf("Tree without %d\n", userDelete);
	print (tree);

	while(tree != NULL)
		tree = delete_node(tree, tree->data);
	
	fclose(fp);
	return 0;
}