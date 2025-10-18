#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void siftdown(int heap[], int i, int n);
int extract(int heap[]);

int n = 13;
int i = 0;
int heap[] = {5, 19, 15, 23, 81, 18, 20, 30, 40, 90, 82, 25, 42};

int main(void)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", heap[i]);
    }

    printf("%d ", n);

    extract(heap);
    //siftdown(heap, i, n);
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("%d ", n);
}

int extract(int heap[])
{
    printf("%d\n", heap[n-1]);
    int temp = heap[0];
    heap[0] = heap[n-1];
    n--;
    return temp;
}

void siftdown(int heap[], int i, int n)
{
    if (n <= (2*i+2))
    {
        if (heap[i] < heap[2*i+1] && heap[i] < heap[2*i+2])
        {
            return;
        }
        else if (heap[2*i+1] <= heap[2*i+2]) 
        {
            int temp = heap[0];
            heap[0] = heap[2*i+1];
            heap[2*i+1] = temp;
            siftdown(heap, 2*i+i, n);
        }
        else if (heap[2*i+1] > heap[2*i+2]) 
        {
            int temp = heap[0];
            heap[0] = heap[2*i+2];
            heap[2*i+2] = temp;
            siftdown(heap, 2*i+2, n);
        }
    }
}

//starting with an array, how do you convert it into a heap?