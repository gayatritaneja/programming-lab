#include <stdio.h>
#include <stdlib.h>

char* shuffle(char* arr, int shift, int n);

int main(void)
{
    int n = 26;
    char* arr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = (char) i + (int) 'a';
        //printf("%c ", arr[i]);
    }
    //printf("\n");

    char* new_arr = shuffle(arr, 2, n);

    for (int i = 0; i < n; i++)
    {
        printf("%c ", new_arr[i]);
    }
    printf("\n");
}

char* shuffle(char* arr, int shift, int n)
{

    char* new_arr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        int num = (((int) arr[i] - (int) 'a') + shift) % 26;
        new_arr[i] = (char) (num + (int)'a');
    }
    return new_arr;

}