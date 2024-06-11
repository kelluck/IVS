#include <stdio.h>
// 배열을 return하기 위해서는 포인터를 사용해야함!
int* returnArray(int* ptr);

int main()
{
    int arr[3] = {10, 20, 30};
    int* afterArr = returnArray(arr);
    printf("수정 전 : ");
    for(int i = 0; i < 3; i++)
    {
        printf("arr[%d] = %d\t", i, arr[i]);
    }
    printf("\n수정 후 : ");
    for(int i = 0; i < 3; i++)
    {
        printf("afterArr[%d] = %d\t", i, afterArr[i]);
    }
}

int* returnArray(int* ptr)
{
    static int resultArr[3]; // static 항상 메모리에 남아있어야할 때 사용. (원래 함수 안 변수는 함수가 끝나면 사라짐)
    for(int i = 0; i < 3; i++)
    {
        resultArr[i] = ptr[i]; // 깊은 복사; (얕은 복사=주소만 복사)
    }
    resultArr[1] = 99;
    return resultArr;
}