# Python day1 (2024-05-30)

# ch1. 파이썬 개요 및 환경설정

### 1. 아나콘다 다운로드
### 2. Jupyter Notebook 파일 저장 경로 수정
   
   * Jupyter Notebook 아이콘 우클릭 -> 속성에서 대상(T) "파일 위치"

### 3. jupyter Notebook 사용법

   ```
   shift+Enter : 포커스된 셀이 실행되고 다음셀로 이동
   alt+Enter : 포커스된 셀이 실행되고 다음셀이 생성된 후 이동
   ctrl+Enter : 포커스된 셀이 실행되고 포커스 이동없음
   Enter =: 셀이 포커스됨(편집 상태)
   ```

### 4. ESC키 누르고 핫키

   ```
    dd : 셀 삭제
    a : 윗셀 추가
    b : 아랫셀 추가
    m : 마크업셀로 전환
    y : 코드셀로 전환
   ```
---
# ch2. 자료형과 연산자

## 1. 변수
### 1-1. 변수선언

   * 별도의 변수 선언과정 없음
   * 다중 선언
     
      ```c
      a, b = 10, 20
      a, b = b, a + b #병렬로 같이 들어감 (20, 40이 아니라 20, 30)
      ```
      
### 1-2. 변수 할당

   * 대입 연산자(=) 사용

   **새로 할당할 때마다 새로운 메모리 공간에 값을 할당**

```python
area = 10
print("area 값은", area)
print("area 타입은", type(area))
print("area 주소는", id(area)) 
```

### 1-3. 변수이름 규칙

   ```
   - 문자(특수문자는 _제외하고 안됨), 숫자, _로 명명.
   - 문자로 시작
   - 파이썬에서 제공되는 기본 함수명은 피하자. 꼭 써야한다면 int_ 식으로 _를 붙임
   - 파이썬 예약어는 변수명 불가(ex. if)
   ```

### 1-4. 도움말
   
   * 함수 내에서 shift + tap 키
   
   * 함수 정의에서 도움말 만들기 -> **""" 설명 """**

      ```python
      def make_number(x, y=0) :
       """doc string(함수의 도움말)
       매개 변수 2개를 이용해서 2자리 정수를 만들어요
       x = 10의 자리수
       y = 1의 자리수 (default값 0)
       """
       return x * 10 + y
       ```

### 1-5. 변수 삭제

   * del 변수명
---
## 2. 화면 I/O

### 2-1. input

   * 문자로 return
   
      ```python
      first = input("첫 번째 숫자는? ")
      ```

   * 숫자로 return

     ```python
     first = int(input("첫 번째 숫자는? "))
     ```
     
### 2-2. print

   ```python
   print("두 수의 합은 {}".format(first + second))
   ```

   ```python
   print('Hello', 'world', sep='~', end='\t')
   ```
---
## 3. 기본 자료형

    -  파이썬은 타입을 지칭하는 키워드가 없고, 변수 할당 시 타입이 정해짐

    -  숫자, 문자, 논리형으로 나눌 수 있다.
      
### 3-1. 숫자 : int, float, complex
      
   * 모든 크기의 정수를 다 처리 가능

### 3-2. 문자 : str
         
   * " ", ' '모두 사용 가능

   * 문자열 슬라이싱 -> [from:to:step]

      ```python
      str_ = "0123456789"
      str_[0:9:2] # 0번째부터 9번째 앞까지 2씩 인덱스 증가
      str_[::2] # 처음부터 끝까지 2씩 인덱스 증가해서
      str_[0:3] # 0번째부터 3번째 앞까지(2번째까지)
         
      str_[-1] # 음수 인덱스는 뒤에서부터
      str_[5:] # 5번째 인덱스부터 끝까지
      str_[:-5] # 처음부터 -5번쩨 앞까지
         
      #str_[19] -> 없는 인덱는 error
      str_[5:19] # 슬라이싱에서는 인덱스를 벗어나면 끝까지

      # 끝부터 처음까지 (거꾸로)
      str_[9::-1]
      str_[::-1]
      ```

### 3-3. 논리 : bool

   * False로 간주하는 것 : 0, ""(빈스트링), ''(빈스트링), [], (), {}

   * True로 가주하는 것 : 0이 아닌 모든 수, " "(스페이스), '\0'(널문자)
      
