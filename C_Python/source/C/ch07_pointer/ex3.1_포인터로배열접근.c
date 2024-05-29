#include <stdio.h>

int main()
{
    int arr[3] = {10, 20, 30};
    for(int i = 0; i < 3; i++)
    {
        printf("배열 arr[%d] = %d\n", i, arr[i]);
    }

    int *ptr = arr;
    for(int i = 0; i < 3; i++)
    {
        printf("배열 ptr[%d] = %d\n", i, ptr[i]);
    }
    
    ptr[0] = 99; ptr[1] = 88; ptr[2] = 77; 
    printf("\n==ptr 수정 후 ===\n");
    for(int i = 0; i < 3; i++)
    {
        printf("배열 arr[%d] = %d\n", i, *(arr + i)); // i는 int이기 때문에 4byte씩 더해짐
    }
    for(int i = 0; i < 3; i++)
    {
        printf("배열 ptr[%d] = %d\n", i, *(ptr + i)); 
    }
}