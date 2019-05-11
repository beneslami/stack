Linked list implementation of stack which is more flexible than that of array based.
In array based implementation, client is required to specify a maximum size for the stack at the
time it's created. If we use a linked list implementation, there won't be any preset limit on the size of the stack.

I just defined "Stack" to be struct node* and let Stack value be a pointer to the first node in the list. However, I still need stack_type structure so that the interface (stack.h) remains unchanged.

Having the stack_type structure will make it easier to change the implementation in the future. For example, I may need to add a counter in stack_type for counting the number of elements in the stack. I can easily add a member to the stack_type structure to store this information.
