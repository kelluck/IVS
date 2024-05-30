# C day3(2024-05-29)
---
# ch6. 배열과 문자열

## 1. 배열    
   * 배열(array)은 동일한 자료형의 집합. 하나의 이름으로 여러 개의 데이터를 저장하는 연속된 공간.   
     1. 배열 선언과 할당을 분리

        ```c    
        int subway[3];
        subway[0] = 30; subway[1] = 40; subway[2] = 50;
        ```
   
     3. 배열 선언과 초기화를 한 번에
        
        ```c    
        int subway[10] = {30, 40, 50}; //나머지 공간(3~9번까지)에는 0으로 초기화됨
        ```
    

## 2. 문자열    
   *  선언과 초기화 방법
         
        ```c
        char* name = "jenny";
        char name[] = "jenny";
        char name[] = {'j', 'e', 'n', 'n', 'y', '\0'}; // 문자열 끝에는 '\0'
        ```
        
   *  빈 문자 포함입력
     
        * scanf("%s", 변수, 입력받은 byte수)
          
          * white space(space, tap, enter)가 오면 그 이전의 버퍼내용을 return.
            
          *  단, 처음나오는 white space는 무시
            
        * gets(변수)
          
          * '\n'이전까지만 인식하고 그 뒤는 버퍼에서 지움.
               
      **scanf를 먼저 사용하고 gets를 사용하면 '\n'이 남아 있기 때문에, gets사용전 먼저 buffer를 비워줘야한다.**

       ```c
      //char* name <- 이렇게 받을 수는 없음; 입력받을 문자열이 저장될 공간인 확보되지 않음 
      char name[128];
      char address[512];  
      scanf("%s", name, sizeof(name));    
      gets(address); //버퍼를 지우는 용도 (gets()를 먼저 사용하면 필요없음)    
      gets(address);
      ```
       
   *  문자열 복사(얕은 복사 vs 깊은 복사)
        * 얕은 복사 : 주소값 복사
          
           ```c
           char* str1 = "Hello"; // 변수(str1)에 문자열(Hello)의 시작 주소값이 들어있음
           char* str2 = str1;  //str1의 주소를 str2에 할당 (얕은 복사) <- str2도 Hello의 시작 주소값이 들어감
           ```
           
        * 깊은 복사 : 내용 복사
          
          ```c
          char* str3;
          strcpy(str3, str1); // str1,의 문자열을 str2에 깊은 복사 <- str3만의 새로운 공간에 str1의 내용을 복사
          ```
  ---

# ch7. 포인터   
## 1. 포인터와 변수
  
* 포인터 : 메모리의 주소값을 저장하는 변수
        
* 주소값 서식 지정자 : %p  

* 변수의 메모리 주소 : 변수명 앞에 &
  
  ```c
  int a = 1;    
  int* pointer = &a;    
  printf("pointer변수가 가르키는 주소:%p\t값:%d\n", pointer, *pointer);    
  ```

## 2. 포인터와 배열

* 배열 : int arr[3]; 에서 arr은 배열의 시작 주소값을 나타냄 -> **포인터로 다룰 수 있다.**
        ex) int *ptr = arr;
  
* 배열 요소 포인터로 나타내기

  ```c
  for(int i = 0; i < 3; i++)
    {
        printf("배열 arr[%d] = %d\n", i, *(arr + i)); // i는 int이기 때문에 4byte씩 더해짐
    }
  ```

* 함수에서 매개 변수로 배열 받기 -> *포인터 사용(int ptr[ ]도 가능)*

   ```c
  void changeArray(int* ptr)

  int main()
  {
    int arr[3] = {10, 20, 30};
    changeArray(arr); 
  }

  void changeArray(int* ptr)
  {
    ptr[1] = 99;
  }
  
  ```
  
* 함수에서 배열 return -> *포인터 사용*
  ```c
  int main()
  {
    int arr[3] = {10, 20, 30};
    int* afterArr = returnArray(arr);
  }

  int* returnArray(int* ptr)
  {
    static int resultArr[3]; 
    **// static 항상 메모리에 남아있어야할 때 사용. (원래 함수 안 변수는 함수가 끝나면 사라짐)**
    for(int i = 0; i < 3; i++)
    {
        resultArr[i] = ptr[i]; // 깊은 복사;
    }
    resultArr[1] = 99;
    return resultArr;
  }
  ```
