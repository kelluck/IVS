#include <stdio.h>

int main() {
	char name[100], gender[3];
	int ko, eng, math;

	printf("�̸��� �Է��ϼ��� : ");
	scanf_s("%s", name, sizeof(name));

	printf("������ �Է��ϼ���(��/��) : ");
	scanf_s("%s", gender, sizeof(gender));

	printf("���� ���� ���� ������ �Է��ϼ��� : ");
	scanf_s("%d %d %d", &ko, &eng, &math);

	printf("\n---�л�����---\n");
	printf("�̸� : %s\n", name);
	printf("���� : %s\n", gender);
	printf("���� = %d\n���� = %d\n���� = %d\n", ko, eng, math);
	printf("�հ� = %d\n��� = %.2lf\n", ko + eng + math, (ko + eng + math)/3.0);
}