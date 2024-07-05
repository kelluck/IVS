#include <stdio.h>
#include<stdlib.h>

// int main()
// {
//     int num = 0;
//     printf("num++:%d\n", num++); // 컴파일러 구성에 따라 속도가 다름
//     printf("num:%d\n", num);
//     printf("num--:%d\n", num--); 
//     printf("num:%d\n", num);
//     printf("++num:%d\n", ++num);
//     printf("--num:%d\n", num);
//     system("pause");
// }

int main()
{
    int num = 0;
    printf("++:%d, --%d\n", num++, num--); // 컴파일러에 따라 값이 다름 -> 따라서 이렇게 쓰지 말아야함
}