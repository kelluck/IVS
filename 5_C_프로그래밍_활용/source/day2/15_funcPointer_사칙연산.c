#include <stdio.h>

int add(int a, int b) {
    return a + b;
}
//subtract �Լ� ����
int subtract(int a, int b) {
    return a - b;
}
//multiply �Լ� ����
int multiply(int a, int b) {
    return a * b;
}
//divide �Լ� ����
int divide(int a, int b) {
    if(b == 0)
    {
        printf("0���� ���� �� �����ϴ�.\n");
        return 0;
    }
    return a / b;
}

int main() {
    // �Լ� ������ ����
    int (*operation) (int, int);

    int num1, num2;
    char operator;
    printf("�� ������ �Է��ϼ���: ");
    scanf("%d %d", &num1, &num2);
    printf("�����ڸ� �����ϼ���(+, -, *, /): ");
    scanf(" %c", &operator);

    //operator���� operation ����
    switch (operator) { 
        case '+':
            operation = add;
            break;
        case '-':
            operation = subtract;
            break;
        case '*':
            operation = multiply;
            break;
        case '/':
            operation = divide;
            break;
        default:
            printf("��ȿ���� ���� �������Դϴ�.\n");
            return 1;
    }
    int result = operation(num1, num2);
    printf("���: %d\n", result);
    return 0;
}