#include <stdio.h>

// stack���� �Ű����� value�� �������� tempvalue, ���� �� ���ư� �� ��...
void modifyValue(int* value) {
    int tempvalue = 10;
    *value = tempvalue; // ���޵� value ���� ����
}

int main() {
    int num = 5;
    printf("���� ��: %d\n", num);
    modifyValue(&num); // �Լ��� ���� ����
    printf("���� ��: %d\n", num);

    return 0;
}

// �ڵ� -> .text (targetȯ�濡���� RAM�� �ȿű�� �״뵵 ���)
// Const ����, �ʱ�ȭ�� ��������-> .text(ROM)
// �ʱ�ȭ �ȵ� ���������� .bss(RAM) / 0���� �ʱ�ȭ -> xbss / �ʱ�ȭ o -> .data(RAM) / static �������� -> ó�� �����Ҷ� �ּҰ� ������
// stack : �Լ� �Ű�����, �������� -> �Ź� ���� -> stack overflow �������� �޸� ��� ���ѵ�.
// U-stack : ���ͷ�Ʈ �ƴ� ������ call �Ǵ� �Լ� (I-stack ħ���������� �޸� �뷮 ����)
// I-stack : ���ͷ�Ʈ�� ���� call�Ǵ� �Լ�
// data(��������; ��Ÿ�� �� ������ ���� -> ������ ���� ����)
//--------------------
// data
//---------------------
// U-stack (ũ�� ����ȭ)
//---------------------
// I-stack (ũ�� ����ȭ)
//---------------------
// ���ÿ����� ���� ������� �������.