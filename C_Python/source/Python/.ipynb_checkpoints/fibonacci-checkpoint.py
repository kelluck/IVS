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

if __name__ == '__main__': # import할때는 실행 x, 함수만 정의
    fibonacci(100)
    print(__name__, '에서 테스트함')