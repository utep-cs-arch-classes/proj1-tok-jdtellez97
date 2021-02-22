#include<stdio.h>
#define LIMIT 50

int main(){

  char s[50];
  int i,c;

  i = 0;
  while(i != LIMIT-1){
    c = getchar();
    if(c == '\n')
      break;
    s[i++] = c;
  }
  s[i] = '\0';
  printf("You entered: %s\n",s);
  return 0;

}
