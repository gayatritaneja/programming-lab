#include <stdio.h>
#include <stdlib.h>

typedef unsigned long BYTECOUNTER;
typedef struct htree
{
    unsigned char c;
    struct htree* parent;
    struct htree* left;
    struct htree* right;
    BYTECOUNTER cfreq;
}huffman;

huffman ht[512];
huffman* root;
int in8, ct8;

static int decompress(FILE* fi, huffman* h)
{
    while (h->right != NULL)
    {
        if (inbit(fi)) //if 1
        {
            h = h->left;
        }
        else //if 0
        {
            h = h->right;
        }
    }
    return h->c;
}
void buildtree(void)
{
    int treect = 256;
    int i;
    huffman *h1, *h2;
    while(1)
    {
        h1 = h2 = NULL;
        for (i = 0; i < treect; i++)
        {
            if (ht[i].cfreq > 0 && ht[i].parent == NULL)
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
        if (h2 == NULL)
        {
            root = h1;
            break;
        }
        h1->parent = ht+treect;
        h2->parent = ht+treect;
        ht[treect].cfreq = h1->cfreq + h2->cfreq;
        ht[treect].right = h1;
        ht[treect].left = h2;
        treect ++;
    }
}

int main(int argc, char* argv[])
{
    FILE* fi;
    FILE* fo;
    unsigned char c;
    BYTECOUNTER bytectr;
    long freqctr;

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

    // open input file and check if it a valid one or exit
    if ((fi = fopen(argv[1], "rb")) == NULL)
    {
        printf("\nCannot open %s", argv[1]);
        fclose(fi);
        exit(EXIT_FAILURE);
    }

    if ((fo = fopen(argv[2], "wb")) == NULL)
    {
        printf("\nCannot open %s", argv[2]);
        fclose(fo);
        exit(EXIT_FAILURE);
    }

    fread(&bytectr, sizeof bytectr, 1, fi);
    fread(&freqctr, sizeof freqctr, 1, fi);

    while(freqctr --)
    {
        fread(&c, sizeof(char), 1, fi);
        ht[c].c = c;
        fread(&ht[c].cfreq, sizeof(BYTECOUNTER), 1, fi);
    }
    buildtree();
    while(bytectr--)
    {
        fputc(decompress(fi, root), fo);
    }
    fclose(fi);
    fclose(fo);
    printf("\nDone\n");
}