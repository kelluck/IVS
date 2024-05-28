#include <stdio.h>
// score를 입력받아 학점 출력
int main()
{
    int score;
    printf("점수는 >>");
    scanf("%d", &score);

    if(90 <= score && score <= 100) printf("A학점\n");
    else if(score >= 80) printf("B학점\n");
    else if(score >= 70) printf("C학점\n");
    else if(score >= 60) printf("D학점\n");
    else if(score >= 0) printf("F학점\n");
    else printf("유효하지 않은 점수입니다\n");
}