#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(void)
{
    int n = 6;
    int arr[] = {1, 4, 7, 9, 11, 2};

    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int max2 = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max2 && arr[i] != max)
        {
            max2 = arr[i];
        } 
    }

    printf("%d\n", max2);
}