#include <stdio.h>
#include <string.h>
int main() {
    char arr[10]; // ���������� � ���� ����ִ��� �𸣱� ������ �ʱ�ȭ�� �ʼ�! (���������� �˾Ƽ� 0���� �ʱ�ȭ��)
                  // char�� 1byte�ϱ� �ٸ� ���ڷε� ����, int���� 1byte�� �ƴ� �ڷ����� byte������ ����Ǳ� ������ 0, -1�θ� �ʱ�ȭ�� ��

    // �迭�� 3���� �ʱ�ȭ
    memset(arr, 3, sizeof(arr)); // byte������ ���� �����.
    
    // �ʱ�ȭ�� �迭�� ���� ���
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");    

    return 0;
}