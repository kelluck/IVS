#include <stdio.h>
#include <string.h>
int main() {
    char arr[10]; // 지역변수는 어떤 값이 들어있는지 모르기 때문에 초기화가 필수! (전역변수는 알아서 0으로 초기화됨)
                  // char는 1byte니까 다른 숫자로도 가능, int같은 1byte가 아닌 자료형도 byte단위로 저장되기 때문에 0, -1로만 초기화할 것

    // 배열을 3으로 초기화
    memset(arr, 3, sizeof(arr)); // byte단위로 값이 저장됨.
    
    // 초기화된 배열의 내용 출력
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");    

    return 0;
}