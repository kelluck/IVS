#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
// state machine ������ �� switch ���
// ���ڰ� ����� ������(100����) if������ switch�� �� ������
// -> �����Ϸ��� ���� �ٸ�! ����� ����Ұ�
int main()
{
    int num1;
    scanf("%d",&num1);
    switch(num1)
    {
        case 1:
            printf("1�Դϴ�.\n");
            break;
        case 2:
            printf("2�Դϴ�.\n");
            break;
        default:
            printf("default.\n");
            break;
    }
}