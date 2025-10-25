//the number of hops becomes larger and larger of the frequency is high
//using a binary tree, every sequence becomes uniquw
//we will have to go through the list again and again and pick 2 minimum elements reliably
//bruteforce approach to print out the strings
//keep storing the bitstrings into a buffer and then print the buffer
//have a global buffer vairbale and instead of writing something to a file, we add this to this buffer
//singe & and | are bitwise operators

//char buf
//int bufsize = 0
//void output(FILE *X, int b)
//{
//  if bufsize == 8 -> fputc(X, buf); bufsize = 0;
//  else if bufsize == 0 -> buf = (buf << 1) | b (leftshift by 1); bufsize++; 
//}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 10;
    printf("%d\n", n >> 1); //significantly faster than a multiplication or division
}