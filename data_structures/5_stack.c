#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 1000

typedef struct {
  int item;
  int top;
	int size;
  int *arr;
} stack_blue_print;

char StrBuffer[MAXLENGTH];
bool push(stack_blue_print *, int); // inserts a new element.
bool pop(stack_blue_print *);       // removes the topmost element.
int peek(stack_blue_print *);      // reveal the topmmost element.
int size(stack_blue_print *); // return the size of the stack.
bool isEmpty(stack_blue_print *);   // determine whether the stack is empty.
bool isFull(stack_blue_print *);    // determine whether the stack is full.
int showUi(stack_blue_print *);                      // display the menu UI.
char* createStackElements(stack_blue_print *);

int main(void) {
	// creating the stack
  stack_blue_print *stackk = (stack_blue_print *)malloc(
      sizeof(stack_blue_print)); // a new stack created.

	// instantiating the default values of the stack.
	stackk->top = -1;
	stackk->size = 10;
	stackk->arr = malloc(sizeof(int) * stackk->size); // sizing the arry list to the size provided.

	while(showUi(stackk) != 3){
		
	}
	free(stackk);
  return 0;
}; // end of main function.

char* createStackElements(stack_blue_print *stackk){
	//printf("stackk top %d", stackk->top);
	if (stackk->top == -1) {
		strcpy(StrBuffer, "[ Empty List ]");
		return StrBuffer;
	}
	strcpy(StrBuffer, " Items \n");
	strcat(StrBuffer, " ----------- \n");
	for (int si = stackk->top; si >-1; si--){
		if (si == stackk->top) {
			char tempBuffer[50] ;
			sprintf(tempBuffer, "\n ( %d ) ( %d ) <-- Top stack \n", si, stackk->item);
			strcat(StrBuffer, tempBuffer);
			continue;
		};	
		char tempBuffer[50];
		sprintf(tempBuffer, " ( %d ) ( %d ) \n", si, stackk->arr[si]);
		strcat(StrBuffer, tempBuffer);
	};
	return StrBuffer;
};

int showUi(stack_blue_print * stackk) {
	int menuValue;
	int pushItem;
	printf("%s",createStackElements(stackk));
  printf(
			"\n"
         "1. Pop\n"
         "2. Push\n"
         "3. Exit\n\n"
				 "-> ");
	scanf("%d", &menuValue);
	switch(menuValue){
		case 1:
			//printf("you selected one");
			pop(stackk);
			//printf("you selected one");
			break;
		case 2:
			printf("\nItem -> "); 
			scanf("%d", &pushItem);
			printf("\n"); 
			push(stackk, pushItem);
			break;
		case 3:
			//printf("you selected three");
			break;
		default:
			printf("\nUnkown item selected!\n");
			break;
	};	
  return menuValue;
}; // end of showUi func.

bool isFull(stack_blue_print *stackk){
	if (stackk->size == (stackk->top+1))return true;
	return false;
}; // end of isFull func.
 
bool isEmpty(stack_blue_print *stackk){
	if (stackk->top == -1) return true;
	else return false;
}; // end of isEmpty func.

bool push(stack_blue_print *stackk, int item){
	if (isFull(stackk)) return false;
	//printf("the stack is not full");
	stackk->arr[++stackk->top] = item;
	stackk->item = stackk->arr[stackk->top];
	//printf("the item %d", stackk->item);
	return true;
};// end of push func.

bool pop(stack_blue_print *stackk){
	if (isEmpty(stackk)) return false;
	stackk->item = stackk->arr[--stackk->top];
	return true;
}; //end of pop func.
