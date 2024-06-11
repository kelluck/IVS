#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;
    char* str = "Hello";
    printf("a변수 주소:%p, 변수값:%d\n", &a, a); //주소값 출력은 "%p"
    printf("b변수 주소:%p, 변수값:%d\n", &b, b);
    printf("str:%p, 문자열주소:%p, 문자열내용:%s", &str, str, str);
    a = 10; b = 20; str = "Hi";

    printf("\n====변수 수정 후====\n");
    printf("a변수 주소:%p, 변수값:%d\n", &a, a); // 주소는 바뀌지 않고 변수값만 바뀜
    printf("b변수 주소:%p, 변수값:%d\n", &b, b); // 
    printf("str:%p, 문자열주소:%p, 문자열내용:%s", &str, str, str); //문자열의 위치가 바뀜
}