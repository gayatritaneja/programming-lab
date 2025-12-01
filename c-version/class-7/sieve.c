#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int n = 15;
    int count = 5;
    int arr[n];
    int counter = 0;

    arr[0] = 0;
    arr[1] = 0;
    //setting all elements of the sieve to true
    for (int i = 2; i < n; i++)
    {
        arr[i] = 1;
    }


    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < n; j+=i)
        {
            if (j != i)
            {
                arr[j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            counter ++;
            if (count == counter)
            {
                printf("%dth prime number: %d\n", count, i);
            }
        }
    }
}