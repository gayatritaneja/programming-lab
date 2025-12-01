#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct stack
{
    int top;
    int *a;
}Stack;

int main(void)
{
    int n = 100;
    Stack *s = (Stack*) malloc(sizeof(Stack));
    s->top = -1;
    s->a = (int*) malloc(sizeof(int) * n);
}

int* add(Stack* s, int data)
{
    if (s->top + 1 != MAX)
    {
        s->top++;
        s->a[s->top] = data;
    }
    return &s->top;
}

void remove(Stack* s)
{
    if (s->top > -1)
    {
        s->top --;
    }
}