#include <stdio.h>
#include "malloc.h"
#include "history.h"

int c = 0; /* serves as a counter for id*/
List *init_history(){
  List *head = (List*)malloc(sizeof(List));
  head->root = NULL;
  return head;
}

void add_history(List *list, char *str){
  Item *temp = list->root;
  if(list->root == NULL){
    list->root = (Item*)malloc(sizeof(Item));
    list->root->id = c++;
    list->root->str = str;
    list->root->next = NULL;
  }else{
    while(temp->next != NULL){
      temp = temp->next;
    }
      temp->next = (Item*) malloc(sizeof(Item));
      temp->next->id =  c++;
      temp->next->str = str;
      temp->next->next = NULL;
  }
}
char *get_history(List *list, int id){
  Item *temp = list-> root;
  while(temp != NULL){
    if(temp-> id == id) return temp->str;
    temp = temp->next;
  }
}
void print_history(List *list){
  Item *temp = list->root;
  while(temp != NULL){
    printf("%s ", temp->str);
  }
  printf("\n");
}
void free_history(List *list){
  Item *temp = list->root;
  while(temp!= NULL){
    free(temp->str);
    free(temp);
  }
}
