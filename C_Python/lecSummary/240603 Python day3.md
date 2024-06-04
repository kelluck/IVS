# ch8. 예외 처리

 * 예외가 날 가능성이 있는 부분을 미리 예상하고 그에 대한 처리를 프로그래밍하는 것 (이유 : 안정적으로 실행될 수 있도록 하기 위함)

## 1. try ~ except로 예외 처리

```python
try:
    예외가 발생할 가능성이 있는 명령어1
    명령어...
except[예외 타입[as 예외객체변수명]]:           #[예외 타입[as 예외객체변수명]]는 써도 돼고 안써도 됨.
    예외가 발생했을 경우 수행
[else:
    예외가 발생되지 않을 경우 수행 명령어]       # 진짜 거의 안씀
[finally:
    예외가 발생되든 안되든 반드시 실행할 명령어]  # database, file access하지 않으면 쓸 일없음. 요즘은 그마저도 다른 문법으로 대체하려고함
```

- 사용예시 1
```python
# 100을 입력받은 정수값으로 나눠 출력한다
# ValueError 
# ZeroDivisionError
try:
    x = int(input("100을 나눌 정수를 입력하세요 >>"))
    print("입력한 수는 {}".format(x))
    print("100을 입력한 정수로 나누면 {:.2f}입니다".format(100/x))
except:
    print("유효한 점수가 아닙니다")
```

- 사용예시 2
```python
try:
    x = int(input("100을 나눌 정수를 입력하세요 >>"))
    print("입력한 수는 {}".format(x))
    print("100을 입력한 정수로 나누면 {:.2f}입니다".format(100/x))
except ValueError:
    print("유효한 숫자를 입력하세요")
except ZeroDivisionError:
    print("0으로는 나눌 수 없습니다")
```

- 사용예시 3
```python
try:
    x = int(input("100을 나눌 정수를 입력하세요 >>"))
    print("입력한 수는 {}".format(x))
    print("100을 입력한 정수로 나누면 {:.2f}입니다".format(100/x))
except ValueError:
    print("유효한 숫자를 입력하세요")
except ZeroDivisionError:
    print("0으로는 나눌 수 없습니다")
except Exception: # except절이 많을 경우 상위 클래스를 아래에 명시
    print("알 수 없는 혹시 모듈 예외입니다") # 상위 클래스(모든 exception(ValueError, ZeroDivisionError...)이 Exception으로부터 상속받았다)! 따라서 가장 밑에 써야한다. 
                                           #위에 쓰면 모든 에러가 Exception으로 간다
```

- 사용예시 4
```python
while True:
    try:
        x = int(input("100을 나눌 정수를 입력하세요 >>"))
        print("입력한 수는 {}".format(x))
        print("100을 입력한 정수로 나누면 {:.2f}입니다".format(100/x))
        break; #try를 다 수행하면 끝내기 위함
    except (ValueError, ZeroDivisionError): # 이렇게 써도 됨
        print("유효한 숫자를 입력하세요")
    except Exception: # except절이 많을 경우 상위 클래스를 아래에 명시
        print("알 수 없는 혹시 모듈 예외입니다") 
```

- 사용예시 5
```python
while True:
    try:
        x = int(input("100을 나눌 정수를 입력하세요 >>"))
        print("입력한 수는 {}".format(x))
        print("100을 입력한 정수로 나누면 {:.2f}입니다".format(100/x))
        break; #try를 다 수행하면 끝내기 위함
    except (ValueError, ZeroDivisionError) as e: # 예외가 발생했을때 변수명이 e로 됨
        print(e) #print(e.__str__()) # print를 쓰면 __str__()함수가 자동으로 수행
        print("예외 객체의 타입 : ", type(e)) 
        print("예외 메세지 e.args : ", e.args) # print(e)와 같음. 따라서 예외 메세지를 보려면 그냥 print하기
```

- 사용예시 6
```python
try:
    f = open('data/ch08.txt', 'r', encoding='utf-8')
    data = f.read() # 파일을 끝까지 텍스트 형태로 읽어서 반환
    #print(data)
except FileNotFoundError as e:
    print(e)
else: # try절이 다 끝났을 경우(except로 안빠졌을때); 그냥 try에 써도 됨...
    print(data)
finally:
    f.close() # 중요; w때는 안 닫으면 저장이 안됨.
```

## 2. 강제 예외 발생 (raise)

* 사용자 정의 예외 타입
  
```python
class LengthZeroError(Exception): # 기존 파이썬에서 제공되는 Exception으로부터 상속받음
    "길이가 0일때 발생하는 예외" # 도움말
    def __init__(self):
        super().__init__("매개변수 길이가 0이면 예외")

def insert(*data): # 튜플 매개변수
    if len(data) == 0:
        raise LengthZeroError()
    for item in data:
        print(item, end=" ")
    print("등을 입력하셨습니다")

insert()

>> LengthZeroError: 매개변수 길이가 0이면 예외
```

## 3. 파일 정리 작업 (with절 이용)

