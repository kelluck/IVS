#include <stdio.h>
struct vision
{
    double left;
    double right;
};

typedef struct vision Vision;// struct vision�� Vision���� Ÿ�� �̸� ����

Vision exchange(Vision robot); // �Լ� ����; ����ü�� return�ϴ� �Լ�

int main()
{
    Vision robot;
    printf("�� �� �÷� >>");
    scanf("%lf %lf", &robot.left, &robot.right);
    printf("�Էµ� �¿� �÷� : %.1lf\t %.1lf\n", robot.left, robot.right);
    robot = exchange(robot);
    printf("�¿찡 �ٲ� �÷� : %.1lf\t %.1lf\n", robot.left, robot.right);

}

Vision exchange(Vision robot)
{
    // �Ű����� robot�� left�� right exchange
    double tmp = robot.left;
    robot.left = robot.right;
    robot.right = tmp;
    return robot;
}