#include <stdio.h>
#include <string.h>
int main() {
    int rows = 3; // �� ��
    int cols = 4; // �� ��

    // ����
    int source[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // ���
    int destination[3][4];

    // ������ ����
    memcpy(destination, source, sizeof(source));

    // ����� ������ ���
    printf("����� ������:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            printf("%d ", destination[i][j]);
        }
        printf("\n");
    }

    return 0;
}