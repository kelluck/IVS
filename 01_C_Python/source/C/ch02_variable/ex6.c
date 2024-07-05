#include <stdio.h>

int main() {
	char name[100], gender[3];
	int ko, eng, math;

	printf("이름을 입력하세요 : ");
	scanf_s("%s", name, sizeof(name));

	printf("성별을 입력하세요(남/여) : ");
	scanf_s("%s", gender, sizeof(gender));

	printf("국어 영어 수학 점수를 입력하세요 : ");
	scanf_s("%d %d %d", &ko, &eng, &math);

	printf("\n---학생정보---\n");
	printf("이름 : %s\n", name);
	printf("성별 : %s\n", gender);
	printf("국어 = %d\n영어 = %d\n수학 = %d\n", ko, eng, math);
	printf("합계 = %d\n평균 = %.2lf\n", ko + eng + math, (ko + eng + math)/3.0);
}