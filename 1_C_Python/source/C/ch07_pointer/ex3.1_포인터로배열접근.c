#include <stdio.h>

int main()
{
    int arr[3] = {10, 20, 30};
    for(int i = 0; i < 3; i++)
    {
        printf("�迭 arr[%d] = %d\n", i, arr[i]);
    }

    int *ptr = arr;
    for(int i = 0; i < 3; i++)
    {
        printf("�迭 ptr[%d] = %d\n", i, ptr[i]);
    }
    
    ptr[0] = 99; ptr[1] = 88; ptr[2] = 77; 
    printf("\n==ptr ���� �� ===\n");
    for(int i = 0; i < 3; i++)
    {
        printf("�迭 arr[%d] = %d\n", i, *(arr + i)); // i�� int�̱� ������ 4byte�� ������
    }
    for(int i = 0; i < 3; i++)
    {
        printf("�迭 ptr[%d] = %d\n", i, *(ptr + i)); 
    }
}