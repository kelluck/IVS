#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);

int main()
{
    srand((unsigned int)time(NULL)); // ���� �ʱ�ȭ
    int level = 1; // level �ʱ�ȭ
    int answer;

    while(level <= 3)// �� 3�ܰ� level
    { 
        int a = getRandomNumber(level);
        int b = getRandomNumber(level);

        showQuestion(level, a, b);
        scanf("%d", &answer);

        if(answer == a*b)
        { // ���߸� level ���
            level++;
        }
        else
        { // Ʋ���� ��� ����
            printf("%d�ܰ� �����Դϴ�. ���� �����Դϴ�.\n", level);
            return 0;
        }
    }
    printf("3�ܰ���� �� ���̽��ϴ�. �����Դϴ�!\n");
}

int getRandomNumber(int level)
{
    //level1 : 1~4, level2 : 5~8, level3 : 9~12 
    return (rand() % 4 + 1) + (level - 1)*4;
}

void showQuestion(int level, int num1, int num2)
{
    printf("\n%d���� �������� ����~\n", level);
    printf("��Ʈ : %d x %d >> ", num1, num2);
}