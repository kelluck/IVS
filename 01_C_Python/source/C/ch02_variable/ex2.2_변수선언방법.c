#include <stdio.h>
//변수 선언 방법
int main(){
	//1. 자료형 변수명 = 초기값
	int num1 = 10; //선언과 초기화를 한 번에
	//2. 자료형 변수명;
	int num2; //선언
	num2 = 20; //할당
	printf("num1=%d\t num2=%d\n", num1, num2);
	//3. 자료형 변수명=값, 변수명=값;
	int num3 = 3, num4 = 4, num5 = 5;
	printf("num3=%d\tnum4=%d\tnum5=%d\n", num3, num4, num5);
	//4. 자료형 변수명1, 변수명2..;
	int n1, n2, n3;
	n1 = 1; n2 = 2; n3 = 3;
	printf("n1=%d, n2=%d, n3=%d\n", n1, n2, n3);
}