#include <stdio.h>
/*
반복문: for(특정 횟수 반복)
        while(조건 만족시 반복)
        do~while(1회 수행 후 조건 만족시 반복)
*/

int main()
{
    for(int i = 0; i <= 10; i++)         //1. int i = 0, 2.i <= 10, 3.{ }, 4.i++ / 1->2->3->4->2->3->4->2->3->4->...
    {
        printf("%d. Hello, world\n", i);
    }
}