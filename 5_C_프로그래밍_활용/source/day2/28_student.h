#define FEATURE_SECOND_STUDENT

typedef struct{
    char name[50];
    int id;
    int math_score;
    int english_score;
}Student;

// ��� ��� �Լ� ����
double calculateAverage(const Student *student);

// �л� ���� ��� �Լ� ����
void printStudentInfo(const Student *student);

// FEATURE_SECOND_STUDENT ��ũ�ο� ���� �� ��° �л� ���� ��� �Լ� ����
#ifdef FEATURE_SECOND_STUDENT
void printSecondStudentInfo(const Student *student);
#endif