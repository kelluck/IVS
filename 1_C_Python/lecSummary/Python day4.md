# Python day4 (2024-06-05)

# ch11. 데이터 시각화
* 시각화 라이브러리 : matplolib, seaborn, folium(지도시각화)
* matplolib : 판다스 데이터프레임 내부적으로 matplotlib 내장
* seaborn : matplolib기반으로 다양한 색, 테마, 챠트 등을 추가한 라이브러리

## 1. matplotlib

> 시작 전 설정
```python
import matplotlib.pyplot as plt
%matplotlib inline
# 그래프 해상도 높임
%config InlineBackend.figure_format='retina'
#한글설정
plt.rc('font', family='Malgun Gothic') # window os
#plt.rc('font', family='AppleGothic') #mac os
plt.rc('axes', unicode_minus=False)
# 경고 메세지 안보이게
import warnings
warnings.filterwarnings(action='ignore')
```

> line plot
```python
import seaborn as sns
iris = sns.load_dataset("iris")
iris.plot(kind="line", figsize=(12,4))
plt.legend(bbox_to_anchor=(1.01, 1), loc=2, borderaxespad=0.)
plt.show()
```

> box plot
```python
iris.plot(kind="box", figsize=(12,4))
```

> scatter plot
```python
iris.plot(kind="scatter", x="petal_length", y="petal_width", figsize=(10,4))
plt.title('두 변수간 scatter plot')
plt.show()
```

## 2. seaborn
* matplotlib을 기반으로 만든 고수준 그래픽 라이브러리
*  Seaborn으로 그래프를 그리기 위해서 다음 단계를 따름
  
    * 데이터 준비
    * 미적속성 설정
    * 함수를 선택하여 그래프 그리기력, 저장 출력, 저장

공식사이트 : <https://seaborn.pydata.org>

seaborn API : <https://seaborn.pydata.org/api.html>

> scatter plot
```python
plt.figure(figsize=(10,4))
sns.scatterplot(data=iris, x="petal_length", y="petal_width", hue="species") # hue : 그룹화
plt.legend(bbox_to_anchor=(1.01, 1), loc=2, borderaxespad=0.) # legend 위치 조정
plt.show()
```

> bar plot
```python
plt.figure(figsize=(10,4))
sns.barplot(data=iris, x="species", y="petal_width")
plt.show()
```

---
# ch12. 웹데이터 수집
* 크롤링(Crawling) : 웹 인덱싱을 위해 WWW를 체계적으로 탐색해나가는 것
* 파싱(Parsing) : 웹 상의 자연어, 컴퓨터 언어 등의 일련의 문자열들을 분석하는 프로세스
  
## 1. BeautifulSoup과 requests

* BeautifulSoup: 웹 페이지의 정보를 쉽게 스크랩할 수 있도록 기능을 제공하는 라이브러리
* Requests: HTTP 요청을 보낼 수 있도록 기능을 제공하는 라이브러리
  
공식 사이트 : <https://www.crummy.com/software/BeautifulSoup>

Documentation : <https://www.crummy.com/software/BeautifulSoup/bs4/doc>

```python
import requests
from requests_file import FileAdapter

s = requests.Session()
s.mount("file://", FileAdapter())
response = s.get('file:///C:/C_Python/source/Python/ch12_sample.html')

if response.status_code == 200: # 200이면 성공
    print('success!')
if response.status_code == 404: # 404면 에러 (파일 주소 확인!)
    print('Not found')

response.content.decode('utf-8')
```

* html 파싱
```python
from bs4 import BeautifulSoup 
soup = BeautifulSoup(response.content,"html.parser")

el = soup.select('div.contents') # select결과는 list
el = soup.select_one('div.contents')
print(el.text)
span = el.select_one('span > b')
print(span.text)

>> <h1 class="greeting css" id="test">Hello CSS</h1>
>> el.text : Hello CSS
>> el의 속성들 : {'class': ['greeting', 'css'], 'id': 'test'}
>> el의 class속성 : ['greeting', 'css']
>> el의 name : h1

# h1태그들 다 : 없는 태그는 빈스트링. 한 엘리먼트만 있어도 리스트로 반환
el = soup.select("h1")
print('el : ', el)
print('el의 text들 :', [e.text for e in el])
print('el의 string :', [e.string for e in el])
print('el의 속성들 :', [e.attrs for e in el])
print('el의 class속성들 :', [e.attrs['class'] for e in el])

>> el :  [<h1 class="greeting css" id="test">Hello CSS</h1>, <h1 class="css">Hi CSS</h1>]
>> el의 text들 : ['Hello CSS', 'Hi CSS']
>> el의 string : ['Hello CSS', 'Hi CSS']
>> el의 속성들 : [{'class': ['greeting', 'css'], 'id': 'test'}, {'class': ['css']}]
>> el의 class속성들 : [['greeting', 'css'], ['css']]

```



