#include <stdio.h>
#include <stdlib.h>

void siftdown(int* arr, int i, int n)
{
    if ((2*i + 2) < n && (arr[(2*i)+1] >= arr[i] && arr[(2*i)+2] >= arr[i]))
    {
        return;
    }
    else if ((2*i) + 1 < n && (arr[(2*i)+1] >= arr[i]))
    {
        return;
    }
    else
    {
        if (arr[(2*i)+1] < arr[i])
        {
            int temp = arr[(2*i)+1];
            arr[(2*i)+1] = arr[i];
            arr[i] = temp;
            siftdown(arr, (2*i) + 1, n);
        }
        else if ((2*i) + 2 < n && arr[(2*i)+2] < arr[i])
        {
            int temp = arr[(2*i)+2];
            arr[(2*i)+2] = arr[i];
            arr[i] = temp;
            siftdown(arr, (2*i) + 2, n);
        }
    }
}

int main(void)
{
    int arr[] = {1, 4, 1, 2, 4};
    int ind = 1;
    int n = 5;

    siftdown(arr, ind, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
