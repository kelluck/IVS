#include <stdio.h>

int main()
{
    int floor = 4;
    for(int i = 0; i < floor; i++)
    {
        for(int j = i; j < floor; j++) printf(" ");
        for(int k = 0; k < i*2+1; k++) printf("*");
        printf("\n");
    }
}