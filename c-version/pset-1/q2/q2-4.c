#include <stdio.h>
#include <stdlib.h>

void mergeSort(int* arr, int left, int right);
void merge(int* arr, int left, int mid, int right);
int main(void)
{
    int n = 9;
    int arr[] = {5, 1, 7, 5, 6, 7, 8, 2, 4};
    mergeSort(arr, 0, 8);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

}

void mergeSort(int* arr, int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int* arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}