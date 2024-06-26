# C day2(2024-05-28)
---
# ch3 - 1. 연산자

## 1. 산술 연산자    

   * 종류 : +, -, /, *, %
   
   * 형변환
     
     ```
       * 묵시적 형변환 : int i = 3.2;
       * 명시적 형변환 : int n1; (double)n1;
     ```
     
## 2. 증감 연산자    

   * 종류 : ++, --    
   * ++n VS n++

     ```
       * ++n : ++연산 먼저 수행
       * n++ : 명령어 수행 후 ++ 연산
     ```

## 3. 비교 연산자    

   * 종류 : <, <=, >, >=, ==, !=    

## 4. 삼항 연산자    
  ```
    조건 ? (조건이 참일때의 값) : (조건이 거짓일때의 값)
  ```

## 5. 논리 연산자    
   * 종류 : &&(and), ||(or), !(not)

  ```
    &&연산의 경우 좌항이 false인 경우 우항은 실행하지 않고 결과를 false로
    ||연산의 경우 좌항이 true인 경우 우항은 실행하지 않고 결과를 true로
  ```

## 6. 비트 연산자    
   * 종류 :  &(and), |(or), ^(xor; 1아 짝수면 false(0), 홀수면 true(1)), <<(왼쪽 shift), >>(오른쪽 shift)

  ```
   '<<'는 2배(2진수니까)
   '>>'는 1/2(2진수니까)
  ```

## 7. 대입 연산자    
   * 종류 : =, +=, -=, /=, *=, %= ...   
---

# ch3 - 2. 반복문
## 1. for

   * ex) for(int i = 0; i < N; i++)  <- N번 반복
     
## 2. while

   * ex) while(참인 경우 수행)
     
## 3. do while

   * ex) do{ 먼저 실행 }while(참인 경우 수행);    

---

# 난수 발생 (Random)      
> 헤더파일          
  * #include <stdlib.h> //rand() 함수 포함        
  * #include <time.h> //난수 발생 초기화 위해
    
> 난수 발생

  ```c
   srand((unsigned int)time(NULL)); //난수 초기화          
   printf("%d\n", rand() % 100); //0~99 사이의 난수        
   printf("%d\n", rand() % 45 + 1); //1~45 사이의 난수
  ```
    
---
# ch4. 조건문
## 1. if   

   * if, else if, else
     
## 2. switch

   * 각 case마다 break; 꼭 작성    
---
# ch5. 함수
## 1. Call By Value    
   * 함수가 인수로 전달받은 값을 복사하여 처리하는 방식
   * **!값을 변경해도 원복 값은 변경되지 않는다!**

     ```
      장점 : 복사하여 처리하기 때문에 안전하다. 원본 값이 보존
      단점 : 복사하기 때문에 메모리 사용량이 늘어난다.
     ```
     
## 2. Call By Reference    
   * 함수 호출 시 던달되는 변수의 참조 값을 함수 내부로 전달하는 방식
   * **!전달된 변수의 값을 변경하면, 호출한 쪽에서도 해당 변수의 값이 변경된다!**

     ```
      장점 : 복사하지 않고 직접 참조하기 때문에 빠르다.
      단점 : 직접 참조를 하기 때문에 원본 값이 영향을 받는다.(리스크)
     ```
