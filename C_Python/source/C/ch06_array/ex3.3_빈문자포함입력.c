#include <stdio.h>
// �ּ�(�� ���� ����), �̸�(�� ���� ������)�� �Է¹ޱ�
/*  scanf("%s", ����, �Է¹��� byte��)
        : white space(space, tap, enter)�� ���� �� ������ ���۳����� return. 
        : ��, ó�������� white space�� ����
    gets(����)
        : '\n'���������� �ν��ϰ� �� �ڴ� ���ۿ��� ����.

*/
int main()
{
    //char* name <- �̷��� ���� ���� ����; �Է¹��� ���ڿ��� ����� ������ Ȯ������ ���� 
    char name[128];
    char address[512];
    printf("�ּ� >>");
    //scanf("%s", address, sizeof(address));
    //gets(address); //���۸� ����� �뵵 (gets()�� ���� ����ϸ� �ʿ����)
    gets(address);

    printf("�̸� >>");
    scanf("%s", name, sizeof(name));

    printf("�Է��� �ּҴ� : %s\n", address);
    printf("�Է��� �̸� : %s\n", name);    
}