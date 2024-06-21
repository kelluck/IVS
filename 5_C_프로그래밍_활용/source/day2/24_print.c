#include <stdio.h>

// static int count = 0; //외부에서 참조 금지
int count = 0;

// static void print3()
void print3()
{
    count++;
    printf("print3 : %d\n", count);
}