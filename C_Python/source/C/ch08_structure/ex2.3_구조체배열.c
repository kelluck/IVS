#include <stdio.h>
struct student
{
    int id;        // 학번
    char name[20]; // 이름 == char* name;(scanf할때는 안됨)
    double grade;  // 학점
};

void stPrint(struct student s); // 함수 선언; 매개 번수로 structure 받기

int main()
{
    struct student sArr[3] ={ {101, "홍길동", 4.4},{102, "신길동", 3.3},{103, "김길동", 4.04}};
    printf("학번\t이름\t학점\n");
    for(int i = 0; i < 3; i++)
    {
        stPrint(sArr[i]); // 함수 호출
    }
    
}

void stPrint(struct student s)
{
    printf("%d\t%s\t%.2lf\n", s.id, s.name, s.grade);
}