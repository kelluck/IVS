#include <stdio.h>

int main()
{
    //char* name = "jenny";
    //char name[] = "jenny";
    char name[] = {'j', 'e', 'n', 'n', 'y', '\0'}; // 문자열 끝에는 '\0'
    printf("%s\n", name);
    // for(int idx = 0; idx < 6; idx++)
    // {
    //     printf("index : %d, 글자 : %c\n", idx, name[idx]);
    // }
}