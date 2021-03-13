#include<stdio.h>
#include "tokenizer.h"
#include "history.h"
#define LIMIT 50

int main(){

  char s[50];
  char ** tokens;
    int i ,c, id;
  List *list = init_history();

  i = 0;
  while(i != LIMIT-1){
    c = getchar();
    if(c == '\n')
      break;
    s[i++] = c;
  }
   s[i] = '\0';
  printf("You entered: %s\n",s);
  // printf("Tokenising...\n ");
  //tokens =  tokenize(s);
  //printf("Total number of words : %d \n ", copy_str(s, get_length(s)));
  //printf(" Your tokens are : %s \n" );
  //print_tokens(tokens);
  //free_tokens(tokens);
  
  return 0;

}
