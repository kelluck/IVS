#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 로또 번호 1 ~ 45 중복 없이 6개
int check[46] = {0,};
int* make_lotto();
void sort(int* lotto);

int main()
{
    int* lotto = make_lotto();
    sort(lotto);
    printf("생성된 로또번호 : ");
    for(int i = 0; i < 6; i++)
    {
        printf("%d ", lotto[i]);
    }    
}

int* make_lotto()
{
    static int lotto[6];
    srand((unsigned int)time(NULL));
    
    int i = 0;
    while(i < 6)
    {
        int tmp = rand() % 45 + 1;
        check[tmp]++;
        if(check[tmp] == 1)
        {
            lotto[i] = tmp;
            i++;
        }
    }
    return lotto;
}

void swap(int* arr1, int* arr2)
{
    int tmp = *arr1;
    *arr1 = *arr2;
    *arr2 = tmp;
}

void sort(int* lotto)
{
    for(int i = 0; i < 6 - 1; i++)
    {
        for(int j = i + 1; j < 6; j++)
        {
            if(lotto[i] > lotto[j])
            {
                swap(&lotto[i], &lotto[j]);
            }
        }
    }
}
