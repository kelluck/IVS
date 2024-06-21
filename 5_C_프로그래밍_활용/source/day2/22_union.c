#include <stdio.h>

// Union 정의
union Data { //가장 큰 자료형 기준으로 공간을 만들고 같이 쓴다.
    char c;
    int d;
    float f;
};

int main() {
    union Data data;
    data.d = 1661; //초기화 필수. 그냥 넣으면 값이 오염된다.
    printf("int value: %d\n", data.d);
    printf("Char value from int: %d\n", data.c);
    data.c = 3;
    printf("int value: %d\n", data.d);
    printf("Char value from int: %d\n", data.c);
    data.f = 2.71828f;
    printf("Float value: %f\n", data.f);
    printf("Char value from float: %d\n", data.c);
    return 0;
}