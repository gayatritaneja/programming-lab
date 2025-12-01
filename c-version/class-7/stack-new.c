#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int n = 100;
    int *s = (int*) mallox(sizeof(int) * n);
    int top = 0;

    for (int i = 0; i < n; i++)
    {
        s[i] = 0;
    }

}

int add(int* s, int top, int n, int data)
{
    if (top + 1 != n)
    {
        s[top+1] = data;
        return top + 1;
    }
    return -1;
}

int remove(int* s, int top, int n, int data)
{
    if (top >= 1)
    {
        return top - 1;
    }
    return -1;
}