#include <stdio.h>
// score�� �Է¹޾� ���� ���
int main()
{
    int score;
    printf("������ >>");
    scanf("%d", &score);

    if(90 <= score && score <= 100) printf("A����\n");
    else if(score >= 80) printf("B����\n");
    else if(score >= 70) printf("C����\n");
    else if(score >= 60) printf("D����\n");
    else if(score >= 0) printf("F����\n");
    else printf("��ȿ���� ���� �����Դϴ�\n");
}