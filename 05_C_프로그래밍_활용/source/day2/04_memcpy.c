#include <stdio.h>
#include <string.h>
int main() {
    int source[10] = {1,2,3,4,5,6,7,8,9,10}; // ����
    int destination[10]; // ���

    // memcpy�� ����Ͽ� ������ ����
    memcpy(destination, source, sizeof(source)); //cpu load Ÿ�ӿ� ���� 

    for (int i = 0; i < 10; i++) {
        printf("%d ", destination[i]);
    }
    printf("\n");
    
    return 0;
}