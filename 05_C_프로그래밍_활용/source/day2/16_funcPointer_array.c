#include <stdio.h>

// ���� �Լ�
double square(double x) {
    return x * x;
}

// ������ �Լ�
double cube(double x) {
    return x * x * x;
}

// ������ �Լ�
double fourthPower(double x) {
    return x * x * x * x;
}

int main() {
    double (*functionPointers[])(double) = {square, cube, fourthPower};
    double num;

    while(1)
    {
        printf("�Ǽ��� �Է��ϼ��� (0�� �Է��ϸ� ����): ");
        scanf("%lf", &num);
        if(num == 0) break;
        
        for(int i = 0; i < sizeof(functionPointers)/sizeof(functionPointers[0]); i++)
        {
            //NULL�� �ƴҶ��� ����ؾ���!
            if(functionPointers[i] != NULL)
                printf("�Լ� %d ��� : %.2lf\n", i + 1, functionPointers[i](num));
        }
    }

    printf("���α׷��� �����մϴ�.\n");

    return 0;
}