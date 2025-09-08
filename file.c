//fisher-yates shuffling algorithms
#include <stdio.h>
#include <stdlib.h>

int print_array(int a[]);
void swap(int*, int*);
void rotateArray(int, int, int);

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

    for (int i = n - 1; i > 0; i--)
    {
        j = rand() % i;
        swap(i, j);
    }
}

int print_array(int a[])
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

void rotateArray(int *a, int n, int rot)
{
    (int *) buf = (int *) malloc(rot * sizeof(int));
    //for (int i = 0; i < rot; i++){buf[i] = a[i];}

    memcpy(buf, a, rot(sizeof(int)));

    for (int i = rot; i < n; i++)
    {
        a[i - rot] = a[i];
    }

    for (int i = 0; i < rot; i ++)
    {
        a[n - rot + 1] = buf[i];
    }
    memcpy(&a[n - rot], buf, rot*(sizeof(int)))
}
// ((rot % n) + n) % n