#include <stdio.h>

int main()
{
    //char* name = "jenny";
    //char name[] = "jenny";
    char name[] = {'j', 'e', 'n', 'n', 'y', '\0'}; // ���ڿ� ������ '\0'
    printf("%s\n", name);
    // for(int idx = 0; idx < 6; idx++)
    // {
    //     printf("index : %d, ���� : %c\n", idx, name[idx]);
    // }
}