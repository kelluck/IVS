#include <stdio.h>
// Call By Value vs Call By Reference
void sum(int from, int to, int* tot);

int main(){
    int a = 1, b = 10, tot;
    sum(a, b, &tot);
    printf("%d부터 %d까지 누적합은 %d\n", a, b, tot);
    
    a = 10, b = 100;
    sum(a, b, &tot);
    printf("%d부터 %d까지 누적합은 %d\n", a, b, tot);
}

void sum(int from, int to, int* tot){
    *tot = 0;
    for(int i = from; i <= to; i++){
        *tot += i;
    }
}