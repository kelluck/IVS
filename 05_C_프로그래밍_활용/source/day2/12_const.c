#include <stdio.h>
void modifyValue(int *value) {
    int tempvalue = 10;
    //const temp = 10;
    //temp = 20;
    *value = tempvalue; // const int num������ �����͸� ���� ���� ����!
}

int main() {
    const int num = 5;
    printf("���� ��: %d\n", num);
    modifyValue(&num); // �Լ��� �����͸� ����
    printf("���� ��: %d\n", num);
    return 0;
}

/*
const int num = 10; -> �� ���� �Ұ�
const int* ptr = &num; -> �� ����Ұ�
int* const ptr = &num;
const int* const ptr = &num;

RAM�� byte�����̱� ������ ������ ����
const������ code�� -> ���� ������ ������
*/