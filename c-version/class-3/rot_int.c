#include <stdio.h>
#include <stdlib.h>

int* shuffle(int* arr, int shift, int n);

int main(void)
{
    int n = 10;
    int* arr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = i+1;
    }

    int* new_arr = shuffle(arr, 5, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", new_arr[i]);
    }
    printf("\n");
}

int* shuffle(int* arr, int shift, int n)
{
    int* new_arr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        int num = (i + shift) % n;
        new_arr[i] = arr[num];
    }
    return new_arr;
}