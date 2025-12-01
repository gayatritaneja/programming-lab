#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--)
    {
        int new_index = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[new_index];
        arr[new_index] = temp;
    }
    return arr;
}