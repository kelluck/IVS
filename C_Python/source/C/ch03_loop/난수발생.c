#include <stdio.h>
#include <stdlib.h> //rand() 함수 포함
#include <time.h> //난수 발생 초기화 위해
//난수 발생전 초기화 작업 필수
//rand() : 0 ~ 32767까지의 난수발생
int main()
{
    srand((unsigned int)time(NULL)); //난수 초기화
    printf("%d\n", rand() % 100); //0~99 사이의 난수
    printf("%d\n", rand() % 45 + 1); //1~45 사이의 난수
    printf("%d\n", rand() % 100);
}