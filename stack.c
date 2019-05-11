#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define STACK_SIZE 100

#define PUBLIC          /* C design pattern */
#define PRIVATE static

struct node{
  Item data;
  struct node *next;
};

struct Stack_type{
  struct node *top;
};

PRIVATE void terminate(const char* message){
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

PUBLIC Stack create(void){
  Stack s = malloc(sizeof(struct Stack_type));
  if(s == NULL)  // assert(s == NULL);
    terminate("error creating stack");
  s->top = NULL;
  return s;
}

PUBLIC void destroy(Stack s){
  make_empty(s);
  free(s);
}

PUBLIC void make_empty(Stack s){
  while(!is_empty(s))
    pop(s);
}

PUBLIC bool is_empty(Stack s){
  return s->top == NULL;
}

PUBLIC bool is_full(Stack s){
  return false;
}

PUBLIC void push(Stack s, Item i){
  struct node *new_node = malloc(sizeof(struct node));
  if(new_node == NULL)  //assert(new_node == NULL);
    terminate("Error creating node.");
  new_node->data = i;
  new_node->next = s->top;
  s->top = new_node;
}

PUBLIC Item pop(Stack s){
  struct node *old_top;
  Item i;
  if(is_empty(s)) //assert(s == NULL);
    terminate("Error in pop: stack is Empty.");
  old_top = s->top;
  i = old_top->data;
  s->top = old_top->next;
  free(old_top);
  return i;
}
