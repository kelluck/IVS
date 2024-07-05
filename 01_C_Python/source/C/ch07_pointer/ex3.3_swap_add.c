#include <stdio.h>

void swap_addr(int* a, int* b); // �Լ�(Call by reference) ����

int main()
{
    int a = 10, b = 20;
    printf("swap() ȣ�� �� a�ּ�=%p, a=%d, b�ּ�=%p, b=%d\n", &a, a, &b, b);
    swap_addr(&a, &b); // �Լ� ȣ��
    printf("swap() ȣ�� �� a�ּ�=%p, a=%d, b�ּ�=%p, b=%d\n", &a, a, &b, b);
}

//�Լ� ����(=�Լ� ����)
void swap_addr(int* a, int* b)
{
    printf("�Լ� �� a�ּ�=%p, a=%d, b�ּ�=%p, b=%d\n", a, *a, b, *b);    

    int tmp = *a;
    *a = *b;
    *b = tmp;
}