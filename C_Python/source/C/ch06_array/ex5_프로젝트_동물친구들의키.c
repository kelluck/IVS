#include <stdio.h>
/* ������, ������, ������, ���밥, �������� Ű�� �Է¹޾�
    ��»��� : ��� : 170.50
               ���� : ������ 190
               �ִ� : ������ 120
*/
int main()
{
    char* names[] = {"������", "������", "������", "���밥", "������"};
    int arrHeight[5]; // ģ���� Ű �Է� �迭
    int totHeight = 0; // Ű ���� ����
    int idxMin, minHeight = 999;
    int idxMax, maxHeight = -1;

    for(int i = 0; i < 5; i++)
    {
        printf("%s�� Ű�� �Է��Ͻÿ� >>", names[i]);
        scanf("%d", &arrHeight[i]);
        totHeight += arrHeight[i];
        if(minHeight > arrHeight[i])
        {
            minHeight = arrHeight[i];
            idxMin = i;
        }
        if(maxHeight < arrHeight[i])
        {
            maxHeight = arrHeight[i];
            idxMax = i;
        }
    }

    printf("���Ű : %.2lf\n", totHeight / 5.0);
    printf("����� ģ�� %s�� Ű�� %d\n", names[idxMax], maxHeight);
    printf("�ִܽ� ģ�� %s�� Ű�� %d\n", names[idxMin], minHeight);
}