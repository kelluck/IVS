#include <stdio.h>
//linked list
struct list
{
    int num;
    struct list* next; // 다음 항목을 가르키는 주소를 저장하기 위한 포인터
};

int main()
{
    struct list a = {10, 0}, b = {20, 0}, c = {30, 0}; // next는 일단 0으로
    struct list* head = &a; // a가 시작인 것을 가르키는 포인터
    struct list* current;
    a.next = &b; //연결; c는 마지막이므로 0값이 그대로 존재
    b.next = &c;

    printf("전체 데이터 : ");
    current = head;
    while (current) // 0이면(마지막이면) while문 탈출
    {
        printf("%d\t", current->num);
        current = current->next;
    }
    
}