#include <stdio.h>
/*서식지정자 : %d, %f, %.3lf, %c, %s
*/
int main() {
	int num1 = 10, num2 = 11;
	printf("두 수의 합 = %d\n", num1 + num2);
	//정수형(4byte)과 정수형(4byte) 사칙연산 결과는 정수형(4byte)
	printf("두 수의 평균 = %.1lf\n", (num1 + num2) / 2.0); //하나만 double로 하면 됨. 강제 형변환 or 2.0처럼 소수로
}