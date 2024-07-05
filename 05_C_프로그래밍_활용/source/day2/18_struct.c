#include <stdio.h>
typedef struct {
    char c_1; // 1 바이트
    int i_1; // 4 바이트
    int i_2; // 4 바이트
} Dest; 

typedef struct { // 원하는 위치에 값을 튜닝하기 위해 패딩해준다
char c_1; // 1 바이트
char pedding_1; // 1 바이트
char pedding_2; // 1 바이트
char pedding_3; // 1 바이트
int i_1; // 4 바이트
int i_2; // 4 바이트
} DestPedding;

typedef struct {
char c; // 1 바이트
int i; // 4 바이트
double d; // 8 바이트
} Dest1;

typedef struct {
char c; // 1 바이트
double d; // 8 바이트
int i; // 4 바이트
} Dest2;

int main() {
    char source[12] = {0x01, 0x04, 0x03, 0x02, 0x01, 0x05, 0x06, 0x07, 0x08, 0x09, 0x10, 0x11};
    Dest destination;
    //int가 가장 크니까 4byte 단위로 가져온다... 1byte (3byte -> x) / 4byte / 4byte => 12byte
    printf("sizeof(destination) = %u\n", sizeof(destination));
    memcpy(&destination, &source,sizeof(destination)); 
    printf("c_1 = %02x\n",destination.c_1); // 01
    printf("i_1 = %08x\n",destination.i_1); // 07060501
    printf("i_2 = %08x\n",destination.i_2); // 11100908

    Dest1 des1;
    printf("sizeof(des1) = %u\n", sizeof(des1)); // 1byte (3byte -> pedding) / 4byte / 8byte => 16byte

    Dest2 des2;
    printf("sizeof(des2) = %u\n", sizeof(des2)); // 1byte (7byte -> pedding) / 8byte / 4byte (4byte -> pedding) => 24byte
    return 0;
}