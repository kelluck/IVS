#include <stdio.h>
#define FACTORIAL(n) ({ \
    int result = 1; \
    for(int i = 1; i <= (n); i++){ \
        result *= i; \
    } \
    result;\
})

int main() {
    int num = 5;
    int factorial_result = FACTORIAL(num);

    printf("%d! = %d\n", num, factorial_result);

    return 0;
}