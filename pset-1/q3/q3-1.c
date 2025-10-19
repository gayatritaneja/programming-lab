#include <stdio.h>
#include <stdlib.h>

void siftup(int n, int* arr, int i);

int main(void)
{
    int n = 4;
    int arr[] = {6, 5, 4, 1};
    int i = 3;

    siftup(n, arr, i);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

void siftup(int n, int* arr, int i)
{
    if (i == 0 || arr[(i-1)/2] <= arr[i])
    {
        return;
    }

    else if (arr[(i-1)/2] > arr[i])
    {
        int temp = arr[i];
        arr[i] = arr[(i-1)/2];
        arr[(i-1)/2] = temp;
        siftup(n, arr, (i-1)/2);
    }

}