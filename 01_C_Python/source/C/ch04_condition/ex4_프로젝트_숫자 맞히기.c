#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned int)time(NULL));
    int randomN = rand() % 100 + 1;
    int chance = 5;
    int answer;
    int from = 1, to = 100;

    printf("정답 : %d\n", randomN);
    while(chance--){
        printf("%d부터 %d 사이의 숫자를 맞춰 보세요(남은 기회 : %d번) >>", from, to, chance + 1);
        scanf("%d", &answer);

        if(answer < from || answer > to) printf("수의 범위를 잘 보고 숫자를 입력하세요\n\n");
        else if(answer > randomN) {
            printf("DOWN↓\n");
            to = answer - 1;
        }
        else if(answer < randomN) {
            printf("UP↑\n");
            from = answer + 1;
        }
        else {
            printf("%d번만에 정답을 맞췄습니다.\n", 5-chance); 
            break;
        }
    }    
    if(chance == -1) printf("5번의 모든 기회를 사용했어요. 아쉽게도 실패했습니다.\n");
}