#include <stdio.h>

typedef struct {
    char c_1; // 1 ����Ʈ
    char c_2; // 1 ����Ʈ
    char c_3; // 1 ����Ʈ
    char c_4; // 1 ����Ʈ
    int i_1; // 4 ����Ʈ
} Dest;

int main() {
    char source[8] = {0x01, 0x02, 0x03, 0x04, 0x04, 0x03, 0x02, 0x01};
    Dest destination;
    memcpy(&destination, &source, sizeof(destination));
    printf("c_1 = %02x\n",destination.c_1); // 01
    printf("c_2 = %02x\n",destination.c_2); // 02
    printf("c_3 = %02x\n",destination.c_3); // 03
    printf("c_4 = %02x\n",destination.c_4); // 04
    printf("i_1 = %08x\n",destination.i_1); // 01020304
    return 0;
}