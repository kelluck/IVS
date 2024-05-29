#include <stdio.h>

void swap(int* arr1, int* arr2);
void sort(int* arr, int cnt);

int main()
{
    int arr[] = {41, 1, 35, 20, 45, 10};
    int cnt = 6;

    printf("정렬 전 : ");
    for(int i = 0; i < cnt; i++)
    {
        printf("%d ", arr[i]);
    }

    sort(arr, cnt);
    
    printf("\n정렬 후 : ");
    for(int i = 0; i < cnt; i++)
    {
        printf("%d ", arr[i]);
    }
}

void swap(int* arr1, int* arr2)
{
    int tmp = *arr1;
    *arr1 = *arr2;
    *arr2 = tmp;
}

void sort(int* arr, int cnt)
{
    for(int i = 0; i < cnt - 1; i++)
    {
        for(int j = i + 1; j < cnt; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}