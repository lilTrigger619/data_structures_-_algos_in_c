#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXBUFFER 10000

struct node {
  int data;
  struct node *next;
  struct node *prev;
} * Head, *tmp, *tmp1;

// function proto to create a stream of characters to print
// out the stat of thelist.
char *create_list_buffer();
char list_buffer[MAXBUFFER];
char insert_first(int);
char insert_last(int);
char remove_first(int);
char remove_last(int);
char input_listener();
void display_menu();

int main() {
  char Exit_key = '6';
  do {
    display_menu(); // display the menu.
  } while (input_listener() != Exit_key);

  return 0;
}; // end of main func.

char *create_list_buffer() {
  if (Head == NULL)
    return "[Empty list!]";
  strcpy(list_buffer, ""); // empty the buffer;
  tmp = Head;
  bool first_time = true;
  while (tmp != NULL) {
    char data_str[15];
    sprintf(data_str, "%d", tmp->data); // conveting the int to a string.
    if (first_time) {
      strcat(
          list_buffer,
          data_str); // concat only the value without the arrows on first loop.
      first_time = false;
    } else {
      strcat(list_buffer, " <--> "); // add the chaining effect.
      strcat(list_buffer, data_str); // add the data to the chain.
    };
    tmp = tmp->next;
  }
  return list_buffer;
};

char insert_first(int value) {
  if (Head == NULL) {
    // when there is no head.
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->data = value;
    //printf("the value from the list %d", tmp->data);
    tmp->prev = NULL;
    Head = tmp;
    tmp = NULL;
    //printf("Heads data %d", Head->data);
  } else {
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->next = Head;
    tmp->data = value;
    Head = tmp;
    tmp = NULL;
  };
  return 0;
}; // end of insert_first func.
   
   
// function to insert element after the last in the list.
char insert_last(int value){
  if(Head == NULL){
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data =  value;
    tmp->next = NULL;
    tmp->prev = NULL;
    Head = tmp;
    tmp = NULL;
    return 0;
  };

  // when the head is not equal to null
  tmp = Head;
  while(tmp != NULL){
    tmp1 = tmp;
    tmp = tmp->next;
  };
  struct node* new_last = (struct node*)malloc(sizeof(struct node));
  new_last->next = NULL;
  new_last->data = value;
  new_last->prev = tmp1;
  tmp1->next = new_last;
  return new_last->data;
}// end of insert_last func.

char remove_first(int);
char remove_last(int);

char input_listener() {
  char key;
  scanf("%c", &key);
  getchar();
  //printf("the input is %c", key);
  int value; // for the value to be inserted.
  switch (key) {
  case '1':
    printf("\nEnter value to be inserted\n -> ");
    scanf("%d", &value); // collecting the value.
    getchar(); //fix the other characters that are still in the input stream.
    return insert_first(value);
    case '2':
    printf("\nEnter value to be inserted\n -> ");
    scanf("%d", &value); // collecting the value.
    getchar(); //fix the other characters that are still in the input stream.
    return insert_last(value);
  case '3':
  case '4':
  case '5':
  case '6':
    printf("\nFunction not implemented !\n\n");
    return key;
    break;
  default:
    break;
  };
  return key;
}
void display_menu() {
  system("clear");
  printf("*****************Doubly_linked_list*****************"
         "\n\n");
  printf("Items ::  %s", create_list_buffer());
  printf("\n\n"
         "\t1. Insert element to the begining of the list."
         "\n\t2. Insert element to the end of the list."
         "\n\t3. Remove element at the begining of the list."
         "\n\t4. Remove element at the end of the list."
         "\n\t5. Reset the element."
         "\n\t6. Exit."
         "\n\n -> ");
};
