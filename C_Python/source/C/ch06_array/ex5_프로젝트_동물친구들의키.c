#include <stdio.h>
/* 유수민, 김현식, 땅땅이, 새대갈, 슘당이의 키를 입력받아
    출력사항 : 평균 : 170.50
               최장 : 김현식 190
               최단 : 슘당이 120
*/
int main()
{
    char* names[] = {"유수민", "김현식", "땅땅이", "새대갈", "슘당이"};
    int arrHeight[5]; // 친구들 키 입력 배열
    int totHeight = 0; // 키 누적 변수
    int idxMin, minHeight = 999;
    int idxMax, maxHeight = -1;

    for(int i = 0; i < 5; i++)
    {
        printf("%s의 키를 입력하시오 >>", names[i]);
        scanf("%d", &arrHeight[i]);
        totHeight += arrHeight[i];
        if(minHeight > arrHeight[i])
        {
            minHeight = arrHeight[i];
            idxMin = i;
        }
        if(maxHeight < arrHeight[i])
        {
            maxHeight = arrHeight[i];
            idxMax = i;
        }
    }

    printf("평균키 : %.2lf\n", totHeight / 5.0);
    printf("최장신 친구 %s의 키는 %d\n", names[idxMax], maxHeight);
    printf("최단신 친구 %s의 키는 %d\n", names[idxMin], minHeight);
}