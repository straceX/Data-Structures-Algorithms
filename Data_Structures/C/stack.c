int is_stack_full(Stack *ptrStack)
{
    if(ptrStack->size == ptrStack->max_size)
        return 1;
    else
        return 0;
}

int is_stack_empty(Stack *ptrStack)
{
    if(ptrStack->size == 0)
        return 1;
    else
        return 0;
}

Stack *initialize_stack(size_t size_of_stack)
{
    Stack *ptr;

    if( (ptr = (Stack *) (malloc(sizeof(Stack)))) )
    {
        if( (ptr->sp) = ( (int *) malloc(sizeof(int) * size_of_stack) ) )
        {
            ptr->size = 0;
            ptr->max_size = size_of_stack;
            return ptr;
        }
        else
            return NULL;
    }
    else
        return NULL;

}


int push_stack(Stack *ptrStack,int val)
{
    if(is_stack_full(ptrStack))
    {
        printf("Error:Stack is Full!..\n");
        return 0;
    }
    else
    {
        *(ptrStack->sp) = val;
        ptrStack->sp++;
        ptrStack->size++;
    }
    return 1;
}

int pop_stack(Stack *ptrStack)
{
    int param;

    if(is_stack_empty(ptrStack))
    {
        printf("Error:Stack is Empty!..\n");
        return -1;
    }
    else
    {
        param = *(--ptrStack->sp);
        ptrStack->size--;
        return param;
    }
}