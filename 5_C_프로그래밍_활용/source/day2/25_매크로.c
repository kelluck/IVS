#include <stdio.h>
#define ADD(a, b) ((a) + (b))
#define SUBTRACT(a, b) ((a) - (b))

int main() {
    int num1 = 20;
    int num2 = 10;
    int sum_result = ADD(num1, num2);
    int diff_result = SUBTRACT(num1, num2);

    printf("���� 1: %d\n", num1);
    printf("���� 2: %d\n", num2);
    printf("���� ���: %d\n", sum_result);
    printf("���� ���: %d\n", diff_result);

    return 0;
}