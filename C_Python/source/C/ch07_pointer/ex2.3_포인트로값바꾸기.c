#include <stdio.h>

int main()
{
    int a = 1, b = 2;
    int* pointer;
    
    pointer = &a;
    *pointer *= 3; // *pointer = *pointer * 3
    
    pointer = &b;
    *pointer *= 3; // b�� ����
    printf("a���� : %d\n", a);
    printf("b���� : %d\n", b);
    printf("pointer������ ����Ű�� �ּ� : %p, ��:%d\n", pointer, *pointer);
    printf("a���� �ּ� : %p\n", &a);
    printf("b���� �ּ� : %p\n", &b);
}