#include <stdio.h>
//#�� �����Ϸ��� �ƴ϶� ��ó��������! functionó�� �����ϱ� ���� ��ȣ�� ���� �����
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int num1 = 20;
    int num2 = 30;
    int max_result = MAX(num1, num2);
    int min_result = MIN(num1, num2);

    printf("���� 1: %d\n", num1);
    printf("���� 2: %d\n", num2);
    printf("�ִ�: %d\n", max_result);
    printf("�ּڰ�: %d\n", min_result);

    return 0;
}