### 3-4. 자료형 확인 및 변환

   ```python
   - type() : 자료형 확인
   - int() : 정수형 변환
   - float() : 실수형 변환
   - str() : 문자형 변환
   - bool() : 논리형 변환
   ```
---
## 4. 포맷팅

   * format()함수

        * "{[인덱스]:[공백대체문자][정렬방법][자릿수][타입]}".format(변수명, ...)
        * 정렬방법 : < (왼쪽정렬), > (오른쪽 정렬), ^ (가운데 정렬)
        * 타입 : d(10진수), x(16진수), b(2진수), f(실수), s(문자)
    
          ```python
          a = 10
          s = 'Hello'
          print("[{0:$>10d}], [{1:*<20.2}]".format(a, s)) #.2는 2개만 출력하라는 뜻

          >> [$$$$$$$$10], [He******************]
          ```  
---          
## 5. 연산자

### 5-1. 산술 연산자

   ```python
   +, -, /(결과는 실수), +, //(몫), %(나머지), **(제곱)
   ```

### 5-2. 할당 연산자

   ```python
   =, +=, -=, /=, %= ...
   ```

### 5-3. 논리 연산자

   ```python
   &, and, |, or, not (연산자 우선순위가 높음)
   ```

### 5-4. 비트 연산자

   ```python
   &, |, ^(XOR) (연산자 우선순위가 높음)
   ```

### 5-5. 비교 연산자

   ```python
   >, >=, <, <=, ==, !=

   '*' < '1' < 'A' < 'a' # 아스키코드 순서 : 특수문자 < 숫자 < 대문자 < 소문자
   ```
---
## 6. 문자열 함수

   ```python
   - 문자열 슬라이싱 : 문자변수[from:to:step]
   - len(문자열) : 문자 개수
   - upper() : 대문자로 변환
   - lower() : 소문자로 변환
   - title() : 각 단어의 앞글자만 대문자로
   - capitalize() : 첫문자만 대문자로, 그외는 소문자
   - count('찾을문자열') : 찾을 문자열이 몇개 들어있는지 갯수 반환
   - find('찾을문자열') : 찾을 문자열을 왼쪽부터 시작하여 몇번째 인덱스에 있는지 index 반환
                         (찾을문자열이 없으면 -1을 반환)
   - rfind('찾을문자열') : 찾을 문자열을 오른쪽부터 시작하여 몇번째 인덱스에 있는지 index 반환
                         (찾을문자열이 없으면 -1을 반환)
   - startswith('특정문자열') : 특정문자열로 시작하는지 여부 T/F 반환
   - endswith('특정문자열') : 특정문자열로 끝나는지 여부 T/F 반환
   - strip() : 좌우 공백제거
   - lstrip() : 왼쪽 공백제거
   - rstrip() : 오른쪽 공백제거
   - isdigit() : 문자열이 숫자 문자열인지 여부 T/F 반환
   - islower() : 문자열이 소문자인지 여부 T/F 반환
   - isupper() : 문자열이 대문자인지 여부 T/F 반환
   - replace(oldStr, newStr) : oldStr을 newStr로 변경
   ```
---
## 7. 날짜 다루기

   * 날짜

        ```python
         from datetime import date # 폴터(파일)안에 파일(함수)를 가져와라
         someday = date(2024, 5, 30)
         print("{}".format(someday))

         >>2024-05-30
        ```

   * 시간

        ```python
         from datetime import datetime
         now = datetime.today()
         print("{:%Y년%m월%d일 %H시 %M분}".format(now))

        >> 2024년05월30일 12시 48분
        ```
 ---       
## 예외 처리

   ```python
   try: # 예외가 발생하지 않으면 try 실행
      print(a / b)
      print(a // b)
      print(a % b)
   except: # 예외 발생했을 때 실행
      print("떼끼 두 번째 정수에 0을 넣으시면 나누기는 못해요")
   ```
---
# ch3. 데이터 구조
   
   * 변수 하나에 여러개 데이터를 넣기 위한 자료형

     ```
     리스트 [], 튜플 (), 딕셔너리(구조체와 유사), 셋 (집합)
     ```

