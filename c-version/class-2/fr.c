#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    FILE* inptr;
    FILE* outptr;
    int n = 27;
    int* arr;
    arr = (int*) malloc(sizeof(int));
    char c; 
    int val;

    for (int i = 0; i < n; i++)
    {
        *(arr+i) = 0;
    }

    inptr = fopen("copy.txt", "r");
    outptr = fopen("output.txt", "w");

    if (inptr == NULL)
    {
        printf("Could not open file.");
        return 1;
    }
    
    while ((c = fgetc(inptr)) != EOF)
    {
        val = (int) c - 'a';
        if (val >= 0 && val <= 26)
        {
            *(arr + val) += 1;
        }
        else
        {
            *(arr + 26) += 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(outptr, "%i", *(arr + i));
    }

    fclose(inptr);
    fclose(outptr);
    free(arr);
}