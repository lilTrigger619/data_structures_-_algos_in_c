#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./utils.h"

// structure.
typedef struct node {
  int data;
  struct node *next; 
  struct node *prev;
} *Head, Tmp, Tmp1;



int main(void){
  char input;
  show_menu();
  show_char_prompt(&input);
  printf("The new input value %c", input);
  return 0;
} // end of main method.
