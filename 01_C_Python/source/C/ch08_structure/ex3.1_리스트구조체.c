#include <stdio.h>
//linked list
struct list
{
    int num;
    struct list* next; // ���� �׸��� ����Ű�� �ּҸ� �����ϱ� ���� ������
};

int main()
{
    struct list a = {10, 0}, b = {20, 0}, c = {30, 0}; // next�� �ϴ� 0����
    struct list* head = &a; // a�� ������ ���� ����Ű�� ������
    struct list* current;
    a.next = &b; //����; c�� �������̹Ƿ� 0���� �״�� ����
    b.next = &c;

    printf("��ü ������ : ");
    current = head;
    while (current) // 0�̸�(�������̸�) while�� Ż��
    {
        printf("%d\t", current->num);
        current = current->next;
    }
    
}