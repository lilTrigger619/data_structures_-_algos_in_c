// display  the menu of the app.
void show_menu(){
  printf(
      "\n\n********* Menu *********\n\n"
      "Items: [[ Empty list ]]\n"
      "1. Add element to begining of list.\n"
      "2. Add element after the last item in the list.\n"
      "3. Remove Head/first element from the list.\n"
      "4. Remove last element from the list.\n"
      "5. Reset the list.\n"
      "6. Exit."
      );
}; // end of show_menu func.

// collect int input value.
int show_int_prompt(int* inp){
  printf("\n -> "); // show the prompt.
  scanf("%d", inp); // collect the input.
  getchar(); // fix input stream.
  return *inp; // return the input.
}; // end of show_int_prompt func.

// collect char input value
char show_char_prompt(char* inp){
  //inp = (char )inp;
  printf("\n -> "); // show the prompt.
  scanf("%c", inp); // collect the input
  getchar(); // fix input stream.
  return *inp; // return what's collected.
}; // end of show_char_prompt func.
