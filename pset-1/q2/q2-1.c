#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(void)
{
    int n;
    int* arr;
    arr = (int*) malloc(sizeof(int)*MAX);
    printf("Enter number: ");
    scanf("%d", &n);

    printf("Enter elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("Maximum element: %d\n", max);
}