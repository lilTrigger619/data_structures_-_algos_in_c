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
char remove_first();
char remove_last();
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
    tmp1 = (struct node *)malloc(sizeof(struct node)); // new node.
    tmp = Head; // tmp(Head) -> ....
    tmp->prev = tmp1; // new_node < - (prev)tmp -> ...
    tmp1->next = tmp; // new_node(next) - >  tmp -> ....
    tmp1->data = value; // new_node(data) =value
    Head = tmp1; // new_node(Head) -<>-  .....
    tmp = NULL; // derefrencing
    tmp1 = NULL; // derefrencing
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

// remove the first element
char remove_first(){
  if (Head == NULL) return 0;
  tmp = Head->next;
  Head = tmp;
  return 1;
}; // end of remove_first func.
   
// remove_last func.   
char remove_last(){
  if (Head == NULL) return 0;
  tmp = Head;
  if (tmp->next == NULL){  // when the next value of head is null remove head.
    tmp = NULL;
    Head = NULL;
    return 1;
  };
  while(tmp != NULL){
    tmp1  = tmp; // buckup the current node
    tmp = tmp->next;
  };
  tmp = tmp1->prev; // last-but-one <- last-node.
  tmp1 = NULL;
  tmp->next = NULL; // last-but-one (now last) -> NULL .
  //tmp = NULL;  // clear pointer.
  return 0;
}; // end of remove_last func
   
char reset_list(){
  if (Head == NULL) return 0;
 Head = NULL;
 return 1;
};

char input_listener() {
  char key;
  scanf("%c", &key);
  getchar();
  //printf("the input is %c", key);
  int value; // for the value to be inserted.
  switch (key) {
  case '1': // insert to begining of list.
    printf("\nEnter value to be inserted\n -> ");
    scanf("%d", &value); // collecting the value.
    getchar(); //fix the other characters that are still in the input stream.
    return insert_first(value);
    break;
    case '2': // insert to end of list 
    printf("\nEnter value to be inserted\n -> ");
    scanf("%d", &value); // collecting the value.
    getchar(); //fix the other characters that are still in the input stream.
    return insert_last(value);
    break;
  case '3': // remove element at the begining
    return remove_first(value);
    break;
  case '4': // remove element at the end.
    return remove_last(value);
    break;
  case '5':
    printf("\nAre you sure you wanna remove the last element?\n (Y/N) -> ");
    char confirm = getchar();
    getchar();
    if(confirm == 'Y' || confirm == 'y' ){
      reset_list();
      return 0;
    }else return 0;
    break;
  case '6':
    return key;
    break;
  default:
    printf("\nFunction not implemented !\n\n");
    return 0;
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
