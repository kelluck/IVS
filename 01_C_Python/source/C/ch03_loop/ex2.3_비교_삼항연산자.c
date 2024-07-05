#include <stdio.h>
#include <stdbool.h> //true, false
//비교연산자 : <, <=, >, >=, ==, !=
//삼항연산자 : 조건 ? (조건이 참일때의 값) : (조건이 거짓일때의 값)

int main()
{
    int n1 = 10, n2 = 5;
    int result = n1 <= n2;
    printf("%d %s %d는 %d\n", n1, "<=", n2, result); //참 : 1, 거짓 : 0

    bool rs = n1 <= n2;
    printf("%d %s %d는 %s\n", n1, "<=", n2, rs? "참":"거짓"); 
}