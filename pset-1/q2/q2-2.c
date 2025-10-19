#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void maxMin(int arr[MAX], int n);

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

    maxMin(arr, n);

}

/*
Iterate the array pair wise, and have a greater and lesser
compare greater to max and lesser to min
Time complexity is still O(n), but the comparisons are a lot lesser than the general appraoch
*/

void maxMin(int arr[MAX], int n)
{
    int* min = malloc(sizeof(int));
    int* max = malloc(sizeof(int));
    int i;
    int smaller;
    int larger;

    if (n%2 == 0)
    {
        *min = (arr[0] < arr[1]) ? arr[0] : arr[1];
        *max = (arr[0] < arr[1]) ? arr[1] : arr[0];
        i = 2;
    }
    else
    {
        *min = *max = arr[0];
    }

    while (i < n - 1)
    {
        smaller = (arr[i] < arr[i+1]) ? arr[i] : arr[i+1];
        larger = (arr[i] < arr[i+1]) ? arr[i+1] : arr[i];

        if (smaller < *min)
        {
            *min = smaller;
        }
        if (larger > *max)
        {
            *max = larger;
        }
        i += 2;
    }
    printf("Minimum: %d\nMaximum: %d\n", *min, *max);
}