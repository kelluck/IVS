#include <stdio.h>
#include <stdint.h>
// 묵시적 형변환하면 미즈라C같은거에서 에러남 -> 명시적 형변환해야함!
int main() {
    int num1 = 7;
    int num2 = 2;
    float num3;
    float num4 = 7.0f;
    float num5 = 2.0f;
    int num6;
    num3 = num1 / num2;
    printf("%f\n", num3);// 3.0000

    num3 = num1 / num5;
    printf("%f\n", num3);// 3.5000

    num3 = (float)num1 / num2;
    printf("%f\n", num3);// 3.5

    num6 = (int)(num4 / num5);
    printf("%d\n", num6); // 3

    printf("%f\n", num4 / num5); // 3.5000
    printf("%d\n", (int)(num4 / num5)); // 3
    return 0;
}