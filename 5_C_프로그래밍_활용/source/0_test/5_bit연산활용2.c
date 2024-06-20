#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t flags = 0; //0, 2, 3, 5, 7��° 1��
    flags |= (1u << 0);
    flags |= (0u << 1);
    flags |= (1u << 2);
    flags |= (1u << 3);
    flags |= (0u << 4);
    flags |= (1u << 5);
    flags |= (0u << 6);
    flags |= (1u << 7);
    // Fail_0���� Fail_7���� ���� �˻��ϰ� ����մϴ�.
    for (int i = 0; i < 8; i++) {
        int flag = (flags >> i) & 1u;
        printf("Fail_%d: %d\n", i, flag);
    }
    return 0;
}