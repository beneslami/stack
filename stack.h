#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#define STACK_SIZE 100

/*
incomplete type: Limited way of encapsulation in C. This type definition states
that a variable of type s is a pointer to a structure with tag Stack.
*/
typedef struct Stack_type *Stack;
typedef int Item;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, int i);
int pop(Stack s);

#endif
