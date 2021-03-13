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
    while(*str){   /* while  theres something in str*/
      if(space_char(*str))  //spaces in str?
	str++;
      else if(non_space_char(*str)) //characters in str?
	return str;
    }
  }
  char *word_end(char *str){
      while(*str){
	if(space_char(*str))
	  return str;      //return if theres a space
	else if( non_space_char(*str))
	  str++;    // move to  next character
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
  char *c = (char*)malloc(sizeof(char)*(len+1)); // allocate the memory for c
  while(i < len ){
    c[i] = inStr[i]; // iterate through inStr with i and assign it to c 
    i++;  
  }
  c[len] = '\0'; // terminate c
  return c;
}
  void print_tokens(char ** tokens){
  int i = 0;
  while(tokens[i]){
    printf("[%d]: %s ", i, tokens[i]);
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
int get_length(char* str){
  int i = 0;
  char * temp  = str;
  while(*temp){
    i++;
    *temp++;
  }
   return i;
}
    
 char **tokenize(char *str){
    int c = 0;
    int words = count_words(str);
     char *temp = str;
    char **tokens = (char**) malloc(sizeof(char*)*(words+1));

    while(c < words){
      temp = word_start(temp);// get the first char of temp
      tokens[c] = copy_str(temp,get_length(temp)); // store the copied  word to that position
      temp = word_end(temp); // end of the word 
      c++;
    }
    tokens[words] = '\0';
    return tokens;
}   
int main(){
  char *c = "I have a bag of hair.";
  char ** tokens;
   printf("\n");
    printf("The first char is \n  %c ",*word_start(c));
    printf("\n");
    printf("terminator triggered.\n  %c ",*word_end(c));
    printf("\n");
    printf("words in total: %d \n ",count_words(c));
    printf("\n");
    printf("copied String  %s \n" , copy_str(c, get_length(c)));
    printf("\n");
    printf("length of String %d \n", get_length(c));
    printf("\n");
    printf("tokens: %s\n ", *tokenize(c));
    printf("printing tokens \n");
    // print_tokens(tokens);
    printf("\n");
    printf("freeing tokens...\n ");
    free_tokens(tokens);
  return 0;
}
