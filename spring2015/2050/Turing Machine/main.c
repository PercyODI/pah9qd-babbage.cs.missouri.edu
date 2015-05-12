/*
 *
 *
 *
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 typedef struct node_ {
	char *val;
	struct node_ *leftPtr;
	struct node_ *rightPtr;
} Node;

typedef struct stack_ {
	Node *stackHead;
	Node *tapeMiddle;
	Node *readHead;
} Stack;
 
 void parseInput(char *inputFile, char *alphabet, char *possibleStates, 
 				 char *initState, char *accptState, char *tape, 
 				 char *transitionRules);
 // void readAlphabet(char *alphabet);
 Stack* createTapeList(char *tape);
 void printTapeStack(Stack *tapeStack);
 Stack* createStatesList(char *possibleStates);
 void printStatesList(Stack *statesList);

 int main(int argc, char *argv[])
 {
	if(argc != 2)
	{
		printf("Invalid parameters\n");
		return 1;
	}
	
	Stack *tapeList = NULL,
		  *statesList = NULL;
	char *alphabet = malloc(sizeof(char) * 256),
		 *possibleStates = malloc(sizeof(char) * 256),
		 *initState = malloc(sizeof(char) * 256),
		 *accptState = malloc(sizeof(char) * 256),
		 *tape = malloc(sizeof(char) * 512),
		 *transitionRules = malloc(sizeof(char) * 512);
		 
	parseInput(argv[1], alphabet, possibleStates, initState, accptState, tape, transitionRules);
	
	// readAlphabet(alphabet); //Do i need to read in the alphabet?

	tapeList = createTapeList(tape);
	statesList = createStatesList(possibleStates);
	printTapeStack(tapeList);
	printStatesList(statesList);
	
	return 0;
	
}

//Parse input txt to strings
void parseInput(char *inputFile, char *alphabet, char *possibleStates, 
			  	char *initState, char *accptState, char *tape, 
			  	char *transitionRules)
{
	FILE *fp = fopen(inputFile, "r");
	if(fp == NULL)
	{
		printf("Invalid or non-existent file.\n");
		return;
	}

	// char *newlineChar = malloc(sizeof(char) * 2);
	// strcpy(newlineChar, "\n\0");
	
	
	char *tempStr = malloc(sizeof(char) * 512);
	
	fgets(alphabet, 256, fp);
	alphabet[strcspn(alphabet, "\r\n")] = 0;

	fgets(possibleStates, 256, fp);
	possibleStates[strcspn(possibleStates, "\r\n")] = 0;

	fgets(initState, 256, fp);
	initState[strcspn(initState, "\r\n")] = 0;

	fgets(accptState, 256, fp);
	accptState[strcspn(accptState, "\r\n")] = 0;

	fgets(tape, 512, fp);
	tape[strcspn(tape, "\r\n")] = 0;

	while(fgets(tempStr, 512, fp))
	{
		tempStr[strcspn(tempStr, "\r\n")] = 0;
		// strcat(tempStr, newlineChar);
		strcat(transitionRules, tempStr);
	}
}
	
	
 
 //Read and process the alphabet
 //Don't forget to include _
 //"sequence of non-whitespace characters"
 
 
 //Read and process the possible states
 //"space-separated list of possible states for the machine"
Stack* createStatesList(char *possibleStates)
{
 	Stack *stateList = malloc(sizeof(Stack));
 	Node *newNode = NULL;
 	Node *prevNode = NULL;
 	// int possibleStatesLen = strlen(possibleStates);
 	char *tokenizedPossibleStates = malloc(sizeof(char) * (strlen(possibleStates) + 1));
 	char *token;
 	char delim[2] = " ";

 	strcpy(tokenizedPossibleStates, possibleStates);
 	token = strtok(tokenizedPossibleStates, delim);
 	
 	if(token != NULL)
 	{
 		newNode = malloc(sizeof(Node));
 		newNode->val = malloc(sizeof(char) * strlen(token));
 		strcpy(newNode->val, token);
 		stateList->stackHead = newNode;
 		stateList->readHead = newNode;
 		prevNode = newNode;
 	}

 	token = strtok(NULL, delim);

 	while(token != NULL)
 	{
 		newNode = malloc(sizeof(Node));
 		newNode->val = malloc(sizeof(char) * strlen(token));
 		strcpy(newNode->val, token);
 		newNode->leftPtr = prevNode;
 		prevNode->rightPtr = newNode;
 		prevNode = newNode;
 		token = strtok(NULL, delim);
 	}

 	// newNode->rightPtr = stateList->stackHead;
 	return stateList;

}
 //Read and set the initial state and acceptiong state
 //"on two sequential lines"
 
 //Read in tape and create the link list from the tape
Stack* createTapeList(char *tape)
{
	if(tape == NULL)
	{
		printf("Error: Blank Tape");
		return NULL;
	}
	Stack *newStack = malloc(sizeof(Stack));
	Node *newNode = NULL;
	Node *prevNode = NULL;
	int i = 0,
		tapeLen = strlen(tape);

	newNode = malloc(sizeof(Node));
	newNode->val = malloc(sizeof(char) * 2);
	memset(newNode->val, '\0', sizeof(newNode->val));
	strncpy(newNode->val, tape, 1);
	newNode->leftPtr = NULL;

	newStack->stackHead = newNode;
	newStack->tapeMiddle = newNode;
	newStack->readHead = newNode;

	for(i = 1; i < tapeLen; i++)
	{
		newNode->val = malloc(sizeof(char) * 2);
		memset(newNode->val, '\0', sizeof(newNode->val));
		strncpy(newNode->val, tape + i, 1);
		newNode->leftPtr = prevNode;
		if(i != (tapeLen - 1))
		{
			newNode->rightPtr = malloc(sizeof(Node));
			prevNode = newNode;
			newNode = newNode->rightPtr;
		}
	}

	return newStack;
}
 //Read and process the list of transition rules
 
 //Run Turing machine and create new tape from result
 //The tapeStack->readHead has to move each time
 //The tapeStack->stackHead has to move if node is added to far left of list
 
 //Print out new tape, middle of tape (|) and  
 //read head position (^)
void printTapeStack(Stack *tapeStack)
{
	Node *travNode = tapeStack->stackHead;

	while(travNode != NULL)
	{
		printf("%s", travNode->val);
		travNode = travNode->rightPtr;
	}
	printf("\n");

	travNode = tapeStack->stackHead;

	while(travNode != tapeStack->tapeMiddle)
	{
		printf(" ");
		travNode = travNode->rightPtr;
	}
	printf("|\n");

	// travNode = tapeStack->stackHead;
}

void printStatesList(Stack *statesList)
{
	// For testing use only
	Node *travNode = statesList->stackHead;

	while(travNode != NULL)
	{
		printf("%s ", travNode->val);
		travNode = travNode->rightPtr;
	}
	printf("\n");
}

