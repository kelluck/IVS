#include <stdio.h>
#include "29_student.h"

double calculateAverage(int math, int eng)
{
    return (math + eng) / 2.0;
}


void printStudentInfo(Student student){
    printf("First Student:\n");
    printf("Name: %s\n", student.name);
    printf("ID: %d\n", student.id);
    printf("Math Score: %d\n", student.math_score);
    printf("English Score: %d\n", student.english_score);
    printf("Average Score: %.2lf\n", calculateAverage);
}

void printSecondStudentInfo(Student student){
    printf("Second Student:\n");
    printf("Name: %s\n", student.name);
    printf("ID: %d\n", student.id);
    printf("Math Score: %d\n", student.math_score);
    printf("English Score: %d\n", student.english_score);
    printf("Average Score: %.2lf\n", calculateAverage);
}
