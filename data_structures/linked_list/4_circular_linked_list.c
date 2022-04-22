#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "./utils.h"

// structure.
struct node {
  int data;
  struct node *next; 
  struct node *prev;
} *Head, *Tmp, *Tmp1;


// validate the input
char menu_input_handler(); 
//add element to the begining
void add_begining(); 
// add element to the end
void add_end(); 
// shift the head
void remove_begining(); 
// remove the last element
void remove_end(); 
// reset the data structure.
void remove_header(); 
// string buffer that will be shown in menu
char list_buffer[MAX_BUFFER]; 
// function to create the list_buffer and return it
char* create_list_buffer();

int main(void){
  /**
  char input;
  show_menu();
  show_char_prompt(&input);
  printf("The new input value %c", input);
  **/

  do {
    show_menu(create_list_buffer()); // display the menu;
  }while(menu_input_handler() != '6');

  return 0;
}; // end of main method.

// add element to the begining of the list.
void add_begining(){
  // prompt user for input
  int inp;
  show_int_prompt(&inp);
	Tmp=(struct node*)malloc(sizeof(struct node));
	// when there is no element.
  if( Head == NULL ){
    Tmp->next = Tmp;
    Tmp->data = inp;
    Head = Tmp;
		return;
  }
	// when head is not null;
	Tmp->data = inp;
	Tmp->next = Head;
	
	Tmp1 = Head;
	while(Tmp1->next != Head){
		Tmp1 = Tmp1->next;
	};
	Tmp1->next = Tmp;
	Head = Tmp;
	return;
}; // end of add_begining funcion.

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

// remove from the beginning of the list.
void remove_begining(){
	if (Head == NULL) return;
	if (Head->next == Head) return;
	Tmp = Head->next;
	Tmp1 = Head;
	while(Tmp1->next != Head){
		Tmp1 = Tmp1->next;
	};
	Tmp1->next = Tmp;
	Head = Tmp;
	return;
}

// add an element to the last item in the list.
void add_end(){
	int input_data;
	show_int_prompt(&input_data); // collect input
	if (Head == NULL) {
		Head->next = Head;
		Head-> data = input_data;
		return; // when there is no data.
	};
	Tmp = Head;
	while(Tmp->next != Head){ //finding the last element.
		Tmp = Tmp->next;
	};
	if (Tmp->next == Head){ // confirm we at the last element.
		Tmp1 = (struct node*) malloc(sizeof(struct node)); // create a new node
		Tmp1->data = input_data; // node data as inputed_data
		Tmp1->next = Head; // make it's next value become the head.
		Tmp->next = Tmp1; // insert it right after the previous last element.
		return;
	};
	return; // when for some reason the Head is not found.
					// Maybe cus the Head dosen't exist yet.
};

void remove_end(){
	if (Head == NULL) return;
	Tmp = Head;
	while (Tmp->next != Head){ //find last element.
		Tmp1 = Tmp; //Buckup the last but one item.
		Tmp = Tmp->next;	
	};
	if(Tmp->next == Head){
		Tmp1->next = Head; // remove the next item whose next is the Head.
	}else if(Tmp == Head){ // when there's only the head node.
		Tmp->next = NULL; // not necessary.
		Tmp = NULL;
		Head = Tmp;
	};
	return;
};

void remove_header(){
	// This will reset the list.
	char response;
	printf("Are you sure you wanna remove the HEAD of the list?\nY/N");
	show_char_prompt(&response);
	if(response == 'y' || response == 'Y') Head = NULL;
	return;
};

//creates the string list that will be 
//displayed in the menu
char* create_list_buffer(){
	if (Head == NULL) return "[Empty list]";
	char next_char = '>', ret_char= '<';
	bool first_iter = true;	
	char tmp_buffer[MAX_BUFFER];
	Tmp = Head;
	// when the next of the first elem is head then
	// we have only one node.
	if(Tmp->next == Head) { 
		// creating the chain back string buffer
		sprintf(list_buffer,"%d %c%c", Tmp->data, next_char, ret_char);
		return list_buffer;	
	};
	//when there is more than one element in the buffer.
	while(Tmp != Head || first_iter == true){
		// when it's the first iteration.
		//printf("the data %d", Tmp->data);
		if(first_iter){
			sprintf(list_buffer, "%d %c", Tmp->data, next_char);
			first_iter = false;
			Tmp = Tmp->next;
			continue;
		}; 
		sprintf(tmp_buffer, "%d %c", Tmp->data, next_char);
		strcat(list_buffer, tmp_buffer);
		Tmp = Tmp->next;
	}; // end of while loop
	strcat(list_buffer, &ret_char);
	return list_buffer;
}; // end of create_list_buffer function.
