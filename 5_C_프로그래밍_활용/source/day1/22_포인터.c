#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int numArr[3][4] = {
    { 11, 22, 33, 44 },
    { 55, 66, 77, 88 },
    { 99, 110, 121, 132 }
    };

    int(*numPtr)[4] = numArr; //()�� �־ 2���� �迭 �����ͷ� ����� �� �ִ�. int* numPtr[4]�ʹ� �ٸ�!

    printf("%p\n", *numPtr);
    printf("%p\n", *numArr);
    printf("%d\n", numPtr[2][1]);
    printf("%d\n", sizeof(numArr));
    printf("%d\n", sizeof(numPtr));

    int *numPtr2 = &numArr[0][0];
    printf("%d\n", *(numPtr+1)[0]);
    printf("%d\n", *(numPtr2+1));
    
    system("pause");
    return 0; 
}