#include <stdio.h>
/*���������� : %d, %f, %.3lf, %c, %s
*/
int main() {
	int num1 = 10, num2 = 11;
	printf("�� ���� �� = %d\n", num1 + num2);
	//������(4byte)�� ������(4byte) ��Ģ���� ����� ������(4byte)
	printf("�� ���� ��� = %.1lf\n", (num1 + num2) / 2.0); //�ϳ��� double�� �ϸ� ��. ���� ����ȯ or 2.0ó�� �Ҽ���
}