## 1. 리스트
   
   * 파이썬은 변수의 타입이 없으니까 동일 자료형의 집합은 아님 따라서 100% 배열과 똑같지는 않다.

   * 파이썬 리스트는 길이 줄였다가 늘렸다가 가능.

   * 동일 자료형의 집합이 아니여도 리스트에 들어갈 수 있다. -> but! 동일 자료형이 아니면 최소, 최대, sort불가

### 1-1. 리스트 만들기

   * [] 이용

   * 인덱스 : 0부터 시작 / -1은 맨 마지막 인덱스

   * 슬라이싱([from:to:step])을 이용하여 추출 가능

     ```python
      fruits = ['banana', 'apple', 'orange', 'grape', 0]
     
      print(fruits) # 그냥 print를 이용해 출력 가능!
      fruits[0] = 'mango' # 요소 변경
     ```

   * 반복문을 통해 리스트 요소 출력

      * for문으로 요소 출력
        
     ```python
      for fruit in fruits:
          print(fruit)
     ```
     
      * enumerate로 인덱스와 요소 출력
        
     ```python
      for idx, value in enumerate(fruits):
          print("{}번째 과일은 {}".format(idx, value))
     ```
     
### 1-2. 기본정보 조회

```python
numbers = [1,2,3,4,5]
print("요소의 수 : ", len(numbers))
print("최소값 : ", min(numbers))
print("최대값 : ", max(numbers))
```

### 1-3. 요소 추가

   * + : 두 리스트를 연결

   * 리스트*n : 리스트를 n만큼 반복

   * append() : 요소 뒤에 추가

     ```python
      numbers = [1,2,3,4]
      num = [5,6]

      numbers.append(num)
      print(numbers)

     >>[1, 2, 3, 4, [5, 6]]
     ```

   * extend() : 리스트의 요소별로 뒤에 추가

        ```python
      numbers = [1,2,3,4]
      num = [5,6]

      numbers.extend(num)
      print(numbers)

     >>[1, 2, 3, 4, 5, 6]
     ```

### 1-4. 인덱싱

```python
index(찾고자하는 값, 1) : 찾고자하는 값을 1번 인덱스부터 찾아 그 위치를 반환.
count(찾고자하는 값) : 찾고자하는 값이 몇 번 나오는지 count

2 in numbers # numbers 안에 2가 있는지 여부 T/F 반환
```

### 1-5. 리스트의 원하는 내용만 추출

   * 슬라이싱 [from:to:step] : 원하는 인덱스의 값을 추출

      ```python
      numbers[::2] # 인덱스가 짝수인 값을 추출

      >>[1, 5, 10, 13, 19]
      ```

   * 리스트 컴프리헨션을 이용 (람다 함수와 관련있음!) : 원하는 데이터만 추출

        ```python
         # for문을 돌면서 if문을 만족하는 num을 result에 저장
         result = [num for num in numbers if num % 2 == 0]
         result
        
        >>[10, 12, 18, 20]

        # 과일의 글자가 5글자 이상인 과일의 글자수를 추출하세요
        fruits = ['orange', 'apple', 'mango', 'kiwi']
        [len(fruit) for fruit in fruits if len(fruit) >= 5]

        >>[6, 5, 5]
        ```

  ### 1-6. 삭제하기

     ```python
      remove(data) : 해당 data가 제거 ; return 되지 않음
      del 리스트변수[idx] : idx번째 요소 제거
      pop() : 가장 마지막 인덱스 요소가 return 되고 삭제
     ```

  ### 1-7. 정렬하기

   * 오름차순 정렬
     
      ```python
      numbers = [9, 10, 1, 5, 5]
      numbers.sort() # 오름차순 정렬
      numbers

      >> [1, 5, 5, 9, 10]
      ```

   * 내림차순 정렬

      ```python
      numbers = [9, 10, 1, 5, 5]
      numbers.sort(reverse = True) # 내림차순 정렬
      numbers
      
      >> [10, 9, 5, 5, 1]
      ```

   ### 1-8. 리스트 복제

      * 얕은 복사 (=를 사용) : 주소값을 복사 -> 인스턴트가 메모리에 새로 생성되지 않는다
      
      ```python
      numbers = [6,1,2]
      new_numbers = numbers # 얕은 복사
      numbers.sort()
      print("정렬 전 데이터 : ", new_numbers)
      print("정렬 후 데이터 : ", numbers)
      # 이렇게 하면 다 바뀜... 깊은 복사 해야한다!

      >> 정렬 전 데이터 :  [1, 2, 6]
      >> 정렬 후 데이터 :  [1, 2, 6]      
      ```

      * 깊은 복사 (.copy()를 사용) : 데이터 자체를 복사 -> 복사된 두 객체는 완전히 독립적인 메모리를 차지한다.

      ```python
      numbers = [6,1,2]
      new_numbers = numbers.copy() # 깊은 복사
      numbers.sort()
      print("정렬 전 데이터 : ", new_numbers)
      print("정렬 후 데이터 : ", numbers)

      >> 정렬 전 데이터 :  [6, 1, 2]
      >> 정렬 후 데이터 :  [1, 2, 6]      
      ```
