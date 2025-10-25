#include <stdio.h>
#include <stdlib.h>

void rotateArray(int* arr, int n, int rot);
int main(void)
{
    int n = 5;
    int* arr;
    arr = (int*) malloc(sizeof(int) * n);

    for (int i = 1; i <= n; i++)
    {
        *(arr + i - 1) = i;
    }

    rotateArray(arr, n, 6);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    free(arr);
}

void rotateArray(int* arr, int n, int rot)
{
    if (!arr || n <= 0) return;
    rot = ((rot % n) + n) % n;
    if (rot == 0) return;

    int count = 0;
    int* buf;
    buf = (int*) malloc(sizeof(int) * rot);

    // adding first rot elements to buffer
    for (int i = 0; i < rot; i++)
    {
        buf[i] = arr[i];
    }

    // shifting elements from rot to n-1 to the left
    for (int i = rot; i < n; i++)
    {
        arr[i-rot] = arr[i];
        count ++;
    }

    for (int i = 0; i < 2; i++)
    {
        arr[count + i] = buf[i];
    }
    free(buf);
}