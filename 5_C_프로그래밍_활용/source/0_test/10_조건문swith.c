#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
// state machine 설계할 때 switch 사용
// 숫자가 충분히 작으면(100이하) if문보다 switch가 더 빠르다
// -> 컴파일러에 따라 다름! 충분히 고민할것
int main()
{
    int num1;
    scanf("%d",&num1);
    switch(num1)
    {
        case 1:
            printf("1입니다.\n");
            break;
        case 2:
            printf("2입니다.\n");
            break;
        default:
            printf("default.\n");
            break;
    }
}