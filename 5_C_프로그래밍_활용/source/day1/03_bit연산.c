#include <stdio.h>

int main()
{
    unsigned char num1 = 131; // 131: 1000 0011
    char num2 = -125; // -125: 1000 0011
    printf("%u\n", num1 >> 5);
    printf("%d\n", num2 >> 5);

    char num11 = 113; // 113: 0111 0001
    char num12 = -15; // -15: 1111 0001
    char num13, num4, num5, num6;
    printf("%d\n", (char)(num11 << 2));
    printf("%d\n", (char)(num12 << 2));
    printf("%d\n", (char)(num11 << 4));
    printf("%d\n", (char)(num12 << 4));

    int num21 = -2000; // -2000: 1111 1000 0011 0000
    printf("%d\n", num21 / 256); // ������ ���� ����, �������� ����(���� �ٸ�!)
    printf("%d\n", num21 >> 8); // ������ ������ ������ ������ ���� �Ⱦ����� ��Ʈ�� �ű涧 ���

    return 0;
}