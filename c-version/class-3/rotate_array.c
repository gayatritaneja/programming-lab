#include <stdio.h>
#include <stdlib.h>

void rotateArray(int* arr, int n, int rot);
int main(void)
{
    int n = 5;
    int* arr;
    arr = (int*) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    rotateArray(arr, n, 2);

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
    printf("printing buffer: ");
    for (int i = 0; i < rot; i++)
    {
        buf[i] = arr[i];
        printf("%d ", buf[i]);
    }
    printf("\n");


    printf("printing arr mid-rotation: ");
    for (int i = rot; i < n; i++)
    {
        arr[i - rot] = arr[i];
    }

<<<<<<< HEAD
    for (int i = 0; i < n; i++)
=======
    for (int i = 0; i < rot; i++)
>>>>>>> 4410b70f6ff1d518988469d352eb268dc00f7238
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = rot + 1; i < n; i++)
    {
        arr[i] = buf[i - rot - 1];
    }

    free(buf);
}
