#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isCoPrime(int a, int b);
int gcd(int a, int b);

int main(void)
{
    int n;
    int arr[] = {2, 3, 13, 5, 14, 6, 7, 11};
    bool valid = true;
    n = sizeof(arr)/sizeof(int);
    int max = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = arr[i];
        valid = true;
        for (int j = i+1; j < n; j++)
        {
            for (int k = i; k < j; k++)
            {
                if (isCoPrime(arr[k], arr[j]) == false)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                printf("%d ", arr[j]);
                sum += arr[j];
            }
        }
        printf("\n");
        if (sum > max)
        {
            max = sum;
        }
    }
    
    printf("%d\n", max); 
}

bool isCoPrime(int a, int b)
{
    if (gcd(a, b) != 1)
    {
        return false;
    }
    return true;
}

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }

    if (a == b)
    {
        return a;
    }

    if (a > b)
    {
        if (a % b == 0)
        {
            return b;
        }
        return gcd(a-b, b);
    }

    if (b % a == 0)
    {
        return a;
    }
    return gcd(a, b-a);
}