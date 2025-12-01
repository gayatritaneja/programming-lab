#include <stdio.h>
#include <stdlib.h>

void siftup(int* arr, int ind)
{
    if (ind == 0 || arr[ind] >= arr[(ind - 1)/2])
    {
        return;
    }
    else
    {
        if (arr[ind] < arr[(ind - 1)/2])
        {
            int temp = arr[ind];
            arr[ind] = arr[(ind - 1)/2];
            arr[(ind - 1)/2] = temp;
            siftup(arr, (ind - 1)/2);
        }
    }
}

int main(void)
{
    int arr[] = {6, 5, 4, 1};
    int ind = 3;
    int n = 4;

    siftup(arr, ind);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}