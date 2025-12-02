#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n);

int main(void)
{
    int n = 101;
    if (isPrime(n) == 0)
    {
        printf("Not Prime\n");
    }
    else
    {
        printf("Prime\n");
    }
}

int isPrime(int n)
{
    for (int i = 2; i < (int) sqrt((double) n) + 1; i++)
    {
        if (n % i == 0)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    return 1;
}