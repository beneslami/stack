#include "stack.h"
#include <stdio.h>

int main(){
  Stack s1;
  int n;

  s1 = create(5);
  push(s1, 1);
  push(s1, 2);
  push(s1, 3);

  n = pop(s1);
  printf("%d\n", n);

  while(!is_empty(s1)){
    printf("%d\n", pop(s1));
  }
  destroy(s1);
}