* with절 이용시 자동 close()실행

```python
with open('data/ch08.txt', 'r', encoding="utf-8") as f:
    lines = f.readlines()
print(lines)

>> ['This is Test File\n', 'Hello, Python\n', '테스트 파일입니다']
```

---
# ch9. 입출력 프로그래밍

## 1. 파일에 데이터 저장하고 불러오기
* w : 있는 파일은 기존의 파일에 덮어쓰고 없는 파일은 생성 (쓰기 전용)
* a : 있는 파일은 추가 / 없는 파일은 생성 (쓰기 전용)
* r : 읽기 전용

- 파일에 데이터 쓰기 (open 이용)
```python
f = open('data/ch09.txt', 'w') # encoding 기본값 CP949
print(f.writable()) # 쓸 수 있다!
f.write("Hello\nWorld\nPython\n반갑습니다\n") # 한글은 cp949
f.write("여러번 write가능\n")
f.close()
```

- 파일에 데이터 쓰기 (with 이용)
```python
with open('data/ch09.txt', 'w') as f: # with를 이용한 write (close자동)
    print("Python is easy\n", file=f)
```

- utf-8로 인코딩 된 csv파일 읽기
```python
with open('data/ch09_member1.csv', 'r', encoding='utf-8') as f:
    data = f.readlines()
    for row in data:
        print(row, end="")
```

---
# ch10. 데이터 프레임과 시리즈 - Pandas

## 1. Pandas 패키지
* 데이터 분석을 위한 반드시 알아야 할 패키지. 넘파이를 기반으로 하며, 다른 라이브러리와 잘 통합되어 설계
* 차원 구조를 갖는 시리즈, 2차원 구조를 갖는 데이터프레임을 제공
* 결측치 처리, 크기변경(열 삭제/추가, 행 삭제/추가), 데이터 정렬, 데이터 분할/병합, 통계 처리, 부분 데이터 추출, 파일 입출력, 레이블링, 시각화 용이, ...
  
## 2. 데이터 프레임 만들기

### 2-1. 딕셔너리를 이용해서 데이터 프레임 만들기

```python
d = {'name':['홍길동', '신길동'], 'age':[20,30]}
df = pd.DataFrame(data=d)
df
```

### 2-2. 리스트를 이용해서 데이터 프레임 만들기

```python
d = [{'name' : '홍길동', 'age':20}, {'name':'신길동', 'age':30}]
df = pd.DataFrame(data=d)
df
```

### 2-3. read_csv()

```python
df = pd.read_csv('data/전국 평균 평당 분양가격(2013년 9월부터 2015년 8월까지).csv', encoding="CP949")
```

- 추가함수
```python
df.shape # 행, 열
df.head(2) # 상위 2줄 # 디폴트 :5줄
iris.tail() # 끝에서부터 5행보기
pd.options.display.max_columns # 최대 디스플레이될 수 있는 colums 수
pd.options.display.max_columns = 22
df.sample() # 랜덤 1행
```

### 2-4. sklearn, statsmodels, searborn 등의 라이브러리에서 데이터프레임 불러오기

* statsmodels
``` python
import statsmodels.api as sm
iris = sm.datasets.get_rdataset('iris', package='datasets').data
```

## 3. 이름(열, 행) 지정하기

```python
# 헤더가 없는 파일
member_df = pd.read_csv('data/ch09_member1.csv', header=None)

# 열이름 지정하기
member_df.columns = ['name', 'age', 'email', 'address']

# 행 병합
member_df = pd.concat([member_df, member_df])

# index 수정
member_df.index = range(len(member_df))

# name을 행이름으로
member_df.set_index("name", inplace=True) # inplace=True 데이터프레임에 적용

# 행이름을 컬럼에 편입시키기
member_df.reset_index(inplace=True) # reset을 member_df에 적용

# 시리즈 # 한 열만 가져올때
name = member_df['name']

# 0번 인덱스 행 => 시리즈 # 한 행만 가져올때
member = member_df.loc[0]

# 결측치 확인, type을 볼 수 있음
member_df.info()

# 데이터 프레임의 한 열의 타입을 변경
member_df['age'] = member_df['age'].astype('float64')
```

## 4. 부분 데이터 조회

* 특정 열, 특정 행, 특정 행의 특정 열, 특정 조건의 행의 모든 열, 특정 조건의 행의 특정 열

### 4-1. 단일 열 조회
```python
# 파일 읽기
member = pd.read_csv('data/ch09_member2.csv')

# 단일 열 조회 # 가장 많이 안 씀
member['name'] # 시리즈
member['name'].to_frame() # 시리즈를 데이터 프레임으로
```

### 4-2. loc[]을 이용한 이름(열, 행)으로 조회

* 단일 행, 여러 행, 여러 열, 행과 열을 동시에 접근
* 데이터프레임.loc[행(행 슬라이싱), 열(열 슬라이싱)]
* 가장 많이 사용