---
## 2. 튜플

   * 리스트와 유사하지만 읽기 전용 (수정이 불가능!)
     
   * ()를 이용해서 생성

   ```python
   t = ('서울',) # 요소가 하나인 튜플은 컴마(,) 필수!
   type(t)

   >> tuple
   ```
---
## 3. 딕셔너리

   * 구조체와 유사 (c의 구조체와 다른점 : 함수 있음, 추가 가능)
   * {}를 이용해서 생성. key-value쌍으로 구성
   * value는 중복 가능하나 key는 중복 불가
   * index를 이용한 참조 불가 (index가 없음)

      ```python
      dic = {'name' : '홍길동', 'address' : '서울시 금천구'}

      dic['score'] # 없으면 error
      >> error!!!

      dic.get('name'), dic.get('address'), dic.get('score') # .get()은 없으면 None으로
      >> ('홍길동', '서울시 금천구', None)
      ```

   * 수정 : 없던 key-value쌍 추가 가능

        ```python
         dic['score'] = 100
         dic['sport'] = 'sleep'
         print(dic)
        >> {'name': '홍길동', 'address': '서울시 금천구', 'score': 100, 'sport': 'sleep'}
        ```

   * 제거 가능

        ```python
         dic.pop('sport')
         >> 'sleep'
        ```

   * for문 사용 방법 (리스트, 튜플과 달리 딕셔너리에는 index가 없는데 어떻게 하지?)
      
      * keys()

        ```python
         dic.keys()
        >> dict_keys(['name', 'address', 'score'])
        ```
        
      * values()

        ```python
         dic.values()
        >> dict_values(['홍길동', '서울시 금천구', 100])
        ```
        
      * **items()**

        ```python
         dic.items()
        >> dict_items([('name', '홍길동'), ('address', '서울시 금천구'), ('score', 100)])
        ```

     * **for문에 items() 사용해서 key, value 출력**

          ```python
          for key, value in dic.items():
          print("{} : {}".format(key, value))
          >>name : 홍길동
          >>address : 서울시 금천구
          >>score : 100
          ```
          
* 'key' in dic

  ```python
   dic = {'name' : '홍길동', 'score' : 100}

  'name' in dic
  >> True

  '홍길동' in dic # 딕셔너리에서는 key값이 있는지를 의미(value X)
  >> False
  ```
---
## 4. 셋

   * 중복을 허용하지 않는 집합 (순서x = 인덱스x; but, enumuerate 사용 가능)
   * {}를 이용해서 정의

     ```python
      fruits = {'apple', 'orange', 'banana', 'banana', 0, 0} # 파이썬은 자료형 상관없음
     
      print(fruits)
      print(type(fruits))
     
      >> {'banana', 0, 'apple', 'orange'}
      >> <class 'set'>
     ```

   * 값 추가

     ```python
      fruits.add('kiwi')
      print(fruits)
     >> {0, 'orange', 'kiwi', 'banana', 'apple'}

     fruits.add('banana') # 이미 존재하는 값은 추가되지 않음
      print(fruits)
     >> {0, 'orange', 'kiwi', 'banana', 'apple'}
     ```
     
        
     
