#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double integral(double A, double B, double D, double N)
{
    double result = (B-A)/N;
    double temp = 0;
    for(int k = 1; k <= N; k++)
    {
        temp += pow(A + k*(B-A)/N, D);
    }

    result *= temp;
    return result;
}

int main()
{
    printf("%lf\n", integral(0,2,2,1000));
    printf("%lf\n", integral(0,2,3,1000));

    return 0;
}