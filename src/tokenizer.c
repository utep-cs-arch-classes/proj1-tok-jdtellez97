#include<stdio.h>
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
  }    char *word_end(char *str){
      while(*str++){
	if(non_space_char(*str))
	*str++;
    }
       return str;
    }

int count_words(char *str){
  int counter, state;
  while(*str != 0){
    if(non_space_char(*str) && state == 0){
      state = 1;
      counter++;
    }
    else if(space_char(*str) && state == 1){
      state = 0;
      *str++;
    }
  }
  return counter;
}
int main(){

  char * c = "leroy";
  printf("\n");
  printf("The first char is \n  %c ",*word_start(c));
  printf("\n");
  printf("terminator triggered.\n  %c ",*word_end(c));
  printf("words in total. \n %d ",count_words(c));
  return 0;
}


