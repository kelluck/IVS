#include <stdio.h>

int main(){
	char gender, name[100];
	printf("������? ");
	scanf_s("%c", &gender);
	printf("�̸���? ");
	scanf_s("%s", name, (unsigned)sizeof(name)); //������ ���� �ȵǱ� ������ unsigned
	printf("�Է��� ������ %c\n�̸��� %s�Դϴ�\n", gender, name);

	return 0;
}