// main.c ����
#include <stdio.h>
#include "29_student.h"
#define FEATURE_SECOND_STUDENT

int main() {
    // ù ��° �л� ���� ����
    Student student1 = {"Alice", 1, 90, 85};
    printf("First Student:\n");
    printStudentInfo(&student1);
    
    // FEATURE_SECOND_STUDENT ��ũ�ΰ� ���ǵǾ� �ִ� ��쿡�� �� ��° �л� ���� ���� �� ���
    #ifdef FEATURE_SECOND_STUDENT
    Student student2 = {"Bob", 2, 78, 92};
    printf("\nSecond Student:\n");
    printSecondStudentInfo(&student2);
    #endif
    return 0;
}