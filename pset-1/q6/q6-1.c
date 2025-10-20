#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    char arr[n];
    int freq[27];

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter string: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &arr[i]);
    }

    for (int i = 0; i < 27; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int val = (int) (arr[i] - 'a');
        if (val > 25)
        {
            freq[26] ++;
        }
        else
        {
            freq[val] ++;
        }
    }

    for (int i = 0; i < 27; i++)
    {
        if (freq[i] != 0)
        {
            char c = (char) (i + (int) 'a');
            printf("%c: %d\n", c, freq[i]);
        }
    }
    printf("\n");
}