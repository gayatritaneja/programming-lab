#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inptr;
    FILE *outptr;
    char c;
    int n = 27;
    int* a;
    a = (int*) malloc(n * sizeof(int));
    //int a[27];
    int val;

    // zero out array
    for (int i = 0; i < n; i++)
    {
        *(a + i) = 0;
    }

    // opening file
    inptr = fopen("copy.txt", "r");
    outptr = fopen("output.txt", "w");

    // checking for file opening error
    if (inptr == NULL)
    {
        printf("failed to open file.\n");
        return 1;
    }

    // iterate over all characters in a and append to a
    while ((c = fgetc(inptr)) != EOF)
    {
        val = (int) c - 'a';
        if (val >= 0 && val <= 26)
        {
            *(a + val) += 1;
        }
        else
        {
            *(a + 26) += 1;
        }
    }

    for (int i = 0; i < 27; i++)
    {
        fprintf(outptr, "%i", *(a + i));
    }

    printf("Execution Completed!\n");
    fclose(inptr);
    fclose(outptr);
    free(a);
}