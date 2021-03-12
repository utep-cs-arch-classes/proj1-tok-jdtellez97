#include<stdio.h>
#include<malloc.h>
#include"tokenizer.h"

  int space_char(char c){
  if((c =='\t' || c == ' ') || c == '\n' )
    return 1;
  else  return 0;
  }
  int non_space_char(char c){
  if((c != '\t' || c !=' ') || c != '\n' )
    return 1;
   else return 0;
   }

  char *word_start(char *str){
    while(*str){
      if(space_char(*str))
	str++;
      else if(non_space_char(*str))
	return str;
    }
  }
  char *word_end(char *str){
      while(*str){
	if(space_char(*str))
	  return str;
	else if( non_space_char(*str))
	 str++;
      }
      return 0 ;
  }
  int count_words(char *str){
    int c = 0; /*counter*/
    int in = 0; /* instate, 1 is true, 0 is false */
    while(*str){
      if(space_char(*str)){
        in = 0;
      }
      else if(in == 0){
	in = 1;
	c++;
      }
      str++;
  }
    return c;
  }
  char *copy_str(char *inStr, short len){
  int i = 0;
  char *c = (char*)malloc(sizeof(char)*(len+1)) ;
  while(i < len ){
    c[i] = inStr[i];
    i++;  
  }
  c[len] = '\0';
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
 char **tokenize(char *str){
   
    int c = 0;
    int words = count_words(str);
     char *temp = str;
    char **tokens = (char**) malloc(sizeof(char*)*(words+1));

    while(c < words){
      temp = word_start(temp);
      tokens[c] = copy_str(temp, (word_end(temp) - word_start(temp)));
      temp = word_end(temp);
      c++;
    }
    tokens[words] = '\0';
    return tokens;
}   
int main(){
  char *c = "Soy Sauce";
   printf("\n");
    printf("The first char is \n  %c ",*word_start(c));
    printf("\n");
    printf("terminator triggered.\n  %c ",*word_end(c));
    printf("\n");
    printf("words in total: %d \n ",count_words(c));
    printf("\n");
    printf("copied word  %s \n" , copy_str(c,30));
    printf("\n");
    printf("tokens: %s, ", tokenize(c));
    printf("\n");
  return 0;
}
