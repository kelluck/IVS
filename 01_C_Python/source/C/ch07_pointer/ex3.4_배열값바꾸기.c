#include <stdio.h>

void changeArray(int* ptr); // �Ű������� �迭�� �޴� �Լ�

int main()
{
    int arr[3] = {10, 20, 30};
    changeArray(arr); 
    for(int i = 0; i < 3; i++)
    {
        printf("arr[%d] = %d\n", i, *(arr + i));
    }
    printf("%p\n", arr);
}

void changeArray(int* ptr)
{
    ptr[1] = 99;

}