```python
# 단일 행
member.loc[0] # 시리즈

# 여러 행
member.loc[0:4] # 0행부터 5행까지

# 여러 열
member.loc[:,'name':'email'] # 무조건 행이 먼저, 모든 행을 쓸거면 ':'

# 여러 열 (name열과 email열)
member.loc[:, ['name','email']]

# 1행부터 4행까지 name과 email
member.loc[1:4, ['name', 'email']]

# 1과 4행, name, email, address 출력
member.loc[[1,4],['name','email', 'address']]
```

### 4-3. iloc[]을 이용한 숫자(인덱스)로 조회
* 몇 번째 행부터 몇 번째 행 앞까지, 몇 번째 열부터 몇 번째 열 앞까지, 음수 가능 / 슬라이싱과 같음

```python
# 슬라이싱 from:to:step -> from부터 to 앞까지 step씩
member.iloc[0:4]

# 0행, 0열부터 3열 앞까지
member.iloc[0,0:3]

# 맨 오른쪽 열을 제외하고 출력
member.iloc[:, :-1]

# member의 행 순서를 역순 출력 (맨 마지막열을 제외하고)
member.iloc[::-1,:-1]
```

### 4-4. 조건으로 조회하기

```python
# 30살 이상의 데이터 출력
member.loc[member['age'] > 30] # 인덱스 대신 조건

# 강서구 사는 사람 출력
address = "서울시 강동구"
address.find('강동구') # 찾으면 인덱스 반환, 못찾으면 -1반환

# 시리즈에 문자함수를 사용하는 방법
# https://pandas.pydata.org/pandas-docs/stable/reference/series.html#string-handling
member['address'].str.find('강서구') != -1

# address가 '강서구'인 데이터의 name, age, address를 출력하시오.
member.loc[member['address'].str.find('강서구') != -1, ['name', 'age', 'address']]
```

* iris 데이터를 이용한 예
```python
import seaborn as sns
iris_df = sns.load_dataset('iris')
# 0~49 setosa / 50~ 99 versicolor / 100~149 virginica
iris_df.loc[48:60].head()

# spacies가 versicolor인 데이터의 모든 열
iris_df[iris_df['species'] == 'versicolor'].head()

# spacies가 versicolor인 데이터의 맨 마지막 열을 제외한 데이터
iris_df.loc[iris_df['species'] == 'versicolor', 'sepal_length': 'petal_width'].head()

# spacies가 versicolor인 데이터의 맨 마지막 열을 제외한 데이터
iris_df.iloc[:, :-1][iris_df['species'] == 'versicolor']

# sepal_length가 6.2보다 크고, spacies가 versicolor인 데이터를 출력
iris_df[(iris_df.species == 'versicolor') & (iris_df.sepal_length > 6.2)] # iris_df['species'] == iris_df.species
                                                                          # 파이썬에서는 &의 우선순위가 높기 떄문에 괄호 필수!

# sepal_length가 6.2보다 크고, spacies가 versicolor인 데이터의 sepal_length와 species, sepal_width를 출력
iris_df.loc[(iris_df.species == 'versicolor') & (iris_df.sepal_length > 6.2), ['sepal_length', 'sepal_width', 'species']]
```

## 5. 데이터 추가 및 삭제

* 추가
  
```python
import numpy as np
member['major'] = ['컴공', '전기', '전자', '기계', 'AI', np.nan] # np.nan로 결측치 넣기

hobby = pd.DataFrame({'hobby' : ['놀기', '자기', '읽기', '먹기', '공부', '명상']})
member = pd.concat([member, hobby], axis=1) # 디폴트는 행 병합 / axis=1 열 병합
```

* 삭제

```python
member.drop(['hobby', 'major'], axis = 1, inplace=True) # member바꾸기 
                                                        # 1) inplace=True 또는 
                                                        # 2) member = member.drop(['hobby', 'major'], axis = 1)

# 행 삭제
member.drop(4, inplace=True)
```

## 6. 정렬 

```python
# 인덱스 정렬
member.sort_index(ascending=False, inplace=True)

# 특정열의 값 기준 정렬
member.sort_values(by=['name', 'age'], inplace=True) # by는 키워드 인수로 꼭! 써야함. 'name'이 같으면 'age' 순서로
```


## 7. 기초통계 분석 

* count : NA(결측치)를 제외한 개수
* min
* max
* sum
* mean
* std : 표준편차
* var : 분산
* quantile 분위수(1사분위수, 2사분위수, 3사분위수)
* median
* corr : 상관관계

* 수치형 데이터
```python
iris_df.describe() # 수치형 데이터의 개수, 평균, 표준편차, 최소 최대, 사분위수
```

* 범주형 데이터
```python
iris_df["species"].describe() # 범주형 데이터 : 전체개수, 종류, 가장 많은 종류, 가장 많은 종류의 개수
```

* 수치형과 범주형 데이터 모두
```python
iris_df.describe(include='all') # 수치형과 범주형 데이터 모두 describe
```

## 8. 그룹화

```python
iris_df.groupby(['species']).mean() # 종류 별로 평균
```




