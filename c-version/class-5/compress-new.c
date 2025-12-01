#include <stdio.h>
#include <stdlib.h>

typedef unsigned long BYTECOUNTER;
typedef struct htree
{
    BYTECOUNTER cfreq;
    struct htree* left;
    struct htree* right;
    struct htree* parent;
    char c;
}huffman;

huffman ht[512];
huffman* root;
char out8;
int ct8;

void outbit(FILE* fo, int bit)
{
    if (ct8 == 8 || bit == -1)
    {
        fputc(out8, fo);
        ct8 = 0;
    }
    out8 = (out8 << 1) | bit;
    ct8++;
}

void compress(FILE* fo, huffman* h, huffman* child)
{
    if (h->parent != NULL)
    {
        compress(fo, h->parent, h);
    }
    if (child)
    {
        if (child == h->right)
        {
            outbit(fo, 0);
        }
        else if (child == h->left)
        {
            outbit(fo, 1);
        }
    }
}

void buildtree(void)
{
    int treect = 256;
    int i;
    huffman *h1;
    huffman *h2;

    while(1)
    {
        h1 = h2 = NULL;
        for (i = 0; i < treect; i++)
        {
            if (ht + i != h1)
            {
                if (ht[i].cfreq != 0 && ht[i].parent == NULL)
                {
                    if (h1 == NULL || ht[i].cfreq < h1->cfreq)
                    {
                        if (h2 == NULL || h1->cfreq < h2->cfreq)
                        {
                            h2 = h1;
                            h1 = ht + i;
                        }
                    }
                    else if (h2 == NULL || ht[i].cfreq < h2->cfreq)
                    {
                        h2 = ht + i;
                    }
                }
            }
        }
        if (h2 == NULL)
        {
            root = h1;
            break;
        }
        h1->parent = ht + treect;
        h2->parent = ht + treect;
        ht[treect].left = h1;
        ht[treect].right = h2;
        ht[treect].cfreq = h1->cfreq + h2->cfreq;
    }

}

int main(int argc, char* argv[])
{
    FILE *fi, *fo;
    int c;
    BYTECOUNTER bytectr = 0; //total bytes
    long freqctr = 0; //no. of unique characters

    // check if everything has been input and collect if not
    if (argc != 3)
    {
        printf("\nUsage: compress infile outfile.\n");
        if (argc > 3)
        {
            printf("\nOnly the first two files will be used.\n");
        }
        if (argc == 1)
        {
            printf("\nEnter Input filename.\n");
            fgets(argv[1], sizeof(argv[1]), stdin);
            argc++;
        }
        if (argc == 2)
        {
            printf("\nEnter output filename.\n");
            fgets(argv[2], sizeof(argv[2]), stdin);
            argc++;
        }
    }

    if ((fi = fopen(argv[1], "rb")) == NULL)
    {
        printf("Error opening input file.\n");
        fclose(fi);
        exit(EXIT_FAILURE);
    }

    if ((fo = fopen(argv[2], "wb")) == NULL)
    {
        printf("Error opening output file.\n");
        flcose(fo);
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(fi)) != EOF)
    {
        c &= 255;
        if (ht[c].cfreq == 0)
        {
            freqctr ++;
            ht[c].c = c;
        }
        ht[c].cfreq ++;
        bytectr ++;
    }

    fwrite(&bytectr, sizeof bytectr, 1, fi);
    fwrite(&freqctr, sizeof freqctr, 1, fi);

    for (c = 0; c < 256; c++)
    {
        if (ht[c].cfreq > 0)
        {
            fwrite(&ht[c].c, sizeof(char), 1, fo);
            fwrite(&ht[c].cfreq, sizeof(BYTECOUNTER), 1, fo);
        }
    }

    buildtree();

    fseek(fi, 0l, 0);

    while ((c = fgetc(fi)) !=  EOF)
    {
        compress(fo, ht + (c & 255), NULL);
    }
    outbit(fo, -1);
    fclose(fi);
    fclose(fo);
    printf("\nDone. \n");

}