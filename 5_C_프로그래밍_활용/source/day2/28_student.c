#include "28_student.h"
#include <stdio.h>


double calculateAverage(const Student *student)
{
    return (double)(student->math_score + student->english_score) / 2.0;
}


void printStudentInfo(const Student *student) {
    printf("Name: %s\n", student->name);
    printf("ID: %d\n", student->id);
    printf("Math Score: %d\n", student->math_score);
    printf("English Score: %d\n", student->english_score);
    
    // ��� ��� �� ���
    double average = calculateAverage(student);
    printf("Average Score: %.2f\n", average);
}

#ifdef FEATURE_SECOND_STUDENT
void printSecondStudentInfo(const Student *student) {
    // FEATURE_SECOND_STUDENT ��ũ�ΰ� ���ǵǾ� ���� ���� ����Ǵ� �ڵ�
    printf("Name: %s\n", student->name);
    printf("ID: %d\n", student->id);
    printf("Math Score: %d\n", student->math_score);
    printf("English Score: %d\n", student->english_score);

    // ��� ��� �� ���
    double average = calculateAverage(student);
    printf("Average Score: %.2f\n", average);
}
#endif
