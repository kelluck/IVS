#include <stdio.h>

// stack에는 매개변수 value와 지역변수 tempvalue, 종료 후 돌아갈 곳 등...
void modifyValue(int* value) {
    int tempvalue = 10;
    *value = tempvalue; // 전달된 value 값을 변경
}

int main() {
    int num = 5;
    printf("변경 전: %d\n", num);
    modifyValue(&num); // 함수에 값을 전달
    printf("변경 후: %d\n", num);

    return 0;
}

// 코드 -> .text (target환경에서는 RAM로 안옮기고 그대도 사용)
// Const 변수, 초기화된 전역변수-> .text(ROM)
// 초기화 안된 전역변수는 .bss(RAM) / 0으로 초기화 -> xbss / 초기화 o -> .data(RAM) / static 지역변수 -> 처음 빌드할때 주소가 정해짐
// stack : 함수 매개변수, 지역변수 -> 매번 가변 -> stack overflow 위험으로 메모리 사용 제한됨.
// U-stack : 인터럽트 아닌 곳에서 call 되는 함수 (I-stack 침범위험으로 메모리 용량 제한)
// I-stack : 인터럽트에 의해 call되는 함수
// data(전역변수; 런타임 중 변하지 않음 -> 제한을 두지 않음)
//--------------------
// data
//---------------------
// U-stack (크기 최적화)
//---------------------
// I-stack (크기 최적화)
//---------------------
// 샤시에서는 힙은 사용하지 말라고함.