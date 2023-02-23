#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUFFER 10000

struct node {
  int data;            // the data
  struct node *next;   // the next data in the linked list.
} * Head, *tmp, *tmp1; // declaring the variable pointers.

int remove_last_element();     // removes the last element in the list
int remove_first_element();    // removes the first element in the list.
int insert_first_element(int); // insert before first element.
int insert_last_element(int);  // insert after the last elemtnt.
void display_menu(char *);     // shows the menu
char input_listener_handler(); // listen to the keyboard input
// char[MAXBUFFER] create_list_buffer(); // display the item list;
char *create_list_buffer(char *); // display the item list;
void reset_list();

int main() {
  char list_buffer[MAXBUFFER];
  char exit_key = '6';
  do {
    getchar(); // to fix the infinite loop of getting char in c.
    display_menu(list_buffer);
  } while (input_listener_handler() != exit_key);

  return 0;
}; // end of main func.

// remove the last element in the list.
int remove_last_element() {
  if (Head == NULL)
    return 0;
  if (Head->next == NULL) {
    Head = NULL;
    return 0;
  } else {
    tmp = Head;
    // loop until reaches the last item in the list (whose tmp->next is null).
    while (tmp->next != NULL) {
      tmp1 = tmp;
      tmp = tmp->next;
    };
    tmp1->next = NULL;
  };
  return 0;
}; // end of remove_last_element func.

// remove the first element in the list.
int remove_first_element() { 
  if(Head == NULL) return 0;
  tmp = Head;
  Head = tmp->next;
  return 0; 
}; // end of remove_first_elment func.

// insert element before the first element.
int insert_first_element(int element) {
  if (Head != NULL) {
    tmp = Head;
    tmp1 = (struct node *)malloc(sizeof(struct node));
    tmp1->data = element;
    tmp1->next = Head;
    Head = tmp1;
    return element;
  } else {
    tmp1 = (struct node *)malloc(sizeof(struct node));
    tmp1->data = element;
    tmp1->next = NULL;
    Head = tmp1;
    return element;
  }
}; // end of insert_first_element func.

// insert element after the last element.
int insert_last_element(int element) {
  if (Head != NULL) {
    struct node *reserve;
    tmp = Head;
    tmp1 = (struct node*)malloc(sizeof(struct node));
    tmp1->next = NULL;
    tmp1->data = element;
    while (tmp != NULL) {
      reserve = tmp;
      tmp = tmp->next;
    }
    reserve->next = tmp1;
  } else {
    tmp1 = (struct node*)malloc(sizeof(struct node));
    tmp1->next = NULL;
    tmp1->data = element;
    Head = tmp1;
  };
  return 0;
}; // end of insert_last_element func.

// display_menu
void display_menu(char *list_buffer) {
  system("clear");
  printf("\nItems: %s\n", create_list_buffer(list_buffer));
  printf("*************Menu***********\n\n");
  printf(
      "\n\t1. Insert to begining. \n\t2. Insert to end. "
      "\n\t3. Remove the begining element. \n\t4. Remove the last. "
      "element. \n\t5. Reset list. \n\t6. Exit.\n\nNOTE: Enter the characters "
      "without the (.) character. \n\n -> ");
}; // end of display_menu func.

// input_listener_handler.
char input_listener_handler() {
  char input = getchar();
  getchar(); // fix infinite getchar loop in c.
  int value;
  switch (input) {
  case '1': // insert as first element.
    printf("\nValue to be inserted.\n -> ");
    scanf("%d", &value);
    return insert_first_element(value);
    break;
  case '2': // insert to end of the list.
    printf("\nValue to be inserted.\n -> ");
    scanf("%d", &value);
    return insert_last_element(value);
    break;
  case '3': // remove the begining element.
    remove_first_element();
    return printf("\nFirst element removed!");
    break;
  case '4': // remove the last element
    remove_last_element();
    return printf("\nFirst element removed!");
    break;
  case '5':
    printf("\nAre you sure you want to reset the list?\n ( y / n ) -> ");
    char confirm = getchar();
    if (confirm != 'y')
      return input;
    reset_list();
    break;
  default:
    return input;
    break;
  };
  return input;
}; // end of input_listener handler func.

// char[MAXBUFFER] create_list_buffer() {
char *create_list_buffer(char *list_buffer) {
  if (Head == NULL) {
    // strcat(list_buffer, "[Empty List]");
    list_buffer = "[Empty List]";
  } else {
    tmp = Head;
    strcpy(list_buffer, ""); // empty the string.
    bool first = true;
    while (tmp != NULL) {
      if (first == true) {
        char dd_str[20];
        sprintf(dd_str, "%d", tmp->data);
        strcat(list_buffer, dd_str);
        first = false;
      } else {
        char dd_str[20];
        sprintf(dd_str, " -> %d", tmp->data);
        strcat(list_buffer, dd_str);
      }
      tmp = tmp->next;
    };
    strcat(list_buffer, "->NULL");
  }
  return list_buffer;
}; // end of create list_buffer func.

// reset the data structure.
void reset_list() {
  if (Head != NULL)
    Head = NULL;
}; // end of reset_list func
