#include <stdio.h>
// ����ü ����
typedef struct {
    int var1,var2,var3,var4,var5,var6,var7,var8\
    ,var9,var10,var11,var12,var13,var14,var15;
}Data;

// ����ü�� �Ű������� �޴� �Լ� ����
int calculate_1(Data data) { //stack�� ���� Data�� ���� -> �޸� ���� ������
    int sum = data.var1 + data.var2 + data.var3 + data.var4 + data.var5 +
              data.var6 + data.var7 + data.var8 + data.var9 + data.var10 +
              data.var11 + data.var12 + data.var13 + data.var14 + data.var15;
    return sum;
}

int calculate_2(int var1, int var2, int var3, int var4, int var5,
                int var6, int var7, int var8, int var9, int var10,
                int var11, int var12, int var13, int var14, int var15) {
    int sum = var1 + var2 + var3 + var4 + var5 + var6 + var7 + var8 + var9 + var10 +
              var11 + var12 + var13 + var14 + var15;
    return sum;
}

int main() {
    // ����ü ������ �����ϰ� �ʱ�ȭ
    Data myData = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};// �Լ��� ȣ���Ͽ� ��� ���
    int result_1 = calculate_1(myData);
    int result_2 = calculate_2(myData.var1,myData.var2,myData.var3,myData.var4\
                                ,myData.var5,myData.var6,myData.var7,myData.var8,myData.var9\
                                ,myData.var10,myData.var11,myData.var12,myData.var13\
                                ,myData.var14,myData.var15);
    printf("���_1: %d\n", result_1);
    printf("���_2: %d\n", result_2);
    return 0;
}
