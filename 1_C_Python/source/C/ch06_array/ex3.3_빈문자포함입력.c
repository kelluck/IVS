#include <stdio.h>
// 주소(빈 문자 포함), 이름(빈 문자 불포함)을 입력받기
/*  scanf("%s", 변수, 입력받은 byte수)
        : white space(space, tap, enter)가 오면 그 이전의 버퍼내용을 return. 
        : 단, 처음나오는 white space는 무시
    gets(변수)
        : '\n'이전까지만 인식하고 그 뒤는 버퍼에서 지움.

*/
int main()
{
    //char* name <- 이렇게 받을 수는 없음; 입력받을 문자열이 저장될 공간인 확보되지 않음 
    char name[128];
    char address[512];
    printf("주소 >>");
    //scanf("%s", address, sizeof(address));
    //gets(address); //버퍼를 지우는 용도 (gets()를 먼저 사용하면 필요없음)
    gets(address);

    printf("이름 >>");
    scanf("%s", name, sizeof(name));

    printf("입력한 주소는 : %s\n", address);
    printf("입력한 이름 : %s\n", name);    
}