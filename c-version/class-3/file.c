#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_array(int a[]);
void swap(int*, int*);
void rotateArray(int*, int, int);

int main(void)
{
    int n = 25;
    int* a;
    srand(12345); //replace 12345 with time(null) for it to be random
    a = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }

    rotateArray(a, n, 4);
    print_array(a);
}

void print_array(int a[])
{
    int n = 25;

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Rotating an array
void rotateArray(int *a, int n, int rot)
{
    int* buf = (int *) malloc(rot * sizeof(int));
    //for (int i = 0; i < rot; i++){buf[i] = a[i];}

    memcpy(buf, a, rot * (sizeof(int)));

    for (int i = rot; i < n; i++)
    {
        a[i - rot] = a[i];
    }

    for (int i = 0; i < rot; i ++)
    {
        a[n - rot + i] = buf[i];
    }
    memcpy(&a[n - rot], buf, rot*(sizeof(int)));
}
// ((rot % n) + n) % n