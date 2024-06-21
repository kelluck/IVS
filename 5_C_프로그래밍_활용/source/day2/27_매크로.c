#include <stdio.h>
//매크로는 함수 호출이 아니기 때문에 추가적인 cpu load가 일어나지 않는다
#define SET_BIT(var, pos) ((var) |= ((1) << (pos)))
#define CLEAR_BIT(var, pos) ((var) &= ~((1) << (pos)))
#define TOGGLE_BIT(var, pos) ((var) ^= ((1) << (pos)))

int main()
{
    int set_result = SET_BIT(32, 2);
    printf("set_result: %d\n", set_result);

    int clear_result = CLEAR_BIT(63, 2);
    printf("clear_result: %d\n", clear_result);

    int toggle_result = TOGGLE_BIT(59, 2);
    printf("toggle_result: %d\n", toggle_result);
}