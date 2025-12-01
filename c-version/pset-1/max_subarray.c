#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 9;
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int sum;
    int max;
    int start_ind = 0;
    int end_ind = 0;

    max = arr[0];
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (max < sum)
            {
                max = sum;
                start_ind = i;
                end_ind = j;
            }
        }
    }

    printf("%d\n", max);
    for (int i = start_ind; i <= end_ind; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}