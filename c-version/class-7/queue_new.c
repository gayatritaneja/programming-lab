#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int main(void)
{
    int start = 0;
    int length = 0;
    int *q = (int*) malloc(sizeof(int) * MAX);

    start = add(start, length, q, 23);
    start = remove(start, length, q);


}

int add(int start, int length, int* q, int data)
{
    q[start+length - 1] = data;
}

int remove(start, length, int* q)
{

}