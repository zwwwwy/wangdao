#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 6

typedef struct stack
{
    int data[MAXLEN];
    int rsp;
    int maxlen;
} stack_t;

int InitStack(stack_t* stack)
{
    stack->rsp = 0;
    stack->maxlen = MAXLEN;
    return 1;
}

int IsEmpty(stack_t* stack)
{
    if (stack->rsp==0)
        return 1;
    else
        return 0;
}

int Push(stack_t* stack, int data)
{
    if (stack->rsp>=stack->maxlen)
    {
        printf("Stack overflow.\n");
        return 0;
    }
    stack->data[stack->rsp] = data;
    ++stack->rsp;
    return 1;
}

int Pop(stack_t* stack)
{
    if (IsEmpty(stack))
    {
        printf("Stack empty.\n");
        return 0;
    }
    --stack->rsp;
    return stack->data[stack->rsp];
}

int GetTop(stack_t* stack)
{
    if (IsEmpty(stack))
    {
        printf("Stack empty.\n");
        return 0;
    }

    return stack->data[stack->rsp-1];
}

int DestoryStack(stack_t* stack)
{
    stack->rsp=0;
    free(stack);
    return 1;
}

void test()
{
    stack_t* stk = (stack_t*)malloc(sizeof(stack_t));
    InitStack(stk);
    int times = 6;
    for (int i=0;i<times+6;++i)
    {
        if (Push(stk, i))
            printf("Push %d.\n", i);
    }

    printf("Top: %d.\n",GetTop(stk));
    DestoryStack(stk);

    for (int i=0;i<times+3;++i)
    {
        int tmp;
        tmp = Pop(stk);
        printf("Pop %d.\n", tmp);
    }
    return;
}

int main() 
{
    test();
    return 0;
}
