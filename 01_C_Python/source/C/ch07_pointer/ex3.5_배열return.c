#include <stdio.h>
// �迭�� return�ϱ� ���ؼ��� �����͸� ����ؾ���!
int* returnArray(int* ptr);

int main()
{
    int arr[3] = {10, 20, 30};
    int* afterArr = returnArray(arr);
    printf("���� �� : ");
    for(int i = 0; i < 3; i++)
    {
        printf("arr[%d] = %d\t", i, arr[i]);
    }
    printf("\n���� �� : ");
    for(int i = 0; i < 3; i++)
    {
        printf("afterArr[%d] = %d\t", i, afterArr[i]);
    }
}

int* returnArray(int* ptr)
{
    static int resultArr[3]; // static �׻� �޸𸮿� �����־���� �� ���. (���� �Լ� �� ������ �Լ��� ������ �����)
    for(int i = 0; i < 3; i++)
    {
        resultArr[i] = ptr[i]; // ���� ����; (���� ����=�ּҸ� ����)
    }
    resultArr[1] = 99;
    return resultArr;
}