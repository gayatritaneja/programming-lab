#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//given a parent, we can say the children are at poitions 2i+1 and 2i+2
//extracting the minmum element is easier because it is ALWAYS at position zero
//H = {.....}
//reduce n by one
//H[0] = H[n]
//you are a particular position in the array and you know that you are wrong, how do you correct it? we use siftdown(h, i, 1), swap i with lesser child and 2i+1, qi+2 shouldn't cross n
//if H[2*i+1] < H[2*i+2], swap this with the i
//recursively keep doing the algorithm until you reach the base case -> the parent is less that the children

int n = 70-50;

void rotateArray(int *a, int n, int rot);

int main(void)
{
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 50;
    }

    rotateArray(arr, n, 5);

    for (int j = 0; j < n; j++)
    {
        printf("%d\n", arr[j]);
    }
    
}

void rotateArray(int* a, int n, int rot)
{
    int* buf = (int *) malloc(rot * sizeof(int));

    memcpy(buf, a, rot * (sizeof(int)));

    for (int i = rot; i < n; i++)
    {
        a[i - rot] = a[i];
    }

    memcpy(&a[n - rot], buf, rot*(sizeof(int)));
    
    free(buf);
}