#include <stdio.h>

int main()
{
    for(int dansu = 2; dansu < 10; dansu++)
    {
        printf("-----%d단-----\n", dansu);
        for(int j = 1; j < 10; j++)
        {
            printf("%d x %d = %d\n", dansu, j, dansu*j);
        }
        printf("\n");
    }
}