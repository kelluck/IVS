#include <stdio.h>
#include <string.h> // ���ڿ� ���� �Լ�

int main()
{
    int i = 0;
    int j = i;
    i = 99;
    printf("i=%d\tj=%d\n", i, j); // j�� �ٲ��� ����

    char* str1 = "Hello"; // ����(str1)�� ���ڿ�(Hello)�� ���� �ּҰ��� �������
    char* str2 = str1;  //str1�� �ּҸ� str2�� �Ҵ� (���� ����) <- str2�� Hello�� ���� �ּҰ��� ��
    char* str3;
    strcpy(str3, str1); // str1,�� ���ڿ��� str2�� ���� ���� <- str3���� ���ο� ������ str1�� ������ ����

    str1 = "Hi"; // str1�� ���ڿ��� �ٲ�� str1�� �������� ������ ���ο� ������ ���ڿ� ����
    printf("str1=%s\tstr2=%s\n",str1, str2); // str1�� Hi, str2�� �״�� Hello
}