#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // 1. 20인분을 시킬 경우 몇 인분을 먹을 수 있는가?
    int order = 20, serviceA = 5, serviceB = 1, total;
    total = order + (order/serviceA) * serviceB;
    printf("total : %d\n", total);

    // 2. 20인분을 먹으려면 몇 인분을 시켜야하는가?
    total = 20;
    order = total / serviceB / ((serviceA + serviceB) / (serviceA * serviceB));
    printf("order : %f\n", ceil(order));

    //system("pause");
    return 0;
}

