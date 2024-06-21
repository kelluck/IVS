#include <stdio.h>
#include <stdlib.h>
// int func1(int *var) { // 후위연산 temp++
//     int temp;
//     temp = *var;
//     *var = *var + 1;

//     return temp; 
// }

int func1(int *var) { // 전위연산 ++temp
    int temp;
    temp = *var + 1;
    *var = *var + 1;

    return temp; 
}

int main() {
    int iPtr;
    iPtr = 1;
    printf("%d\n", iPtr);
    printf("%d\n", func1(&iPtr));
    printf("%d\n", iPtr);
    system("pause");
    return 0;
}