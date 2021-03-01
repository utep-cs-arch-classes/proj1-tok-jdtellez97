#include<stdio.h>
#include<malloc.h>
#include"tokenizer.h"

  int space_char(char c){
  if((c =='\t' || c == '\n') && c == ' ')
    return 1;
  else  return 0;
  }
  int non_space_char(char c){
  if((c != '\t' || c !='\n') && c != ' ')
   return 1;
   else return 0;
   }

  char *word_start (char *str){
    while(*str){
      if(space_char(*str))
	 *str++;
      else if(non_space_char(*str))
	return str;
    }
  }
  char *word_end(char *str){
      while(*str++){
	if(non_space_char(*str))
	*str++;
    }
       return str;
    }

  int count_words(char *str){
  int counter,  state ;
  while(*str){
    if(space_char(*str)){
      state = 0;
       *str++;
    }
    else if(non_space_char(*str)){
      state = 1;
    counter++;
    }
     return counter;
  }
}
  char *copy_str(char *inStr, short len){
  int i;
  char *c = malloc(sizeof(*inStr)+1);
  for(i = 0; i < len-1; i++){
    (*c++) = (*inStr++);
  }
  return c;
}

  void print_tokens(char ** tokens){
  int i = 0;
  while(*(tokens+i)){
    printf("[%d]: %s ", i, *(tokens+i));
	   i++;
      }
}
  void free_tokens(char ** tokens ){
  int i = 0;
  while(*(tokens+i)){
    free(*(tokens+i));
    i++;
  }
  free(tokens);
}
  
		      
int main(){

  char * c = "Leroy Sinclair";
  // printf("\n");
  // printf("The first char is \n  %c ",*word_start(c));
  // printf("\n");
  // printf("terminator triggered.\n  %c ",*word_end(c));
  printf("words in total: %d\n ",count_words(c));
  return 0;
}


