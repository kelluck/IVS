#include <stdio.h>
#include <stdint.h>

typedef struct {
    unsigned int BR : 3;
    unsigned int Reserved : 1;
    unsigned int BR_RATIO    : 2;  // 2 bits
    unsigned int Reserved    : 1;  // 1 bit
    unsigned int SWK_EN      : 1;  // 1 bit
} BitFieldData;

int main() {
    BitFieldData data;
    data.BR = 4;
    data.BR_RATIO = 0;
    data.SWK_EN = 1;

    uint8_t target;

    memcpy(&target,&data,sizeof(target));
    
    printf("Register Value: %x\n", target);
    for (int i = 7; i >= 0; i--) {
        printf("%d", (target & (1 << i)) ? 1 : 0);
    }

    return 0;
}