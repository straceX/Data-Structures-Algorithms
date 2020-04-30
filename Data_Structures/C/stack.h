typedef struct Stacks
{
    size_t max_size;
    size_t size;
    int *sp;
   
} Stack;


Stack *initialize_stack(size_t);

int push_stack(Stack *,int );

int pop_stack(Stack *);