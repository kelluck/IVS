#include <stdio.h>
#include <stdint.h>

int main()
{
    char s8_1 = 0, s8_2 = 0;
    short s16_1 = 32767;
    int s32_1 = -1;
    unsigned int u32_1 = 1u;
    printf("1. %d\n", sizeof(s8_1 + s8_2));
    printf("2. %d, %d, %u\n", sizeof(32767*100000), 32767*100000, 32767*100000); // char끼리 연산 불가 -> 알아서 int(4byte)로 형변환
    printf("3. %d, %u\n", -1, -1);
    if(s32_1 < u32_1) //부호가 없는 것과 있는 것 중에서 부호가 없는 걸로 형변환됨. (비교 연산할 때도 형변환 신경써야함)
    {
        printf("4.s32_1 < u32_1 is true\n");
    }
    else
    {
        printf("4.s32_1 < u32_1 is false\n");
    }
    system("pause");
    return 0;
}