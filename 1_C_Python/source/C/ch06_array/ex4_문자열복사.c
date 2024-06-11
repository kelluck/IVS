#include <stdio.h>
#include <string.h> // 문자열 관련 함수

int main()
{
    int i = 0;
    int j = i;
    i = 99;
    printf("i=%d\tj=%d\n", i, j); // j는 바뀌지 않음

    char* str1 = "Hello"; // 변수(str1)에 문자열(Hello)의 시작 주소값이 들어있음
    char* str2 = str1;  //str1의 주소를 str2에 할당 (얕은 복사) <- str2도 Hello의 시작 주소값이 들어감
    char* str3;
    strcpy(str3, str1); // str1,의 문자열을 str2에 깊은 복사 <- str3만의 새로운 공간에 str1의 내용을 복사

    str1 = "Hi"; // str1의 문자열이 바뀌면 str1의 기존문자 버리고 새로운 공간에 문자열 저장
    printf("str1=%s\tstr2=%s\n",str1, str2); // str1만 Hi, str2는 그대로 Hello
}