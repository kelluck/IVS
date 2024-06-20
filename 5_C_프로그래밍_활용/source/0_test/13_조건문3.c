#include <stdio.h>
int main() {
    int x = 5;
    int y = 10;
    if (x < 0 && y++ == 15){ // &&에서 왼쪽이 거짓이면 오른쪽은 실행 안함.
        printf("이 코드는 실행되지 않습니다.\n");
    }

    printf("y = %d\n", y); // 11이 아니라 10이 출력
    return 0;
}