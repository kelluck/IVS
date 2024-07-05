#include <stdio.h>

int main()
{
    int num;
    printf("몇단 구구단을 출력할까요 >>");
    scanf("%d", &num);
    printf("%d단 구구단입니다\n", num);
    for(int i = 1; i < 10; i++)
    {
        printf("%d x %d = %d\n", num, i, num*i);
    }    
}
