#include <stdio.h>
int main() {
    int x = 5;
    int y = 10;
    if (x < 0 && y++ == 15){ // &&���� ������ �����̸� �������� ���� ����.
        printf("�� �ڵ�� ������� �ʽ��ϴ�.\n");
    }

    printf("y = %d\n", y); // 11�� �ƴ϶� 10�� ���
    return 0;
}