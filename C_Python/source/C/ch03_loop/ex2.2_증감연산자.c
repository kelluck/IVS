#include <stdio.h>
// 증감연산자 : ++ --
int main()
{
    int n1 = 10;
    printf("++n1 = %d\n", ++n1); //++연산 먼저 수행 -> 11

    printf("n1++ = %d\n", n1++); //명령어 수행 후 ++연산 -> 11
    printf("n1=%d\n", n1); //-> 12
}