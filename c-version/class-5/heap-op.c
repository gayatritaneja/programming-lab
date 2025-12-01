#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int insert(int* heap, int key, int i);
void siftup(int* heap, int i);
int extract_min(int* heap, int* n);
void siftdown(int* heap, int i, int n);
void build_heap(int* heap, int n);
int extract_element(int* heap, int n, int key);

int main(void)
{
    int n = 13;
    int init[] = {5, 19, 15, 23, 81, 18, 20, 30, 40, 90, 82, 25, 42};
    int heap[MAX];

    for (int i = 0; i < n; i++)
    {
        heap[i] = init[i];
    }

    printf("Initial heap (%d elements):\n", n);
    for (int k = 0; k < n; ++k) printf("%d ", heap[k]);
    printf("\n\n");

    /* test build_heap: heapify the array and print result */
    build_heap(heap, n);
    printf("Heap after build_heap (%d elements):\n", n);
    for (int k = 0; k < n; ++k) printf("%d ", heap[k]);
    printf("\n\n");

    /* insert a few keys */
    n = insert(heap, 10, n);
    n = insert(heap, 2, n);
    n = insert(heap, 17, n);

    printf("Heap after inserts (%d elements):\n", n);
    for (int k = 0; k < n; ++k) printf("%d ", heap[k]);
    printf("\n\n");

    /* test extract_min a few times */
    for (int iter = 0; iter < 3 && n > 0; ++iter)
    {
        int extracted = extract_min(heap, &n);
        printf("Extracted min: %d (size now %d)\n", extracted, n);
        printf("Heap after extract:\n");
        for (int k = 0; k < n; ++k) printf("%d ", heap[k]);
        printf("\n\n");
    }

    /* test extract_element: remove a couple of known keys and print result */
    {
        int key = 81;
        printf("Removing element %d\n", key);
        n = extract_element(heap, n, key);
        printf("Heap after removing %d (size %d):\n", key, n);
        for (int k = 0; k < n; ++k) printf("%d ", heap[k]);
        printf("\n\n");
    }

    {
        int key = 2;
        printf("Removing element %d\n", key);
        n = extract_element(heap, n, key);
        printf("Heap after removing %d (size %d):\n", key, n);
        for (int k = 0; k < n; ++k) printf("%d ", heap[k]);
        printf("\n\n");
    }

    return 0;
}

int insert(int* heap, int key, int n)
{
    heap[n] = key;
    siftup(heap, n);
    n ++;
    return n;
}

void siftup(int* heap, int i)
{

    while (i > 0)
    {
        int parent = (i - 1)/2;

        if (heap[parent] <= heap[i])
        {
            break;
        }

        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

int extract_min(int* heap, int* n)
{
    if (*n <= 0)
    {
        return -1;
    }

    int min = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    siftdown(heap, 0, *n);
    return min;
}

void siftdown(int* heap, int i, int n)
{
    while(1)
    {
        int child1 = (2 * i) + 1;
        int child2 = (2 * i) + 2;
        int smallest = i;

        if (child1 < n && heap[child1] < heap[smallest])
        {
            smallest = child1;
        }

        if (child2 < n && heap[child2] < heap[smallest])
        {
            smallest = child2;
        }

        if (smallest == i)
        {
            break;
        }

        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        i = smallest;
    }
}

void build_heap(int* heap, int n)
{
    for (int i = (n/2) - 1; i >= 0; --i)
    {
        {
            siftdown(heap, i, n);
        }
    }
}

int extract_element(int* heap, int n, int key)
{
    int i = -1;
    for (int j = 0; j < n; j++)
    {
        if (heap[j] == key)
        {
            i = j;
            break;
        }
    }

    if (i == -1) 
    {
        return n;
    }

    heap[i] = heap[n -1];
    n --;

    if (i > 0 && heap[i] < heap[(i - 1)/2])
    {
        siftup(heap, i);
    }
    else
    {
        siftdown(heap, i, n);
    }
    return n;
}