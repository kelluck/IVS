#include <stdio.h>
struct student
{
    int id;        // �й�
    char name[20]; // �̸� == char* name;(scanf�Ҷ��� �ȵ�)
    double grade;  // ����
};

void stPrint(struct student s); // �Լ� ����; �Ű� ������ structure �ޱ�

int main()
{
    struct student sArr[3] ={ {101, "ȫ�浿", 4.4},{102, "�ű浿", 3.3},{103, "��浿", 4.04}};
    printf("�й�\t�̸�\t����\n");
    for(int i = 0; i < 3; i++)
    {
        stPrint(sArr[i]); // �Լ� ȣ��
    }
    
}

void stPrint(struct student s)
{
    printf("%d\t%s\t%.2lf\n", s.id, s.name, s.grade);
}