#include <stdio.h>
#include <stdlib.h>

int main() {
    // 포인터 변수 선언
    int *numPtr;
    int num1 = 10;

    // num1의 메모리 주소를
    // 포인터 변수에 저장
    numPtr = &num1;

    printf("%p, %d\n", numPtr, *numPtr);
    printf("%p, %d\n", &num1, num1);
    printf("%d\n", sizeof(numPtr)); //모든 포인터의 size는 자료형이 달라도 동일. 32bit compiler라서 4byte / 64bit compiler면 8byte 
    printf("%d\n", sizeof(int*));
    printf("%d\n", sizeof(char*)); 
    system("pause");
    return 0;
}