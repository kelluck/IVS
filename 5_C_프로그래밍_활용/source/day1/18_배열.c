#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>

unsigned int binaryToDecimal(unsigned numOfDigit, unsigned int no)
{
    for(int i = 0; i < numOfDigit; i++)
    {
        no *= 2;
    }
    return no;
}

int main()
{
    unsigned int num = 0;
    unsigned int arr[8] = {0,};
    unsigned int index = 0;
    unsigned int decimal = 0;

    printf("��ȣ�� ����(unsigned) �������� 0�ڸ����� 8�� �Է��ϼ���\n");

    while(index < 8)
    {
        scanf("%d", &num);
        arr[index] = num;
        index++;
    }
    
    for(int i = 0; i < 8; i++)
    {
        decimal += binaryToDecimal(i, arr[i]);
    }

    printf("2���� �� : ");
    for(int i = 7; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }

    printf("\n");
    printf("10���� �� : %d\n", decimal);

    return 0;
}