#include <stdio.h>

// Union ����
union Data { //���� ū �ڷ��� �������� ������ ����� ���� ����.
    char c;
    int d;
    float f;
};

int main() {
    union Data data;
    data.d = 1661; //�ʱ�ȭ �ʼ�. �׳� ������ ���� �����ȴ�.
    printf("int value: %d\n", data.d);
    printf("Char value from int: %d\n", data.c);
    data.c = 3;
    printf("int value: %d\n", data.d);
    printf("Char value from int: %d\n", data.c);
    data.f = 2.71828f;
    printf("Float value: %f\n", data.f);
    printf("Char value from float: %d\n", data.c);
    return 0;
}