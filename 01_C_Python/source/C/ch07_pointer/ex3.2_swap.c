#include <stdio.h>

void swap(int a, int b); // �Լ� ����

int main()
{
    int a = 10, b = 20;
    printf("swap() ȣ�� �� a�ּ�=%p, a=%d, b�ּ�=%p, b=%d\n", &a, a, &b, b);
    swap(a, b); // �Լ� ȣ��
    printf("swap() ȣ�� �� a�ּ�=%p, a=%d, b�ּ�=%p, b=%d\n", &a, a, &b, b);
}

//�Լ� ����(=�Լ� ����)
void swap(int a, int b) //�̷��� �ϸ� �ǹ�x (�Լ� ���ο����� �ٲ�)
{
    printf("�Լ� �� a�ּ�=%p, a=%d, b�ּ�=%p, b=%d\n", &a, a, &b, b);    

    int tmp = a;
    a = b;
    b = tmp;
}