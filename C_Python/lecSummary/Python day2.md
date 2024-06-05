# Python day2 (2024-05-31)

# ch4. 제어문

## 1. if문

* if, elif, else

```python
if 조건: 
   수행
elif 조건:
   수행
else:
   수행
```
## 2. for-in문

```python
for 변수 in 나열이 가능한 자료형:
    반복할 문장1
    반복할 문장2
else:
    변수에 값이 할당되지 않은 경우 한 번 실행할 문장 (else 구문은 선택사항)
    for문 안에서 break로 빠져나오면 else는 수행되지 않는다. (모든 반복을 마친 후 수행)
```

## 3. while문

```python
while 조건:
    반복문장1
    반복문장1
else:
    조건이 거짓일 경우 한 번 수행할 문장 (else는 선택사항)
    while문 내 break를 통해서 빠져 나올때는 else블럭은 수행하지 않음

```

## 4. break, continue

* break : 반복문을 종료시킨다.

* continue : continue 아래 코드는 실행하지 않고 다음 증감식으로 넘어간다.

## *난수 발생

```python
# 1~100까지 수 중에서 난수 발생
import random
com = random.randint(1, 100)
```
---
# ch5. 함수

## 1. 함수의 정의 및 사용(호출)

### 1-1. 함수 정의

* 반복해서 사용할 코드를 묶어서 구현해 놓은 것

* 같은 이름의 함수는 덮어씀 (오버로딩 불가)

```python
# 함수 정의 (구현)
  def 함수명([인수1, 인수2, ...]):
    명령어1
    명령어2
```

```python
def my_hello(x, msg): # 함수정의
    for i in range(x):
        print(i, msg)
```

### 1-2. docstring
* 함수 도움말 : shift+tab키로 볼 수 있음

  ```python
  def fibonacci(n):
    '''
    인수로 들어온 n값 미만의 피보나치 수열을 출력하는 함수
    ex. n = 10 : 0, 1, 1, 2, 3, 5, 8
    ex. n = 5 : 0, 1, 1, 2, 3
    '''
    a, b = 0, 1 # 내부적으로 튜플로
    while a < n:
        print(a, end='. ')
        a, b = b, a + b
    print() # 개행
  ```

### 1-3. 지역변수(local var)와 전역변수(global var)

* 지역변수 : 함수 내에서만 사용 가능한 변수

  ```python
  def func2():
    local_var = 100 # 지역변수
    print(local_var)
  func2()
  ```

* 전역변수 : 어디에서나 쓸 수 있는 변수

  ```python
  global_var = 100 # 전역변수
  def func1():
      print(global_var)

  func1()
  global_var
  ```

### 1-4. Lexical 특성

* 초기화하기 전에 참조하는 행위로 지역변수를 선언하면 선언하는 부분을 먼저 컴파일 한다.
  하지만, 아직 값을 할당하진 않아(초기화 하지 않아) 그 전에 지역변수를 사용하면 오류가 발생한다.
  
  ```python
  g_var = 100 # 전역변수
  def func3():
    print(g_var) # error
    g_var = 200 # 지역변수 먼저 선언/ but, 초기화는 순서대로
    print(g_var)
  func3()
  ```
  
### 1-5. 전역변수 수정
* global 전역변수
  
```python
g_var = 100 # 전역변수
def func3():
    global g_var # 함수 내에서 g_var는 전역변수를 쓴다!
    print(g_var)
    g_var = 200 # 전역 변수에 값을 할당
    print(g_var)
func3()
```

### 1-6. 값에 의한 호출 (Call by Value)
: 함수 안에서 값이 바뀌어도 함수 밖에서는 바뀌지 않는다.

+ 함수에 인수로 전달된는 인수가 **스칼라 변수**(**숫자**, **문자**, **논리**)일 경우

### 1-7. 참조에 의한 호출 (Call by reference)
: 함수 안에서 값이 바뀌면 함수 밖에서도 값이 바뀐다.

+ 함수에 전달되는 인수가 **리스트, 딕셔너리, 셋**일 경우

---
## 2. 함수의 실행결과를 반환하는 return
* 여러 개의 값을 반환할 수 있다 (하나의 튜플로 반환, 컴파(,)는 자동적으로 튜플로 인식)
  
  ```python
  def swap(a, b):
    return b, a
  ```
---
## 3. ⭐함수의 매개변수 ⭐

### 3-1. 기본값을 갖는 매개변수

* 기본값을 갖는 인수는 순서인수 뒤에
  
```python
def my_add(num1, num2, num3 = 0): # num3은 기본값을 갖는 인수 -> 매개 변수 2개도 되고 3개도 된다!
    return num1 + num2 + num3
print(my_add(1, 2, 3))
print(my_add(1, 2))
```

### 3-2. 튜플 매개변수를 이용한 가변인수(인수 개수가 가변) 설정

