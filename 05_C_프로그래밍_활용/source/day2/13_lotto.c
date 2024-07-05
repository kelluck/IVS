#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_LOTTO_NUMBER 45
int check[46];
int cnt, bonus;

void generateLottoNumber(int lottoNum[7]) {
    srand((unsigned)time(NULL));
    int i = 0;
    while(i < 7) {
        int num = (rand() % MAX_LOTTO_NUMBER) + 1;
        if(check[num] == 0){
            check[num] = 1;
            lottoNum[i] = num;
            i++;
        }            
    }
}

void printResult(int lottoNum[7], int inputNum[6]) {
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(lottoNum[i] == inputNum[j]) cnt++;
            if(lottoNum[6] == inputNum[j]) bonus = 1;
        }
    }
    
    if(cnt == 6){
        printf("1위 6개 번호 모두 일치\n");
    }
    else if(cnt == 5 && bonus){
        printf("2위 5개 번호 일치 + 보너스 번호 일치\n");
    }
    else if(cnt == 5){
        printf("3위 5개 번호 일치\n");
    }
    else if(cnt == 4){
        printf("4위 4개 번호 일치\n");
    }
    else if(cnt == 3){
        printf("5위 3개 번호 일치\n");
    }

}
int main(void) {
    int lottoNum[7], inputNum[6];
    int equalCount = 0;

    generateLottoNumber(lottoNum);
    printf("lotto number : %d %d %d %d %d %d\n", lottoNum[0], lottoNum[1],
    lottoNum[2], lottoNum[3], lottoNum[4], lottoNum[5]);
    printf("bonus number : %d\n", lottoNum[6]);

    printf("\nplease input 6 number : ");
    scanf("%d %d %d %d %d %d", &inputNum[0], &inputNum[1], &inputNum[2],
    &inputNum[3], &inputNum[4], &inputNum[5]);

    printResult(lottoNum, inputNum);
    system("pause");
    return 0;
}