#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // 1. 20�κ��� ��ų ��� �� �κ��� ���� �� �ִ°�?
    int order = 20, serviceA = 5, serviceB = 1, total;
    total = order + (order/serviceA) * serviceB;
    printf("total : %d\n", total);

    // 2. 20�κ��� �������� �� �κ��� ���Ѿ��ϴ°�?
    total = 20;
    order = total / serviceB / ((serviceA + serviceB) / (serviceA * serviceB));
    printf("order : %f\n", ceil(order));

    //system("pause");
    return 0;
}

