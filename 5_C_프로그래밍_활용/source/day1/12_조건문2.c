#include<stdio.h>
#include<stdlib.h>

int main() {
    float num1 = 0.1f;
    char c1 = 'a';

    if (num1 == 0.1f) // �Ǽ� ��
        printf("0.1�Դϴ�.\n");

    if (c1 == 'a') // ���� ��
        printf("a�Դϴ�.\n");

    if (c1 == 97) // ���ڸ� ASCII �ڵ�� ��
        printf("a�Դϴ�.\n");

    if (num1*num1 == 0.01f) // false!!!!
        printf("0.01�Դϴ�.\n");
    else
        printf("0.01�� �ƴմϴ�.\n");
    
    printf("%f\n",num1*num1);
    system("pause");
    return 0;
}