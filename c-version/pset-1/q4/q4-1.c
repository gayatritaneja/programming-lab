#include <stdio.h>
#include <stdlib.h>

void siftdown(int n, int* arr, int i);

int main(void)
{
    int n = 5;
    int arr[] = {1, 4, 1, 2, 4};
    int i = 1;

    siftdown(n, arr, i);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

void siftdown(int n, int* arr, int i)
{
    if ((2*i + 1) < n && (arr[(2*i)+1] >= arr[i] && arr[(2*i)+2] >= arr[i]))
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
            siftdown(n, arr, 2*i);
        }
        else if ((2*i)+2 < n && arr[(2*i)+2] < arr[i])
        {
            int temp = arr[(2*i)+2];
            arr[(2*i)+2] = arr[i];
            arr[i] = temp;
            siftdown(n, arr, (2*i)+ 1);
        }
    }

}