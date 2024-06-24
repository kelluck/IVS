#define FEATURE_SECOND_STUDENT

typedef struct{
    char name[50];
    int id;
    int math_score;
    int english_score;
}Student;

// 평균 계산 함수 정의
double calculateAverage(const Student *student);

// 학생 정보 출력 함수 정의
void printStudentInfo(const Student *student);

// FEATURE_SECOND_STUDENT 매크로에 따라 두 번째 학생 정보 출력 함수 정의
#ifdef FEATURE_SECOND_STUDENT
void printSecondStudentInfo(const Student *student);
#endif