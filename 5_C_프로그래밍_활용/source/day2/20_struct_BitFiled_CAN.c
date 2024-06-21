#include <stdio.h>
#include <stdint.h>

typedef struct {
    unsigned int BR : 3;
    unsigned int Reserved : 1;
    
} BitFieldData;

int main() {
    BitFieldData data;

    uint8_t target;
    memcpy(&target,&data,sizeof(target));
    for (int i = 7; i >= 0; i--) {
        printf("%d", (target & (1 << i)) ? 1 : 0);
    }

    return 0;
}