---
# ch8. 구조체

## 1. 구조체란?

  * 여러 자료형의 집합을 단일 타입으로 다루기
  * 구조체 정의하기

     ```c
     struct 구조체명
     {
        자료형1 변수명1;
        자료형2 변수명2;
        ...
     };
    ```
     
    ```c
     struct student
     {
        int num;
        double grade;
     };
    ```
      
  * 구조체 변수 선언하기

      ```c
      struct 구조체명 변수명;
      ```

      ```c
      struct student s1;
      struct student s1 = {2, 4.4};
      ```

      * typedef 사용
          struct student를 Student로 사용가능

          ```c
          typedef struct student Student;
          ```
          
  *  구조체 변수 멤버

     ```c
     변수명.멤버명 = 값;
     ```

     ```c
     s1.num = 2;
     s1.grade = 4.4;
     ```
      
## 2. 구조체 배열

  * 구조체 배열 정의

    ```c
    struct 구조체명 배열명[배열크기];
    ```

    ```c
    struct student
    {
    int id;        // 학번
    char name[20]; // 이름 char* name;
    double grade;  // 학점
    };

     int main(void)
    {
      // 구조체 변수 선언과 초기화
      struct student sArr[3] = {  {101, "홍길동", 4.43},
                                {102, "김길동", 3.43},
                                {103, "신길동", 4.01}};
    }
    ```
    
## 3. 구조체 함수

  * 구조체 변수를 매개변수로 사용

    ```c
    void stPrint(struct student s); // 함수선언

    int main(void)
    {
      struct student sArr[3] = {  {101, "홍길동", 4.43},
                                {102, "김길동", 3.43},
                                {103, "신길동", 4.01}};
      for(int idx = 0; idx<3 ; idx++)
      {
        stPrint(sArr[idx]); // 함수 호출
      } 
    } 

    void stPrint(struct student s)
    {
      printf("%d\t%s\t%.2lf\n", s.id, s.name, s.grade);
    }
    ```

 * 구조체를 return

     ```c
     struct vision
     {
      double left; 
      double right;
     };
     typedef struct vision Vision; // struct vision을 Vision으로 타입으로
     Vision exchange(Vision robot); // 함수

    int main(void)
    {
      Vision robot;
      scanf("%lf %lf", &robot.left, &robot.right);
      robot = exchange(robot);
    }
     
    Vision exchange(Vision robot)
    {
      // 매개변수 robot의 left와 right exchange
      double temp = robot.left;
      robot.left = robot.right;
      robot.right = temp;

     return robot;
    }
     ```
## 4. 구조체 포인터

  * 구조체 포인터 정의

    구조체 변수의 주소를 가리키는 변수

    ```c
    struct 구조체명* 변수명;
    ```

    ```c
    struct GameInfo* gamePtr; //구조체 포인터 변수 선언
    gamePtr = &gameInfo1;
    ```

  * 구조체 포인터 연산자 **->**

    ```c
    struct GameInfo
    {
    char* name;
    int year;
    int price;
    };
    
    struct GameInfo gameInfo1;
    struct GameInfo* gamePtr = &gameInfo1;

    //다 같은 값을 의미한다. 
    printf("게임이름 : %s\n", gameInfo1.name);
    printf("게임이름 : %s\n", (*gamePtr).name);
    printf("게임이름 : %s\n", gamePtr->name);
    ```

## 5. 자기 참조 구조체로 linked list만들기

![08장_링크드list](https://github.com/kelluck/IVS/assets/78212039/da2a1399-1d27-43df-ba2b-ad9b68d5538d)

```c
struct list
{
    int num;
    struct list* next; //형태가 같은 자기 참조 구조체!
};

int main(void)
{
    struct list a = {10, 0}, b={20, 0}, c={30,0};
    struct list* head = &a;
    struct list* current;

    a.next = &b;
    b.next = &c;

    current = head;
    while(current)
    {
        printf("%d\t", current->num);
        current = current->next;
    }
}
```

    






