#include <stdio.h>
#include <stdlib.h>
int main() 
{
    long long *numPtr1; // long long형 포인터 선언
    float *numPtr2; // float형 포인터 선언
    char *cPtr1; // char형 포인터 선언

    long long num1 = 10;
    float num2 = 3.5f;
    char c1 = 'a';

    numPtr1 = &num1;
    numPtr2 = &num2;
    cPtr1 = &c1;

    printf("%lld\n", *numPtr1); // 시작주소부터 8byte를 던져줌
    printf("%f\n", *numPtr2); // 시작주소부터 4byte를 던져줌
    printf("%c\n", *cPtr1); // 시작주소부터 1byte를 던져줌 -> 포인터의 타입은 컴파일될때 중요!

    system("pause");
    return 0;
}