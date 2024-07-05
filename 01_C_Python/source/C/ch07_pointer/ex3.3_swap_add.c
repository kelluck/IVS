#include <stdio.h>

void swap_addr(int* a, int* b); // 함수(Call by reference) 선언

int main()
{
    int a = 10, b = 20;
    printf("swap() 호출 전 a주소=%p, a=%d, b주소=%p, b=%d\n", &a, a, &b, b);
    swap_addr(&a, &b); // 함수 호출
    printf("swap() 호출 전 a주소=%p, a=%d, b주소=%p, b=%d\n", &a, a, &b, b);
}

//함수 구현(=함수 정의)
void swap_addr(int* a, int* b)
{
    printf("함수 안 a주소=%p, a=%d, b주소=%p, b=%d\n", a, *a, b, *b);    

    int tmp = *a;
    *a = *b;
    *b = tmp;
}