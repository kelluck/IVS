#include <stdio.h>
#include <stdlib.h>

// extern void print3();
extern int count;

void print1() {
    int count = 0;
    count++;
    printf("print1 : %d\n", count);
}

void print2() {
    static int count = 0;
    count++;
    printf("print2 : %d\n", count);
}

int main()
{
    print1();
    print1();
    print1();
    print2();
    print2();
    print2();
    print3();
    print3();
    print3();
    print3();
    printf("count : %d\n", count);
    system("pause");
    return 0;
}