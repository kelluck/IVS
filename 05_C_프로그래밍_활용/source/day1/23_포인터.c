#include <stdio.h>
int main() {
    int array[5] = {10, 20, 30, 40, 50}; // 5���� ������ ������ �迭 ����
    int *ptr1 = &array[0]; // 0 ��° ������ ���� ������ �Ҵ�
    int *ptr2 = &array[4]; // 4 ��° ������ ���� ������ �Ҵ�

    int difference = ptr2 - ptr1; // �� �������� ����
    
    printf("0 ��° ������ ��: %p\n", *ptr1);
    printf("4 ��° ������ ��: %p\n", *ptr2);
    printf("0 ��° ������ 4 ��° ������ ����: %d\n", difference);
    return 0;
}