#include <stdio.h>

int main( void )
{
	int menuChoice;
	
	printf("Asterisk Shapes\n\n");
	printf("What shape would you like to have printed?\n");
	printf("1. Square\n");
	printf("2. Circle\n");
	printf("3. Arrow\n");
	printf("4. Diamond\n");
	printf("Enter your choice: ");
	scanf("%d", &menuChoice);

	if (menuChoice == 1){
		printf("*********\n");
		printf("*       *\n");
		printf("*       *\n");
		printf("*       *\n");
		printf("*       *\n");
		printf("*       *\n");
		printf("*       *\n");
		printf("*       *\n");
		printf("*********\n");
	}

	if (menuChoice == 2){
                printf("   ***   \n");
                printf(" *     * \n");
                printf("*       *\n");
                printf("*       *\n");
                printf("*       *\n");
                printf("*       *\n");
                printf("*       *\n");
                printf(" *     * \n");
                printf("   ***   \n");
	}

	if (menuChoice == 3){
                printf("    *    \n");
                printf("   ***   \n");
                printf("  *****  \n");
                printf("    *    \n");
                printf("    *    \n");
                printf("    *    \n");
                printf("    *    \n");
                printf("    *    \n");
                printf("    *    \n");
	}

	if (menuChoice == 4){
                printf("    *    \n");
                printf("   * *   \n");
                printf("  *   *  \n");
                printf(" *     * \n");
                printf("*       *\n");
                printf(" *     * \n");
                printf("  *   *  \n");
                printf("   * *   \n");
                printf("    *    \n");
	}
		
	return 0;
}
