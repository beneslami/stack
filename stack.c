#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define STACK_SIZE 100

#define PUBLIC          /* C design pattern */
#define PRIVATE static


struct Stack_type{
  Item contents[STACK_SIZE];
  int top;
};

PRIVATE void terminate(const char* message){
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

PUBLIC Stack create(void){
  Stack s = malloc(sizeof(struct Stack_type));
  if(s == NULL)
    terminate("error creating stack");
  s->top = 0;
  return s;
}

PUBLIC void destroy(Stack s){
  free(s);
}

PUBLIC void make_empty(Stack s){
  s->top = 0;
}

PUBLIC bool is_empty(Stack s){
  return s->top == 0;
}

PUBLIC bool is_full(Stack s){
  return s->top == STACK_SIZE;
}

PUBLIC void push(Stack s, Item i){
  if(is_full(s))
    terminate("Error in push: stack is full.");
  s->contents[s->top++] = i;
}

PUBLIC Item pop(Stack s){
  if(is_empty(s))
    terminate("Error in pop: Stack is empty.");
  return s->contents[--s->top];
}
