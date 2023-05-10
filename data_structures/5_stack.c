#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int item;
  unsigned int top;
  int *arr;
} stack_blue_print;

void push(stack_blue_print *, int); // inserts a new element.
void pop(stack_blue_print *);       // removes the topmost element.
void peek(stack_blue_print *);      // reveal the topmmost element.
void isEmpty(stack_blue_print *);   // determine whether the stack is empty.
void isFull(stack_blue_print *);    // determine whether the stack is full.
char showUi(); // display the menu UI.

int main(void) {
  stack_blue_print *stackk = (stack_blue_print*) malloc(sizeof(stack_blue_print)); // a new stack created.
	stackk->arr[0] = 12;
  return 0;
};