* 대표적으로 print -> 인수의 개수가 가변 = 가변인수

* 튜플 매개변수 : 함수에 매개변수를 (**매개변수 이름*)으로 튜플로 전달 받음
  ```python
  def add(*args) :
    print("전달받은 args : ", args)
    print(type(args))
    sum = 0
    for num in args:
        sum += num
    return sum

  print(add(1, 2, 3, 4, 5, 6))
  print(add(1))
  
  >> 전달받은 args :  (1, 2, 3, 4, 5, 6)
  >> <class 'tuple'>
  >>  21
  
  >> 전달받은 args :  (1,)
  >> <class 'tuple'>
  >> 1
  ```

### 3-3. 딕셔너리 매개변수

* 딕셔너리 매개변수 : 함수에 매개변수를 (***매개변수 이름*)으로 딕셔너리로 전달 받음

  ```python
  def func(**args): # args를 딕셔너리로 전달 받음
    print(args)
    print(type(args))

    for key, value in args.items():
        print("{} : {}".format(key, value))

  func(name="홍길동", age=20)

  >> {'name': '홍길동', 'age': 20}
  >> <class 'dict'>
  >> name : 홍길동
  >> age : 20
  ```

### 3-4. 함수 정의 시 매개변수의 순서
* 순서 인수 > 튜플 인수(*) > 키워드 인수(매개변수 이름을 명시) > 딕셔너리 인수(**)

  ```python
  def func(a, b, c, *d, e=10, **f):
    print('a=', a)
    print('b=', b)
    print('c=', c)
    print('d=', d)
    print('e=', e)
    print('f=', f)

  func(10, 20, 30, 1, 2, 3, 4, 5, e=100, height=180, name='홍길동',address='서울시')
  >> a= 10
  >> b= 20
  >> c= 30
  >> d= (1, 2, 3, 4, 5)
  >> e= 100
  >> f= {'height': 180, 'name': '홍길동', 'address': '서울시'}
  ```

### 3-5. 인수(매개변수)의 언패킹
* 함수에 인수를 패킹하지 않고 그대로 전달하고 싶을때 함수를 호출할때 튜플:(**변수명*) / 딕셔너리:(***변수명*)

  * 튜플 인수 언패킹
    ```python
    # args앞에 * : args가 튜플로 전달 받음; 튜플 매개변수
    def add(*args) :
      print("전달받은 args : ", args)
      print(type(args))
      sum = 0
      for num in args:
        sum += num
      return sum

    data = (1, 2, 3, 4, 5, 6)
    add(*data) # 언패킹/ 그냥 add(data)하면 error
    ```

  * 딕셔너리 인수 언패킹
    ```python
    def func(**args): # args를 딕셔너리로 전달 받음
    print(args)
    print(type(args))

    for key, value in args.items():
        print("{} : {}".format(key, value))

    dic = {'name' : '홍길동', 'age' : '30'}
    func(**dic) # 언패킹 / 그냥 func(dic)하면 error
    ```
---
## 4. 람다식
* 람다식은 작은 익명함수를 의미함
* 실행할 문장을 한 문장만 작성할 수 있음
* 리스트 컴프리헨션과 같이 참조해서 학습 추천
* ex. map(), filter()에서 사용할 예정

```python
(lambda a, b : a + b)(5, 6)b # (lambda 매개변수 : return 값)
>> 11                     
```

* *매개변수로 람다식 이용
  ```python
  def map_template(func, L=[]):
    result = []
    for data in L:
        result.append(func(data))
    return result

  list_data = [1,2,3,4,5]
  map_template(lambda x : x**2, list_data)
  
  >> [1, 4, 9, 16, 25]

  # map함수 (복잡한게 많아서 리스트 컴프리헨션이 아니라 map을 많이씀, 간단한 것은 리스트 컴프리헨션 사용)
  list(map(lambda x:x*2, list_data))
  >> [2, 4, 6, 8, 10]

  # filter함수
  list(filter(lambda x : x%2==0, list_data))
  >> [2, 4]
  
  ```
---
# ch6. 모듈과 패키지

## 1. 모듈이란

* 모듈은 함수, 변수, 클래스가 담긴 파일(*.py)
* 패키지는 모듈들이 묶여있는 폴더
* 파이썬 표준 모듈 200여개
* 표준 모듈 외의 모듈 사용하려면 라이브러리를 설치 : "pip install 라이브러리명" "conda install 라이브러리명"

## 2. 사용자 정의 모듈

* 모듈을 가져오는 순서 (1) 표준모듈 (2) sys.path 변수에 저장된 경로

```python
import sys
sys.path.append("C:\\IVS\\C_Python\\source\\pylib") # sys.path에 모듈이 있는 경로 추가
sys.path
```

> 2-1. import A : A모듈을 가져옴
  ```python
  import fibonacci
  fibonacci.fibonacci(100)
  ```
