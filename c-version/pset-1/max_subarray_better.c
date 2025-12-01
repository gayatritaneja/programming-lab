#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(arr)/sizeof(int);
    int start = 0;
    int end = 0;
    int temp_start = 0;
    int max_sum = arr[0];
    int curr_sum = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > (arr[i] + curr_sum))
        {
            curr_sum = arr[i];
            temp_start = i;
        }
        else
        {
            curr_sum += arr[i];
        }

        if (curr_sum > max_sum)
        {
            max_sum = curr_sum;
            start = temp_start;
            end = i;
        }
    }

    printf("%d\n", max_sum);
    for (int i = 0; i <= end; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}