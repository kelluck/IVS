#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>

// c언어는 0빼고 다 참이다.

int main()
{
    float input, average = 0;
    int sum = 0;
    for(int i = 1; i <= 5; i++)
    {
        scanf("%f", &input);
        sum += input;
        average = (float)sum / i;
        printf("average : %f\n", average);
    }    

    return 0;
}
