#include<stdio.h>
#include<stdlib.h>

int main()
{
    float diff = 1;
    for(int i = 0; ; i++)
    {
        diff *= (1 - i/365.0);
        printf("studentNumber : %d, diffPercent : %f\n", i+1, diff);
        if(diff < 0.5)
        {
            printf("�������� %d�� �̻��϶� �����̰� �̱� Ȯ���� ����!\n", i+1);
            break;
        }
    }
}