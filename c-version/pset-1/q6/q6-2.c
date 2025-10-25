#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int shift;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter shift: ");
    scanf("%d", &shift);
    printf("Enter string: ");

    char arr[n];
    char shifted[n];

    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &arr[i]);
    }

    int val;
    for (int i = 0; i < n; i++)
    {
        val = (int) (((arr[i] - 'a') + shift) % 26);
        shifted[i] = (char) (val + 97);
        printf("%c", shifted[i]);
    }
    printf("\n");
}