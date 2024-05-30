# Python day1 (2024-05-30)

# ch1. 파이썬 개요 및 환경설정

1. 아나콘다 다운로드
2. Jupyter Notebook 파일 저장 경로 수정
   
   * Jupyter Notebook 아이콘 우클릭 -> 속성에서 대상(T) "파일 위치"

3. jupyter Notebook 사용법

   ```
   shift+Enter : 포커스된 셀이 실행되고 다음셀로 이동
   alt+Enter : 포커스된 셀이 실행되고 다음셀이 생성된 후 이동
   ctrl+Enter : 포커스된 셀이 실행되고 포커스 이동없음
   Enter =: 셀이 포커스됨(편집 상태)
   ```

4. ESC키 누르고 핫키

   ```
    dd : 셀 삭제
    a : 윗셀 추가
    b : 아랫셀 추가
    m : 마크업셀로 전환
    y : 코드셀로 전환
   ```

# ch2. 자료형과 연산자

## ch2-1. 변수
1.1 변수선언

   * 별도의 변수 선언과정 없음


1.2 변수 할당

   * 대입 연산자(=) 사용

**새로 할당할 때마다 새로운 메모리 공간에 값을 할당**

```c

area = 10
print("area 값은", area)
print("area 타입은", type(area))
print("area 주소는", id(area)) 
```




