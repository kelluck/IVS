#include <stdio.h>
#include <string.h>

#define rows 4 // �� ��
#define cols 3 // �� ��
int main() {
    char arr[rows][cols]; // 2���� �迭 ����

    // �迭�� 3���� �ʱ�ȭ
    memset(arr, 3, sizeof(arr));

    // �ʱ�ȭ�� �迭�� ���� ���
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}