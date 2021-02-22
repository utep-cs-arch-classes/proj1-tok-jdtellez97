#include< stdio.h>
#include"tokenizer.h"

int space_char(char c){
  if((c =='\t' || c == '\n') && c == ' '){
    return 1;
  }else{
    return 0;
  }
  }
  int non_space_char(char c){
  if((c != '\t' || c !='\n') && c != ' '){
   return 1;
   }else{
   return 0;
   }
   }
    