> 2-2. import A as B : A모듈을 B이름으로 가져옴
  ```python
  import fibonacci as fibo
  fibo.fibonacci(50)
  ```

> 2-3. from A import B : A모듈 안의 B함수를 가져옴 (다른 함수는 안 가져다!)
  ```python
  from fibonacci import fibonacci
  # 여러 함수 가져오려면 from fibonacci import fibonacci, a, b, c... (컴마로 구분해서 가져옴)
  fibonacci(50)
  ```

> 2-4. from A import B as C : A모듈 안에 B함수를 C이름으로 가져옴
  ```python
  from fibonacci import fibonacci as fibo
  fibo(20)
  ```
* import 취소
  ```python
  del fibonacci
  ```
  
## 3. __name__
* 모듈의 이름을 가지고 있는 변수로 현재 .py 파일의 이름을 가지고 있는 변수이다.
* 직접 실행된 파일의 __name__은 __main__이 되고 import 돼서 모듈로 사용된 파일의 __name__은 모듈이름이 된다.
* Python 인터프리터가 최초로 실행한 스크립트 파일의 name에는 'main'이 들어간다. 이는 프로그램의 시작점이라는 뜻이다.

---
# ch7. 객체자향 프로그래밍

## 1. 객체와 클래스

```python
class 클래스명(상속받을 클래스명):
    변수나 함수들을 선언

class Person:
    "Person 클래스는 어쩌구 저쩌구 여러 줄 설명하는 독스트링"
    pass
p1 = Person()
```

> Class
```python
class Person:
    # 클래스를 설명하는 독스트링
    "Person은 이름과 성별 멤버변수가 있는 객체타입입니다"

    # 생성자 함수를 이용한 초기화 # self는 내 객체 변수를 뜻함
    def __init__(self, name='홍길동', gender='남자'): 
        self.name = name
        self.gender = gender # gender는 매개변수, self.gender는 내 객체 변수
        print('{}, {} Person 객체가 생성되었습니다'.format(self.name, self.gender))
    
    def print_info(self): # self 꼭 넣어야함! 매개변수 아님! 객체 안의 함수!!
        print("{}님은 {}입니다".format(self.name, self.gender), end=' ')     

    def printCnt(self, cnt):
        for i in range(cnt):
            print(self.name, end='\t')

    # 새롭게 셋팅하면 원래 __str__()는 없어짐
    def __str__(self): 
        return "{}, 성별은 {}".format(self.name, self.gender)
```

> 객체 생성
```python
p1 = Person('성춘향', '여자')
>>성춘향, 여자 Person 객체가 생성되었습니다
```

> 객체 변수 출력
```python
print(p1.name, p1.gender)
>> 성춘향 여자
```

> def print_info(self): 함수 호출
```python
p1.print_info()
>> 성춘향님은 여자입니다 
```

>  def printCnt(self, cnt): 함수 호출
```python
p1.printCnt(5)
>> 성춘향	성춘향	성춘향	성춘향	성춘향	
```

>  def __str__(self):
```python
print(p1.__str__()) # default로 .__str__() # error가 안남 -> 상속받은게 있기 때문
>> 성춘향, 성별은 여자

print(p1) # def __str__(self): 로 새로 셋팅해서 그냥 출력 가능
성춘향, 성별은 여자
```
---
## 2. 상속과 재정의

* Person에 있는걸 상속받으면 Person에 있는 것 변수와 메소드 다 쓸 수 있음
  
> major 추가
```python
class Student(Person):
    'name, gender, major 멤버변수를 갖는 Student타입'
    def __init__(self, name, gender, major):
        # 부모 클래스의 생성자 함수로 name, gender 초기화
        super().__init__(name, gender) # 'super()는 부모 클래스의' 라는 뜻
        self.major = major

    def print_info(self): # major는 print가 없다!! 좀 바꿔야징
        super().print_info()
        print("그리고 전공은 {}입니다".format(self.major))

    def __str__(self):
        return super().__str__() + ", 전공은 {}".format(self.major)
```

> 부모 클래스의 생성자 함수로 name, gender 초기화한 후, self.major = major 추가
```python
s1 = Student("김철수", "남자", "컴공") # Person생성자에서 print함
>> 김철수, 남자 Person 객체가 생성되었습니다
```

```python
s1.name, s1.gender, s1.major
>> ('김철수', '남자', '컴공')
```

> 부모 클래스의 print_info()에 print("그리고 전공은 {}입니다".format(self.major))추가
```python
s1.print_info()
>> 김철수님은 남자입니다 그리고 전공은 컴공입니다
```

> 부모 클래스의 함수 그대로 사용
```python
s1.printCnt(5)
김철수	김철수	김철수	김철수	김철수	
```

> 부모 클래스의 __str__()에 + ", 전공은 {}".format(self.major) 추가가
```python
print(s1)
>> 김철수, 성별은 남자, 전공은 컴공
```

