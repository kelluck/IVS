#include <stdio.h>
void modifyValue(int *value) {
    int tempvalue = 10;
    //const temp = 10;
    //temp = 20;
    *value = tempvalue; // const int num이지만 포인터를 통해 값을 변경!
}

int main() {
    const int num = 5;
    printf("변경 전: %d\n", num);
    modifyValue(&num); // 함수에 포인터를 전달
    printf("변경 후: %d\n", num);
    return 0;
}

/*
const int num = 10; -> 값 변경 불가
const int* ptr = &num; -> 값 변경불가
int* const ptr = &num;
const int* const ptr = &num;

RAM은 byte단위이기 때문에 문제가 없음
const변수는 code에 -> 섹터 단위로 지워짐
*/