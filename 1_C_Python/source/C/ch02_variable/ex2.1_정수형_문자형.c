#include <stdio.h>
//주석 달기 : ctrl + k, c
 //주석 해체 : ctrl + k, u
//변수 : 정수형(int), 문자형(문자'', 문자열"")
int main() {
	int age = 28;
	char gender = 'F';
	char name[] = "제니";
	// == char* name = "제니";
	printf("안녕하세요, %d살(%c) %s입니다\n", age, gender, name);
	printf("안녕하세요, %d살(%c) %s입니다\n", age, gender, name);
	printf("안녕하세요, %d살(%c) %s입니다\n", age, gender, name);
}