#include <stdio.h>

int main()
{
    int score;
    printf("������ >>");
    scanf("%d", &score);
    int temp = score == 100 ? 99 : score;
    switch (temp/10)
    {
    case 9:
        printf("A����\n");
        break;
    case 8:
        printf("B����\n");
        break;
    case 7:
        printf("C����\n");
        break;
    case 6:
        printf("D����\n");
        break;
    case 5: case 4: case 3: case 2: case 1: case 0:
        printf("F����\n");
        break;
    default:
        printf("��ȿ���� ���� �����Դϴ�\n");
        break;
    }
}