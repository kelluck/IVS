#include <stdio.h>

int main(){
	char gender, name[100];
	printf("성별은? ");
	scanf_s("%c", &gender);
	printf("이름은? ");
	scanf_s("%s", name, (unsigned)sizeof(name)); //음수가 들어가면 안되기 때문에 unsigned
	printf("입력한 성별은 %c\n이름은 %s입니다\n", gender, name);

	return 0;
}