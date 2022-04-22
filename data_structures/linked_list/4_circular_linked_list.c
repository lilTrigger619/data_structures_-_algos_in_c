#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./utils.h"

// structure.
struct node {
  int data;
  struct node *next; 
  struct node *prev;
} *Head, *Tmp, *Tmp1;


char menu_input_handler(); // validate the input
void add_begining(); //add element to the begining
void add_end(); // add element to the end
void remove_begining(); // shift the head
void remove_end(); // remove the last element
void remove_header(); // reset the data structure.

int main(void){
  /**
  char input;
  show_menu();
  show_char_prompt(&input);
  printf("The new input value %c", input);
  **/

  do {
    show_menu(); // display the menu;
  }while(menu_input_handler() != '6');

  return 0;
}; // end of main method.

// add element to the begining of the list.
void add_begining(){
  // prompt user for input
  int input;
  show_int_prompt(&input);
  if( Head == NULL ){
    Tmp=(struct node*)malloc(sizeof(struct node));
    Tmp->next = NULL;
    Tmp->data = input;
    Head = Tmp;
  }
};

char menu_input_handler(){
  char listenerValue;
  show_char_prompt(&listenerValue);
  switch(listenerValue){
    case '1':
      add_begining();
      return listenerValue;
      break;
    case '2':
      add_end();
      return listenerValue;
      break;
    case '3':
      remove_begining();
      return listenerValue;
      break;
    case '4':
      remove_end();
      return listenerValue;
      break;
    case '5':
      remove_header(); // reset the list.
      return listenerValue;
      break;
    case '6':
      return listenerValue;
      break;
    default: // when an unknown character is inputed.
      printf("Unknown character entered!\nExiting now...");
      return '6';
      break;
  };
}
