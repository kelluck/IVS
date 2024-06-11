#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);

int main()
{
    srand((unsigned int)time(NULL)); // 난수 초기화
    int level = 1; // level 초기화
    int answer;

    while(level <= 3)// 총 3단계 level
    { 
        int a = getRandomNumber(level);
        int b = getRandomNumber(level);

        showQuestion(level, a, b);
        scanf("%d", &answer);

        if(answer == a*b)
        { // 맞추면 level 상승
            level++;
        }
        else
        { // 틀리면 즉시 종료
            printf("%d단계 오답입니다. 실패 종료입니다.\n", level);
            return 0;
        }
    }
    printf("3단계까지 잘 오셨습니다. 성공입니다!\n");
}

int getRandomNumber(int level)
{
    //level1 : 1~4, level2 : 5~8, level3 : 9~12 
    return (rand() % 4 + 1) + (level - 1)*4;
}

void showQuestion(int level, int num1, int num2)
{
    printf("\n%d레벨 구구단을 외자~\n", level);
    printf("힌트 : %d x %d >> ", num1, num2);
}