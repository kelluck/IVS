# C day1(2024-05-27)
---
## 컴퍼일 언어 VS 인터프리터 언어

### 1. 컴파일 언어 : 소스 코드를 컴파일을 통해 기계어로 번역한 파일을 만들고 이 파일을 통해 실행시키는 언어
   * 장점: 컴파일 된 실행 파일만 있으면 프로그램을 실행시킬 수 있어 매우 빠름
     * ex) C, C++ 등

### 2. 인터프리터 언어 : 인터프리터(해석기)에 의해 소스 코드를 한 줄씩 읽어 실행하는 언어
   * 장점 : 코드를 빠르게 테스트해 볼 수 있고, 프로그래밍을 대화식으로 할 수 있음 
     * ex) Python, JavaScript, R등   

---
## GitHub 활용

<https://mywaycoding.tistory.com/50>   

<https://gist.github.com/ihoneymon/652be052a0727ad59601>

---
## ch2. C언어 변수

### 1. 정수형 변수 : 숫자형 값 중 정수를 담을 때 사용
   * int(4byte) : 약 21억까지 표현가능, 서식 지정자 == %d
  
   ```c
      printf(“%d”, num);
      scanf(“%d”, &num);
   ```

### 2. 실수형 변수 : 소수점이 붙는 수  
   (float는 사용하지 않는 것이 좋음. 4byte라 값을 정확히 표현하기 어려움)
   * double(8byte) : 서식 지정자 == %lf

     ```c
      printf(“%lf”, num);
      scanf(“%lf”, &num);
     ```

### 3. 문자형 변수 : 문자 or 문자열을 담을 때 사용
   * 문자 -> char(1byte), 서식 지정자 == %c

     ```c
      prinrtf(“%c”, c);
      scanf(“%c”, &c);
     ```

   * 문자열 -> char* arr or char arr[], 서식 지정자 == %s

     ```c
      printf(“%s”, str);
      scanf(“%s”, str, sizeof(str));
     ```