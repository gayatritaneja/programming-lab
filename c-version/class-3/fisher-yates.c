#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int* arr, int n);
void swap(int* arr, int new_index, int old_index);
int main(void)
{
    int* arr;
    int n = 5;
    arr = (int*) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = i+1;
    }

    shuffle(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void shuffle(int* arr, int n)
{
    int new_index;
    int i = n - 1;
    srand(time(0));

    while(i > 0)
    {
        new_index = rand() % (n-1);
        swap(arr, new_index, i);
        i--;
    }
}

void swap(int* arr, int new_index, int old_index)
{
    int temp = *(arr + old_index);
    *(arr+old_index) = *(arr + new_index);
    *(arr + new_index) = temp;
}