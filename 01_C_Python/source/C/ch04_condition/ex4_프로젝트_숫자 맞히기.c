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

    printf("���� : %d\n", randomN);
    while(chance--){
        printf("%d���� %d ������ ���ڸ� ���� ������(���� ��ȸ : %d��) >>", from, to, chance + 1);
        scanf("%d", &answer);

        if(answer < from || answer > to) printf("���� ������ �� ���� ���ڸ� �Է��ϼ���\n\n");
        else if(answer > randomN) {
            printf("DOWN��\n");
            to = answer - 1;
        }
        else if(answer < randomN) {
            printf("UP��\n");
            from = answer + 1;
        }
        else {
            printf("%d������ ������ ������ϴ�.\n", 5-chance); 
            break;
        }
    }    
    if(chance == -1) printf("5���� ��� ��ȸ�� ����߾��. �ƽ��Ե� �����߽��ϴ�.\n");
}