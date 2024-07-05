#include <stdio.h>
#include <stdint.h>

typedef union {
    struct{
        unsigned int BR          : 3;  // 3 bits
        unsigned int Reseved     : 1;  // 1 bit
        unsigned int BR_RATIO    : 2;  // 2 bits
        unsigned int Reserved    : 1;  // 1 bit
        unsigned int SWK_EN      : 1;  // 1 bit
    }fields;
    uint8_t value;
} BitFieldUnion;

int main() {
    BitFieldUnion data;
    // data.fields.BR = 4;
    // data.fields.BR_RATIO = 0;
    // data.fields.SWK_EN = 1;
    data.value = 0xc4;
    
    for (int i = 7; i >= 0; i--) {
        printf("%d", (data.value & (1 << i)) ? 1 : 0); 
    }
    
    return 0;
}