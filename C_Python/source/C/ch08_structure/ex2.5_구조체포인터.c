#include <stdio.h>
struct GameInfo
{
    char* name;
    int year;
    int price;
};

int main()
{
    struct GameInfo gameInfo1;
    gameInfo1.name = "사이버C";
    gameInfo1.year = 2024;
    gameInfo1.price = 33000;
    struct GameInfo* gamePtr = &gameInfo1;
    printf("게임정보(gameInfo1) 출력\n");
    printf("게임이름 : %s\n", gameInfo1.name);
    printf("출시연도 : %d\n", gameInfo1.year);
    printf("게임가격 : %d\n", gameInfo1.price);

    printf("\n게임정보(gamePtr포인터변수) 출력\n");
    printf("게임이름 : %s\n", (*gamePtr).name); // .보다 *가 우선순위가 낮기 때문에 괄호 필수!
    printf("출시연도 : %d\n", (*gamePtr).year);
    printf("게임가격 : %d\n", (*gamePtr).price);

    printf("\n게임정보(gamePtr포인터변수->) 출력\n");
    printf("게임이름 : %s\n", gamePtr->name);
    printf("출시연도 : %d\n", gamePtr->year);
    printf("게임가격 : %d\n", gamePtr->price);
}