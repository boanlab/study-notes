# 문자열 탐색 (String Matching)

### 정의
- 문자열에서 찾고자 하는 특정 문자열(pattern)의 위치를 찾는 알고리즘

### 종류
- 단순 비교
- 라빈-카프 알고리즘
- KMP 알고리즘
- 보이어-무어 알고리즘
- 아호-코라식 알고리즘

---




## 라빈-카프 알고리즘(Rabin-Karp)

 

### 정의

- 문자열에 **해싱 기법**을 사용하여 **해시 값**으로 비교하는 알고리즘

### 원리

- 각 문자의 **아스키 코드** 값에 **특정 제곱수**를 차례대로 곱하고 **모두 더하여** 해시 값을 만든다.
    - 차례대로 라는 의미는 자리마다(흔히 인덱스) 다른 수를 곱해주는 것

### 예시

- 특정 제곱수를 2로 설정 시, abacaaba의 해시 값 ( a : 97 , b : 98 )
    - 97 * 2^7 +
        
        98 * 2^6  +
        
        97 * 2^5 + … (생략)
        
    
- 문자열 AABDCDAB에서 패턴 ABD 가 발견되는 지 탐색하는 예제

| 문자열 | A | A | B | D | C | D | A | B |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 패턴 | A | B | D |  |  |  |  |  |
- 검색 대상 문자열 해시 값(AAB) : 846
- 문자열 패턴 해시 값(ABD) : 851
    - 탐색 실패

| 문자열 | A | A | B | D | C | D | A | B |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 패턴 | A | B | D |  |  |  |  |  |
- ABD 해시 값이 같아 탐색 성공

이후로도 있는 지 같은 방식으로 계속 탐색

### 코드

```python
def find_string(parent, pattern):
	  parent_len = len(parent)    # 검색 대상 문자열
    pattern_len = len(pattern)  # 찾으려는 패턴 문자열
    parent_hash = 0
    pattern_hash = 0
    power = 1
    for i in range(parent_len - pattern_len + 1):
        if i == 0:
            for j in range(pattern_len):
                parent_hash += ord(parent[pattern_len - 1 - j]) * power  # ord : 아스키코드 값 반환
                pattern_hash += ord(pattern[pattern_len - 1 - j]) * power
                if j < pattern_len - 1:
                    power *= 2
        else:
            parent_hash = 2 * (parent_hash - ord(parent[i - 1]) * power) + ord(parent[pattern_len - 1 + i])

        if parent_hash == pattern_hash:
            found = True
            for j in range(pattern_len):
                if parent[i + j] != pattern[j]:
                    found = False
                    break
            if found:
                print(f'{i + 1}번째에서 발견')
```

- 특정 제곱수를 2로 설정 시의 코드

### 장점

- 일반적인 경우 빠른 속도
- 비교적 간단한 구조

### 단점

- 패턴 등이 길어질 수록 연산이 증가
    - 호너의 법칙 등을 사용하여 보완
- 해시 충돌

### 시간복잡도

- O(n)
