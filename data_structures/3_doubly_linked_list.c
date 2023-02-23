#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXBUFFER 10000

struct node{
  int data;
  struct node *next;
  struct node* prev;
}*Head, *tmp, *tmp1;

//function proto to create a stream of characters to print 
//out the stat of thelist.
char* create_list_buffer();
char list_buffer[MAXBUFFER];

int main(){
  printf(" %s ", create_list_buffer());
  return 0;
}; // end of main func.

char* create_list_buffer(){
  if(Head == NULL) return "[Empty list!]";
  strcpy(list_buffer,""); //empty the buffer;
  tmp = Head;
  bool first_time =true;
  while(tmp != NULL){
    char data_str[15];
    sprintf(data_str, "%d", tmp->data ); // conveting the int to a string.
    if(first_time){
      strcat(list_buffer, data_str); // concat only the value without the arrows on first loop.
      first_time = false;
    }else{
      strcat(list_buffer, " <--> "); // add the chaining effect.
      strcat(list_buffer, data_str); // add the data to the chain.
      
    };
  }
  return list_buffer;
};
