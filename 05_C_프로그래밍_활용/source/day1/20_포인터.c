#include <stdio.h>
#include <stdlib.h>

int main() {
    // ������ ���� ����
    int *numPtr;
    int num1 = 10;

    // num1�� �޸� �ּҸ�
    // ������ ������ ����
    numPtr = &num1;

    printf("%p, %d\n", numPtr, *numPtr);
    printf("%p, %d\n", &num1, num1);
    printf("%d\n", sizeof(numPtr)); //��� �������� size�� �ڷ����� �޶� ����. 32bit compiler�� 4byte / 64bit compiler�� 8byte 
    printf("%d\n", sizeof(int*));
    printf("%d\n", sizeof(char*)); 
    system("pause");
    return 0;
}